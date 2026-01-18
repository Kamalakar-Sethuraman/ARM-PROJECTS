# Bluetooth-Based Smart Home Automation System

## Overview
This project demonstrates a smart home automation system using **LPC2129**, **HC-05 Bluetooth module**, and various sensors. The system provides both **Automatic** and **Manual** modes to control home appliances like lights and fans.

---

## Features

- **Automatic Mode**
  - **LDR-based light control**: Lights turn ON/OFF based on ambient brightness.
  - **Temperature-based fan control**: LM35 sensor triggers fan beyond a defined temperature threshold.
  
- **Manual Mode**
  - **BLE control via mobile app**: Users can override automatic controls to manually turn ON/OFF lights and fan.

- **User Feedback**
  - **16×2 LCD display** shows real-time sensor readings and appliance status.

---

## Hardware Used

| Component          | Purpose                                         |
|-------------------|-------------------------------------------------|
| LPC2129 (ARM7 MCU) | Microcontroller to process sensor data & control |
| HC-05 BLE Module    | Wireless communication via Bluetooth          |
| LDR Sensor         | Ambient light detection                         |
| LM35 Temperature Sensor | Temperature monitoring for fan control     |
| 16×2 LCD           | Real-time display of system status             |
| Relay / LED        | Appliance or indicator control                  |

---

## Software & Communication

- **UART Communication** with HC-05 for Bluetooth control.
- **Embedded C** programming for LPC2129.
- **Modes Handling**:
  - Auto Mode: Sensors automatically control appliances.
  - Manual Mode: Commands received over BLE override auto control.

---

## Implementation Details

1. **Initialize Peripherals**
   - UART for BLE communication
   - ADC for LDR & LM35 sensors
   - GPIO for appliances

2. **Automatic Mode Logic**
   - Read LDR and LM35 values.
   - Compare against predefined thresholds.
   - Control lights and fan accordingly.

3. **Manual Mode Logic**
   - Receive commands over Bluetooth.
   - Turn ON/OFF appliances based on user input.

4. **Display**
   - Update 16×2 LCD with sensor values and appliance status continuously.

---

## How to Use

1. Power the LPC2129 and connect the BLE module.
2. Open the mobile application (BLE-enabled) and pair with HC-05.
3. Select **Auto Mode** to enable automatic control.
4. Select **Manual Mode** to control lights and fan manually.
5. Monitor system status on the 16×2 LCD.

---

## Skills Demonstrated

- Embedded C programming
- Bluetooth communication using UART
- Sensor integration (LDR & LM35)
- LCD interfacing
- Real-time control logic
- Auto/manual mode switching

---

## Potential Enhancements

- Mobile app feedback for sensor readings.
- Cloud logging of appliance status.
- Integration of additional sensors (humidity, motion).
- PWM control for fan speed regulation.

---
