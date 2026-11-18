// The Uno pin the light sensor's S wire is plugged into
const int lightPin = A0;

// Readings above this number count as "dark" (remember: bigger = darker)
const int darkLevel = 825;

void setup() {
  Serial.begin(9600);

  // Sets the built-in LED pin as an output so the Uno can turn it on and off
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int lightLevel = analogRead(lightPin);
  Serial.println(lightLevel);

  // Checks the condition in the parentheses; runs the first block if true, the else block if not
  if (lightLevel > darkLevel) {
    digitalWrite(LED_BUILTIN, HIGH);  // dark, so turn the LED on
  } else {
    digitalWrite(LED_BUILTIN, LOW);   // light, so turn the LED off
  }

  delay(50);
}