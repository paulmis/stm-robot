#define LED_RATE 200    // in microseconds; should give 0.5Hz toggles

extern const int IA1, IB1, IA2, IB2; // motors
extern const int FR_TRIG, FR_ECHO; // ultrasonic
extern const int IFR_L, IFR_R; // infrared
extern const int ENC_L, ENC_R; // speed encoders
extern const int LED;

HardwareTimer timer(2);

void setup() {
  Serial.begin(9600);
  
  pinMode(LED, OUTPUT);
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

  // Pause the timer while we're configuring it
    timer.pause();

    // Set up period
    timer.setPeriod(LED_RATE); // in microseconds

    // Set up an interrupt on channel 1
    timer.setChannel1Mode(TIMER_OUTPUT_COMPARE);
    timer.setCompare(TIMER_CH1, 1);  // Interrupt 1 count after each update
    timer.attachCompare1Interrupt(handler_led);

    // Refresh the timer's count, prescale, and overflow
    timer.refresh();

    // Start the timer counting
    timer.resume();
}

bool lastOn = false;
void handler_led(void) {
    if (lastOn) ledOff();
    else ledOn();
    lastOn = !lastOn;
}

void loop() {
  Serial.println(TIMER2_BASE->PSC);
  delay(500);
}
