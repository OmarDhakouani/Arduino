#include <Stepper.h>
#define sensorPin A0
Stepper myStepper(32,2,4,3,5);
int sensorValue,motorSpeed;//LDR value and motor speed
int direction=32;//clockwise, 32 steps/revolution
  
void setup() {
  Serial.begin(9600);//initialize serial port
  pinMode(sensorPin,INPUT);//sensor as input
  analogReference(DEFAULT);//ADC reference to 5V
}

void loop() {
  sensorValue=analogRead(sensorPin);//read the sensor value
  Serial.print("LDR Values = ");
  Serial.print(sensorValue);//print value

  motorSpeed=map(sensorValue,0,1023,0,1000);
  Serial.print(" | Motor Speed is = ");
  Serial.println(motorSpeed);//print speed
  myStepper.setSpeed(motorSpeed);//set motor speed
  myStepper.step(direction);

}
