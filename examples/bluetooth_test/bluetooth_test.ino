/*
 * HC-05 Bluetooth Test Sketch
 * 
 * This sketch tests the HC-05 Bluetooth module connectivity
 * Use this to verify Bluetooth communication before full assembly
 * 
 * Author: Ankit Kumar Yadav
 * Version: 1.0
 */

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  Serial.println("HC-05 Bluetooth Test");
  Serial.println("Waiting for Bluetooth connection...");
  Serial.println("Pair your device with HC-05 (PIN: 1234)");
  Serial.println("Send any message to test communication");
}

void loop() {
  // Check for incoming Bluetooth data
  if (Serial.available()) {
    String receivedData = Serial.readString();
    receivedData.trim();
    
    Serial.println("Received: " + receivedData);
    
    // Echo back the received data
    Serial.println("Echo: " + receivedData);
    
    // Test specific commands
    if (receivedData == "TEST") {
      Serial.println("Bluetooth communication test successful!");
    }
    else if (receivedData == "STATUS") {
      Serial.println("HC-05 Status: Connected and functional");
    }
    else if (receivedData == "RANGE") {
      Serial.println("Testing communication range...");
      for (int i = 1; i <= 10; i++) {
        Serial.println("Range test " + String(i) + "/10");
        delay(1000);
      }
      Serial.println("Range test complete");
    }
    else {
      Serial.println("Available commands: TEST, STATUS, RANGE");
    }
  }
  
  // Send periodic status updates
  static unsigned long lastUpdate = 0;
  if (millis() - lastUpdate > 10000) { // Every 10 seconds
    lastUpdate = millis();
    Serial.println("HC-05 Status: Active - " + String(millis()/1000) + "s uptime");
  }
}