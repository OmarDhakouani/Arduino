#include <SimpleDHT.h>
// for DHT11,
// VCC: 5V or 3V
// GND: GND
// DATA: 2
int pinDHT11 = 8;
SimpleDHT11 dht11;
void setup() {
  //declare Baud Rate for the serial communication
  Serial.begin(9600);
}
void loop() {
  // start working...
  Serial.println("=================================");
  Serial.println("Sample DHT11...");
  byte temperature = 0;
  byte humidity = 0;
  byte data[40] = {0};
  // Check if the sensor is working
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    Serial.print("Read DHT11 failed");
    return;
  }
  // Print the received digital data
  Serial.print("Sample RAW Bits: ");
  for (int i = 0; i < 40; i++) {
    Serial.print((int)data[i]);
    if (i > 0 && ((i + 1) % 4) == 0) {
      Serial.print(' ');
    }
  }
  // Print the decimal values
  Serial.println("");
  Serial.print("Sample OK: ");
  Serial.print((int)temperature); Serial.print(" °C, ");
  Serial.print((int)humidity); Serial.println(" %");
  delay(1000);
}
