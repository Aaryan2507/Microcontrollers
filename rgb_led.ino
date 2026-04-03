int bluePin = 3;
int greenPin = 4;
int redPin = 5;

void setup() {
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(redPin, OUTPUT);
}

void loop() {
  // Red
  analogWrite(redPin, 255);
  digitalWrite(greenPin, LOW);
  analogWrite(bluePin, 0);
  delay(1000);

  // Green
  analogWrite(redPin, 0);
  digitalWrite(greenPin, HIGH);
  analogWrite(bluePin, 0);
  delay(1000);

  // Blue
  analogWrite(redPin, 0);
  digitalWrite(greenPin, LOW);
  analogWrite(bluePin, 255);
  delay(1000);

  // Yellow = Red + Green
  analogWrite(redPin, 255);
  digitalWrite(greenPin, HIGH);
  analogWrite(bluePin, 0);
  delay(1000);

  // Magenta = Red + Blue
  analogWrite(redPin, 255);
  digitalWrite(greenPin, LOW);
  analogWrite(bluePin, 255);
  delay(1000);

  // Cyan = Green + Blue
  analogWrite(redPin, 0);
  digitalWrite(greenPin, HIGH);
  analogWrite(bluePin, 255);
  delay(1000);

  // White
  analogWrite(redPin, 255);
  digitalWrite(greenPin, HIGH);
  analogWrite(bluePin, 255);
  delay(1000);

  // Off
  analogWrite(redPin, 0);
  digitalWrite(greenPin, LOW);
  analogWrite(bluePin, 0);
  delay(1000);
}
