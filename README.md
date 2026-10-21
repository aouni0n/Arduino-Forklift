# 🚜 Arduino Forklift — Bluetooth Controlled 4WD Robot

The **Arduino Forklift** is a custom-built, four-wheel-drive robotic vehicle with a motorized lifting mechanism, controlled wirelessly through Bluetooth. Built using an **Arduino, L298N motor driver, and a 2-channel relay module**, the project combines mobile robotics, motor control, and mechanical automation into a single embedded system.

The robot supports forward and backward movement, left and right turns, and independent forklift lifting and lowering through simple serial commands.

Originally developed as a hands-on robotics project, it demonstrates practical applications of **embedded systems, electronics, motor control, and electromechanical engineering**.

---

# 📌 Project Overview

## 🚜 The forklift combines:

- Four-wheel-drive mobility
- Bluetooth wireless control
- Dual DC motor control through an L298N driver
- Relay-controlled lifting mechanism
- Bidirectional pulley motor operation
- Adjustable movement and turning speeds
- Serial communication with an Arduino

## ⚙️ Arduino handles:

- Processing Bluetooth commands
- Controlling the left and right drive motors
- Adjusting motor speeds using PWM
- Operating the forklift lifting mechanism
- Managing relay switching
- Stopping the wheels and pulley when commanded

## 📡 Communication

**Bluetooth Serial Communication — 9600 baud**

The Bluetooth module receives commands from a compatible phone application and passes them to the Arduino.

---

# 🎮 Control Commands

| Command | Function |
|---|---|
| `F` | Move forward |
| `B` | Move backward |
| `L` | Turn left |
| `R` | Turn right |
| `T` | Stop the wheels |
| `U` | Lift the forklift |
| `D` | Lower the forklift |
| `P` | Stop the lifting mechanism |

Movement and lifting durations are configured in the Arduino sketch and can be adjusted to suit the chassis and pulley mechanism.

---

# ⚙️ Features

✔ Four-Wheel-Drive Robotic Platform  
✔ Bluetooth-Based Wireless Control  
✔ Forward and Reverse Movement  
✔ Left and Right Turning  
✔ PWM Motor Speed Control  
✔ Independent Forklift Lifting and Lowering  
✔ Dual-Relay Direction Control  
✔ Separate Wheel and Pulley Stop Functions  
✔ Arduino-Based Embedded Control  
✔ Configurable Movement and Turning Speeds  

---

# 🧰 Hardware Components

| Component | Quantity |
|---|---:|
| Arduino Uno / compatible board | 1 |
| L298N dual H-bridge motor driver | 1 |
| DC geared drive motors | 4 |
| Bluetooth module (HC-05 / HC-06) | 1 |
| 2-channel relay module | 1 |
| DC motor for the lifting pulley | 1 |
| Forklift chassis and lifting mechanism | 1 |
| Battery / suitable motor power supply | 1 |
| Jumper wires | Multiple |

*The component list can be adapted to match the exact hardware configuration.*

---

# 🔌 Wiring Instructions

## 1. L298N Motor Driver

| L298N Pin | Arduino Pin | Purpose |
|---|---|---|
| ENA | D3 | Motor A speed control |
| ENB | D5 | Motor B speed control |
| IN1 | D2 | Motor A direction |
| IN2 | D4 | Motor A direction |
| IN3 | D7 | Motor B direction |
| IN4 | D8 | Motor B direction |
| GND | GND | Common ground |

**Motor outputs:**
- `OUT1` and `OUT2`: Motor A
- `OUT3` and `OUT4`: Motor B

For a four-wheel-drive chassis, the two motors on each side can be connected in parallel to the corresponding motor output, provided the driver's current limits are respected.

## 2. Forklift Relay Module

| Relay Module Pin | Arduino Pin | Purpose |
|---|---|---|
| IN1 | A0 | Lift upward |
| IN2 | A1 | Lower downward |
| VCC | Suitable supply | Relay module power |
| GND | GND | Common ground |

The sketch uses active-LOW relay logic:

- `LOW`: Activate the relay
- `HIGH`: Deactivate the relay

The two relays switch the lifting motor's direction. The relay contacts must be wired so that the motor reverses polarity safely, without shorting the power supply.

## 3. Bluetooth Module

| Bluetooth Pin | Arduino Connection |
|---|---|
| TXD | Arduino RX (D0) |
| RXD | Arduino TX (D1), through suitable level shifting if required |
| VCC | Supply appropriate to the module |
| GND | Arduino GND |

**Note:** Hardware serial pins D0 and D1 are shared with USB serial communication on the Uno. Disconnect the Bluetooth module during uploading if it interferes with programming.

## 4. Power Supply

- Supply the motors using a suitable external motor power source.
- Connect the Arduino and motor-driver grounds together.
- Ensure the relay contacts and power supply are rated for the lifting motor's current.
- Avoid powering high-current motors directly from the Arduino's 5V pin.

---

# 💻 Software Requirements

- Arduino IDE
- Arduino-compatible board package
- L298N motor-driver wiring
- Bluetooth serial controller application
- Compatible Bluetooth module

The Arduino sketch uses standard functions such as `digitalWrite()`, `analogWrite()`, `pinMode()`, and `Serial`.

---

# 📂 Project Structure

```text
Arduino-Forklift/
│
├── forklift.ino
└── README.md
```

The repository can also include wiring diagrams, photographs of the assembled robot, a bill of materials, and a demonstration video.

---

# 🚀 Setup Instructions

## Step 1 — Assemble the Robot

Mount the four drive motors, wheels, chassis, lifting mechanism, and pulley motor securely.

## Step 2 — Connect the Motor Driver

Wire the L298N inputs, enable pins, and motor outputs according to the wiring table.

## Step 3 — Connect the Relay Module

Connect the relay inputs to A0 and A1. Wire the relay contacts to reverse the lifting motor's direction safely.

## Step 4 — Configure Bluetooth

Pair the Bluetooth module with a compatible controller and configure serial communication for **9600 baud**.

## Step 5 — Upload the Arduino Sketch

Open the `.ino` file in Arduino IDE, select the correct board and port, and upload the program.

## Step 6 — Test the Controls

Test each movement command with the wheels raised or the robot otherwise secured. Test lifting and lowering without a load first, and verify that the pulley stops correctly.

---

# 🔧 Adjustable Parameters

The following variables in the Arduino sketch control the robot's movement:

```cpp
int Speeed = 90;      // Motor B speed
int Speeed1 = 90;     // Motor A speed
int turnSpeed = 80;   // Motor B turning speed
int turnSpeed1 = 80;  // Motor A turning speed
```

Motor speed values range from `0` to `255` when used with PWM-capable pins.

Movement duration and lifting duration can also be adjusted in the sketch to match the robot's turning radius, chassis, and lifting mechanism.

---

# 🔮 Future Improvements

- Proportional joystick control
- Continuous movement while a button is held
- Adjustable lifting speed
- Limit switches for maximum and minimum lift positions
- Obstacle detection using ultrasonic sensors
- Load detection and overload protection
- Emergency stop functionality
- Battery monitoring
- ESP32-based wireless control
- Autonomous navigation and object transportation
- Custom mobile application with a graphical controller

---

# 📚 Learning Outcomes

This project demonstrates practical experience with:

- Arduino programming and embedded systems
- H-bridge motor control
- PWM speed regulation
- Relay-based motor direction switching
- Bluetooth serial communication
- Four-wheel-drive robotics
- Electromechanical lifting mechanisms
- Hardware integration and troubleshooting

---

# 👨‍💻 Author

**Aounion**

- GitHub: https://github.com/aouni0n
- Portfolio: https://aouni0n.github.io/

---

# 📜 License

MIT License — free to use, modify, and distribute under the terms of the license.

---

**Arduino Forklift** is a hands-on robotics project exploring how electronics, embedded programming, and mechanical systems work together to create a remotely operated lifting vehicle.
