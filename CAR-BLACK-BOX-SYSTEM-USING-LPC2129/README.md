# Car Black Box System using LPC2129

## Overview
This project implements a standalone Car Black Box system using the LPC2129 (ARM7) microcontroller.  
It monitors vehicle parameters, provides a secure user interface, logs events, and enables post-event analysis.

## Features
- Keypad-driven HMI with screen state machine
- Dashboard, Menu, Login, and Log Access screens
- ADC-based speed simulation
- Switch-based gear detection
- Secure password-protected log access
- EEPROM-based event logging
- UART-based log download
- Real-time alerts via LCD and buzzer

## Hardware Used
- LPC2129 (ARM7)
- 4×4 Keypad
- 16×2 LCD
- Potentiometer (speed simulation)
- Push buttons (gear)
- UART interface

## Software Architecture
- Layered driver design
- Hardware abstraction
- Event-driven UI state machine
- Modular and reusable code

## How to Run
1. Flash the code to LPC2129
2. Power on system
3. Navigate UI using keypad
4. Access logs after password authentication
5. Download logs via UART

## Future Enhancements
- CAN-based multi-node logging
- RTC-based timestamping
- SD card storage
- Crash/accident sensor integration

## Author
Embedded Systems Developer  
(ARM7 / Embedded C / Automotive Systems)
