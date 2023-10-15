#include <Stepper.h>

#define stepsPerRevolution 2048

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(32, 8, 10, 9, 11);

void setup() {
  myStepper.setSpeed(300);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
}

