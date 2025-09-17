# Circuit Diagrams and Schematics

## Main Circuit Diagram

```
                    RC ROBOCAR CIRCUIT DIAGRAM
                           
    ┌─────────────────┐         ┌──────────────────┐         ┌─────────────────┐
    │   Arduino Uno   │         │   L298N Driver   │         │   HC-05 Module  │
    │                 │         │                  │         │                 │
    │              D2 ├─────────┤ IN1              │         │             VCC ├─── 5V
    │              D3 ├─────────┤ IN2              │         │             GND ├─── GND
    │              D4 ├─────────┤ IN3         OUT1 ├─────────┤ Motor A (+)     │
    │              D5 ├─────────┤ IN4         OUT2 ├─────────┤ Motor A (-)     │
    │              D9 ├─────────┤ ENA         OUT3 ├─────────┤ Motor B (+)     │
    │             D10 ├─────────┤ ENB         OUT4 ├─────────┤ Motor B (-)     │
    │                 │         │                  │         │             TXD ├─── D0 (RX)
    │             D13 ├─────────┤ LED              │         │             RXD ├─── D1 (TX)
    │                 │         │                  │         │                 │
    │             5V  ├─────────┤ VCC              │         └─────────────────┘
    │             GND ├─────────┤ GND              │
    │                 │         │                  │
    └─────────────────┘         │             12V  ├─── 18650 Battery Pack (+)
                                │             GND  ├─── 18650 Battery Pack (-)
                                └──────────────────┘

                                Power Distribution:
                                ┌─────────────────┐
                                │  18650 x2 Pack  │
                                │     7.4V        │
                                │   ┌─────────┐   │
                                │   │ Battery │   │
                                │   │ Monitor │   │
                                │   └─────────┘   │
                                │                 │
                                │  (+) ────┬───── │ → L298N 12V Input
                                │          │      │
                                │          └───── │ → Arduino VIN (via switch)
                                │                 │
                                │  (-) ────────── │ → Common Ground
                                └─────────────────┘
```

## Pin Configuration Details

### Arduino Uno Connections
| Arduino Pin | Connected To | Function |
|-------------|--------------|----------|
| D0 (RX) | HC-05 TXD | Serial receive from Bluetooth |
| D1 (TX) | HC-05 RXD | Serial transmit to Bluetooth |
| D2 | L298N IN1 | Motor A direction control |
| D3 | L298N IN2 | Motor A direction control |
| D4 | L298N IN3 | Motor B direction control |
| D5 | L298N IN4 | Motor B direction control |
| D9 (PWM) | L298N ENA | Motor A speed control |
| D10 (PWM) | L298N ENB | Motor B speed control |
| D13 | LED | Status indicator |
| 5V | L298N VCC, HC-05 VCC | Power supply |
| GND | Common ground | Ground reference |

### L298N Motor Driver Connections
| L298N Pin | Connected To | Function |
|-----------|--------------|----------|
| IN1 | Arduino D2 | Motor A input 1 |
| IN2 | Arduino D3 | Motor A input 2 |
| IN3 | Arduino D4 | Motor B input 1 |
| IN4 | Arduino D5 | Motor B input 2 |
| ENA | Arduino D9 | Motor A enable (PWM) |
| ENB | Arduino D10 | Motor B enable (PWM) |
| OUT1 | Motor A (+) | Motor A positive terminal |
| OUT2 | Motor A (-) | Motor A negative terminal |
| OUT3 | Motor B (+) | Motor B positive terminal |
| OUT4 | Motor B (-) | Motor B negative terminal |
| 12V | Battery (+) | Motor power supply |
| 5V | Arduino 5V | Logic power supply |
| GND | Common ground | Ground reference |

### HC-05 Bluetooth Module Connections
| HC-05 Pin | Connected To | Function |
|-----------|--------------|----------|
| VCC | Arduino 5V | Power supply |
| GND | Arduino GND | Ground |
| TXD | Arduino D0 (RX) | Transmit data |
| RXD | Arduino D1 (TX) | Receive data |

## Power Supply Design

### Battery Configuration
- **Primary Power**: 2x 18650 Li-ion batteries in series (7.4V nominal)
- **Capacity**: 2500-3500mAh per cell
- **Total Energy**: ~18-26 Wh
- **Protection**: Built-in PCB protection circuits

### Power Distribution
1. **Motor Power**: 7.4V directly to L298N motor supply
2. **Logic Power**: 5V regulated output from L298N to Arduino
3. **Backup Option**: Arduino USB power for programming

### Power Switch Circuit
```
Battery (+) ──┬─── SPST Switch ──┬─── L298N 12V Input
              │                  │
              │                  └─── Power LED + 1kΩ resistor
              │
              └─── Voltage Monitor (optional)

Battery (-) ────────────────────────── Common Ground
```

## Motor Control Logic

### Direction Control Truth Table
| IN1 | IN2 | Motor A Action |
|-----|-----|----------------|
| 0 | 0 | Stop |
| 0 | 1 | Reverse |
| 1 | 0 | Forward |
| 1 | 1 | Brake |

| IN3 | IN4 | Motor B Action |
|-----|-----|----------------|
| 0 | 0 | Stop |
| 0 | 1 | Reverse |
| 1 | 0 | Forward |
| 1 | 1 | Brake |

### Movement Combinations
| Command | Motor A | Motor B | Result |
|---------|---------|---------|--------|
| Forward | Forward | Forward | Move forward |
| Backward | Reverse | Reverse | Move backward |
| Left | Reverse | Forward | Turn left |
| Right | Forward | Reverse | Turn right |
| Stop | Stop | Stop | Stop |

## PCB Layout Considerations

### Recommended PCB Design
1. **Power Traces**: Minimum 1mm width for motor power
2. **Ground Plane**: Solid ground plane for noise reduction
3. **Component Placement**: Keep digital and analog sections separate
4. **Heat Management**: Adequate spacing around L298N
5. **Mounting Holes**: M3 holes for secure chassis mounting

### Trace Specifications
- **Motor Power (12V)**: 1.5mm minimum width
- **Logic Power (5V)**: 0.5mm minimum width
- **Signal Traces**: 0.3mm minimum width
- **Ground Traces**: 1mm minimum width

## Safety Features

### Overcurrent Protection
- L298N built-in thermal protection
- Optional fuses: 3A fast-blow for motor supply

### Voltage Protection
- Battery protection circuits (over-discharge, over-charge)
- Reverse polarity protection (recommended)

### Mechanical Protection
- Proper wire strain relief
- Secure component mounting
- Protected battery compartment

## Testing Points

### Essential Test Points on PCB
1. **TP1**: Battery voltage input
2. **TP2**: 5V regulated output
3. **TP3**: Arduino VCC
4. **TP4**: Motor A output
5. **TP5**: Motor B output
6. **TP6**: Bluetooth TX/RX signals

## Troubleshooting Guide

### Common Issues and Solutions
| Problem | Possible Cause | Solution |
|---------|----------------|----------|
| Motors don't move | No power / wrong wiring | Check battery, verify connections |
| One motor doesn't work | Loose connection | Check motor terminals |
| Erratic behavior | Low battery | Charge/replace batteries |
| No Bluetooth connection | Pairing issue | Re-pair device, check HC-05 |
| Arduino not responding | Programming issue | Re-upload code |

---

*Always double-check connections before powering on the system. Use a multimeter to verify voltages and continuity.*