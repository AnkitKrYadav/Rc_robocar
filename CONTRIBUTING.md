# Contributing to RC Robocar

Thank you for your interest in contributing to the RC Robocar project! This guide will help you get started with contributing to this educational robotics project.

## 🤝 How to Contribute

### Types of Contributions Welcome
- 🐛 **Bug Reports**: Help us identify and fix issues
- 💡 **Feature Suggestions**: Propose new functionality
- 📝 **Documentation**: Improve guides, comments, and examples
- 🔧 **Code Improvements**: Optimize performance, add features
- 🎨 **Circuit Designs**: Better schematics and PCB layouts
- 📹 **Media Content**: Photos, videos, demonstrations
- 🧪 **Testing**: Validate functionality across different setups

## 🚀 Getting Started

### Prerequisites
1. Arduino IDE (v1.8.0 or higher)
2. Basic knowledge of C/C++ programming
3. Understanding of electronics and circuits
4. Access to Arduino hardware for testing

### Development Setup
1. **Fork the repository**
   ```bash
   # Click "Fork" on GitHub, then clone your fork
   git clone https://github.com/YOUR_USERNAME/Rc_robocar.git
   cd Rc_robocar
   ```

2. **Set up development environment**
   ```bash
   # Add upstream remote
   git remote add upstream https://github.com/AnkitKrYladav/Rc_robocar.git
   
   # Create a new branch for your feature
   git checkout -b feature/your-feature-name
   ```

3. **Test the existing code**
   - Load `src/arduino/rc_car_control/rc_car_control.ino` in Arduino IDE
   - Verify compilation without errors
   - Test on hardware if available

## 📋 Contribution Guidelines

### Code Standards

#### Arduino Code Style
```cpp
// Use descriptive function and variable names
void moveForward() {  // Good
void mf() {          // Bad

// Include comments for complex logic
// Calculate PWM value based on battery voltage
int adjustedSpeed = (motorSpeed * batteryVoltage) / 8.4;

// Use consistent indentation (2 spaces)
if (condition) {
  doSomething();
}
```

#### Documentation Style
- Use clear, concise language
- Include code examples where applicable
- Provide both beginner and advanced explanations
- Update README if adding new features

### Testing Requirements

#### Before Submitting
- [ ] Code compiles without warnings
- [ ] Functionality tested on actual hardware
- [ ] Documentation updated if needed
- [ ] Examples work as described
- [ ] No breaking changes to existing API

#### Testing Checklist
```cpp
// Test all basic movements
testMovement("FORWARD");
testMovement("BACKWARD"); 
testMovement("LEFT");
testMovement("RIGHT");
testMovement("STOP");

// Test speed control
testSpeedControl(0, 100, 200, 255);

// Test edge cases
testInvalidCommands();
testLowBattery();
testConnectionLoss();
```

## 🐛 Bug Reports

### Bug Report Template
```markdown
## Bug Description
Clear description of the issue

## Steps to Reproduce
1. Step one
2. Step two
3. Step three

## Expected Behavior
What should happen

## Actual Behavior
What actually happens

## Environment
- Arduino Board: (Uno/Nano/etc.)
- Arduino IDE Version: 
- Operating System:
- Hardware Setup: (describe connections)

## Additional Context
Any other relevant information
```

### Common Issues to Check First
- Battery voltage and charge level
- Correct wiring according to circuit diagrams
- Proper Bluetooth pairing
- Arduino IDE board and port selection
- Serial monitor baud rate (9600)

## ✨ Feature Requests

### Feature Request Template
```markdown
## Feature Description
Clear description of the proposed feature

## Use Case
Why is this feature needed?

## Proposed Implementation
How should this be implemented?

## Alternatives Considered
What other approaches were considered?

## Additional Context
Any other relevant information
```

### Feature Categories
- **Core Functionality**: Basic robot control improvements
- **Safety Features**: Emergency stops, battery monitoring
- **Performance**: Speed optimization, response time
- **Connectivity**: Enhanced Bluetooth, WiFi support
- **Sensors**: Ultrasonic, gyroscope, camera integration
- **Competition Features**: Autonomous navigation, combat systems

## 🔧 Development Process

### Branching Strategy
- `main`: Stable, tested code
- `develop`: Integration branch for new features
- `feature/feature-name`: Individual feature development
- `bugfix/issue-number`: Bug fixes
- `docs/topic`: Documentation updates

### Commit Message Format
```
type(scope): short description

Longer description if needed

Closes #issue-number
```

**Types**: feat, fix, docs, style, refactor, test, chore

**Examples**:
```
feat(motor): add variable speed control

Add PWM-based speed control with SPEED command.
Supports values from 0-255 for precise control.

Closes #15
```

### Pull Request Process

1. **Create descriptive PR title**
   ```
   feat: Add autonomous navigation with ultrasonic sensors
   fix: Resolve Bluetooth connection timeout issue
   docs: Update assembly guide with safety warnings
   ```

2. **Fill out PR template**
   - Description of changes
   - Testing performed
   - Breaking changes (if any)
   - Screenshots/videos (if applicable)

3. **Code Review Process**
   - At least one review required
   - All tests must pass
   - Documentation must be updated
   - No merge conflicts

4. **Merging**
   - Squash commits for cleaner history
   - Update version numbers if needed
   - Tag releases appropriately

## 📚 Documentation Guidelines

### Documentation Types
- **README**: Project overview and quick start
- **Code Comments**: Inline documentation
- **API Documentation**: Function references
- **Tutorials**: Step-by-step guides
- **Troubleshooting**: Common issues and solutions

### Writing Style
- Use active voice
- Be concise but thorough
- Include practical examples
- Consider different skill levels
- Update when making changes

## 🏆 Recognition

### Contributors
All contributors are recognized in:
- GitHub contributors list
- README acknowledgments section
- Release notes for major contributions

### Contribution Types Recognized
- Code contributions
- Documentation improvements
- Bug reports and testing
- Community support
- Educational content creation

## 📞 Getting Help

### Communication Channels
- **GitHub Issues**: For bugs and feature requests
- **GitHub Discussions**: For questions and ideas
- **Email**: (Add contact email for urgent issues)

### Response Times
- **Bug Reports**: 1-3 days
- **Feature Requests**: 1-7 days
- **Pull Reviews**: 2-5 days
- **Questions**: 1-2 days

## 📄 License

By contributing to this project, you agree that your contributions will be licensed under the MIT License.

## 🙏 Thank You

Every contribution, no matter how small, helps make this project better for the robotics and education community. Thank you for taking the time to contribute!

---

**Questions?** Feel free to open a GitHub issue or reach out to the maintainers.

*Happy coding and building! 🤖*