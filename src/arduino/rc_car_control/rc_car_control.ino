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
 * Project: Robowar RC Car
 * Version: 1.0
 */

char t;
char previousCommand = ' ';  // Store the last command

void setup() {
  pinMode(2, OUTPUT);   // Left motors forward
  pinMode(4, OUTPUT);   // Left motors reverse
  pinMode(7, OUTPUT);   // Right motors forward
  pinMode(8, OUTPUT);   // Right motors reverse
  pinMode(9,OUTPUT);
  //horn+
  pinMode(10, OUTPUT);
  //horn-
  digitalWrite(10, LOW);
  //always low, horn negative.
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);

    // Only act if the current command is different from the previous one
    if (t != previousCommand) {
      previousCommand = t;  // Update the last command

      // Reset all motors first to avoid overlapping movement commands
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);
      
      

      if (t == 'F') {        // Move forward
        digitalWrite(2, HIGH);
        digitalWrite(7, HIGH);
      } 
      else if (t == 'B') {   // Move reverse
        digitalWrite(4, HIGH);
        digitalWrite(8, HIGH);
      }
      else if (t == 'L') {   // Turn right
        digitalWrite(7, HIGH);
        digitalWrite(4,HIGH);
                
      }
      else if (t == 'R') {   // Turn left
        digitalWrite(2, HIGH);
        digitalWrite(8,HIGH);
      }
      else if (t == 'V') {   // Turn left
        digitalWrite(9, HIGH);
      }
      else if (t == 'v') {   // Turn left
        digitalWrite(9, LOW);
      }
      // The stop command is not needed since the motors are reset to LOW
    }
  } 
 // else {
    // If no serial command is available, stop all motors
  //  digitalWrite(2, LOW);
  //  digitalWrite(4, LOW);
  // digitalWrite(7, LOW);
 // //  digitalWrite(8, LOW);
}
