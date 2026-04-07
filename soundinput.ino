const int aoPin = A0;     // Analog output from sensor
const int ledPin = 13;    // Built-in LED
const int threshold = 30; // Trigger level

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int soundLevel = analogRead(aoPin);

  Serial.println(soundLevel);

  if (soundLevel > threshold) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }

  delay(50);
}
