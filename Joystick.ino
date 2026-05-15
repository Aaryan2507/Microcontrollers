const int VRX_PIN = A4;
const int VRY_PIN = A3;
const int SW_PIN  = A2;

void setup() {
  Serial.begin(9600);

  pinMode(SW_PIN, INPUT_PULLUP);  
}

void loop() {
  int xValue = analogRead(VRX_PIN);
  int yValue = analogRead(VRY_PIN);
  int buttonState = digitalRead(SW_PIN);

  Serial.print("X = ");
  Serial.print(xValue);

  Serial.print(" | Y = ");
  Serial.print(yValue);

  Serial.print(" | Button = ");
  if (buttonState == LOW) {
    Serial.println("PRESSED");
  } else {
    Serial.println("RELEASED");
  }

  delay(100);
}
