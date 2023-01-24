# ContinuousStepper_Generic Library

[![arduino-library-badge](https://www.ardu-badge.com/badge/ContinuousStepper_Generic.svg?)](https://www.ardu-badge.com/ContinuousStepper_Generic)
[![GitHub release](https://img.shields.io/github/release/khoih-prog/ContinuousStepper_Generic.svg)](https://github.com/khoih-prog/ContinuousStepper_Generic/releases)
[![GitHub](https://img.shields.io/github/license/mashape/apistatus.svg)](https://github.com/khoih-prog/ContinuousStepper_Generic/blob/main/LICENSE)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](#Contributing)
[![GitHub issues](https://img.shields.io/github/issues/khoih-prog/ContinuousStepper_Generic.svg)](http://github.com/khoih-prog/ContinuousStepper_Generic/issues)



<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://cdn.buymeacoffee.com/buttons/v2/default-yellow.png" alt="Donate to my libraries using BuyMeACoffee" style="height: 50px !important;width: 181px !important;" ></a>
<a href="https://www.buymeacoffee.com/khoihprog6" title="Donate to my libraries using BuyMeACoffee"><img src="https://img.shields.io/badge/buy%20me%20a%20coffee-donate-orange.svg?logo=buy-me-a-coffee&logoColor=FFDD00" style="height: 20px !important;width: 200px !important;" ></a>


---
---

## Table of Contents

* [Why do we need this ContinuousStepper_Generic library](#why-do-we-need-this-ContinuousStepper_Generic-library)
  * [Features](#features)
  * [Why using hardware-based PWM is better](#why-using-hardware-based-pwm-is-better)
  * [Currently supported Boards](#currently-supported-boards)
* [Changelog](changelog.md)
* [Prerequisites](#prerequisites)
* [Installation](#installation)
  * [Use Arduino Library Manager](#use-arduino-library-manager)
  * [Manual Install](#manual-install)
  * [VS Code & PlatformIO](#vs-code--platformio)
* [More useful Information about RP2040 PWM](#more-useful-information-about-RP2040-PWM)
  * [PWM overview](#PWM-overview)
  * [Programmer’s Model](#Programmers-Model)
* [Usage](#usage)
  * [1. Create PWM Instance with Pin, Frequency and dutycycle](#1-Create-PWM-Instance-with-Pin-Frequency-and-dutycycle)
  * [2. Initialize PWM Instance](#2-Initialize-PWM-Instance)
  * [3. Set or change PWM frequency or dutyCycle](#3-set-or-change-PWM-frequency-or-dutyCycle)
  * [4. Set or change PWM frequency and dutyCycle manually and efficiently in waveform creation](#4-Set-or-change-PWM-frequency-and-dutyCycle-manually-and-efficiently-in-waveform-creation)
  * [5. Important Notes](#5-Important-Notes)
* [Examples](#examples)
  * [  1. ATtiny_PWM_StepperControl](examples/ATtiny_PWM_StepperControl)
  * [  2. AVR_PWM_StepperControl](examples/AVR_PWM_StepperControl)
  * [  3. Dx_PWM_StepperControl](examples/Dx_PWM_StepperControl)
  * [  4. ESP32_PWM_StepperControl](examples/ESP32_PWM_StepperControl)
  * [  5. MBED_RP2040_PWM_StepperControl](examples/MBED_RP2040_PWM_StepperControl)
  * [  6. megaAVR_PWM_StepperControl](examples/megaAVR_PWM_StepperControl)
  * [  7. nRF52_MBED_PWM_StepperControl](examples/nRF52_MBED_PWM_StepperControl)
  * [  8. nRF52_PWM_StepperControl](examples/nRF52_PWM_StepperControl)
  * [  9. Portenta_H7_PWM_StepperControl](examples/Portenta_H7_PWM_StepperControl)
  * [ 10. RP2040_PWM_StepperControl](examples/RP2040_PWM_StepperControl)
  * [ 11. SAMD_PWM_StepperControl](examples/SAMD_PWM_StepperControl)
  * [ 12. SAMDUE_PWM_StepperControl](examples/SAMDUE_PWM_StepperControl)
  * [ 13. STM32_PWM_StepperControl](examples/STM32_PWM_StepperControl)
  * [ 14. Teensy_PWM_StepperControl](examples/Teensy_PWM_StepperControl)
* [Example RP2040_PWM_StepperControl](#example-RP2040_PWM_StepperControl)
* [Debug Terminal Output Samples](#debug-terminal-output-samples)
  * [1. PWM_Multi on MBED RaspberryPi Pico](#1-PWM_Multi-on-MBED-RaspberryPi-Pico)
  * [2. PWM_Multi on RASPBERRY_PI_PICO](#2-PWM_Multi-on-RASPBERRY_PI_PICO)
  * [3. PWM_DynamicFreq on Nano RP2040 Connect](#3-PWM_DynamicFreq-on-Nano-RP2040-Connect)
  * [4. PWM_DynamicDutyCycle on RASPBERRY_PI_PICO](#4-PWM_DynamicDutyCycle-on-RASPBERRY_PI_PICO)
  * [5. PWM_MultiChannel on RASPBERRY_PI_PICO](#5-PWM_MultiChannel-on-RASPBERRY_PI_PICO)
  * [6. PWM_Waveform on RASPBERRY_PI_PICO](#6-PWM_Waveform-on-RASPBERRY_PI_PICO)
  * [7. PWM_Waveform_Fast on RASPBERRY_PI_PICO](#7-PWM_Waveform_Fast-on-RASPBERRY_PI_PICO)
* [Debug](#debug)
* [Troubleshooting](#troubleshooting)
* [Issues](#issues)
* [TO DO](#to-do)
* [DONE](#done)
* [Contributions and Thanks](#contributions-and-thanks)
* [Contributing](#contributing)
* [License](#license)
* [Copyright](#copyright)

---
---

### Why do we need this [ContinuousStepper_Generic library](https://github.com/khoih-prog/ContinuousStepper_Generic)

### Features

This PWM-wrapper library enables you to use Hardware-PWM use PWM to control continuous Stepper Motor.

This library is the wrapper of the following FastPWM libraries to enable you to **port your PWM code easily between platforms**

 1. [**RP2040_PWM**](https://github.com/khoih-prog/RP2040_PWM)
 2. [**AVR_PWM**](https://github.com/khoih-prog/AVR_PWM)
 3. [**megaAVR_PWM**](https://github.com/khoih-prog/megaAVR_PWM)
 4. [**ESP32_FastPWM**](https://github.com/khoih-prog/ESP32_FastPWM)
 5. [**SAMD_PWM**](https://github.com/khoih-prog/SAMD_PWM)
 6. [**SAMDUE_PWM**](https://github.com/khoih-prog/SAMDUE_PWM)
 7. [**nRF52_PWM**](https://github.com/khoih-prog/nRF52_PWM)
 8. [**Teensy_PWM**](https://github.com/khoih-prog/Teensy_PWM)
 9. [**ATtiny_PWM**](https://github.com/khoih-prog/ATtiny_PWM)
10. [**Dx_PWM**](https://github.com/khoih-prog/Dx_PWM)
11. [**Portenta_H7_PWM**](https://github.com/khoih-prog/Portenta_H7_PWM)
12. [**MBED_ContinuousStepper_Generic**](https://github.com/khoih-prog/MBED_ContinuousStepper_Generic)
13. [**nRF52_MBED_PWM**](https://github.com/khoih-prog/nRF52_MBED_PWM)
14. [**STM32_PWM**](https://github.com/khoih-prog/STM32_PWM)

---

The most important feature is they're purely hardware-based PWM channels. Therefore, their operations are **not blocked by bad-behaving software functions / tasks**.

This important feature is absolutely necessary for mission-critical tasks. These hardware PWM-channels, still work even if other software functions are blocking. Moreover, they are much more precise (certainly depending on clock frequency accuracy) than other software timers using `millis()` or `micros()`. That's necessary if you need to control external systems (Servo, etc.) requiring better accuracy.

Being hardware-based PWM, their executions are not blocked by bad-behaving functions / tasks, such as connecting to WiFi, Internet or Blynk services. You can also have many `(up to 16)` PWM output signals to use.

This non-being-blocked important feature is absolutely necessary for mission-critical tasks.

---

#### Why using hardware-based PWM is better

Imagine you have a system with a **mission-critical** function, controlling a robot or doing something much more important. You normally use a software timer to poll, or even place the function in loop(). But what if another function is **blocking** the loop() or setup().

So your function **might not be executed, and the result would be disastrous.**

You'd prefer to have your function called, no matter what happening with other functions (busy loop, bug, etc.).

The correct choice is to use a Hardware Timer with **Interrupt** to call your function.

These hardware-based PWM channels still work even if other software functions are blocking. Moreover, they are much more **precise** (certainly depending on clock frequency accuracy) than other software-based PWMs, using millis() or micros(). That's necessary if you need to measure some data requiring better accuracy.

Functions using normal software-based PWMs, relying on loop() and calling millis(), won't work if the loop() or setup() is blocked by certain operation. For example, certain function is blocking while it's connecting to WiFi or some services.


---

### Currently supported Boards

This [**ContinuousStepper_Generic** library](https://github.com/khoih-prog/ContinuousStepper_Generic) currently supports these following boards:

 1. **nRF52 boards**, such as **AdaFruit Feather nRF52832, nRF52840 Express, BlueFruit Sense, Itsy-Bitsy nRF52840 Express, Metro nRF52840 Express, NINA_B302_ublox, NINA_B112_ublox, etc.**
 2. **SAM DUE**
 3. **SAMD21**
  - Arduino SAMD21: ZERO, MKRs, NANO_33_IOT, etc.
  - Adafruit SAMD21 (M0): ItsyBitsy M0, Feather M0, Feather M0 Express, Metro M0 Express, Circuit Playground Express, Trinket M0, PIRkey, Hallowing M0, Crickit M0, etc.
  - Seeeduino:  LoRaWAN, Zero, Femto M0, XIAO M0, Wio GPS Board, etc.
  
 4. **SAMD51**
  - Adafruit SAMD51 (M4): Metro M4, Grand Central M4, ItsyBitsy M4, Feather M4 Express, Trellis M4, Metro M4 AirLift Lite, MONSTER M4SK Express, Hallowing M4, etc.
  - Seeeduino: Wio Terminal, Grove UI Wireless
  
 5. **Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0, LC) with SPI, SPI1, SPI2**
 6. **AVR Mega1280, 2560, ADK.**
 7. ESP32
 8. ESP8266 **To be addded**
 
 9. RP2040-based boards, such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, using [**Arduino-mbed RP2040** core](https://github.com/arduino/ArduinoCore-mbed) or [**Earle Philhower's arduino-pico** core](https://github.com/earlephilhower/arduino-pico) with **SPI, SPI1**
 
 10. **Portenta_H7**
 
 11. **Arduino UNO WiFi Rev2, AVR_NANO_EVERY, etc.**
 
 12. **Arduino AVR_Dx boards using DxCore**

- **AVRDA-based boards (AVR128DA, AVR64DA, AVR32DA, etc.)**

- **AVRDB-based boards (AVR128DB, AVR64DB, AVR32DB, etc.)**

 13. **Seeeduino nRF52840-based boards such as XIAO_NRF52840 and XIAO_NRF52840_SENSE**, etc. using Seeed `mbed` or `nRF52` core


---
---

## Prerequisites

 1. [`Arduino IDE 1.8.19+` for Arduino](https://github.com/arduino/Arduino). [![GitHub release](https://img.shields.io/github/release/arduino/Arduino.svg)](https://github.com/arduino/Arduino/releases/latest)
 2. [`Arduino AVR core 1.8.6+`](https://github.com/arduino/ArduinoCore-avr) for Arduino (Use Arduino Board Manager) AVR boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-avr.svg)](https://github.com/arduino/ArduinoCore-avr/releases/latest)
 3. [`Teensy core v1.57+`](https://www.pjrc.com/teensy/td_download.html) for Teensy (4.1, 4.0, 3.6, 3.5, 3,2, 3.1, 3.0) boards. [![GitHub release](https://img.shields.io/github/release/PaulStoffregen/cores.svg)](https://github.com/PaulStoffregen/cores/releases/latest)
 4. [`Arduino SAM DUE core v1.6.12+`](https://github.com/arduino/ArduinoCore-sam) for SAM DUE ARM Cortex-M3 boards.
 5. [`Arduino SAMD core 1.8.13+`](https://github.com/arduino/ArduinoCore-samd) for SAMD ARM Cortex-M0+ boards. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-samd.svg)](https://github.com/arduino/ArduinoCore-samd/releases/latest)
 6. [`Adafruit SAMD core 1.7.11+`](https://github.com/adafruit/ArduinoCore-samd) for SAMD ARM Cortex-M0+ and M4 boards (Nano 33 IoT, etc.). [![GitHub release](https://img.shields.io/github/release/adafruit/ArduinoCore-samd.svg)](https://github.com/adafruit/ArduinoCore-samd/releases/latest)
 7. [`Seeeduino SAMD core 1.8.3+`](https://github.com/Seeed-Studio/ArduinoCore-samd) for SAMD21/SAMD51 boards (XIAO M0, Wio Terminal, etc.). [![Latest release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-samd.svg)](https://github.com/Seeed-Studio/ArduinoCore-samd/releases/latest/)
 8. [`Adafruit nRF52 v1.3.0+`](https://github.com/adafruit/Adafruit_nRF52_Arduino) for nRF52 boards such as Adafruit NRF52840_FEATHER, NRF52832_FEATHER, NRF52840_FEATHER_SENSE, NRF52840_ITSYBITSY, NRF52840_CIRCUITPLAY, NRF52840_CLUE, NRF52840_METRO, NRF52840_PCA10056, PARTICLE_XENON, **NINA_B302_ublox**, etc. [![GitHub release](https://img.shields.io/github/release/adafruit/Adafruit_nRF52_Arduino.svg)](https://github.com/adafruit/Adafruit_nRF52_Arduino/releases/latest)
 9. [`ESP32 Core 2.0.6+`](https://github.com/espressif/arduino-esp32) for ESP32-based boards. [![Latest release](https://img.shields.io/github/release/espressif/arduino-esp32.svg)](https://github.com/espressif/arduino-esp32/releases/latest/)
10. [`ESP8266 Core 3.1.1+`](https://github.com/esp8266/Arduino) for ESP8266-based boards. [![Latest release](https://img.shields.io/github/release/esp8266/Arduino.svg)](https://github.com/esp8266/Arduino/releases/latest/). To use ESP8266 core 2.7.1+ for LittleFS.
11. [`ArduinoCore-mbed mbed_rp2040, mbed_nano, mbed_portenta core 3.5.4+`](https://github.com/arduino/ArduinoCore-mbed) for Arduino (Use Arduino Board Manager) **Portenta_H7, RP2040-based boards, such as Nano_RP2040_Connect, RASPBERRY_PI_PICO**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-mbed.svg)](https://github.com/arduino/ArduinoCore-mbed/releases/latest)
12. [`Earle Philhower's arduino-pico core v2.7.1+`](https://github.com/earlephilhower/arduino-pico) for RP2040-based boards such as **RASPBERRY_PI_PICO, ADAFRUIT_FEATHER_RP2040 and GENERIC_RP2040**, etc. [![GitHub release](https://img.shields.io/github/release/earlephilhower/arduino-pico.svg)](https://github.com/earlephilhower/arduino-pico/releases/latest)
13. [`Arduino megaAVR core 1.8.7+`](https://github.com/arduino/ArduinoCore-megaavr/releases) for Arduino megaAVR boards such as **Arduino UNO WiFi Rev2, AVR_NANO_EVERY, etc.**. [![GitHub release](https://img.shields.io/github/release/arduino/ArduinoCore-megaavr.svg)](https://github.com/arduino/ArduinoCore-megaavr/releases/latest)
14. [`SpenceKonde DxCore core 1.5.3+`](https://github.com/SpenceKonde/DxCore) for Arduino AVRDx boards.  [![GitHub release](https://img.shields.io/github/release/SpenceKonde/DxCore.svg)](https://github.com/SpenceKonde/DxCore/releases/latest). Follow [**DxCore Installation**](https://github.com/SpenceKonde/DxCore/blob/master/Installation.md).
15. [`Seeeduino nRF52 core 1.1.0+`](https://github.com/Seeed-Studio/Adafruit_nRF52_Arduino) for Seeed nRF52840-based boards such as **Seeed_XIAO_NRF52840 and Seeed_XIAO_NRF52840_SENSE**. [![GitHub release](https://img.shields.io/github/release/Seeed-Studio/Adafruit_nRF52_Arduino.svg)](https://github.com/Seeed-Studio/Adafruit_nRF52_Arduino/releases/latest)
16. [`Seeeduino mbed core 2.9.0+`](https://github.com/Seeed-Studio/ArduinoCore-mbed) for Seeed nRF52840-based boards such as **SEEED_XIAO_NRF52840 and SEEED_XIAO_NRF52840_SENSE**. [![GitHub release](https://img.shields.io/github/release/Seeed-Studio/ArduinoCore-mbed.svg)](https://github.com/Seeed-Studio/ArduinoCore-mbed/releases/latest)

---

17. [`RP2040_PWM library v1.4.1+`](https://github.com/khoih-prog/RP2040_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/RP2040_PWM.svg?)](https://www.ardu-badge.com/RP2040_PWM)
18. [`AVR_PWM library v1.0.1+`](https://github.com/khoih-prog/AVR_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/AVR_PWM.svg?)](https://www.ardu-badge.com/AVR_PWM)
19. [`megaAVR_PWM library v1.0.1+`](https://github.com/khoih-prog/megaAVR_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/megaAVR_PWM.svg?)](https://www.ardu-badge.com/megaAVR_PWM)
20. [`ESP32_FastPWM library v1.0.1+`](https://github.com/khoih-prog/ESP32_FastPWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/ESP32_FastPWM.svg?)](https://www.ardu-badge.com/ESP32_FastPWM)
21. [`SAMD_PWM library v1.0.1+`](https://github.com/khoih-prog/SAMD_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/SAMD_PWM.svg?)](https://www.ardu-badge.com/SAMD_PWM)
22. [`SAMDUE_PWM library v1.0.1+`](https://github.com/khoih-prog/SAMDUE_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/SAMDUE_PWM.svg?)](https://www.ardu-badge.com/SAMDUE_PWM)
23. [`nRF52_PWM library v1.0.1+`](https://github.com/khoih-prog/nRF52_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/nRF52_PWM.svg?)](https://www.ardu-badge.com/nRF52_PWM)
24. [`Teensy_PWM library v1.0.1+`](https://github.com/khoih-prog/Teensy_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Teensy_PWM.svg?)](https://www.ardu-badge.com/Teensy_PWM)
25. [`ATtiny_PWM library v1.0.1+`](https://github.com/khoih-prog/ATtiny_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/ATtiny_PWM.svg?)](https://www.ardu-badge.com/ATtiny_PWM)
26. [`Dx_PWM library v1.0.1+`](https://github.com/khoih-prog/Dx_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Dx_PWM.svg?)](https://www.ardu-badge.com/Dx_PWM)
27. [`Portenta_H7_PWM library v2.0.3+`](https://github.com/khoih-prog/Portenta_H7_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/Portenta_H7_PWM.svg?)](https://www.ardu-badge.com/Portenta_H7_PWM)
28. [`MBED_RP2040_PWM library v1.0.1+`](https://github.com/khoih-prog/MBED_RP2040_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/MBED_RP2040_PWM.svg?)](https://www.ardu-badge.com/MBED_RP2040_PWM)
29. [`nRF52_MBED_PWM library v1.0.3+`](https://github.com/khoih-prog/nRF52_MBED_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/nRF52_MBED_PWM.svg?)](https://www.ardu-badge.com/nRF52_MBED_PWM)
30. [`STM32_PWM library v1.0.1+`](https://github.com/khoih-prog/STM32_PWM). To install. check [![arduino-library-badge](https://www.ardu-badge.com/badge/STM32_PWM.svg?)](https://www.ardu-badge.com/STM32_PWM)
 
---
---

## Installation

### Use Arduino Library Manager

The best and easiest way is to use `Arduino Library Manager`. Search for [**ContinuousStepper_Generic**](https://github.com/khoih-prog/ContinuousStepper_Generic), then select / install the latest version.
You can also use this link [![arduino-library-badge](https://www.ardu-badge.com/badge/ContinuousStepper_Generic.svg?)](https://www.ardu-badge.com/ContinuousStepper_Generic) for more detailed instructions.

### Manual Install

Another way to install is to:

1. Navigate to [**ContinuousStepper_Generic**](https://github.com/khoih-prog/ContinuousStepper_Generic) page.
2. Download the latest release `ContinuousStepper_Generic-main.zip`.
3. Extract the zip file to `ContinuousStepper_Generic-main` directory 
4. Copy whole `ContinuousStepper_Generic-main` folder to Arduino libraries' directory such as `~/Arduino/libraries/`.

### VS Code & PlatformIO

1. Install [VS Code](https://code.visualstudio.com/)
2. Install [PlatformIO](https://platformio.org/platformio-ide)
3. Install [**ContinuousStepper_Generic** library](https://registry.platformio.org/libraries/khoih-prog/ContinuousStepper_Generic) by using [Library Manager](https://registry.platformio.org/libraries/khoih-prog/ContinuousStepper_Generic/installation). Search for **ContinuousStepper_Generic** in [Platform.io Author's Libraries](https://platformio.org/lib/search?query=author:%22Khoi%20Hoang%22)
4. Use included [platformio.ini](platformio/platformio.ini) file from examples to ensure that all dependent libraries will installed automatically. Please visit documentation for the other options and examples at [Project Configuration File](https://docs.platformio.org/page/projectconf.html)

---
---

### Examples: 

 1. [ATtiny_PWM_StepperControl](examples/ATtiny_PWM_StepperControl)
 2. [AVR_PWM_StepperControl](examples/AVR_PWM_StepperControl)
 3. [Dx_PWM_StepperControl](examples/Dx_PWM_StepperControl)
 4. [ESP32_PWM_StepperControl](examples/ESP32_PWM_StepperControl)
 5. [MBED_RP2040_PWM_StepperControl](examples/MBED_RP2040_PWM_StepperControl)
 6. [megaAVR_PWM_StepperControl](examples/megaAVR_PWM_StepperControl)
 7. [nRF52_MBED_PWM_StepperControl](examples/nRF52_MBED_PWM_StepperControl)
 8. [nRF52_PWM_StepperControl](examples/nRF52_PWM_StepperControl)
 9. [Portenta_H7_PWM_StepperControl](examples/Portenta_H7_PWM_StepperControl)
10. [RP2040_PWM_StepperControl](examples/RP2040_PWM_StepperControl)
11. [SAMD_PWM_StepperControl](examples/SAMD_PWM_StepperControl)
12. [SAMDUE_PWM_StepperControl](examples/SAMDUE_PWM_StepperControl)
13. [STM32_PWM_StepperControl](examples/STM32_PWM_StepperControl)
14. [Teensy_PWM_StepperControl](examples/Teensy_PWM_StepperControl)
 
 
---
---

### Example [RP2040_PWM_StepperControl](examples/RP2040_PWM_StepperControl)

https://github.com/khoih-prog/ContinuousStepper_Generic/blob/dd0c59c125f14188bb811c5509fd197e99b0ac0c/examples/RP2040_PWM_StepperControl/RP2040_PWM_StepperControl.ino#L16-L92


---
---

### Debug

Debug is enabled by default on Serial.

You can also change the debugging level `_PWM_LOGLEVEL_` from 0 to 4

```cpp
// Don't define _PWM_LOGLEVEL_ > 0. Only for special ISR debugging only. Can hang the system.
#define _PWM_LOGLEVEL_     0
```

---

### Troubleshooting

If you get compilation errors, more often than not, you may need to install a newer version of the core for Arduino boards.

Sometimes, the library will only work if you update the board core to the latest version because I am using newly added functions.


---
---

### Issues

Submit issues to: [ContinuousStepper_Generic issues](https://github.com/khoih-prog/ContinuousStepper_Generic/issues)

---

## TO DO

1. Search for bug and improvement
2. Similar features for remaining or new Arduino boards

---

## DONE

 1. Initial coding to use PWM to control continuous Stepper Motor. Check [Using PWM to step a stepper driver #16](https://github.com/khoih-prog/ContinuousStepper_Generic/issues/16)
 2. Use `allman astyle` and add `utils`

---
---

### Contributions and Thanks

Many thanks for everyone for bug reporting, new feature suggesting, testing and contributing to the development of this library.

1. Thanks to [Paul van Dinther](https://github.com/dinther) for proposing new way to use PWM to drive Stepper-Motor in [Using PWM to step a stepper driver #16](https://github.com/khoih-prog/RP2040_PWM/issues/16), leading to this library


<table>
  <tr>
    <td align="center"><a href="https://github.com/dinther"><img src="https://github.com/dinther.png" width="100px;" alt="dinther"/><br /><sub><b>Paul van Dinther</b></sub></a><br /></td>
  </tr>
</table>
  
---

## Contributing

If you want to contribute to this project:
- Report bugs and errors
- Ask for enhancements
- Create issues and pull requests
- Tell other people about this library

---

### License

- The library is licensed under [MIT](https://github.com/khoih-prog/ContinuousStepper_Generic/blob/main/LICENSE)

---

## Copyright

Copyright 2023- Khoi Hoang


