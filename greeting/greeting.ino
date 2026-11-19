const int pirPin = 8;
const int trigPin = 9;
const int echoPin = 10;
const int ledPin = 7;
const int buzzerPin = 11;

// Closer than this many centimeters counts as "close" (you used 350 before)
const int closeLevel = 100;

bool wasMoving = false;  // did the PIR see motion on the last pass?
bool wasClose = false;   // was something close on the last pass?

// A function is a named block of code. Calling its name runs everything inside it.
void curiousChirp() {
  tone(buzzerPin, 700, 60);    // three small notes, each higher than the last
  delay(90);
  tone(buzzerPin, 900, 60);
  delay(90);
  tone(buzzerPin, 1200, 120);  // ends high, like a question
  delay(150);
}

void excitedChirp() {
  for (int i = 0; i < 3; i++) {  // repeats the chirp inside the braces 3 times
    tone(buzzerPin, 1300, 50);   // fast, high two-note chirp
    delay(70);
    tone(buzzerPin, 1800, 70);
    delay(110);
  }
}

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Stage 1: the PIR notices someone far away
  bool moving = (digitalRead(pirPin) == HIGH);
  if (moving && !wasMoving) {   // only when motion STARTS, not the whole time
    curiousChirp();
  }
  wasMoving = moving;

  // Stage 2: the ultrasonic notices someone close
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  long duration = pulseIn(echoPin, HIGH, 30000);
  int distance = duration * 0.034 / 2;

  bool isClose = (distance > 0 && distance < closeLevel);
  if (isClose && !wasClose) {   // only at the moment they step into range
    excitedChirp();
  }
  wasClose = isClose;

  // The LED shows whether something is close
  if (isClose) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(50);
}