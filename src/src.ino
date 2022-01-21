extern const int IA1, IB1, IA2, IB2; // motors
extern const int FR_TRIG, FR_ECHO, SI_TRIG, SI_ECHO; // ultrasonic
extern const int IFR_L, IFR_R; // infrared
extern const int ENC_L, ENC_R; // speed encoders
extern const int LED;
extern int sideDistance;

HardwareTimer timer(3);

void setup() {
  // Set up serial port
  Serial.begin(9600);

  // Set up GPIO
  pinMode(LED, OUTPUT);
  pinMode(IA1, OUTPUT);
  pinMode(IB1, OUTPUT);
  pinMode(IA2, OUTPUT);
  pinMode(IB2, OUTPUT);
  pinMode(FR_TRIG, OUTPUT);
  pinMode(FR_ECHO, INPUT);
  pinMode(SI_TRIG, OUTPUT);
  pinMode(SI_ECHO, INPUT);
  pinMode(IFR_L, INPUT);
  pinMode(IFR_R, INPUT);
  pinMode(ENC_L, INPUT);
  pinMode(ENC_R, INPUT);

  // Enable TIM2 (usually enabled by default) [7.3.8]
  RCC_BASE->APB1ENR |= 1;

  // Interrupts
  // Attach speed encoder interrupts
  attachInterrupt(digitalPinToInterrupt(ENC_L), countL, FALLING);
  attachInterrupt(digitalPinToInterrupt(ENC_R), countR, FALLING);

  // Attach ultrasonic sensor interrupts
  ultrasonicFront();
  attachInterrupt(digitalPinToInterrupt(FR_ECHO), frontUltrasonicCallback, CHANGE);
  ultrasonicSide();
  attachInterrupt(digitalPinToInterrupt(SI_ECHO), sideUltrasonicCallback, CHANGE);

  // Set up the LED
  timer.pause();
  timer.setPeriod(200000);
  timer.setChannel1Mode(TIMER_OUTPUT_COMPARE);
  timer.setCompare(TIMER_CH1, 1);
  timer.attachCompare1Interrupt(handleLed);
  timer.refresh();
  timer.resume();
}

void loop() {
  // 1. demo();
  // 2. in 5.
  // 3. line(160, 255, 600, 2);
  // 4. platoon(600);
  // 5. travel(220, 100, 2, 1.0);
  demo();
}
