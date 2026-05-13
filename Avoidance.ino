int ledpin=13;
int detectorpin=3;
int val;
//int enavlePin=2;//Enable pin for when we want to use it
void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin,OUTPUT);
  pinMode(detectorpin,INPUT);
  //pinMode(enablePin,OUTPUT);
  //digitalWrite(enablepin,HIGH);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(detectorpin);
  if(val==LOW){
    digitalWrite(ledpin,HIGH);
  }
  else{
    digitalWrite(ledpin,LOW);
  }

}
