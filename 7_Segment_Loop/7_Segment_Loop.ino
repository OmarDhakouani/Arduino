const int NUM_LEDS = 7;
int ledPins[NUM_LEDS] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  for (int i = 0; i < NUM_LEDS; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  //initialize at 0
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], LOW);
  }  
  delay(1000);
  for (int i = 0; i < NUM_LEDS; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(1000);
    digitalWrite(ledPins[i], LOW);
    delay(1000);
  }  
  delay(1000);

}