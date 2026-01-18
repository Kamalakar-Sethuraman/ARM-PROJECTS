# CAN-Based Battery Management and Body Control System  
*(LPC2129 – ARM7)*

## Overview
This project implements a **unified CAN-based automotive system** on the LPC2129 (ARM7) microcontroller, integrating a **Battery Management System (BMS)** and a **Body Control Module (BCM)**.  
The objective is to reduce wiring complexity, improve scalability, and demonstrate reliable inter-ECU communication using the CAN protocol.

The system simulates multiple vehicle subsystems as independent CAN nodes communicating over a shared CAN bus.

---

## System Architecture
- **Microcontroller:** NXP LPC2129 (ARM7TDMI-S)
- **Communication Protocol:** CAN (Controller Area Network)
- **Programming Language:** Embedded C (register-level)
- **Display & Alerts:** LCD, Buzzer
- **Sensors & Actuators:** LM35 temperature sensor, LEDs (indicators), DC motor (wiper simulation)

---

## Functional Modules

### 1. Battery Management System (BMS)
Implemented as **4 independent CAN nodes**:
- Continuous battery temperature monitoring using **LM35**
- Threshold-based fault detection
- Automated cooling control logic
- Fault and status alerts via **LCD and buzzer**
- Periodic transmission of sensor data over CAN

---

### 2. Body Control Module (BCM)
Implemented as **2 CAN nodes**:
- Left and right indicator control
- Wiper control logic
- Receives commands and status frames via CAN
- Actuator response based on received CAN messages

---

## CAN Communication Design
- Unique **CAN Message IDs** assigned for each ECU and function
- **Acceptance Filter (AFMR)** configured to:
  - Accept only relevant message IDs
  - Reject unwanted or unrelated CAN frames
- Ensures reliable, collision-free inter-node communication

---

## Key Technical Highlights
- Register-level **CAN driver development** on LPC2129
- Multi-node CAN simulation on embedded hardware
- Modular ECU-based software design
- Real-time sensor acquisition and actuator control
- Automotive-style message filtering and ID management

---

## Project Objectives
- Demonstrate practical CAN protocol implementation
- Understand multi-ECU automotive architecture
- Reduce wiring complexity through networked communication
- Build industry-relevant embedded firmware skills

---

---

## Skills Demonstrated
- CAN Protocol
- ARM7 (LPC2129) Microcontroller
- Embedded C (Bare-metal)
- Register-level driver development
- Automotive ECU communication
- Real-time embedded system design

---

## Disclaimer
This project is **educational and non-commercial**, developed to demonstrate embedded automotive concepts.  
It is **not derived from proprietary company code**.

---

## Future Enhancements
- Event logging using EEPROM
- CAN error handling and bus-off recovery
- Integration with a Car Black Box system
- Migration to ARM Cortex-M (STM32)


