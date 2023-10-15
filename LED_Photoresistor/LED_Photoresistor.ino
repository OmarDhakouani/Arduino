#define LED 9
#define Photoresistor A0
int sensorValue,outputValue;
void setup() {
  //set pin modes and initialize serial port
  pinMode(LED,OUTPUT);
  pinMode(Photoresistor,INPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue=analogRead(Photoresistor);//read sensor value 
  outputValue=map(sensorValue,0,1023,0,255);//map ADC Value to PWM 
  constrain(outputValue,0,255);//calibrate output
  analogWrite(LED,outputValue);//output to LED

  //write results to serial port 
  Serial.print("Photoresistor Value : ");
  Serial.print(sensorValue);
  Serial.print(" |LED Value : ");
  Serial.println(outputValue);

  delay(500);
  
}
