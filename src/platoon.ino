extern int frontDistance;

void platoon(int threshold) {
  ultrasonicFront();
  
  // Get the IFR readouts and check if thresholds were broken
  int l = ifr(IFR_L), r = ifr(IFR_R);
  bool cl = l > threshold, cr = r > threshold;

  if (frontDistance > 60 || (frontDistance >= 12 && frontDistance < 14))
    freeze();
  else if (frontDistance < 12) {
    if (cl ^ cr) {
      if (cl) {
        mtr(155, 0, 220, 0);
        delay(30);
      }
      else {
        mtr(230, 0, 145, 0);
        delay(30);
      }
    }
    else
      backwards(180);
  }
  else {
    int speed = max(0, min(200, 15 * frontDistance - 70));
    if (cl ^ cr) {
      if (cl) leftonly(180);
      else    rightonly(180);
    }
    else 
      fowards(speed);
  }
  delay(10);
}
