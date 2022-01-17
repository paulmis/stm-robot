const int LED = PB0;

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
