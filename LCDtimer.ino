#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

unsigned long previousMillis = 0;
int totalSeconds = 20;   // countdown start value

void showTime(int secs) {
  int minutes = secs / 60;
  int seconds = secs % 60;

  lcd.setCursor(0, 0);
  lcd.print("Countdown");

  lcd.setCursor(0, 1);
  if (minutes < 10) lcd.print("0");
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) lcd.print("0");
  lcd.print(seconds);
  lcd.print("        ");   // erase leftover chars
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  showTime(totalSeconds);
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;

    if (totalSeconds > 0) {
      totalSeconds--;
      showTime(totalSeconds);
    } else {
      lcd.setCursor(0, 1);
      lcd.print("Done!           ");
    }
  }
}
