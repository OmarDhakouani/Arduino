#include <Stepper.h>
#define xPin A0
#define yPin A1
#define KeyPin 8
Stepper myStepper(32,2,4,3,5);//stepper motor sequence 1-3-2-4
int direction;
int xValue,yValue;
  
void setup() {
  Serial.begin(9600);//initialize serial port
  pinMode(KeyPin,INPUT_PULLUP);//Keypin as Input
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);
}

void loop() {
  xValue=analogRead(xPin);
  int motorSpeed=0;
  if(xValue>=520){
    motorSpeed=map(xValue,520,1023,0,1000);
    direction=1;
  }
  if(xValue<510){
    motorSpeed=map(xValue,0,510,1000,0);
    direction=-1;
  }
  if(motorSpeed>0){
    myStepper.setSpeed(motorSpeed);
    myStepper.step(direction);
  }
}