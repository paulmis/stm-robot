const int LED = PB10;

void ledOn() {
  digitalWrite(LED, HIGH);
}

void ledBlink(int period) {
  digitalWrite(LED, HIGH);
  wait(period / 2);
  digitalWrite(LED, LOW);
  wait(period / 2);
}

void ledOff() {
  digitalWrite(LED, LOW);
}
