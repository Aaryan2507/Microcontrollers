#include <Servo.h>//Servo class
Servo myservo;//Servo object to use servo
int pos=0;//position/angle of servo

void setup() {
  // put your setup code here, to run once:
  int SigPin=9;//Pin to connect Servo's signal pin to
  myservo.attach(SigPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(pos=0;pos<=180;pos++){
    myservo.write(pos);
    delay(15);
  }

}
