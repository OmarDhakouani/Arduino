int buzzer = 2;//the pin of the active buzzer
void setup()
{
pinMode(buzzer, OUTPUT);
}
void loop()
{
  for (int i = 0; i < 120; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
    delay(1);
  }
  delay(200);
  for (int i = 0; i < 120; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
    delay(1);
  }
  delay(200);
  for (int i = 0; i < 60; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
    delay(1);
  }
  delay(100);
    for (int i = 0; i < 60; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
    delay(1);
  }
  delay(100);
    for (int i = 0; i < 120; i++)
  {
    digitalWrite(buzzer, HIGH);
    delay(1);
    digitalWrite(buzzer, LOW);
    delay(1);
  }
  delay(200);
}
