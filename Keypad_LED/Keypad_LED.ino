#include <Keypad.h>
#define Red 10
#define Yellow 11
#define Blue 12
 
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

void setup(){
  Serial.begin(9600);
  pinMode(Red,OUTPUT);
  pinMode(Yellow,OUTPUT);
  pinMode(Blue,OUTPUT);

}
  
void loop(){
  char key = keypad.getKey();
  
  if (key){
    Serial.println(key);
    switch(key){
      case '1':
        digitalWrite(Red,HIGH);
        delay(1000);
        break;
      case '2':
        digitalWrite(Yellow,HIGH);
        delay(1000);
        break;
      case '3':
        digitalWrite(Blue,HIGH);
        delay(1000);
        break;
      case '0':
        digitalWrite(Red,LOW);
        digitalWrite(Yellow,LOW);
        digitalWrite(Blue,LOW);
        delay(1000);
        break;
    }
  }
}
