const int IFR_L = PA3; // left IFR sensor
const int IFR_R = PA0; // right IFR sensor

/**
 * Returns the infrared sensor readout with values between 0 and 2^15.
 * IFR - infrared GPIO analog input pin
 */
int ifr(int IFR) {
  // Make sure the IFR pin is one of the PA0-7 ones (connected to ADC1)
  // For STM32F103Cs PA0-7 are evaluated to 0-7
  ASSERT(IFR >= 0 && IFR < 8);

  // PA0-7 pins have corresponding ADC1 channels from 0-7 assigned
  return adc(IFR);
}

/**
 * Equivalent of analogRead for the specified channel of ADC1.
 * Based on figure 23 from the STM32 manual.
 */
int adc(int channel) {
  // Set the channel [11.12.11]
  ADC1_BASE->SQR3 = channel;

  // Start the conversion [11.7]
  // The SWSTART is the 22nd bit in ADC_CR2 [11.12.3]
  ADC1_BASE->CR2 |= (1 << 22);

  // Block until the End of Conversion bit is set [11.12.1]
  while (!(ADC1_BASE->SR & 0x2));

  // Return the data from the data register
  // Since ADC_DR can contain dual mode data from ADC2, use a mask to
  // retrieve lower 16 bits only [11.12.14]
  return (uint16)(ADC1_BASE->DR & 0xFFFF);
}
