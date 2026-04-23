#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1 // Reset pin not used with I2C

Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
void text(int i){
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,10);
  display.println("Kitte Marks?:");
  display.println(i);
  delay(500);
  display.display();
}
void setup() {
  Serial.begin(9600);
  Serial.println("SH1106 OLED Test");

  if(!display.begin(0x3C, true)) { // Address 0x3C for most modules
    Serial.println("SH1106 allocation failed");
    for(;;);
  }

  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(0,10);
  display.println("Hi, nice to meet u");
  display.display();
}

void loop() {
  for(int i=0;i<30;i++){
    text(i);
  };
}
