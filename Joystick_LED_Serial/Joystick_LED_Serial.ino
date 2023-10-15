//connections
#define xPin A0
#define yPin A1
#define KeyPin 8
#define redLED 9
#define blueLED 10
#define yellowLED 11

int xValue, yValue; //reading values
int redX,blueY,yellowZ;//mapped values

void setup() {
  //setting input and output pins
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
  pinMode(KeyPin,INPUT_PULLUP);
  pinMode(redLED,OUTPUT);
  pinMode(blueLED,OUTPUT);
  pinMode(yellowLED,OUTPUT);
  //initializing the serial monitor
  Serial.begin(9600);
}

void loop() {

  Serial.print("X= ");
  xValue=analogRead(xPin);
  Serial.print(xValue,DEC);
  redX=map(xValue,0,1023,0,255);
  analogWrite(redLED,redX);

  Serial.print(" |Y= ");
  yValue=analogRead(yPin);
  Serial.print(yValue,DEC);
  blueY=map(yValue,0,1023,0,255);
  analogWrite(blueLED,blueY);

  Serial.print(" |Z= ");
  yellowZ=digitalRead(KeyPin);
  digitalWrite(yellowLED,!yellowZ);
  Serial.println(yellowZ);
  delay(50);
}
