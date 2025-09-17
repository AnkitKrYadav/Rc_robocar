# Component Specifications

## Arduino Uno/Nano
- **Microcontroller**: ATmega328P
- **Operating Voltage**: 5V
- **Input Voltage**: 7-12V (recommended)
- **Digital I/O Pins**: 14 (6 PWM outputs)
- **Analog Input Pins**: 6
- **Flash Memory**: 32KB
- **SRAM**: 2KB
- **Clock Speed**: 16MHz

### Purchase Links
- [Arduino Uno Official](https://store.arduino.cc/products/arduino-uno-rev3)
- [Arduino Nano Compatible](https://www.amazon.com/s?k=arduino+nano)

## L298N Motor Driver Module
- **Supply Voltage**: 5V-35V
- **Logic Voltage**: 5V
- **Logic Current**: 0-36mA
- **Drive Current**: 2A (Max single bridge)
- **Max Power**: 25W
- **Storage Temperature**: -20°C to +135°C
- **Number of Channels**: 2

### Features
- Dual H-Bridge motor driver
- Built-in 5V regulator
- Heat sink for thermal management
- LED indicators for power and direction
- Protection diodes included

### Purchase Links
- [Amazon - L298N Module](https://www.amazon.com/s?k=L298N+motor+driver)
- [Local Electronics Store](https://example.com)

## HC-05 Bluetooth Module
- **Bluetooth Version**: 2.0+EDR
- **Frequency**: 2.4GHz ISM band
- **Modulation**: GFSK (Gaussian Frequency Shift Keying)
- **Emission Power**: ≤4dBm, Class 2
- **Sensitivity**: ≤-84dBm at 0.1% BER
- **Speed**: Asynchronous: 2.1Mbps(Max)/160kbps
- **Security**: Authentication and encryption
- **Profiles**: Bluetooth serial port
- **Operating Voltage**: 3.3V-5V
- **Operating Current**: 50mA
- **Standby Current**: <1mA
- **Operating Temperature**: -10°C to +65°C

### Purchase Links
- [Amazon - HC-05 Module](https://www.amazon.com/s?k=HC-05+bluetooth+module)
- [SparkFun](https://www.sparkfun.com/)

## 18650 Li-ion Battery
- **Voltage**: 3.7V nominal (4.2V max, 3.0V min)
- **Capacity**: 2500-3500mAh (recommended)
- **Chemistry**: Lithium-ion
- **Cycle Life**: 300-500 cycles
- **Discharge Rate**: 1C-2C (depending on model)
- **Protection**: Built-in PCB protection (recommended)

### Recommended Models
- Samsung INR18650-35E (3500mAh)
- LG HG2 (3000mAh, 20A discharge)
- Panasonic NCR18650B (3400mAh)

### Safety Notes
⚠️ **Important**: Always use batteries with built-in protection circuits
⚠️ Use appropriate charger (4.2V, 1A max)
⚠️ Never short circuit or expose to extreme temperatures

### Purchase Links
- [Battery Supplier](https://example.com)
- **Note**: Buy from reputable suppliers only for safety

## DC Geared Motors
- **Voltage**: 6V-12V
- **Speed**: 200-300 RPM (with gearbox)
- **Torque**: 2-5 kg-cm
- **Gear Ratio**: 1:48 to 1:120
- **Shaft Diameter**: 6mm
- **Current**: 0.5-1.5A (stall current)

### Recommended Specifications
- Operating voltage: 12V
- No-load speed: 250 RPM
- Gear ratio: 1:75
- Torque: 3 kg-cm

## Additional Components

### Resistors
- **10kΩ** (pull-up resistors) - Qty: 2
- **220Ω** (LED current limiting) - Qty: 1

### Capacitors
- **100µF electrolytic** (power filtering) - Qty: 2
- **0.1µF ceramic** (decoupling) - Qty: 4

### Connectors
- **Jumper wires** (male-to-male, male-to-female)
- **Breadboard** or **PCB** for prototyping
- **Screw terminals** for motor connections
- **JST connectors** for battery connections

### Chassis Materials
- **Acrylic sheet** (3-5mm thickness)
- **Aluminum extrusion** (optional for reinforcement)
- **Mounting screws** (M3 bolts and nuts)
- **Standoffs** for component mounting

## Total Estimated Cost
| Component | Estimated Cost (USD) |
|-----------|---------------------|
| Arduino Uno | $15-25 |
| L298N Module | $3-8 |
| HC-05 Module | $5-12 |
| 18650 Batteries (2x) | $10-20 |
| DC Motors (2x) | $15-30 |
| Chassis & Hardware | $10-25 |
| Miscellaneous | $5-15 |
| **Total** | **$63-135** |

*Prices may vary based on quality, supplier, and location*