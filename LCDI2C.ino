#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Try 0x27 first. If it does not work, change to 0x3F.
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();         // Initialize LCD
  lcd.backlight();    // Turn on backlight
  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Betichod");
}

void loop() {
}
