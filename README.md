# Fire Fighting Robot Car

[![Arduino](https://img.shields.io/badge/Platform-Arduino-blue)](https://www.arduino.cc/)
[![License](https://img.shields.io/badge/License-MIT-green)](LICENSE)

An autonomous fire-fighting robot built with Arduino Uno. The robot uses three IR flame sensors to detect fire from front, left, and right directions, navigates toward the flame using a 4WD chassis with differential steering, and extinguishes small flames (e.g., candles) by spraying water from an onboard submersible pump. A servo motor directs the nozzle for targeted spraying.


## Features
- Omnidirectional flame detection with three KY-026 IR flame sensors
- 4WD differential steering for quick turns toward fire
- Servo-controlled nozzle for precise water spray direction
- Submersible water pump for effective extinguishing
- 4-channel relay module for safe control of the pump
- Fully autonomous operation (patrols forward, detects, approaches, and extinguishes)

## Components Used
| Component                     | Purpose                                   |
|-------------------------------|-------------------------------------------|
| Arduino Uno                   | Main controller                           |
| L298N Motor Driver            | Drives four DC geared motors              |
| TowerPro SG90 Servo           | Directs the water nozzle                  |
| 3–6V Mini Submersible Pump    | Sprays water from reservoir               |
| 5V 4-Channel Relay Module     | Safely switches the pump                  |
| 3× Flame Sensors (KY-026)     | Detects flames in IR range                |
| 4WD Robot Chassis             | Mobility platform                         |
| Silicone Tubing               | Water delivery pipe                       |
| Breadboard & Jumper Wires     | Prototyping connections                   |
| Power Supply (batteries/power bank) | Powers the system                    |



## How It Works
1. The robot continuously moves forward in patrol mode.
2. Three flame sensors monitor for fire:
   - **Front detection**: Stops, centers nozzle, activates pump and sweeps servo for wide spray coverage.
   - **Left/Right detection**: Turns toward the flame, stops, then activates pump with servo sweep.
3. Water is pumped from an onboard reservoir through silicone tubing to the servo-mounted nozzle.
4. Relay ensures safe switching of the pump (active LOW trigger).

## Code
The complete Arduino sketches are included in this repository:

- `FireFightingRobot.ino` – Main code handling flame detection, motor control, servo movement, and pump activation.
- `MotorTest.ino` – Simple test code for verifying motor directions and basic movement.

Upload using the Arduino IDE. Requires the standard `Servo.h` library (included by default).

## Challenges Faced
- Weight imbalance from heavy power bank → solved by switching to lighter batteries.
- False flame detections from ambient light → fixed by adjusting sensor potentiometers and adding confirmation logic.
- Breadboard connection noise causing servo jitter → improved with shorter wires and partial soldering.

## Future Improvements
- Add buzzer/siren on spare relay channel
- Integrate ESP8266 for Wi-Fi fire alerts
- Add ultrasonic sensors for obstacle avoidance
- MQ-2 smoke sensor for earlier detection
- Larger water reservoir or optional fan extinguisher

## License
MIT License – feel free to fork, modify, and build your own!

---
Arduino robotics project. For questions or contributions, open an issue.
