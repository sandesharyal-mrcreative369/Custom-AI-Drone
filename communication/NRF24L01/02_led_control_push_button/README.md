# ESP32 nRF24L01 LED Control

A simple wireless communication project using ESP32 and nRF24L01 modules.

The transmitter reads the state of a push button and sends the data wirelessly to another ESP32 through the nRF24L01 module. The receiver reads the incoming packet and controls an LED based on the received value.

## Features

* Wireless communication using nRF24L01
* ESP32 based transmitter and receiver
* Real-time button state transmission
* LED control over RF communication
* Beginner-friendly project for learning NRF24L01

## Components Required

### Transmitter

* ESP32
* nRF24L01 Module
* Push Button
* Jumper Wires

### Receiver

* ESP32
* nRF24L01 Module
* LED
* 220Ω Resistor
* Jumper Wires

## Wiring

### nRF24L01 ↔ ESP32

| nRF24L01 | ESP32  |
| -------- | ------ |
| VCC      | 3.3V   |
| GND      | GND    |
| CE       | GPIO4  |
| CSN      | GPIO5  |
| SCK      | GPIO18 |
| MOSI     | GPIO23 |
| MISO     | GPIO19 |

### Transmitter

| Component   | ESP32 Pin |
| ----------- | --------- |
| Push Button | GPIO32    |

### Receiver

| Component | ESP32 Pin |
| --------- | --------- |
| LED       | GPIO12    |

## Folder Structure

```text
NRF24L01/
│
├── README.md
│
├── 02_led_control_push_button/
│      ├── push-button_transmitter/
│      │       └── transmitter.ino
│      └── led_receiver/
│      |       └── receiver.ino
|      |
|      ├── README.md
```

## How It Works

1. The transmitter reads the button state from GPIO32.
2. The button state is sent through the nRF24L01 module.
3. The receiver listens for incoming packets.
4. When data is received, the LED state is updated.
5. Pressing the button changes the LED state wirelessly.

## Libraries Used

* SPI.h
* nRF24L01.h
* RF24.h

## Future Improvements

* Bidirectional communication
* Sensor data transmission
* Multiple receiver nodes
* Acknowledgement packets
* Home automation applications

## Author

Sandesh Aryal
Built for learning wireless communication using ESP32 and nRF24L01 modules.
