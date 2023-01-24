/****************************************************************************************************************************
  Portenta_H7_PWM_StepperControlerControl.ino
  
  For Portenta_H7 boards
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/ContinuousStepper_Generic
  Licensed under MIT license

  Credits of Paul van Dinther (https://github.com/dinther). Check https://github.com/khoih-prog/RP2040_PWM/issues/16
*****************************************************************************************************************************/

// Use with Stepper-Motor driver, such as TMC2209

#if !( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) )
  #error For Portenta_H7 only
#endif

#define _PWM_LOGLEVEL_        4

// To be included only in main(), .ino with setup() to avoid `Multiple Definitions` Linker Error
#include "ContinuousStepper_Generic.h"

// Can't use same TimerIndex again, e.g., the D1 and D2, using TIM1, can't be use concurrently
// That's why D0, D1, D3, D4 and D6 (using TimerIndex 8, 1, HRTIM and 3) are OK together

// Only OK for D0, D1, D2, D4 and D5, PA_0C(D15/A0), PA_1C(D16/A1),
// D3, D6, D7, D8, D9, D10, D11, D12, D13, D14, D17(PC_2C/A2), D18(PC_3C/3), PC2(D19/A4) LEDG, LEDB not OK
#define pinD0    D0       // PH15 / TIM8_CH3N
#define pinD1    D1       // PK1  / TIM1_CH1, TIM8_CH3
#define pinD2    D2       // PJ11 / TIM1_CH2, TIM8_CH2N
#define pinD3    D3       // PG7  / HRTIM_CHE2
#define pinD4    D4       // PC7  / TIM3_CH2, TIM8_CH2, HRTIM_CHA2
#define pinD5    D5       // PC6  / TIM3_CH1, TIM8_CH1, HRTIM_CHA1, LPTIM3_OUT
#define pinD6    D6       // PA8  / HRTIM_CHB2 (TIM1_CH1, TIM8_BKIN2)

// See https://www.st.com/resource/en/datasheet/stm32h747xi.pdf, Table 7, page 53
// Can't use pins with same TIMx. For example,
// pinD1 and pinD2, using same TIM1, can't be used at the same time
// pinD4 and pinD5, using same TIM3, can't be used at the same time
// pinD3 and pinD6 are using HRTIM, can't be used at the same time and the minimum freq must be ~770Hz

#define STEP_PIN        pinD5

#define DIR_PIN         D9

mbed::PwmOut* stepper = nullptr;

// The Stepper RPM will be ( speed * 60 ) / steps-per-rev
// For example, 28BYJ-48 Stepper Motor (https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/) has 32 Steps/Rev
// Speed = 640 Hz => Stepper RPM = (640 * 60 / 32) = 1200 RPM
void setSpeed(int speed)
{
  if (speed == 0)
  {
    // Use DC = 0 to stop stepper
    setPWM(stepper, STEP_PIN, 500, 0);
  }
  else
  {
    //  Set the frequency of the PWM output and a duty cycle of 50%
    digitalWrite(DIR_PIN, (speed < 0));
    setPWM(stepper, STEP_PIN, abs(speed), 50);
  }
}

void setup() 
{
  pinMode(DIR_PIN, OUTPUT);
  
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  delay(100);

  Serial.print(F("\nStarting Portenta_H7_PWM_StepperControlerControl on "));
  Serial.println(BOARD_NAME);
  Serial.println(PORTENTA_H7_PWM_VERSION);
  Serial.println(CONTINUOUS_STEPPER_GENERIC_VERSION);
  
  //  SetPWM object and passed just a random frequency of 500
  //  The duty cycle is how you turn the motor on and off
  setPWM(stepper, STEP_PIN, 500, 0);
}

void loop() 
{
  // The Stepper RPM will be ( speed * 60 ) / steps-per-rev
  setSpeed(1000);
  delay(3000);

  // Stop before reversing
  setSpeed(0);
  delay(3000);

  // Reversing
  setSpeed(-500);
  delay(3000);

  // Stop before reversing
  setSpeed(0);
  delay(3000);
}
