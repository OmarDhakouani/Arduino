#include <Wire.h>
#include <LiquidCrystal_I2C.h>
  //set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27,16,2);
int randNum[26];
void setup() {
  // initialize the lcd
  lcd.init();
  lcd.backlight();

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.setCursor(0,0);
  for(int i=0;i<26;i++){
    randNum[i]=random(9);
    lcd.print(randNum[i]);
    lcd.print("  ");
    delay(250);
  }

}
