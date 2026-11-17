// MO-55 heartbeat: a "thump-thump" pause pattern

const int LED_PIN = 13;   // pin the LED is on (13 = the small built-in LED on the Uno)

void setup() {            // setup() runs once when the board powers on
  pinMode(LED_PIN, OUTPUT);   // tell the board this pin sends power out
}

void loop() {             // loop() repeats forever
  digitalWrite(LED_PIN, HIGH);  // LED on
  delay(200);                   // wait 200 ms (delay takes milliseconds)

  digitalWrite(LED_PIN, LOW);   // LED off
  delay(100);                   // short gap between the two thumps

  digitalWrite(LED_PIN, HIGH);  // second thump, on
  delay(300);                   // held a bit longer

  digitalWrite(LED_PIN, LOW);   // off for the long rest
  delay(700);                  // 0.7 second pause, then loop() starts over
}