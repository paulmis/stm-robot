/**
 * The line-following algorithm.
 * foward - the PWM speed when moving foward
 * turn - the PWM speed when turning
 * threshold - the IFR threshold to determine if the sensor detects a black line
 * wait - the time (in milliseconds) to wait after the frame has been executed
 */
void line(int foward, int turn, int threshold, int wait) {
  static bool last_left = true;
  static int x = 1.4;
  
  // Get the IFR readouts and check if thresholds were broken
  int l = ifr(IFR_L), r = ifr(IFR_R);
  bool cl = l > threshold, cr = r > threshold; 

  // Print plot data
  Serial.print("Left: ");
  Serial.print(l);
  Serial.print(", Right: ");
  Serial.println(r);

  if (cl && cr) {
    if ((float)l / r > x) {
      left(turn);
      last_left = true;
    }
    else if ((float)l / r < 1 / x) {
      right(turn);
      last_left = false;
    }
    else if (last_left) right(turn);
    else left(turn);
    ledOff();
    delay(50);
  } else if (cl) {
    mtr(turn, 0, 0, 140);
    ledOn();
    last_left = true;
    delay(10);
  } else if (cr) {
    mtr(0, 140, turn, 0);
    ledOn();
    last_left = false;
    delay(10);
  } else {
    fowards(foward);
    ledOn();
  }
  
  delay(wait);
}
