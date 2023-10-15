//SDA connected to A4
//SCL connected to A5

//include library code
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//sketch settings
#define Button 8
#define LASER_SYMBOL '^'
#define INVADERS "** * ** * ** * "
#define DEBOUNCE_TIME 5

//set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

//invader string
String invaders;

//current laser position
int laserColumn;

//direction flags
bool front, back;

//number of invaders
int numInvaders;

//timer variables
long int timerStart, timerLength, currentTime;

//button debounce variables
int currentReading;
int newReading;

//edge detection variable
int previousReading;
void setup() {

  // initialize the lcd
  lcd.init();
  lcd.backlight();

  // initialize laser position and direction
  laserColumn = 0;
  front = 1;

  //initialize number of invaders
  numInvaders = 9;
  invaders = "** * ** * ** * ";


  //setup laser button
  pinMode(Button, INPUT_PULLUP);

  //initialize timer
  timerStart = millis();
  timerLength = 250;

  //initialize debouncing
  currentReading = HIGH;
}

void loop() {
  while (digitalRead(Button) == HIGH) {
    lcd.setCursor(0, 0);
    lcd.print("Zap invaders");
    lcd.setCursor(0, 1);
    lcd.print("Press Button...");
  }
  delay(500);
  lcd.setCursor(0, 0);
  lcd.print("                ");
  lcd.setCursor(0, 1);
  lcd.print("                ");
  while (numInvaders > 0) {
    currentTime = millis();
    if ((currentTime - timerStart) > timerLength) {

      //reset timer
      timerStart = currentTime;

      //display invaders
      lcd.setCursor(0, 0);
      lcd.print(invaders);

      //erase the old frame
      lcd.setCursor(laserColumn, 1);
      lcd.print(" ");

      //calculate new frame
      if (front)
        laserColumn += 1;
      else if (back)
        laserColumn -= 1;

      //limit the laser column
      if (laserColumn >= 15) {
        front = 0;
        back = 1;
      } else if (laserColumn <= 0) {
        front = 1;
        back = 0;
      }

      //set the cursor to laser position, line 1
      lcd.setCursor(laserColumn, 1);
      lcd.print(LASER_SYMBOL);
    }

    //Save the current reading
    previousReading = currentReading;


    //debounce the button
    currentReading = debounce(Button, currentReading, DEBOUNCE_TIME);

    //check the button and zap invaders
    if (((currentReading == LOW) && (previousReading == HIGH))) {
      if (invaders[laserColumn] == '*') {
        numInvaders -= 1;
        invaders[laserColumn] = '+';
      } 
      else if (invaders[laserColumn] == '+') {
        numInvaders += 1;
        invaders[laserColumn] = '*';
      }
    }
  }

  //initialize number of invaders
  numInvaders = 9;

  //initialize invaders
  invaders = "** * ** * ** * ";
  lcd.setCursor(laserColumn, 1);
  lcd.print(" ");
  lcd.setCursor(0, 0);
  lcd.print("Congratulations");
  lcd.setCursor(0, 1);
  lcd.print(" You won");
  delay(5000);
}

int debounce(int pin, int pinState, int interval) {
  int newValue = digitalRead(pin);
  if (newValue != pinState) {
    delay(interval);
    newValue = digitalRead(Button);
    if (newValue != pinState) {
      pinState = newValue;
    }
  }
  return pinState;
}