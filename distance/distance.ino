// The Uno pins the sensor's Trig and Echo wires are plugged into
const int trigPin = 9;  // Uno sends the ping out on this pin
const int echoPin = 10;  // Uno listens for the echo on this pin
const int ledPin = 7;      // LED that lights up when something is close

// Anything closer than this many centimeters counts as "close"
const int closeLevel = 350;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);  // trig sends a signal, so it's an output
  pinMode(echoPin, INPUT);   // echo receives one, so it's an input
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Sends a short burst of sound: low, then high for 10 microseconds, then low
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measures how many microseconds the echo takes to come back
  long duration = pulseIn(echoPin, HIGH, 30000);

  // Sound travels about 0.034 cm per microsecond; divide by 2 because it goes there and back
  int distance = duration * 0.034 / 2;

  Serial.println(distance);

  // A reading of 0 means no echo came back, so ignore it
  if (distance > 0 && distance < closeLevel) {
    digitalWrite(ledPin, HIGH);  // something is close, so the LED turns on
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(50);
}
