# Arduino Smart Waste Management System

This Arduino project aims to develop a smart waste management system using ultrasonic sensors and servo motors. The system is designed to detect the level of waste in a bin and categorize it as dry or wet waste. It utilizes an LCD display to provide real-time feedback and alerts when the bin is full or overloaded.

## Features

- Detects the level of waste using ultrasonic sensors.
- Categorizes waste as dry or wet based on user-defined thresholds.
- Utilizes servo motors to open/close the bin lid based on waste level.
- Provides visual and audible alerts when the bin is full or overloaded.
- Displays real-time waste level percentage on an LCD screen.
- Can send SMS alerts using GSM module (not implemented in this code).

## Components Used

- Arduino UNO
- Ultrasonic sensors (HC-SR04)
- Servo motors
- LCD display (16x2)
- Buzzer
- LED indicators
- Resistors
- Jumper wires

## Setup Instructions

- Connect the components as per the circuit diagram provided in the project.
- Upload the Arduino sketch (`smart_waste_management.ino`) to your Arduino board.
- Power up the Arduino board and ensure all connections are secure.
- The LCD will display real-time waste level information and alerts based on the sensor readings.

## Usage

- Ensure the system is powered up and the components are connected correctly.
- The LCD will display the current waste level percentage and any alerts if the bin is full or overloaded.
- Dry waste will trigger the servo to open the bin lid and turn on the red LED and buzzer.
- Wet waste will trigger the servo to open a different compartment of the bin, turn on the yellow LED and buzzer.
- When the waste level exceeds capacity, the system will display an overload message and trigger an alert (SMS alert feature can be added using GSM module).
