#include <Adafruit_GFX.h>    
#include<Adafruit_ST7735.h>
#include <SPI.h>
// | Value | Orientation                   |
// | ----- | ----------------------------- |
// | 0     | Portrait (default)            |
// | 1     | Landscape (clockwise)         |
// | 2     | Portrait (upside down)        |
// | 3     | Landscape (counter-clockwise) |
// tft.initR(INITR_BLACKTAB);
// tft.setRotation(1); // rotate display



// Pin definitions for ESP32
#define TFT_CS     5
#define TFT_RST   15
#define TFT_DC    32
#define TFT_MOSI  23
#define TFT_CLK   18
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_CLK, TFT_RST);

void setup() {
  Serial.begin(115200);
  Serial.println("DHTxx test!");
  tft.initR(INITR_BLACKTAB); // For 1.8" TFT with black tab
  tft.fillScreen(ST77XX_BLACK);
 tft.setRotation(1);
  tft.setCursor(45, 60);             // Set position on screen
  tft.setTextColor(ST77XX_BLUE);    // Text color
  tft.setTextSize(2);                // Scale text size
  tft.println("Hello");

  tft.fillScreen(ST77XX_BLACK);
  tft.drawTriangle(30, 30, 60, 90, 90, 30, ST77XX_GREEN);

       // Print text
       
}

void loop() {
 
   for (int x = 0; x < 128; x += 2) { // Move from left to right
    tft.fillScreen(ST77XX_BLACK);   // Clear screen

    // Draw triangle at new position
    tft.fillTriangle(x, 50, x + 15, 80, x + 50, 50, ST77XX_RED);

    delay(50);
}
}
