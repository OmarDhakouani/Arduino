// Define Pins
#define RED 9
#define GREEN 10
#define BLUE 11
#define delayTime 10 // fading time between colors
void setup()
{
  // Set the pins to output
  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
}
// define variables
int redValue;
int greenValue;
int blueValue;
// main loop
void loop()
  {
  // Set Red as the starting colour
  redValue = 255; 
  greenValue = 0;
  blueValue = 0;
  for (int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
    redValue -= 1;
    greenValue += 1;
    analogWrite(RED, redValue);
    analogWrite(GREEN, greenValue);
    delay(delayTime);
  }
  redValue = 0;
  greenValue = 255;
  blueValue = 0;
  for (int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    analogWrite(GREEN, greenValue);
    analogWrite(BLUE, blueValue);
    delay(delayTime);
  }
  redValue = 0;
  greenValue = 0;
  blueValue = 255;
  for (int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
  {
    blueValue -= 1;
    redValue += 1;
    analogWrite(BLUE, blueValue);
    analogWrite(RED, redValue);
    delay(delayTime);
  }
}