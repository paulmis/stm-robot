const int IFR_L = PA3; // left IFR sensor
const int IFR_R = PA0; // right IFR sensor

/**
 * Returns the infrared sensor readout with values between 0 and 2^15.
 * IFR - infrared GPIO analog input pin
 */
int ifr(int IFR) {
  return analogRead(IFR);
}
