const int pirPin = 8;      // PIR signal wire
const int buzzerPin = 11;  // passive buzzer signal wire
const int ledPin = 7;      // check LED

// The pitch of the high "hello" note in hertz
const int helloPitch = 800;

// Remembers whether the PIR saw motion on the previous pass through loop()
bool wasMoving = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // true while the PIR output is HIGH, false when it's LOW
  bool moving = (digitalRead(pirPin) == HIGH);

  // Chirps only at the moment motion STARTS (moving now, but wasn't before)
  if (moving && !wasMoving) {
    tone(buzzerPin, 600, 80);         // low blip
    delay(120);
    tone(buzzerPin, helloPitch, 120); // high note
  }

  if (moving) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  wasMoving = moving;  // saves this pass's answer for the next pass
  delay(50);
}