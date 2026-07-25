#include <Adafruit_ST7735.h>
#include <Adafruit_GFX.h>
#include <SPI.h>

#define TFT_CS 5
#define TFT_RST 15
#define TFT_DC 32

Adafruit_ST7735 tft=Adafruit_ST7735(TFT_CS,TFT_DC,TFT_RST);
void setup() {
  // put your setup code here, to run once:
  tft.initR(INITR_BLACKTAB);
  tft.setRotation(1);
  tft.fillScreen(ST7735_BLACK);

  tft.setCursor(20,10);
  tft.setTextColor(ST7735_BLUE);
  tft.setTextSize(1);
  tft.print("Initializing...");
}

void loop() {
  // put your main code here, to run repeatedly:
  tft.setCursor(15,20);
  tft.setTextColor(ST7735_RED,ST7735_BLACK); //(Text color, backgroudn color)
  tft.setTextSize(2);
  tft.print("First line");
  delay(1000);

  tft.setCursor(15,20);
  tft.setTextColor(ST7735_BLUE,ST7735_BLACK); //(Text color, backgroudn color)
  tft.setTextSize(2);
  tft.print("First line");
  delay(1000);

}
