# ARM Projects

This repository contains multiple ARM-based embedded system projects developed for real-time applications, hardware interfacing, and IoT automation. Each project is organized in its own directory to maintain modularity, readability, and scalability.

---

## Projects

### 1. CAR-BLACK-BOX-SYSTEM-USING-LPC2129
A vehicle black box system implemented on the LPC2129 microcontroller that records vehicle parameters in real-time.

**Features:**
- Keypad-driven screen state machine with Dashboard, Menu, Login, and Log Access screens.
- Real-time simulation of vehicle parameters such as speed and gear.
- Secure login with masked password entry.
- UART-based log download for data retrieval.

**Technologies:** LPC2129 MCU, Embedded C, UART, ADC, LCD, Keypad.

---

### 2. CAN-BASED-BATTERY-MANAGEMENT-AND-BODY-CONTROL-SYSTEM
A CAN network-based embedded system that integrates battery management and body control functions for vehicles.

**Features:**
- Unified CAN network combining multiple ECUs for battery and body control.
- Temperature sensing and cooling system control using LM35 sensors.
- Left/right indicators and buzzer alerts controlled via a 2-node BCM.
- Modular and scalable architecture for multi-ECU communication.

**Technologies:** LPC2129 MCU, Embedded C, CAN Protocol, DC Motors, LCD, Buzzer, Sensors.

---

### 3. BLUETOOTH-BASED-SMART-HOME-AUTOMATION-SYSTEM
An IoT-based home automation system controlled via Bluetooth communication.

**Features:**
- Control of home appliances (lights, fans, etc.) using a mobile app.
- Real-time monitoring and feedback via UART.
- Modular design for easy expansion to additional devices.

**Technologies:** LPC2129 MCU, Embedded C, Bluetooth Module, UART, Relays, Sensors.

---


