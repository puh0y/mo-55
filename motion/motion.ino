// The Uno pin the PIR's OUT wire is plugged into
const int pirPin = 8;
const int ledPin = 7;    // the same check LED as before

void setup() {
  Serial.begin(9600);
  pinMode(pirPin, INPUT);   // the PIR sends a signal in, so it's an input
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // The PIR output is HIGH while it sees motion and LOW when it doesn't
  if (digitalRead(pirPin) == HIGH) {
    digitalWrite(ledPin, HIGH);   // motion, so the LED turns on
    Serial.println("motion");
  } else {
    digitalWrite(ledPin, LOW);    // no motion, so the LED turns off
    Serial.println("quiet");
  }

  delay(200);  // checks five times a second
}