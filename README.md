# Arduino Pedestrian Crossing System

A microcontroller-based pedestrian crossing prototype developed as part of a university group project at Aston University. The system simulates a pedestrian crossing using an OLED display, push button, LED and buzzer.

## Project Overview

The system begins in a STOP state with the LED illuminated. When a pedestrian presses the button, the OLED display presents a countdown before changing to GO. An audible buzzer provides an additional signal, and after the crossing period the system produces a flashing and audible warning before automatically returning to the STOP state.

## Features

- Push-button activated pedestrian crossing sequence
- OLED display showing STOP, WAIT countdown and GO states
- Three-second countdown before the crossing phase
- LED control to represent crossing states
- Buzzer feedback before the GO state
- Flashing LED and buzzer warning before returning to STOP
- Button debouncing to reduce unintended repeated activation
- Automatic return to the default STOP state

## Technologies and Hardware

- Arduino / microcontroller
- C/C++ (Arduino)
- Grove Beginner Kit
- OLED display
- Push button
- LED
- Buzzer
- U8g2 graphics library
- I2C communication

## My Contribution

This was completed as a university group project. My individual contribution included writing the Arduino code for the pedestrian crossing functionality and recording the project demonstration video.

The code I developed controls the interaction between the push button, OLED display, LED and buzzer. I implemented the countdown sequence, STOP and GO display states, timed crossing period, audible feedback, warning sequence and return to the default STOP state.

## Skills Demonstrated

- Embedded programming using Arduino C/C++
- Microcontroller input and output control
- Integration of hardware components with software
- OLED display programming using the U8g2 library
- Implementing timed and event-driven program logic
- Breaking functionality into reusable functions
- Testing hardware and software behaviour
- Teamwork on a technical university project
- Communicating technical work through a recorded demonstration

## Source Code

The Arduino implementation is available in pedestrian_crossing.ino.

## Academic Context

Developed as part of my BSc Cybersecurity studies at Aston University.
