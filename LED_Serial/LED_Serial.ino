#define LED 8
int counter=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  Serial.println("");
}

void loop() {
  // put your main code here, to run repeatedly:
  counter = counter + 10;
  Serial.print("Blink number # ");
  Serial.println(counter);
  digitalWrite(LED,HIGH);
  delay(1000-counter);
  digitalWrite(LED,LOW);
  delay(500-counter);
}
