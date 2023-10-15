#define dataPin 8
#define latchPin 10
#define clockPin 11
//initialize an Array of the numbers 0-9
int dataArray[10]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6};
void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  for (int index=0; index<10; index++){
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,MSBFIRST,dataArray[index]);
    digitalWrite(latchPin,HIGH);
    delay(1000);
  }
}
