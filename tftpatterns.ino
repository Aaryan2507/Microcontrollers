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
  randomSeed(analogRead(0)); //This fn seeds random values 
  tft.setTextColor(ST7735_WHITE);
  tft.print("PATTERNS!!");
}
void loop() {
  // put your main code here, to run:
  int x= random(0,tft.width());
  int y =random(15,tft.height());
  int w =random(10,40);
  int h =random(10,40);
  int r =random(5,20);

  uint16_t color=random(0xFFFF);
  int shapeType =random(0,4);
  switch(shapeType){
    case 0:
      tft.fillRect(x,y,w,h,color);
      break;
    case 1:
      tft.drawCircle(x,y,r,color);
      break;
    case 2:
      tft.fillTriangle(x,y,x+w,y,x+(w/2),y+h,color);
      break;
    case 3:
      tft.drawLine(x,y,x+w,y+h,color);
      break; 
  }
  delay(1000);

  static int framecount=0;
  framecount++;
  if(framecount>50){
    tft.fillRect(0,15,160,128,ST7735_CYAN);
    framecount=0;
  }
}
