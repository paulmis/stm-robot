#define _T TIMER2_BASE
#define _T_APB RCC_BASE->APB1ENR
#define _T_EN RCC_APB1ENR_TIM2EN
#define CYCLES_PER_MICROSECOND 72

/**
 * Sets up the eq. of the Arduino's delay().
 * Uses the TIM2 timer.
 */
void waitSetup(uint32 period) {
  // Enable TIM2 (enabled by default)
  _T_APB |= _T_EN;

  // The SYSCLOCK is already prescaled to us-precision,
  // therefore disable the timer's prescaler
  _T->PSC = 10000;

  // Set overflow to max
  _T->ARR = 0xFFFF;

  // Enable the counter (as per 15.4.1)
  _T->CR1 |= TIMER_CR1_CEN;      

/**
  0. setup
  - halt
  - ??

  1. setPeriod
  - set prescaler
  - set overflow

  uint32 periodCycles = period * CYCLES_PER_MICROSECOND;
  uint16 psc = (uint16)(periodCycles / MAX_RELOAD + 1);
  TIMER2_BASE->PSC = psc;
  TIMER2_BASE->ARR = (uint16)((periodCycles + (psc / 2)) / psc);

  2. setInterrupt
  - set channel mode
  - set compare
  - attach interrupt

  3. refresh
  **/
}

/**
 * Sleeps for the specified amount of microseconds.
 * us - time to sleep (in microseconds)
 */
void waitu(uint16_t us) {
  // Reset and wait for the counter to reach the desired value
  _T->CNT = 0;
  while (_T->CNT < us);
}

/**
 * Sleeps for the specified amount of microseconds.
 * ms - time to sleep (in milliseconds)
 */
void wait(uint16_t ms) {
  // Execute a 1000us wait ms times
  while (ms--) waitu(1000);
}
