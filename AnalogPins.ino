int redPin=9;
void setup() {
  // put your setup code here, to run once:
  pinMode(redPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(redPin,HIGH);
  analogWrite(redPin,255);
  //delay(1000);
  //analogWrite(redPin,128);
  //delay(1000);


}
