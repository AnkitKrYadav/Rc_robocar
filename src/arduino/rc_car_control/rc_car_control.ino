/*
 * RC Robocar Control System
 * 
 * This Arduino sketch controls an RC car for robowar competitions using:
 * - Arduino Uno/Nano
 * - L298N Motor Driver
 * - HC-05 Bluetooth Module
 * - 18650 Battery Pack
 * 
 * Author: Ankit Kumar Yadav
 * Project: University Robowar RC Car
 * Version: 1.0
 */

// Pin definitions for L298N Motor Driver
const int motor1Pin1 = 2;  // Motor A direction pin 1
const int motor1Pin2 = 3;  // Motor A direction pin 2
const int motor2Pin1 = 4;  // Motor B direction pin 1
const int motor2Pin2 = 5;  // Motor B direction pin 2
const int enableA = 9;     // Motor A speed control (PWM)
const int enableB = 10;    // Motor B speed control (PWM)

// LED indicator
const int ledPin = 13;

// Motor speed (0-255)
int motorSpeed = 200;

// HC-05 Bluetooth communication
String command = "";

void setup() {
  // Initialize serial communication for HC-05
  Serial.begin(9600);
  
  // Set motor control pins as outputs
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  pinMode(enableA, OUTPUT);
  pinMode(enableB, OUTPUT);
  
  // Set LED pin as output
  pinMode(ledPin, OUTPUT);
  
  // Initialize motors to stop
  stopMotors();
  
  // Blink LED to indicate ready
  for(int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  
  Serial.println("RC Robocar initialized and ready!");
}

void loop() {
  // Check for Bluetooth commands
  if (Serial.available()) {
    command = Serial.readString();
    command.trim();
    
    // Process commands
    if (command == "F" || command == "FORWARD") {
      moveForward();
      Serial.println("Moving Forward");
    }
    else if (command == "B" || command == "BACKWARD") {
      moveBackward();
      Serial.println("Moving Backward");
    }
    else if (command == "L" || command == "LEFT") {
      turnLeft();
      Serial.println("Turning Left");
    }
    else if (command == "R" || command == "RIGHT") {
      turnRight();
      Serial.println("Turning Right");
    }
    else if (command == "S" || command == "STOP") {
      stopMotors();
      Serial.println("Stopped");
    }
    else if (command.startsWith("SPEED")) {
      // Format: SPEED150 (sets speed to 150)
      int newSpeed = command.substring(5).toInt();
      if (newSpeed >= 0 && newSpeed <= 255) {
        motorSpeed = newSpeed;
        Serial.println("Speed set to: " + String(motorSpeed));
      }
    }
    else {
      Serial.println("Invalid command: " + command);
    }
    
    // Clear command
    command = "";
  }
}

void moveForward() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(ledPin, HIGH);
}

void moveBackward() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(ledPin, HIGH);
}

void turnLeft() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, HIGH);
  digitalWrite(motor2Pin1, HIGH);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(ledPin, HIGH);
}

void turnRight() {
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, HIGH);
  analogWrite(enableA, motorSpeed);
  analogWrite(enableB, motorSpeed);
  digitalWrite(ledPin, HIGH);
}

void stopMotors() {
  digitalWrite(motor1Pin1, LOW);
  digitalWrite(motor1Pin2, LOW);
  digitalWrite(motor2Pin1, LOW);
  digitalWrite(motor2Pin2, LOW);
  analogWrite(enableA, 0);
  analogWrite(enableB, 0);
  digitalWrite(ledPin, LOW);
}