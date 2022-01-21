const int LED = PB10;

void ledOn() {
  digitalWrite(LED, HIGH);
}

void ledBlink(int period) {
  digitalWrite(LED, HIGH);
  delay(period / 2);
  digitalWrite(LED, LOW);
  delay(period / 2);
}

void ledOff() {
  digitalWrite(LED, LOW);
}

bool lastOn = false;
void handleLed() {
    if (lastOn) ledOff();
    else ledOn();
    lastOn = !lastOn;
}
