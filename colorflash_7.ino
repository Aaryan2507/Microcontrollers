int laserPin = 8;  // Signal pin

void setup() {
  pinMode(laserPin, OUTPUT);
}

void loop() {
  digitalWrite(laserPin, HIGH);  // Laser ON
  delay(1000);
  digitalWrite(laserPin, LOW);   // Laser OFF
  delay(1000);
}
