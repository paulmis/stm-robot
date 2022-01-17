/**
 * Sets up the eq. of the Arduino's delay().
 * Uses the TIM7 basic timer.
 */
void waitSetup() {
  // Enable TIM7
  RCC_BASE->APB1ENR |= RCC_APB1ENR_TIM7ER;

  // APB1 is limited to 36MHz
  // To get microsecond accuracy the perscaler register value needs to
  // be set to 35 (as per 17.4.7)
  TIMER7_BASE->PSC = 35;

  // Overflow ARR to apply the perscaler change
  TIMER7_BASE->ARR = 0xFFFF;

  // Enable the counter (as per 15.4.1)
  TIMER7_BASE->CR1 = true;

  // Wait for the changes to take effect
  // The UIF should be set (as per 15.4.5)
  while (!(TIMER7->SF & TIMER_SR_UIF_BIT));            
}

/**
 * Sleeps for the specified amount of microseconds.
 * us - time to sleep (in microseconds)
 */
void waitu(uint16_t us) {
  // Reset the counter
  TIMER7_BASE->CNT = 0;

  // Wait for the counter to reach the desired value
  while (TIMER7_BASE->CNT < us);
}

/**
 * Sleeps for the specified amount of microseconds.
 * ms - time to sleep (in milliseconds)
 */
void wait(uint16_t ms) {
  // Execute a 1000us wait ms times
  while (ms--) waitu(1000);
}
