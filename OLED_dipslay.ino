#include <Arduino.h>
#include <Wire.h>
#include <U8g2lib.h>

// Try this first for many 0.91"/0.93" SH1106 modules
U8G2_SH1106_128X32_VISIONOX_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// If the above constructor doesn't compile/work, try this instead:
// U8G2_SH1106_128X32_UNIVISION_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

void drawFlower(int bloom) {
  int cx = 64;   // center x
  int cy = 18;   // flower center y

  // Stem
  u8g2.drawLine(cx, cy + 2, cx, 31);

  // Leaves
  u8g2.drawDisc(cx - 4, 25, 2, U8G2_DRAW_ALL);
  u8g2.drawDisc(cx + 4, 27, 2, U8G2_DRAW_ALL);

  // Flower center
  u8g2.drawDisc(cx, cy, 2, U8G2_DRAW_ALL);

  // Petals bloom outward
  if (bloom > 0) {
    u8g2.drawDisc(cx, cy - bloom, 2, U8G2_DRAW_ALL); // top
    u8g2.drawDisc(cx, cy + bloom, 2, U8G2_DRAW_ALL); // bottom
    u8g2.drawDisc(cx - bloom, cy, 2, U8G2_DRAW_ALL); // left
    u8g2.drawDisc(cx + bloom, cy, 2, U8G2_DRAW_ALL); // right
  }

  if (bloom > 2) {
    u8g2.drawDisc(cx - bloom + 1, cy - bloom + 1, 2, U8G2_DRAW_ALL); // top-left
    u8g2.drawDisc(cx + bloom - 1, cy - bloom + 1, 2, U8G2_DRAW_ALL); // top-right
    u8g2.drawDisc(cx - bloom + 1, cy + bloom - 1, 2, U8G2_DRAW_ALL); // bottom-left
    u8g2.drawDisc(cx + bloom - 1, cy + bloom - 1, 2, U8G2_DRAW_ALL); // bottom-right
  }
}

void setup() {
  u8g2.begin();
}

void loop() {
  // Bloom
  for (int i = 0; i <= 5; i++) {
    u8g2.clearBuffer();
    drawFlower(i);
    u8g2.sendBuffer();
    delay(180);
  }

  // Hold fully bloomed flower
  delay(700);

  // Close slightly
  for (int i = 5; i >= 1; i--) {
    u8g2.clearBuffer();
    drawFlower(i);
    u8g2.sendBuffer();
    delay(120);
  }

  delay(400);
}
