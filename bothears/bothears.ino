// Each ear's A0 wire goes to its own Uno pin
const int leftPin = A1;
const int rightPin = A2;

// How big a swing counts as a noise (whole numbers only)
const int quietLevel = 2;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Each ear tracks its own loudest and quietest reading for this window
  int leftHigh = 0;
  int leftLow = 1023;
  int rightHigh = 0;
  int rightLow = 1023;
  unsigned long startTime = millis();  // remembers when this listening window began

  // Listens for 50 milliseconds, reading both ears each time around
  while (millis() - startTime < 50) {
    int leftNow = analogRead(leftPin);
    int rightNow = analogRead(rightPin);

    if (leftNow > leftHigh) leftHigh = leftNow;
    if (leftNow < leftLow) leftLow = leftNow;
    if (rightNow > rightHigh) rightHigh = rightNow;
    if (rightNow < rightLow) rightLow = rightNow;
  }

  // The swing is how big the wiggle was for each ear in this window
  int leftSwing = leftHigh - leftLow;
  int rightSwing = rightHigh - rightLow;

  // The || means "or": runs if either ear heard something louder than quietLevel
  if (leftSwing > quietLevel || rightSwing > quietLevel) {
    // Whichever ear had the bigger swing gets the credit
    if (leftSwing > rightSwing) {
      Serial.println("LEFT");
    } else {
      Serial.println("RIGHT");
    }
  }
}