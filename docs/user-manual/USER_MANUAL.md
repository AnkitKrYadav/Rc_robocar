# User Manual - RC Robocar

## 🚀 Quick Start

### Power On Sequence
1. **Insert charged 18650 batteries** into battery pack (observe polarity!)
2. **Turn on power switch** - LED should illuminate
3. **Wait 3 seconds** for system initialization
4. **Enable Bluetooth** on your mobile device
5. **Pair with "HC-05"** (PIN: 1234)
6. **Open Bluetooth terminal app**
7. **Send test command "S"** to ensure connection

### Basic Operation Commands
| Command | Function | Response |
|---------|----------|----------|
| `F` | Move Forward | "Moving Forward" |
| `B` | Move Backward | "Moving Backward" |
| `L` | Turn Left | "Turning Left" |
| `R` | Turn Right | "Turning Right" |
| `S` | Stop | "Stopped" |

## 📱 Mobile App Recommendations

### Android Apps
- **Bluetooth Terminal** (by Kai Morich) - Free
- **Serial Bluetooth Terminal** - Free
- **Arduino Bluetooth Control** - Free

### iOS Apps
- **BLE Terminal** - Free
- **Bluetooth Terminal** - Paid
- **LightBlue Explorer** - Free

### Custom Commands
```
Basic Movement:
F, FORWARD    - Move forward at current speed
B, BACKWARD   - Move backward at current speed  
L, LEFT       - Turn left (tank steering)
R, RIGHT      - Turn right (tank steering)
S, STOP       - Emergency stop

Speed Control:
SPEED100      - Set speed to 100 (0-255 range)
SPEED200      - Set speed to 200 (default)
SPEED255      - Set maximum speed
```

## ⚙️ Advanced Operation

### Speed Control
The robot supports variable speed control using PWM values from 0-255:
- **0-50**: Very slow, good for precise movements
- **51-100**: Slow speed, good for navigation
- **101-150**: Medium speed, balanced performance
- **151-200**: Default speed, good for general use
- **201-255**: High speed, maximum performance

### Custom Control Sequences
You can send multiple commands in sequence:
```
F       // Move forward
SPEED150 // Reduce speed
R       // Turn right
SPEED200 // Restore default speed
S       // Stop
```

### Programming Your Own Controller
Example Python script for computer control:
```python
import serial
import time

# Connect to HC-05 via COM port
bluetooth = serial.Serial('COM3', 9600)  # Adjust COM port

def send_command(cmd):
    bluetooth.write(cmd.encode())
    time.sleep(0.1)

# Example control sequence
send_command('F')    # Move forward
time.sleep(2)        # For 2 seconds
send_command('R')    # Turn right
time.sleep(1)        # For 1 second
send_command('S')    # Stop
```

## 🔋 Battery Management

### Battery Status Indicators
- **Solid LED**: Normal operation (>7.0V)
- **Flickering LED**: Low battery warning (<6.8V)
- **No LED**: Battery depleted or disconnected

### Charging Procedure
1. **Remove batteries** from robot
2. **Use appropriate Li-ion charger** (4.2V, 1-2A)
3. **Charge until green light** (typically 2-4 hours)
4. **Test voltage** should read 4.1-4.2V per cell
5. **Store in cool, dry place** if not used immediately

### Battery Safety
⚠️ **CRITICAL SAFETY INFORMATION**:
- Never leave batteries charging unattended
- Do not over-discharge below 3.0V per cell
- Store batteries at 40-60% charge for long term
- Dispose of damaged batteries properly
- Use only quality batteries with protection circuits

### Battery Life Optimization
- **Avoid full throttle** for extended periods
- **Turn off when not in use**
- **Store batteries properly** when not used for weeks
- **Cycle batteries monthly** (full charge/discharge)

## 🎮 Competition Mode

### Robowar Configuration
For competitive robotics events, optimize settings:

```cpp
// High-performance settings
int motorSpeed = 255;        // Maximum speed
int responseTime = 10;       // Faster response
bool aggressiveMode = true;  // Enable competition features
```

### Competition Commands
```
Emergency Commands:
ESTOP     - Emergency stop (highest priority)
RESET     - System reset and initialization

Combat Commands:
SPRINT    - Maximum speed for 5 seconds
DODGE     - Quick left-right-left movement
CHARGE    - Full speed forward until stop command
```

### Team Communication
Use standardized commands for team coordination:
- `STATUS` - Request robot status
- `POSITION` - Request current position/orientation
- `BATTERY` - Check battery level
- `READY` - Confirm ready for competition

## 🛠️ Maintenance

### Daily Maintenance (Before Each Use)
- [ ] Check battery voltage (>7.0V for two batteries)
- [ ] Verify all connections are secure
- [ ] Test Bluetooth pairing
- [ ] Verify all movement commands work
- [ ] Check wheels rotate freely

### Weekly Maintenance
- [ ] Clean chassis and remove debris
- [ ] Check motor mounting screws
- [ ] Inspect wires for damage
- [ ] Test full speed operation
- [ ] Cycle batteries (full charge/discharge)

### Monthly Maintenance
- [ ] Deep clean all components
- [ ] Re-torque all screws
- [ ] Update firmware if available
- [ ] Performance testing and calibration
- [ ] Replace worn components

### Storage Procedures
**Short-term (1-7 days)**:
- Leave batteries in robot
- Store in room temperature
- Power off completely

**Long-term (1+ weeks)**:
- Remove batteries
- Store batteries at 50-60% charge
- Store robot in dry location
- Clean before storage

## 🚨 Troubleshooting

### Power Issues

**Problem**: Robot won't turn on
- Check battery polarity
- Verify battery charge (>6.8V total)
- Check power switch connection
- Inspect fuse if installed

**Problem**: Intermittent power
- Check battery contacts for corrosion
- Verify all ground connections
- Test individual battery voltages
- Check for loose wire connections

### Communication Issues

**Problem**: Can't connect via Bluetooth
- Verify HC-05 power LED is blinking
- Clear Bluetooth cache on mobile device
- Try pairing from close range (<1 meter)
- Reset HC-05 by power cycling

**Problem**: Commands not responding
- Check TX/RX wire connections
- Verify baud rate (9600)
- Test with different terminal app
- Check Arduino programming

**Problem**: Intermittent communication
- Move closer to robot (< 5 meters)
- Check for interference from WiFi/other devices
- Verify HC-05 antenna orientation
- Check battery voltage

### Movement Issues

**Problem**: Robot doesn't move
- Check motor connections to L298N
- Verify motor power supply (7.4V)
- Test motors individually
- Check enable pins (ENA, ENB)

**Problem**: Robot moves in wrong direction
- Swap motor wire polarity
- Check command mapping in code
- Verify left/right motor assignment

**Problem**: Robot moves slowly
- Check battery charge level
- Verify speed setting (PWM value)
- Check for mechanical binding
- Lubricate wheel bearings

**Problem**: Robot turns when going straight
- Calibrate motor speeds
- Check wheel alignment
- Verify motor performance balance
- Adjust PWM compensation in code

### Performance Issues

**Problem**: Short battery life
- Check for current leaks
- Verify efficient code (no busy loops)
- Check motor efficiency
- Consider larger capacity batteries

**Problem**: Poor range
- Reposition HC-05 antenna
- Check for metal interference
- Upgrade to HC-05 with external antenna
- Verify line-of-sight communication

## 📊 Performance Specifications

### Normal Operating Parameters
| Parameter | Specification | Notes |
|-----------|---------------|-------|
| Operating Voltage | 6.8-8.4V | 2S Li-ion pack |
| Current Draw (Idle) | 50-100mA | Bluetooth + Arduino |
| Current Draw (Moving) | 1-3A | Depends on load and speed |
| Maximum Speed | 2-3 m/s | Depends on gear ratio |
| Communication Range | 8-12 meters | Line of sight |
| Response Time | 20-50ms | Command to action |
| Battery Life | 45-90 minutes | Depends on usage pattern |

### Environmental Limits
- **Temperature**: 0°C to 40°C (32°F to 104°F)
- **Humidity**: <80% non-condensing
- **Altitude**: Sea level to 2000m
- **Surface**: Hard, flat surfaces recommended

## 🆘 Emergency Procedures

### Emergency Stop
1. **Send "S" or "STOP"** command immediately
2. **Turn off power switch** if robot doesn't respond
3. **Remove batteries** if robot is out of control
4. **Check for damage** before restarting

### Lost Communication
1. **Move closer** to robot (within 2 meters)
2. **Send "S" command** repeatedly
3. **Power cycle robot** if no response
4. **Remove batteries** as last resort

### Overheating
1. **Stop operation** immediately
2. **Turn off power** and let cool
3. **Check for blocked ventilation**
4. **Verify current draw** is within specs
5. **Inspect for damaged components**

## 📞 Support and Contact

### Technical Support
- **GitHub Issues**: [Repository Issues Page](https://github.com/AnkitKrYadav/Rc_robocar/issues)
- **Email**: (Add your contact email)
- **University Lab**: (Add lab contact if applicable)

### Community Resources
- Arduino Community Forums
- Reddit: r/arduino, r/robotics
- YouTube tutorials and demonstrations
- Local robotics clubs and competitions

### Warranty and Liability
This is an educational/hobbyist project. Use at your own risk. Always follow safety guidelines and local regulations for battery handling and robot operation.

---

**Enjoy your RC Robocar!** 🎉

*This manual covers basic operation. For advanced programming and modifications, refer to the source code and circuit diagrams in the repository.*