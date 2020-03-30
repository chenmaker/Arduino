#include <SPI.h>
#include "RF24.h"

const int bL = 2; //左 left
const int bR = 3; //右 right
const int bY = 4; //雙黃 double yellow
const int ledPin = 6; //LED pin
int bsL = 0; //左 left
int bsR = 0; //右 right
int bsY = 0; //雙黃 double yellow
RF24 rf24(7,8); // CE腳, CSN腳
String rmsg;
const byte addr[] = "1Node";
//const byte pipe = 1;  // 指定通道編號

void setup() {
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(bsL,INPUT);
  pinMode(bsR,INPUT);
  pinMode(bsY,INPUT); 
  //nRF24
  rf24.begin();
  rf24.setChannel(83);  // 設定頻道編號
  rf24.setPALevel(RF24_PA_MAX);
  rf24.setDataRate(RF24_1MBPS);
  rf24.openWritingPipe(addr);
  rf24.stopListening(); 
}
void loop() {
  digitalWrite(ledPin, LOW);
  bsL = digitalRead(bL);
  bsR = digitalRead(bR);
  bsY = digitalRead(bY);
  Serial.print("bsL=");
  Serial.println(bsL);
  Serial.print("bsR=");
  Serial.println(bsR);
  Serial.print("bsY=");
  Serial.println(bsY);
    if (bsL == HIGH) {
        rmsg="L";//傳送訊息
        rf24.write(&rmsg[0], 40);
        delay(100);
        digitalWrite(ledPin, HIGH);
        delay(300);
        digitalWrite(ledPin, LOW);
    } else if (bsR == HIGH) {
        rmsg="R";//傳送訊息
        rf24.write(&rmsg[0], 40);
        delay(100);
        digitalWrite(ledPin, HIGH);
        delay(300);
        digitalWrite(ledPin, LOW);
    }
     else if (bsY == HIGH) {
        rmsg="Y";//傳送訊息
        rf24.write(&rmsg[0], 40);
        delay(100);
        digitalWrite(ledPin, HIGH);
        delay(300);
        digitalWrite(ledPin, LOW);
    }else if (bsL == LOW ||bsR == LOW || bsY == LOW ){
        digitalWrite(ledPin, LOW);
        rmsg="N";//傳送訊息
        rf24.write(&rmsg[0], 40);
        delay(1000);
    }  
   Serial.print("rmsg=");
   Serial.println(rmsg);
}
