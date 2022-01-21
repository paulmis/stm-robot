/**
 * Tests the motors (variable speed).
 */
void demo() {
  int s, e;
  // Run
  fowards(170);
  s = micros();
  wait(3999, 62999); // 3.5s
  e = micros();
  Serial.println(e - s);

  // Increase speed
  for (int speed = 170; speed < 256; speed++) {
    fowards(speed);
    wait(11, 59999); // 10ms
  }

  // Run
  fowards(255);
  s = micros();
  wait(3999, 62999); // 3.5s
  e = micros();
  Serial.println(e - s);

  // Stop
  for (int speed = 255; speed > 100; speed--) {
    fowards(speed);
    wait(7, 53999); // 6ms
  }
  freeze();

  s = micros();
  wait(1124, 62999); // 1s
  e = micros();
  Serial.println(e - s);
}
