const int pinA2 = 16;  // A2 is also digital pin 16 on Arduino Uno

void setup() {
  // initialize the A2 pin as an output.
  pinMode(pinA2, OUTPUT);
}

void loop() {
  // LED ON 
  digitalWrite(pinA2, HIGH);
  delay(1000);
  // LED OFF
  digitalWrite(pinA2, LOW);
  delay(1000);
}