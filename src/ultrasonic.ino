#define MIN_ULTRASONIC_DELAY 50
const int FR_TRIG = PB4, FR_ECHO = PB3;   // front
const int SI_TRIG = PB15, SI_ECHO = PB14; // side
bool obstaclePresent = false;
int frontDistance, sideDistance;

int bFront, eFront, lastUltrasonicFront = 0;
int bSide, eSide, lastUltrasonicSide = 0;

/**
 * Emits a homing ultrasonic pulse from the specified sensor.
 * TRIG - the TRIG GPIO pin
 */
void ultrasonic(int TRIG) {
  // Clear the TRIG
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);

  // Send a 10uS pulse to trigger the ultrasonic emmital
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
}

inline void ultrasonicFront() {
  if (millis() - lastUltrasonicFront > MIN_ULTRASONIC_DELAY) {
    ultrasonic(FR_TRIG);
    lastUltrasonicFront = millis();
  }
}

/**
 * Callback triggered when FR_ECHO creates a pulse.
 */
void frontUltrasonicCallback() {
  if (digitalRead(FR_ECHO) == HIGH)
    bFront = micros();
  else {
    eFront = micros();
    frontDistance = (float)(eFront - bFront) * 0.017;
    obstaclePresent = frontDistance <= 15.0;    
  }
}

inline void ultrasonicSide() {
  if (millis() - lastUltrasonicSide > MIN_ULTRASONIC_DELAY) {
    ultrasonic(SI_TRIG);
    lastUltrasonicFront = millis();
  }
}

void sideUltrasonicCallback() {
  if (digitalRead(SI_ECHO) == HIGH)
    bSide = micros();
  else {
    eSide = micros();
    sideDistance = (float)(eSide - bSide) * 0.017;
  }
}
