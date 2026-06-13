# Custom-AI-Drone

A custom drone project built completely from scratch, starting from low-level embedded programming and progressing toward a full AI-assisted autonomous drone platform.

---

## Project Vision

The goal of this project is to design and develop every major component of a drone system independently, including:

- Custom Flight Controller using STM32
- Custom RF Transmitter
- Custom RF Receiver
- Sensor Integration
- Flight Stabilization Algorithms
- Raspberry Pi Companion Computer
- Computer Vision
- AI Assisted Navigation
- Autonomous Flight Features

---

## Development Roadmap

### Phase 1 - STM32 Fundamentals

Learning embedded systems and microcontroller programming using the STM32F407 Discovery Board.

#### Register Level Programming
- [ ] GPIO Output
- [ ] LED Blink
- [ ] Button Input
- [ ] UART
- [ ] Timer
- [ ] PWM
- [ ] ADC
- [ ] SPI
- [ ] I2C
- [ ] Interrupts

#### CMSIS
- [ ] GPIO
- [ ] UART
- [ ] PWM
- [ ] Timers

#### HAL Drivers
- [ ] GPIO
- [ ] UART
- [ ] PWM
- [ ] Sensors

---

### Phase 2 - Flight Controller Development

- [ ] IMU Interface
- [ ] Sensor Fusion
- [ ] PID Controller
- [ ] ESC Interface
- [ ] Motor Mixing
- [ ] Flight Stabilization

---

### Phase 3 - RF Communication

- [ ] Custom Transmitter
- [ ] Custom Receiver
- [ ] Telemetry Link

---

### Phase 4 - Companion Computer

- [ ] Raspberry Pi Integration
- [ ] Camera Interface
- [ ] Video Streaming

---

### Phase 5 - Artificial Intelligence

- [ ] Object Detection
- [ ] Object Tracking
- [ ] Autonomous Navigation
- [ ] AI Assisted Flight

---

## Repository Structure

```text
Custom-AI-Drone/
│
├── docs/
│
├── firmware/
│   └── stm32/
│       ├── register_level/
│       ├── cmsis/
│       └── hal/
│
├── hardware/
│
└── README.md
```

---

## Hardware

Current Development Board:

- STM32F407G-DISC1 Discovery Board

Future Hardware:

- Custom STM32 Flight Controller
- RF Communication Module
- IMU Sensors
- ESCs
- Brushless Motors
- Raspberry Pi Companion Computer

---

## Learning Philosophy

The project starts from direct register programming to understand the hardware at a low level before moving to CMSIS, HAL drivers, and advanced drone software development.

---

## Current Status

Phase 1: STM32 Fundamentals

Current Task:
- Register Level GPIO Programming
- LED Blink
- Button Interface

---

## Author

Sandesh Aryal

Learning • Building • Iterating • Flying