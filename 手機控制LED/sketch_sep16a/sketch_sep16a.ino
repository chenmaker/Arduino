#include<SoftwareSerial.h>
SoftwareSerial BT(10,9);
const byte ledPin = 13;
char val;
void setup() {
  // put your setup code here, to run once:
pinMode(ledPin , OUTPUT);
BT.begin(5700);
BT.print("BT is ready");
}
void loop() {
  // put your main code here, to run repeatedly:
if (BT.available()){
  val = BT.read();
  switch(val){
    case'0':
    digitalWrite(ledPin , LOW);
    break;
      case'1':
    digitalWrite(ledPin , HIGH);
    break; 
    }
  }
}

