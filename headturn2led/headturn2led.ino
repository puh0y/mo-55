#include <Servo.h>   // the servo library that comes with the IDE

Servo headServo;     // the servo object we send commands to

const int servoPin = 6;   // servo signal (yellow) wire
const int ledLeft = 7;    // lights when the servo turns left
const int ledRight = 5;   // lights when the servo turns right

// Angle for the left position in degrees (try 20)
const int leftAngle = 180;
// The right angle is the mirror image of the left one
const int rightAngle = 180 - leftAngle;

void setup() {
  headServo.attach(servoPin);
  pinMode(ledLeft, OUTPUT);
  pinMode(ledRight, OUTPUT);
}

void loop() {
  headServo.write(leftAngle);      // turn to the left side
  digitalWrite(ledLeft, HIGH);     // left LED on
  digitalWrite(ledRight, LOW);     // right LED off
  delay(1000);

  headServo.write(90);             // back to center
  digitalWrite(ledLeft, LOW);      // both LEDs off at center
  digitalWrite(ledRight, LOW);
  delay(1000);

  headServo.write(rightAngle);     // turn to the right side
  digitalWrite(ledLeft, LOW);      // left LED off
  digitalWrite(ledRight, HIGH);    // right LED on
  delay(1000);

  headServo.write(90);             // back to center
  digitalWrite(ledLeft, LOW);
  digitalWrite(ledRight, LOW);
  delay(1000);
}