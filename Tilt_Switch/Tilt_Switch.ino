#define tilt 2
#define LedPin 5
void setup()
{
  pinMode(LedPin,OUTPUT);
  pinMode(tilt,INPUT_PULLUP);
}
void loop()
{
  if(digitalRead(tilt)==HIGH)
  {
    digitalWrite(LedPin,LOW);//turn the led off
  }
  else
  {
    digitalWrite(LedPin,HIGH);//turn the led on
  }
}
