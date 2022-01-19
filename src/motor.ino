const int IB1 = PB6; // motor 1 (backwards)
const int IA1 = PB7; // motor 1 (fowards)
const int IB2 = PB8; // motor 2 (backwards)
const int IA2 = PB9; // motor 2 (fowards)

inline void fowards(int speed) { mtr(0, speed, 0, speed); }
inline void fowards(int speedL, int speedR) { mtr(0, speedL, 0, speedR); }
inline void backwards(int speed) { mtr(speed, 0, speed, 0); }
inline void left(int speed) { mtr(speed, 0, 0, speed); }
inline void leftonly(int speed) { mtr(0, 0, 0, speed); }
inline void right(int speed) { mtr(0, speed, speed, 0); }
inline void rightonly(int speed) { mtr(0, speed, 0, 0); }
inline void freeze() { mtr(0, 0, 0, 0); }

/** 
 *  Sets the h-bridge signals.
 *  ia1, ib1 -> motor 1
 *  ia2, ib2 -> motor 2
 */
void mtr(int ia1, int ib1, int ia2, int ib2) {
  analogWrite(IA1, ia1);
  analogWrite(IB1, ib1);
  analogWrite(IA2, ia2);
  analogWrite(IB2, ib2);
}

void travel(int speed, int distance, int lead, float dx) {
  resetRot();
 
  while ((int)getDistanceTraveledL() < min(distance - lead, 5)) {
    fowards(255);
  }

  while ((int)getDistanceTraveledL() < distance - lead) {
    float dl = (float)distance + lead - getDistanceTraveledL(),
          dr = (float)distance + lead - getDistanceTraveledR();
    if (getDistanceTraveledL() - getDistanceTraveledR() > dx) {
      rightonly(speed - max(0.0, 26.0 - dr) * 3);
      ledOn();
    }
    else if (getDistanceTraveledR() - getDistanceTraveledL() > dx) {
      leftonly(speed - max(0.0, 26.0 - dl) * 3);
      ledOn();
    }
    else {
      fowards(speed - max(0.0, 26.0 - dl) * 3, speed - max(0.0, 26.0 - dr) * 3);
      ledOff();
    }
  }

  freeze();
}
