/*
 * RC Robocar - Basic Test Sketch
 * 
 * This sketch provides basic motor testing functionality
 * Use this to verify motor connections and basic operation
 * 
 * Author: Ankit Kumar Yadav
 * Version: 1.0
 */

// Motor pins
const int motor1Pin1 = 2;
const int motor1Pin2 = 3;
const int motor2Pin1 = 4;
const int motor2Pin2 = 5;
const int enableA = 9;
const int enableB = 10;

void setup() {
  Serial.begin(9600);
  
  // Initialize motor pins
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  
  Serial.println("RC Robocar Motor Test");
  Serial.println("Commands: 1=Motor A Forward, 2=Motor A Reverse");
  Serial.println("          3=Motor B Forward, 4=Motor B Reverse");
  Serial.println("          0=Stop All Motors");
}

void loop() {
  if (Serial.available()) {
    char command = Serial.read();
    
    switch(command) {
      case '1':
        testMotorA(true);
        Serial.println("Motor A Forward");
        break;
      case '2':
        testMotorA(false);
        Serial.println("Motor A Reverse");
        break;
      case '3':
        testMotorB(true);
        Serial.println("Motor B Forward");
        break;
      case '4':
        testMotorB(false);
        Serial.println("Motor B Reverse");
        break;
      case '0':
        stopAllMotors();
        Serial.println("All Motors Stopped");
        break;
      default:
        Serial.println("Invalid command");
    }
  }
}

void testMotorA(bool forward) {
  if (forward) {
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
  } else {
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
  }
  analogWrite(enableA, 150); // 50% speed for testing
}

void testMotorB(bool forward) {
  if (forward) {
    digitalWrite(motor2Pin1, HIGH);
    digitalWrite(motor2Pin2, LOW);
  } else {
    digitalWrite(motor2Pin1, LOW);
    digitalWrite(motor2Pin2, HIGH);
  }
  analogWrite(enableB, 150); // 50% speed for testing
}

void stopAllMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enableA, 0);
  analogWrite(enableB, 0);
}