/****************************************************************************************************************************
  ContinuousStepper_Generic.h
  For Generic boards
  Written by Khoi Hoang

  Built by Khoi Hoang https://github.com/khoih-prog/ContinuousStepper_Generic
  Licensed under MIT license

  Version: 1.0.0

  Version Modified By   Date      Comments
  ------- -----------  ---------- -----------
  1.0.0   K.Hoang      23/01/2023 Initial coding to use PWM to control continuous Stepper Motor
*****************************************************************************************************************************/

#pragma once

#ifndef CONTINUOUS_STEPPER_GENERIC_H
#define CONTINUOUS_STEPPER_GENERIC_H

#ifndef CONTINUOUS_STEPPER_GENERIC_VERSION
  #define CONTINUOUS_STEPPER_GENERIC_VERSION          "ContinuousStepper_Generic v1.0.0"

  #define CONTINUOUS_STEPPER_GENERIC_VERSION_MAJOR     1
  #define CONTINUOUS_STEPPER_GENERIC_VERSION_MINOR     0
  #define CONTINUOUS_STEPPER_GENERIC_VERSION_PATCH     0

  #define CONTINUOUS_STEPPER_GENERIC_VERSION_INT       1000000
#endif

#include "PWM_Generic_Debug.h"

/////////////////////////////// AVR ///////////////////////////////

#if ( defined(__AVR_ATmega2560__) || defined(__AVR_ATmega2561__) || defined(__AVR_ATmega1280__) || defined(__AVR_ATmega1281__) || \
      defined(__AVR_ATmega640__) || defined(__AVR_ATmega641__))
  #if defined(CONTINUOUS_STEPPER_USING_ATMEGA2560)
    #undef CONTINUOUS_STEPPER_USING_ATMEGA2560
  #endif
  #define CONTINUOUS_STEPPER_USING_ATMEGA2560      true

  #define CONTINUOUS_STEPPER_USING_AVR             true

  #define BOARD_TYPE    "Arduino AVR Mega2560/ADK"

  #if(_PWM_LOGLEVEL_>3)
    #warning Using Arduino AVR Mega, Mega640(P), Mega2560/ADK. Timer1-5 available
  #endif

#elif ( defined(__AVR_ATmega644__) || defined(__AVR_ATmega644A__) || defined(__AVR_ATmega644P__) || defined(__AVR_ATmega644PA__)  || \
        defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_NANO) || defined(ARDUINO_AVR_MINI) ||    defined(ARDUINO_AVR_ETHERNET) || \
        defined(ARDUINO_AVR_FIO) || defined(ARDUINO_AVR_BT)   || defined(ARDUINO_AVR_LILYPAD) || defined(ARDUINO_AVR_PRO)      || \
        defined(ARDUINO_AVR_NG) || defined(ARDUINO_AVR_UNO_WIFI_DEV_ED) || defined(ARDUINO_AVR_DUEMILANOVE) )
  #define CONTINUOUS_STEPPER_USING_AVR     true

  #define BOARD_TYPE    "Arduino AVR UNO, Nano, etc."

  #if(_PWM_LOGLEVEL_>3)
    #warning Using Aduino AVR ATMega644(P), ATMega328(P) such as UNO, Nano. Only Timer1,2 available
  #endif

#elif ( defined(ARDUINO_AVR_FEATHER328P) || defined(ARDUINO_AVR_METRO) || defined(ARDUINO_AVR_PROTRINKET5) || defined(ARDUINO_AVR_PROTRINKET3) || \
      defined(ARDUINO_AVR_PROTRINKET5FTDI) || defined(ARDUINO_AVR_PROTRINKET3FTDI) )
  #define CONTINUOUS_STEPPER_USING_AVR     true

  #define BOARD_TYPE      "Adafruit AVR ATMega328(P)"

  #if(_PWM_LOGLEVEL_>3)
    #warning Using Adafruit ATMega328(P), such as AVR_FEATHER328P or AVR_METRO. Only Timer1,2 available
  #endif

#elif ( defined(ARDUINO_AVR_LEONARDO) || defined(ARDUINO_AVR_LEONARDO_ETH) || defined(ARDUINO_AVR_YUN) || defined(ARDUINO_AVR_MICRO) || \
        defined(ARDUINO_AVR_ESPLORA)  || defined(ARDUINO_AVR_LILYPAD_USB)  || defined(ARDUINO_AVR_ROBOT_CONTROL) || defined(ARDUINO_AVR_ROBOT_MOTOR) || \
        defined(ARDUINO_AVR_CIRCUITPLAY)  || defined(ARDUINO_AVR_YUNMINI) || defined(ARDUINO_AVR_INDUSTRIAL101) || defined(ARDUINO_AVR_LININO_ONE) )
  #if defined(CONTINUOUS_STEPPER_USING_ATMEGA_32U4)
    #undef CONTINUOUS_STEPPER_USING_ATMEGA_32U4
  #endif
  #define CONTINUOUS_STEPPER_USING_ATMEGA_32U4       true

  #define CONTINUOUS_STEPPER_USING_AVR               true

  #define BOARD_TYPE    "Arduino AVR ATMega32U4"

  #if(_PWM_LOGLEVEL_>3)
    #warning Using Arduino ATMega32U4, such as Leonardo or Leonardo ETH. Only Timer1,3,4 available
  #endif

#elif ( defined(ARDUINO_AVR_FLORA8 ) || defined(ARDUINO_AVR_FEATHER32U4) || defined(ARDUINO_AVR_CIRCUITPLAY) || defined(ARDUINO_AVR_ITSYBITSY32U4_5V) || \
        defined(ARDUINO_AVR_ITSYBITSY32U4_3V)  || defined(ARDUINO_AVR_BLUEFRUITMICRO) || defined(ARDUINO_AVR_ADAFRUIT32U4) )
  #if defined(CONTINUOUS_STEPPER_USING_ATMEGA_32U4)
    #undef CONTINUOUS_STEPPER_USING_ATMEGA_32U4
  #endif
  #define CONTINUOUS_STEPPER_USING_ATMEGA_32U4       true

  #define CONTINUOUS_STEPPER_USING_AVR               true

  #define BOARD_TYPE    "Adafruit AVR ATMega32U4"

  #if(_PWM_LOGLEVEL_>3)
    #warning Using Adafruit ATMega32U4, such as Feather_32u4, AVR_CIRCUITPLAY, etc.. Only Timer1,3,4 available
  #endif

#elif ( defined(__AVR_ATmega32U4__) || defined(ARDUINO_AVR_MAKEYMAKEY ) || defined(ARDUINO_AVR_PROMICRO) || defined(ARDUINO_AVR_FIOV3) || \
        defined(ARDUINO_AVR_QDUINOMINI) || defined(ARDUINO_AVR_LILYPAD_ARDUINO_USB_PLUS_BOARD ) ) && !defined(TEENSYDUINO)
  #if defined(CONTINUOUS_STEPPER_USING_ATMEGA_32U4)
    #undef CONTINUOUS_STEPPER_USING_ATMEGA_32U4
  #endif
  #define CONTINUOUS_STEPPER_USING_ATMEGA_32U4       true

  #define CONTINUOUS_STEPPER_USING_AVR               true

  #define BOARD_TYPE    "Generic or Sparkfun AVR ATMega32U4"

  #if(_PWM_LOGLEVEL_>3)
    #warning Using Generic ATMega32U4, such as Sparkfun AVR_MAKEYMAKEY, AVR_PROMICRO, etc. Only Timer1,3,4 available
  #endif

#elif ( defined(__AVR_ATmega328P__) || defined(ARDUINO_AVR_DIGITAL_SANDBOX ) || defined(ARDUINO_REDBOT) || defined(ARDUINO_AVR_SERIAL_7_SEGMENT) )
  #define CONTINUOUS_STEPPER_USING_AVR               true

  #define BOARD_TYPE    "Generic or Sparkfun AVR ATMega328P"

  #if(_PWM_LOGLEVEL_>3)
    #warning Using Generic ATMega328P, such as Sparkfun AVR_DIGITAL_SANDBOX, REDBOT, etc.
  #endif

#elif ( defined(__AVR_ATmega128RFA1__) || defined(ARDUINO_ATMEGA128RFA1_DEV_BOARD) )
  #define CONTINUOUS_STEPPER_USING_AVR               true

  #define BOARD_TYPE    "Generic or Sparkfun AVR ATMega128RFA1"

  #if(_PWM_LOGLEVEL_>3)
    #warning Using Generic ATMega128RFA1, such as Sparkfun ATMEGA128RFA1_DEV_BOARD, etc.
  #endif

#elif ( defined(ARDUINO_AVR_GEMMA) || defined(ARDUINO_AVR_TRINKET3) || defined(ARDUINO_AVR_TRINKET5) )
  #error These AVR boards are not supported! Please check your Tools->Board setting.

/////////////////////////////// ESP8266 ///////////////////////////////

#elif ( defined(ESP8266) || ESP8266 )

  #define CONTINUOUS_STEPPER_USING_ESP8266           true
  #error Not supported yet

/////////////////////////////// ESP32 ///////////////////////////////

#elif ( defined(ESP32) || ESP32 )

  #define CONTINUOUS_STEPPER_USING_ESP32             true

/////////////////////////////// Nano-33-BLE ///////////////////////////////

#elif ( ARDUINO_ARCH_NRF52840 && TARGET_NAME == ARDUINO_NANO33BLE )
  #if(_PWM_LOGLEVEL_>3)
    #warning Using ARDUINO_NANO33BLE
  #endif

  #define CONTINUOUS_STEPPER_USING_NANO33BLE         true

/////////////////////////////// SAMD ///////////////////////////////

#elif ( defined(ARDUINO_SAMD_ZERO) || defined(ARDUINO_SAMD_MKR1000) || defined(ARDUINO_SAMD_MKRWIFI1010) \
     || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_SAMD_MKRFox1200) || defined(ARDUINO_SAMD_MKRWAN1300) || defined(ARDUINO_SAMD_MKRWAN1310) \
     || defined(ARDUINO_SAMD_MKRGSM1400) || defined(ARDUINO_SAMD_MKRNB1500) || defined(ARDUINO_SAMD_MKRVIDOR4000) || defined(__SAMD21G18A__) \
     || defined(ARDUINO_SAMD_CIRCUITPLAYGROUND_EXPRESS) || defined(__SAMD21E18A__) || defined(__SAMD51__) || defined(__SAMD51J20A__) || defined(__SAMD51J19A__) \
     || defined(__SAMD51G19A__) || defined(__SAMD51P19A__) || defined(__SAMD21G18A__) )

  #define CONTINUOUS_STEPPER_USING_SAMD              true

/////////////////////////////// NRF52 ///////////////////////////////

#elif (defined(NRF52840_FEATHER) || defined(NRF52832_FEATHER) || defined(NRF52_SERIES) || defined(ARDUINO_NRF52_ADAFRUIT) || \
       defined(NRF52840_FEATHER_SENSE) || defined(NRF52840_ITSYBITSY) || defined(NRF52840_CIRCUITPLAY) || \
       defined(NRF52840_CLUE) || defined(NRF52840_METRO) || defined(NRF52840_PCA10056) || defined(PARTICLE_XENON) || \
       defined(MDBT50Q_RX) || defined(NINA_B302_ublox) || defined(NINA_B112_ublox) )

  #define CONTINUOUS_STEPPER_USING_NRF52             true

/////////////////////////////// SAM DUE ///////////////////////////////

#elif ( defined(ARDUINO_SAM_DUE) || defined(__SAM3X8E__) )

  #define CONTINUOUS_STEPPER_USING_SAMDUE            true

/////////////////////////////// TEENSY ///////////////////////////////

#elif ( defined(CORE_TEENSY) ||  defined(__IMXRT1062__) || defined(__MK66FX1M0__) || defined(__MK64FX512__) ||  \
        defined(__MKL26Z64__) || defined(__MK20DX256__) || defined(__MK20DX128__) )

  #define CONTINUOUS_STEPPER_USING_TEENSY            true
  
/////////////////////////////// PORTENTA_H7 ///////////////////////////////
   
#elif ( ( defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_PORTENTA_H7_M4) ) && defined(ARDUINO_ARCH_MBED) )

  #define CONTINUOUS_STEPPER_USING_PORTENTA_H7        true    

/////////////////////////////// STM32 ///////////////////////////////

#elif ( defined(STM32F0) || defined(STM32F1) ||  defined(STM32F2) || defined(STM32F3)  ||defined(STM32F4) || defined(STM32F7) || \
        defined(STM32L0) || defined(STM32L1) ||  defined(STM32L4) || defined(STM32H7)  ||defined(STM32G0) || defined(STM32G4) || \
        defined(STM32WB) || defined(STM32MP1) || defined(STM32L5) )

  #define CONTINUOUS_STEPPER_USING_STM32             true

/////////////////////////////// megaAVR ///////////////////////////////

#elif ( defined(__AVR_ATmega4809__) || defined(ARDUINO_AVR_UNO_WIFI_REV2) || defined(ARDUINO_AVR_NANO_EVERY) || \
        defined(ARDUINO_AVR_ATmega4809) || defined(ARDUINO_AVR_ATmega4808) || defined(ARDUINO_AVR_ATmega3209) || \
        defined(ARDUINO_AVR_ATmega3208) || defined(ARDUINO_AVR_ATmega1609) || defined(ARDUINO_AVR_ATmega1608) || \
        defined(ARDUINO_AVR_ATmega809) || defined(ARDUINO_AVR_ATmega808) )

  #define CONTINUOUS_STEPPER_USING_MEGA_AVR          true

/////////////////////////////// RP2040 ///////////////////////////////

#elif ( defined(ARDUINO_ARCH_RP2040) || defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) || defined(ARDUINO_GENERIC_RP2040) ) && !defined(ARDUINO_ARCH_MBED)

  #define CONTINUOUS_STEPPER_USING_RPI_PICO          true

/////////////////////////////// MBED_RP2040 ///////////////////////////////

#elif ( defined(ARDUINO_NANO_RP2040_CONNECT) || defined(ARDUINO_RASPBERRY_PI_PICO) || defined(ARDUINO_ADAFRUIT_FEATHER_RP2040) || \
      defined(ARDUINO_GENERIC_RP2040) ) && defined(ARDUINO_ARCH_MBED)

  #define CONTINUOUS_STEPPER_USING_MBED_RPI_PICO     true
  
/////////////////////////////// ATTiny ///////////////////////////////
  
#elif defined(MEGATINYCORE)
  
  #define CONTINUOUS_STEPPER_USING_ATTINY             true  
  
/////////////////////////////// DxCore ///////////////////////////////
   
#elif defined(DXCORE)

  #define CONTINUOUS_STEPPER_USING_DX                 true

#else

  #error Unsupported Board! Please check your Tools->Board setting.

#endif

////////////////////////////////////////////////////

#if CONTINUOUS_STEPPER_USING_AVR
  #include <AVR_PWM.h>
#elif CONTINUOUS_STEPPER_USING_ESP8266
  #include <ESP8266_FastPWM.h>
#elif CONTINUOUS_STEPPER_USING_ESP32
  #include <ESP32_FastPWM.h>
#elif CONTINUOUS_STEPPER_USING_NANO33BLE
  #include <nRF52_MBED_PWM.h>
#elif CONTINUOUS_STEPPER_USING_SAMD
  #include <SAMD_PWM.h>
#elif CONTINUOUS_STEPPER_USING_NRF52
  #include <nRF52_PWM.h>
#elif CONTINUOUS_STEPPER_USING_SAMDUE
  #include <SAMDUE_PWM.h>
#elif CONTINUOUS_STEPPER_USING_TEENSY
  #include <Teensy_PWM.h>
#elif CONTINUOUS_STEPPER_USING_PORTENTA_H7
  #include <Portenta_H7_PWM.h>  
#elif CONTINUOUS_STEPPER_USING_STM32
  #include <STM32_PWM.h>
#elif CONTINUOUS_STEPPER_USING_MEGA_AVR
  #include <megaAVR_PWM.h>
#elif CONTINUOUS_STEPPER_USING_RPI_PICO
  #include <RP2040_PWM.h>
#elif CONTINUOUS_STEPPER_USING_MBED_RPI_PICO
  #include <MBED_RP2040_PWM.h>   
#elif CONTINUOUS_STEPPER_USING_DX
  #include <Dx_PWM.h>
#elif CONTINUOUS_STEPPER_USING_ATTINY
  #include <ATtiny_PWM.h>  
#endif

////////////////////////////////////////////////////


#endif    // CONTINUOUS_STEPPER_GENERIC_H

