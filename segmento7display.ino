const byte segPins[7] = {2, 3, 4, 5, 6, 7, 8}; // a, b, c, d, e, f, g

const byte digits[10][7] = {
  // a, b, c, d, e, f, g
  {LOW, LOW, LOW, LOW, LOW, LOW, HIGH},   // 0
  {HIGH, LOW, LOW, HIGH, HIGH, HIGH, HIGH}, // 1
  {LOW, LOW, HIGH, LOW, LOW, HIGH, LOW},  // 2
  {LOW, LOW, LOW, LOW, HIGH, HIGH, LOW},  // 3
  {HIGH, LOW, LOW, HIGH, HIGH, LOW, LOW}, // 4
  {LOW, HIGH, LOW, LOW, HIGH, LOW, LOW},  // 5
  {LOW, HIGH, LOW, LOW, LOW, LOW, LOW},   // 6
  {LOW, LOW, LOW, HIGH, HIGH, HIGH, HIGH},// 7
  {LOW, LOW, LOW, LOW, LOW, LOW, LOW},    // 8
  {LOW, LOW, LOW, LOW, HIGH, LOW, LOW}    // 9
};

void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segPins[i], OUTPUT);
    digitalWrite(segPins[i], HIGH); // off for common anode
  }
}

void showDigit(byte n) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segPins[i], digits[n][i]);
  }
}

void loop() {
  for (byte n = 0; n <= 9; n++) {
    showDigit(n);
    delay(1000);
  }
}
