/**
 * Tests the motors (variable speed).
 */
void demo() {
  // Run
  fowards(150);
  delay(3500);

  // Increase speed
  for (int speed = 150; speed < 256; speed++) {
    fowards(speed);
    delay(12);
  }

  // Run
  fowards(255);
  delay(3500);

  // Stop
  for (int speed = 255; speed > 100; speed--) {
    fowards(speed);
    delay(8);
  }
  freeze();
  delay(1000);
}
