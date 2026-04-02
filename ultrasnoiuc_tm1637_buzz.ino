#include <TM1637Display.h>
int i=20;
int CLK=4;
int DIO=3;
int Trig=7;
int Echo=6;
int buzz=5;
TM1637Display display(CLK,DIO);
void setup() {
  // put your setup code here, to run once:
display.setBrightness(0x0f);
pinMode(Trig,OUTPUT);
pinMode(Echo,INPUT);
pinMode(buzz,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(Trig,LOW);
delayMicroseconds(10);
digitalWrite(Trig,HIGH);
delayMicroseconds(10);
digitalWrite(Trig,LOW);
long duration=pulseIn(Echo,HIGH);
float dist=(duration*0.0343)/2;
Serial.print("Distance:");
Serial.println(dist);
delay(100);
if(dist>20){
  for(i;i>0;i--){
    display.showNumberDec(i);
    delay(300);
    tone(buzz,1000);
    if(dist<20){
      noTone(buzz);
      break;
    }
  };
}
}
