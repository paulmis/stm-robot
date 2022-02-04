# stm-robot [CSE2215]
Code for the STM32-based robot written during the CSE2215 (Embedded Systems) course.

### Components

- STM32F103C8T6 low-power MCU
- 5000mAh 5V LiPo battery
- x2 65mm wheels powered by TT DC motors @ 5V
- x2 HC-020K speed encoders (5mm precision)
- x2 TCTR5000 infrared sensors
- HC-SR04 ultrasonic sensor

### Functions

The *stm-robot* is capable of:
- travelling a fixed distance with a relative error of <2% (or 1cm absolute, whichever is bigger)
- following a line with <=90 degrees turns
- detecting obstacles in front of the robot
- forming a platoon on a line with other robots

This code scored 10/10 during the 10-minute demo, fulfilling all requirements.

### Files

- src.ino - setup, main loop
- delay.ino - delay functions using hardware timers
- ifr.ino - reading infraread sensor output using MCU's ADC registers
- led.ino - led handling
- motor.ino - motor control functions
- speed.ino - HC-020K speed encoders
- ultrasonic.ino - HC-SR04 ultrasonic sensor
- demo.ino - variable motor speed
- line.ino - line-following algorithm
- platton.ino - platoon forming algorithm
- travel.ino - fixed distance travel with obstacle detection

The comments refer to the STM32F10* series manual [available here](https://www.st.com/resource/en/reference_manual/rm0008-stm32f101xx-stm32f102xx-stm32f103xx-stm32f105xx-and-stm32f107xx-advanced-armbased-32bit-mcus-stmicroelectronics.pdf).
