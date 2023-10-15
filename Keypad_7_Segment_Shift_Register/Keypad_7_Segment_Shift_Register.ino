#include <Keypad.h>
#define dataPin 10
#define latchPin 11
#define clockPin 12
//initialize an Array of the numbers 0-9
int dataArray[14]={0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,0xFE,0xF6,0xEE,0xFE,0x9C,0xFC};
const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );
void setup() {
  // put your setup code here, to run once:
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  Serial.begin(9600);
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,MSBFIRST,dataArray[0]);
  digitalWrite(latchPin,HIGH);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = keypad.getKey();

  if (key){
    Serial.println(key);
    switch(key){
      case '0':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[0]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '1':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[1]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '2':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[2]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '3':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[3]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '4':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[4]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '5':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[5]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '6':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[6]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '7':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[7]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '8':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[8]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case '9':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[9]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case 'A':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[10]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case 'B':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[11]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case 'C':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[12]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;
      case 'D':
        digitalWrite(latchPin,LOW);
        shiftOut(dataPin,clockPin,MSBFIRST,dataArray[13]);
        digitalWrite(latchPin,HIGH);
        delay(1000);
        break;

    }
  }
}
