extern const int IA1, IB1, IA2, IB2; // motors
extern const int FR_TRIG, FR_ECHO; // ultrasonic
extern const int IFR_L, IFR_R; // infrared
extern const int ENC_L, ENC_R; // speed encoders
extern const int LED;

void setup() {
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);
  pinMode(IA1, OUTPUT);
  pinMode(IB1, OUTPUT);
  pinMode(IA2, OUTPUT);
  pinMode(IB2, OUTPUT);
  pinMode(FR_TRIG, OUTPUT);
  pinMode(FR_ECHO, INPUT);
  pinMode(IFR_L, INPUT);
  pinMode(IFR_R, INPUT);
  pinMode(ENC_L, INPUT);
  pinMode(ENC_R, INPUT);
  Serial.begin(9600);
  ledBlink(500);
  ledOn();
}

void loop() {
  line(170, 255, 700, 2);
}
