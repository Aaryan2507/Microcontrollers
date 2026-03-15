#include <TM1637Display.h>
#define CLK 2
#define DIO 3
#define BUZZ 4
#define SigPin 5
#define Disp 6
bool alarmDismissed = false;
int i=15;
TM1637Display display(CLK,DIO);
void setup() {
  // put your setup code here, to run once:
display.setBrightness(0x0f);
pinMode(BUZZ,OUTPUT);
pinMode(SigPin,INPUT);
pinMode(Disp, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
if(alarmDismissed){
  digitalWrite(Disp,LOW);
  return;
}
digitalWrite(Disp,HIGH);
for(i;i>0;i--){
  display.showNumberDec(i);
  delay(500);
}
display.showNumberDec(0000);
tone(BUZZ,500);
if(digitalRead(SigPin)==LOW){
  alarmDismissed=true;
  noTone(BUZZ);
  return;
}
}
