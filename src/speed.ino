const int ENC_L = PB12; // left speed encoder
const int ENC_R = PB13; // right speed encoder

int ROT_L = 0, ROT_R = 0;
int time_l = 0, time_r = 0;

void resetRot() {
  ROT_L = 0, ROT_R = 0;
  time_l = 0, time_r = 0;
}

void countL() {
  if (millis() - time_l > 3) {
    ROT_L++;
    time_l = micros();
  }
}

void countR() {
  if (millis() - time_r > 3) {
    ROT_R++;
    time_r = micros();
  }
}

double getDistanceTraveledL() {
  return 3.14 * 6.5 / 40 * ROT_L;
}

double getDistanceTraveledR() {
  return 3.14 * 6.5 / 40 * ROT_R;
}
