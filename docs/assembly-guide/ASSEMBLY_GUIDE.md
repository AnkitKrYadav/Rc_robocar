# RC Robocar Assembly Guide

## 📋 Prerequisites

### Tools Required
- [ ] Soldering iron (25-40W)
- [ ] Solder (60/40 rosin core)
- [ ] Wire strippers
- [ ] Screwdrivers (Phillips and flathead)
- [ ] Multimeter
- [ ] Hot glue gun
- [ ] Drill with bits (for chassis)
- [ ] Side cutters/pliers

### Safety Equipment
- [ ] Safety glasses
- [ ] Well-ventilated workspace
- [ ] Fire extinguisher nearby
- [ ] First aid kit

### Components Checklist
- [ ] Arduino Uno/Nano
- [ ] L298N Motor Driver Module
- [ ] HC-05 Bluetooth Module
- [ ] 2x 18650 Li-ion batteries
- [ ] Battery holder (2S configuration)
- [ ] 2x DC geared motors
- [ ] Chassis material (acrylic/aluminum)
- [ ] Jumper wires
- [ ] Mounting screws and standoffs
- [ ] Power switch (SPST)
- [ ] LED indicator
- [ ] 220Ω resistor

## 🔧 Step-by-Step Assembly

### Step 1: Chassis Preparation (30 minutes)

#### 1.1 Chassis Layout
```
Top View of Chassis (200mm x 150mm recommended):

    ┌────────────────────────────────┐
    │  [Battery Pack]    [Arduino]   │ ← Front
    │                                │
    │  [L298N]          [HC-05]      │
    │                                │
    │     [Motor A]   [Motor B]      │ ← Rear
    └────────────────────────────────┘
```

#### 1.2 Drilling and Mounting Points
1. **Mark mounting holes** for all components
2. **Drill holes** for:
   - Arduino: 4x M3 holes
   - L298N: 4x M3 holes
   - Battery pack: 2x M3 holes
   - Motors: 2x M4 holes each
   - Power switch: 12mm hole

3. **Test fit** all components before final assembly

### Step 2: Motor Installation (20 minutes)

#### 2.1 Motor Mounting
1. Attach motors to rear of chassis using M4 bolts
2. Ensure motors are parallel and aligned
3. Motors should rotate freely without obstruction
4. Secure with nuts and washers

#### 2.2 Wheel Installation
1. Attach wheels to motor shafts
2. Ensure wheels are firmly secured
3. Test wheel rotation manually

### Step 3: Electronics Mounting (45 minutes)

#### 3.1 Arduino Installation
```bash
# Mount Arduino to chassis
1. Install M3 standoffs (10mm height)
2. Secure Arduino with M3 screws
3. Ensure USB port is accessible
4. Route power cable neatly
```

#### 3.2 L298N Motor Driver Installation
1. Mount L298N near motors for short wire runs
2. Use M3 screws and standoffs
3. Ensure heat sink has adequate airflow
4. Orient connectors for easy access

#### 3.3 HC-05 Bluetooth Module
1. Mount HC-05 in accessible location
2. Consider antenna orientation for best range
3. Protect from mechanical damage
4. Route wires away from interference sources

#### 3.4 Battery Pack Installation
1. Install battery holder in center of chassis
2. Use vibration-resistant mounting
3. Ensure easy battery access
4. Install power switch in accessible location

### Step 4: Wiring (90 minutes)

#### 4.1 Power Wiring (Safety Critical!)
⚠️ **IMPORTANT**: Double-check all power connections before testing

```
Battery Wiring Sequence:
1. Battery Pack (+) → Power Switch → L298N 12V Input
2. Battery Pack (-) → L298N GND
3. L298N 5V Output → Arduino VIN
4. Common ground to all components
```

#### 4.2 Motor Connections
```
Motor A (Left):  L298N OUT1 → Motor (+), OUT2 → Motor (-)
Motor B (Right): L298N OUT3 → Motor (+), OUT4 → Motor (-)
```

#### 4.3 Control Signal Wiring
| Arduino Pin | L298N Pin | Wire Color (Suggested) |
|-------------|-----------|------------------------|
| D2 | IN1 | Red |
| D3 | IN2 | Orange |
| D4 | IN3 | Yellow |
| D5 | IN4 | Green |
| D9 | ENA | Blue |
| D10 | ENB | Purple |

#### 4.4 Bluetooth Module Wiring
| Arduino Pin | HC-05 Pin | Wire Color (Suggested) |
|-------------|-----------|------------------------|
| 5V | VCC | Red |
| GND | GND | Black |
| D0 (RX) | TXD | White |
| D1 (TX) | RXD | Gray |

#### 4.5 Status LED Wiring
```
Arduino D13 → 220Ω Resistor → LED (+) → LED (-) → GND
```

### Step 5: Initial Testing (30 minutes)

#### 5.1 Visual Inspection
- [ ] Check all solder joints for quality
- [ ] Verify no short circuits
- [ ] Ensure proper wire routing
- [ ] Confirm secure component mounting

#### 5.2 Power-On Test
1. **Insert batteries** (ensure correct polarity!)
2. **Turn on power switch**
3. **Check voltage measurements**:
   - Battery pack: ~7.4V
   - L298N 5V output: ~5V
   - Arduino VCC: ~5V

#### 5.3 Basic Function Test
1. **Upload test sketch** to Arduino
2. **Test LED** blinks on startup
3. **Verify Bluetooth** connectivity
4. **Test each motor** individually

### Step 6: Programming and Calibration (45 minutes)

#### 6.1 Arduino IDE Setup
1. Install Arduino IDE (latest version)
2. Select correct board type
3. Select correct COM port
4. Upload the main control sketch

#### 6.2 Bluetooth Pairing
1. Power on the RC car
2. Enable Bluetooth on your mobile device
3. Search for "HC-05" device
4. Pair with default PIN: 1234
5. Install Bluetooth terminal app

#### 6.3 Motor Calibration
```cpp
// Test each direction
// Send commands via Bluetooth:
F  // Forward - both motors should rotate forward
B  // Backward - both motors should rotate backward
L  // Left - left motor reverse, right forward
R  // Right - right motor reverse, left forward
S  // Stop - all motors stop
```

### Step 7: Final Assembly and Testing (30 minutes)

#### 7.1 Cable Management
1. Secure all wires with zip ties
2. Protect wires from moving parts
3. Ensure adequate wire lengths for movement
4. Use heat shrink tubing for exposed connections

#### 7.2 Safety Features
1. Install power LED indicator
2. Verify emergency stop function
3. Test battery low voltage cutoff (if implemented)
4. Check mechanical stability

#### 7.3 Range and Performance Testing
1. **Test communication range**: Should work up to 10 meters
2. **Test response time**: Commands should execute within 50ms
3. **Test battery life**: Note runtime for future reference
4. **Test all movement combinations**: Forward, backward, turns, stop

## 🛠️ Troubleshooting Common Issues

### Power Issues
| Problem | Check | Solution |
|---------|-------|----------|
| No power | Battery voltage, connections | Charge batteries, check wiring |
| Intermittent power | Loose connections | Re-solder joints, check battery contacts |
| Overheating | Current draw, heat sinks | Check motor stall, improve cooling |

### Communication Issues
| Problem | Check | Solution |
|---------|-------|----------|
| Can't pair Bluetooth | HC-05 power, visibility | Reset HC-05, check power supply |
| No response to commands | Serial connection, baud rate | Check TX/RX wiring, verify code |
| Intermittent connection | Interference, range | Move closer, check antenna orientation |

### Motor Issues
| Problem | Check | Solution |
|---------|-------|----------|
| Motor doesn't turn | Power, connections | Check motor wiring, test voltage |
| Wrong direction | Motor polarity | Swap motor wires |
| Weak performance | Battery level, speed setting | Charge battery, adjust PWM values |

## 📏 Final Specifications

After successful assembly, your RC robocar should meet these specifications:

- **Dimensions**: 200mm x 150mm x 100mm (approximate)
- **Weight**: 800-1200g (depending on chassis material)
- **Speed**: Variable, up to 2 m/s
- **Range**: 10 meters (Bluetooth)
- **Battery Life**: 45-60 minutes continuous operation
- **Response Time**: <50ms command to action

## 🎯 Performance Optimization Tips

### Speed Optimization
- Use lightweight chassis materials
- Minimize wire lengths
- Optimize gear ratios for your application
- Balance payload distribution

### Range Optimization
- Position HC-05 antenna away from metal components
- Use quality jumper wires
- Minimize electrical interference
- Consider external antenna for HC-05

### Battery Life Optimization
- Use efficient motors
- Implement sleep modes when idle
- Monitor battery voltage
- Use quality batteries with low self-discharge

## 📋 Maintenance Schedule

### Weekly
- [ ] Check battery charge level
- [ ] Inspect for loose connections
- [ ] Clean chassis and components
- [ ] Test all functions

### Monthly
- [ ] Deep battery cycle (full discharge/charge)
- [ ] Re-torque all mechanical fasteners
- [ ] Update firmware if needed
- [ ] Performance testing and calibration

### As Needed
- [ ] Replace worn components
- [ ] Upgrade software features
- [ ] Modify for competition requirements

---

**Congratulations!** 🎉 You have successfully assembled your RC robocar. Your robot is now ready for competition and further development!

*Remember to always prioritize safety and follow proper handling procedures for batteries and electronic components.*