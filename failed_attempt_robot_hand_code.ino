#include <Servo.h>

Servo whiteservo;
Servo blackservo;

int whiteservopin = 3;
int blackservopin = 4;

// Joystick pins
int xPin = A1; // X-axis controls the white servo
int yPin = A2; // Y-axis controls the black servo

int xVal;
int yVal;
float whiteangle;
float blackangle;

void setup() {
  Serial.begin(9600);
  
  whiteservo.attach(whiteservopin);
  blackservo.attach(blackservopin);
}

void loop() {
  // Read the joystick values (0 to 1023)
  xVal = analogRead(xPin);
  yVal = analogRead(yPin);
  
  // Calculate angles using the linear equation: y = mx + c (m = 180.0 / 1023.0, c = 0)
  whiteangle = (180.0 / 1023.0) * xVal;
  blackangle = (180.0 / 1023.0) * yVal;
  
  // Constrain to ensure values stay safely within 0° to 180°
  whiteangle = constrain(whiteangle, 0, 180);
  blackangle = constrain(blackangle, 0, 180);
  
  // Send the calculated angles to the servos
  whiteservo.write((int)whiteangle);
  blackservo.write((int)blackangle);
  
  // Small delay for stability
  delay(20);
}
