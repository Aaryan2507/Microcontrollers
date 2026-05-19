int buzzer = 9; // set the buzzer control digital IO pin

void setup() {
  pinMode(buzzer, OUTPUT); // set pin 8 as output
}

void loop() {
  for (int i = 0; i < 25; i++) {  // make a sound
  analogWrite(buzzer,i*10);
  delay(20);
}}
