int melody[] = {
523, 587, 659, 698, 784, 880, 988, 1047};
int duration = 500; // 500 miliseconds
void setup() {
}
void loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    // pin8 output the sound, every scale is 0.5 sencond
    tone(8, melody[thisNote], duration);
    delay(1000);
}
  // restart after two seconds
  delay(2000);
}
