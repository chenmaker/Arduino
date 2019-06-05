const int bt =2;
const int led = 7;
int bts=0;
void setup() {
pinMode(led,OUTPUT);
pinMode(bt,INPUT);
}

void loop() {
bts=digitalRead(bt);
if(bts==LOW){
  digitalWrite(led,HIGH);
  delay(300);
  }else if(bts==HIGH){digitalWrite(led,LOW);
  delay(300);
  }
}
