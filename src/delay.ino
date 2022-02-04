 /**
 * Sets the TIM2 period. The prescaler and overflow values need to be calculted.
 */
void setPeriod(uint16_t PSC, uint16_t ARR) {
  // Disable the counter [15.4.1]
  TIMER2_BASE->CR1 &= ~1;
 
  // Set the prescaler and overflow values
  // The APB1 PSC is assumed to be 1, and the SYSCLOCK to be 72MHz
  TIMER2_BASE->PSC = PSC;
  TIMER2_BASE->ARR = ARR;

  // Generate update [15.4.6]
  TIMER2_BASE->EGR |= 1;

  // Enable the counter [15.4.1]
  TIMER2_BASE->CR1 |= 1;
}

/**
 * Sets a new period for TIM2 and waits for that time to elapse.
 */
inline void wait(uint16_t PSC, uint16_t ARR) {
  setPeriod(PSC, ARR);
  wait();
}

/**
 * Resets the TIM2 and waits until the preset period elapsed.
 */
void wait() {
  // Reset the counter and overflow flag (UIF) [15.4.5]
  TIMER2_BASE->CNT = 0;
  TIMER2_BASE->SR &= ~1;

  // Wait for the overflow flag to be raised [15.4.5]
  while (!(TIMER2_BASE->SR & 1));
}
