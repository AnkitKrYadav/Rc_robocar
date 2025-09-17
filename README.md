# RC Robocar 🚗⚡

[![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.arduino.cc/)
[![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)](https://isocpp.org/)
[![MIT License](https://img.shields.io/badge/License-MIT-green.svg?style=for-the-badge)](https://choosealicense.com/licenses/mit/)

> **Professional RC Car Project for University Robowar Competition**

A sophisticated remote-controlled robotic car designed for university robowar competitions, featuring Bluetooth connectivity, dual motor control, and robust hardware integration. This project demonstrates advanced embedded systems design, wireless communication, and competitive robotics engineering.

## 🎯 Project Overview

This repository contains the complete design and implementation of a competitive RC robocar built for university-level robot warfare competitions. The system integrates Arduino microcontroller technology with professional-grade motor control and wireless communication for precise, responsive operation in competitive environments.

### 🏆 Competition Features
- **High-speed maneuverability** for quick tactical movements
- **Reliable wireless control** via Bluetooth communication
- **Robust motor control** for precise directional handling
- **Modular design** for easy modifications and upgrades
- **Professional documentation** for educational and portfolio purposes

## 🔧 Hardware Components

| Component | Model/Type | Purpose | Specifications |
|-----------|------------|---------|----------------|
| **Microcontroller** | Arduino Uno/Nano | Main control unit | ATmega328P, 16MHz |
| **Motor Driver** | L298N | Dual H-Bridge motor control | 2A per channel, 5V-35V |
| **Bluetooth Module** | HC-05 | Wireless communication | Class 2, 10m range |
| **Battery** | 18650 Li-ion | Power supply | 3.7V, 2500-3500mAh |
| **Motors** | DC Geared Motors | Locomotion | 12V, high torque |
| **Chassis** | Custom/Acrylic | Structural frame | Lightweight, durable |

## 📁 Repository Structure

```
Rc_robocar/
├── 📂 src/
│   └── 📂 arduino/
│       └── 📂 rc_car_control/
│           └── 🔧 rc_car_control.ino    # Main Arduino sketch
├── 📂 docs/
│   ├── 📂 circuit-diagrams/             # Electrical schematics
│   ├── 📂 assembly-guide/               # Step-by-step build instructions
│   └── 📂 user-manual/                  # Operation and maintenance
├── 📂 hardware/
│   ├── 📂 components/                   # Component specifications
│   └── 📂 schematics/                   # Circuit designs
├── 📂 media/
│   ├── 📂 images/                       # Project photos
│   └── 📂 videos/                       # Demonstration videos
├── 📂 examples/                         # Code examples and tutorials
├── 📄 README.md                         # This file
└── 📄 LICENSE                           # MIT License
```

## 🚀 Quick Start Guide

### Prerequisites
- Arduino IDE (v1.8.0 or higher)
- Basic electronics knowledge
- Soldering equipment
- Mobile device with Bluetooth

### 1. Hardware Assembly
1. Connect L298N motor driver to Arduino (see [circuit diagrams](docs/circuit-diagrams/))
2. Wire HC-05 Bluetooth module for serial communication
3. Install 18650 battery pack with proper voltage regulation
4. Mount components on chassis with secure connections

### 2. Software Installation
```bash
# Clone the repository
git clone https://github.com/AnkitKrYadav/Rc_robocar.git

# Open Arduino IDE and load the sketch
# File: src/arduino/rc_car_control/rc_car_control.ino
```

### 3. Configuration
1. Upload the Arduino sketch to your microcontroller
2. Pair your mobile device with HC-05 (default PIN: 1234)
3. Use any Bluetooth terminal app to send commands

## 🎮 Control Commands

| Command | Action | Description |
|---------|--------|-------------|
| `F` or `FORWARD` | Move Forward | Both motors rotate forward |
| `B` or `BACKWARD` | Move Backward | Both motors rotate backward |
| `L` or `LEFT` | Turn Left | Left motor reverse, right forward |
| `R` or `RIGHT` | Turn Right | Right motor reverse, left forward |
| `S` or `STOP` | Stop | All motors stop |
| `SPEED150` | Set Speed | Set motor speed (0-255) |

## ⚡ Circuit Diagram

```
Arduino Uno    L298N Motor Driver    HC-05 Bluetooth
    D2   ----->   IN1                    VCC  <----- 5V
    D3   ----->   IN2                    GND  <----- GND
    D4   ----->   IN3                    TXD  <----- D0 (RX)
    D5   ----->   IN4                    RXD  <----- D1 (TX)
    D9   ----->   ENA            
    D10  ----->   ENB            
    5V   ----->   VCC            
    GND  ----->   GND            
```

## 🏁 Competition Performance

### Technical Specifications
- **Maximum Speed**: Variable (0-255 PWM)
- **Operating Voltage**: 7.4V (2S Li-ion)
- **Communication Range**: 10 meters
- **Response Time**: <50ms
- **Battery Life**: 45-60 minutes continuous operation

### Competitive Advantages
- ✅ **Instant Response**: Low-latency Bluetooth communication
- ✅ **Precise Control**: Variable speed and direction control
- ✅ **Robust Design**: Industrial-grade components
- ✅ **Easy Maintenance**: Modular, well-documented design
- ✅ **Expandable**: Ready for weapon systems and sensors

## 🛠️ Advanced Features

### Implemented
- [x] Bluetooth wireless control
- [x] Variable speed control
- [x] Bidirectional movement
- [x] Status LED indicators
- [x] Serial command interface

### Future Enhancements
- [ ] Autonomous navigation with ultrasonic sensors
- [ ] Camera integration for FPV control
- [ ] Weapon systems for combat competitions
- [ ] Gyroscope for stability control
- [ ] Mobile app with custom interface

## 📚 Educational Value

This project demonstrates proficiency in:
- **Embedded Systems Programming** (Arduino/C++)
- **Wireless Communication Protocols** (Bluetooth UART)
- **Motor Control Systems** (PWM, H-Bridge drivers)
- **Circuit Design and Analysis**
- **Project Management and Documentation**
- **Competitive Robotics Engineering**

## 🤝 Contributing

Contributions are welcome! Please read our [Contributing Guidelines](CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

### Development Setup
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes (`git commit -m 'Add amazing feature'`)
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

## 📝 Documentation

Comprehensive documentation is available in the `/docs` directory:
- [Assembly Guide](docs/assembly-guide/) - Step-by-step build instructions
- [Circuit Diagrams](docs/circuit-diagrams/) - Electrical schematics and wiring
- [User Manual](docs/user-manual/) - Operation and troubleshooting

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 👨‍💻 Author

**Ankit Kumar Yadav**
- 🎓 University Student - Robotics Engineering
- 🏆 Robowar Competition Participant
- 💼 [LinkedIn](https://linkedin.com/in/ankit-kumar-yadav) | [Portfolio](https://github.com/AnkitKrYadav)

## 🙏 Acknowledgments

- University Robotics Club for competition support
- Arduino community for extensive documentation
- Open-source robotics community for inspiration

---

⭐ **Star this repository if it helped you in your robotics journey!**

*Built with ❤️ for competitive robotics and educational purposes*