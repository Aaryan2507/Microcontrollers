int Led=13;
int shock=9;
int val;
void setup() {
  // put your setup code here, to run once:
  pinMode(Led,OUTPUT);
  pinMode(shock,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  val=digitalRead(shock);
  if(val==HIGH){
    digitalWrite(Led,LOW);
  }
  else{
    digitalWrite(Led,HIGH);
  }

}
