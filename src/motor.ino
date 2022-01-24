const int IB1 = PB6; // motor 1 (backwards)
const int IA1 = PB7; // motor 1 (fowards)
const int IB2 = PB8; // motor 2 (backwards)
const int IA2 = PB9; // motor 2 (fowards)

inline void fowards(int speed) { mtr(0, speed, 0, speed); }
inline void fowards(int speedL, int speedR) { mtr(0, speedL, 0, speedR); }
inline void backwards(int speed) { mtr(speed, 0, speed, 0); }
inline void left(int speed) { mtr(speed, 0, 0, speed); }
inline void leftonly(int speed) { mtr(0, 0, 0, speed); }
inline void leftreverseonly(int speed) { mtr(0, 0, speed, 0); }
inline void right(int speed) { mtr(0, speed, speed, 0); }
inline void rightonly(int speed) { mtr(0, speed, 0, 0); }
inline void rightreverseonly(int speed) { mtr(speed, 0, 0, 0); }
inline void freeze() { mtr(0, 0, 0, 0); }

extern bool obstaclePresent;

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

/**
 * Travels the specified distance, moving in a straight-ish line.
 * speed - pwm cycle duty
 * distance - the distance to travel in cm
 * lead - the length of the slide at the end (depends on the surface)
 * dx - the threshold at which the direction correction should take place
 *      compared to the distance traveled by each of the wheels
 */
void travel(int speed, int distance, int lead, float dx) {
  // Reset distance traveled counter
  resetRot();

  // Logic
  while ((int)getDistanceTraveledL() < distance - lead) {
    if (obstaclePresent)
      freeze();
    else {
      int l = speed - max(0.0, 26.0 - (float)distance + lead - getDistanceTraveledL()) * 3;
      int r = speed - max(0.0, 26.0 - (float)distance + lead - getDistanceTraveledR()) * 3;

      if (getDistanceTraveledL() - getDistanceTraveledR() > dx) {
        rightonly(r);
        ledOn();
      }
      else if (getDistanceTraveledR() - getDistanceTraveledL() > dx) {
        leftonly(l);
        ledOn();
      }
      else {
        fowards(l, r);
        ledOff();
      }
    }
    ultrasonicFront();
  }

  // Stop the vehicle
  freeze();
  delay(60000);
}
