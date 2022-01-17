const int FR_TRIG = PB4; // front trigger
const int FR_ECHO = PB3; // front echo

/**
 * Returns the current distance (in cm) from an ultrasonic sensor.
 * TRIG - the TRIG GPIO pin
 * ECHO - the ECHO GPIO pin
 */
int ultrasonic(int TRIG, int ECHO) {
  // Clear the TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Send a 10uS pulse to trigger the ultrasonic emmital
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  // Wait for the signal return
  return pulseIn(ECHO, HIGH) * 0.017;
}
