
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
