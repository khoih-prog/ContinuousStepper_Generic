/****************************************************************************************************************************
  SAMDUE_PWM_StepperControl.ino
  For SAM_DUE boards using hardware-based PWM
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/ContinuousStepper_Generic
  Licensed under MIT license

  Credits of Paul van Dinther (https://github.com/dinther). Check https://github.com/khoih-prog/RP2040_PWM/issues/16
*****************************************************************************************************************************/

// Use with Stepper-Motor driver, such as TMC2209

#define _PWM_LOGLEVEL_       4

// Select false to use PWM
#define USING_TIMER       true

#include "ContinuousStepper_Generic.h"

// SAM_DUE:
// PWM pins: 6, 7, 8, 9
// Timer pins: 2-5, 10-13.
// pin2:   TC0_CHA0, pin3:  TC2_CHA7, pin4:  TC2_CHB6, pin5:  TC2_CHA6
// pin 10: TC2_CHB7, pin11: TC2_CHA8, pin12: TC2_CHB8, pin13: TC0_CHB0

#if USING_TIMER
  #define STEP_PIN       5
#else
  #define STEP_PIN       6
#endif

SAMDUE_PWM* stepper;

#define DIR_PIN       9

// The Stepper RPM will be ( speed * 60 ) / steps-per-rev
// For example, 28BYJ-48 Stepper Motor (https://lastminuteengineers.com/28byj48-stepper-motor-arduino-tutorial/) has 32 Steps/Rev
// Speed = 640 Hz => Stepper RPM = (640 * 60 / 32) = 1200 RPM
void setSpeed(int speed)
{
  if (speed == 0)
  {
    // Use DC = 0 to stop stepper
    stepper->setPWM(STEP_PIN, 500, 0);
  }
  else
  {
    //  Set the frequency of the PWM output and a duty cycle of 50%
    digitalWrite(DIR_PIN, (speed < 0));
    stepper->setPWM(STEP_PIN, abs(speed), 50);
  }
}

void setup() 
{
  pinMode(DIR_PIN, OUTPUT);
  
  Serial.begin(115200);

  while (!Serial && millis() < 5000);

  delay(100);

  Serial.print(F("\nStarting SAMDUE_PWM_StepperControl on "));
  Serial.println(BOARD_NAME);
  Serial.println(SAMDUE_PWM_VERSION);
  Serial.println(CONTINUOUS_STEPPER_GENERIC_VERSION);
  
  // Create PWM object and passed just a random frequency of 500
  // The duty cycle is how you turn the motor on and off
  stepper = new SAMDUE_PWM(STEP_PIN, 500, 0);
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
