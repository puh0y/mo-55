const int soundPin = A1;

// How big a swing counts as a noise
const int quietLevel = 0.4;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int highest = 0;      // loudest reading so far (starts at the bottom so any reading beats it)
  int lowest = 1023;    // quietest reading so far (starts at the top so any reading beats it)
  unsigned long startTime = millis();  // remembers when this listening window began

  // Keeps taking readings until 50 milliseconds have passed
  while (millis() - startTime < 50) {
    int soundLevel = analogRead(soundPin);
    if (soundLevel > highest) highest = soundLevel;  // new loudest? remember it
    if (soundLevel < lowest) lowest = soundLevel;    // new quietest? remember it
  }

  int swing = highest - lowest;  // how big the wiggle was in this window

  // Only prints when the swing is bigger than quietLevel
  if (swing > quietLevel) {
    Serial.println(swing);
  }
}