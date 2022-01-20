extern int frontDistance;

void platoon(int threshold) {
  if (frontDistance > 50)
    freeze();
  else {
    int speed = 20 + 9 * frontDistance;
  
    // Get the IFR readouts and check if thresholds were broken
    int l = ifr(IFR_L), r = ifr(IFR_R);
    bool cl = l > threshold, cr = r > threshold; 
  
    float x = 1.3;
    if (cl ^ cr) {
      if (cl) fowards(min(255, x * speed), speed);
      else    fowards(speed, min(255, x * speed));
    }
    else 
      fowards(speed);
  }
}
