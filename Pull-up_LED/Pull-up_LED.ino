// Led connected at Pin 5
int ledPin = 5;
// Buttons connected to Pin 9 and 8
int buttonApin = 9;
int buttonBpin = 8;
byte leds = 0;
void setup()
{
  // Set pin modes(Led:output, Switches:Pull up Resistor)
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}
void loop()
{
  // Led on if button A is pressed
  if (digitalRead(buttonApin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  // Led off if button B is pressed
  if (digitalRead(buttonBpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}
