#include <Servo.h>
#define servoPin 9
#define Trig 8
#define Echo 7
Servo myServo;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
myServo.attach(servoPin);
pinMode(Trig,OUTPUT);
pinMode(Echo,INPUT);
}
float radar(){
digitalWrite(Trig,LOW);
delayMicroseconds(10);
digitalWrite(Trig,HIGH);
delayMicroseconds(10);
digitalWrite(Trig,LOW);
long duration=pulseIn(Echo,HIGH);
float dist=(duration*0.0343)/2;
return dist;
}
void loop() {
  radar();
  for(int pos=15;pos<=165;pos+=1){
    myServo.write(pos);
    delay(15);
    float dist=radar();
    Serial.print(pos);
    Serial.print(",");
    Serial.print(dist);
    Serial.print(".");
  }
  for(int pos=165;pos>=15;pos-=1){
    myServo.write(pos);
    delay(15);
    float dist=radar();
    Serial.print(pos);
    Serial.print(",");
    Serial.print(dist);
    Serial.print(".");
  }
}
