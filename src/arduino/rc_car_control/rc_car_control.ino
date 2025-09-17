/****************************************************************
Arduino Baud rate: 9600. Works for "Bluetooth RC Controller" app.
App transmission Codes: L(Left), R(Right), F(Forward), B(Backward), I(Forward right), G (Forward left), J(Backward right), H(Backward left),
V(Horn On), v(Horn off), s(Nothing Pressed).

Author: Ankit Kumar Yadav (INDIA)
Date: 16th SEP 2024.
*****************************************************************/


/********************** CODE STARTS: ***********************/
char t;                      // Stores current command.
char previousCommand = ' ';  // Stores last command.

//One time setup.         
void setup() {                
  pinMode(2, OUTPUT);        // Left motors forward pin (Set it high to execute left motors forward movement).
  pinMode(4, OUTPUT);        // Left motors reverse pin
  pinMode(7, OUTPUT);        // Right motors forward pin
  pinMode(8, OUTPUT);        // Right motors reverse pin
  pinMode(9,OUTPUT);         //Horn +
  pinMode(10, OUTPUT);       //Horn -
  digitalWrite(10, LOW);     //Remains always low (horn negative).
  Serial.begin(9600);
}

//Runs in loop repeatedly.
void loop() {
  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t); //For debugging (serial monitor).

    // Act only if the current command is different from the previous one.
    if (t != previousCommand) {
      previousCommand = t;  // Update the last command.

      //Reset all motors first, to avoid overlapping movement commands.
      digitalWrite(2, LOW);
      digitalWrite(4, LOW);
      digitalWrite(7, LOW);
      digitalWrite(8, LOW);

      if (t == 'F') {       // Move forward.
        digitalWrite(2, HIGH);
        digitalWrite(7, HIGH);
      } 
      else if (t == 'B') {  // Move reverse.
        digitalWrite(4, HIGH);
        digitalWrite(8, HIGH);
      }
      else if (t == 'I'){   // Move Forward-Right
        digitalWrite(2,HIGH);
      }
      else if (t == 'G'){   // Move Forward-Left
        digitalWrite(7,HIGH);
      }
      else if (t == 'J'){   // Move Backward-Right
        digitalWrite(4,HIGH);
      }
      else if (t == 'H'){   // Move Backward-Left
        digitalWrite(8,HIGH);
      }
      else if (t == 'L') {   // Spin Left.
        digitalWrite(7, HIGH);
        digitalWrite(4,HIGH);
      }
      else if (t == 'R') {   // Spin Right.
        digitalWrite(2, HIGH);
        digitalWrite(8,HIGH);
      }
      else if (t == 'V') {   // Horn On.
        digitalWrite(9, HIGH);
      }
      else if (t == 'v') {   // Horn Off.
        digitalWrite(9, LOW);
      }
      // 's' = Nothing Pressed -> all LOW already.
    }
  } 
}
