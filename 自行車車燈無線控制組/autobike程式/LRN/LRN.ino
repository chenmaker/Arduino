#include <SPI.h>
#include "RF24.h"
//A0~A5-->14~19
const int ledL  =17 ; // LED引腳號
const int ledR  =18 ; // LED引腳號
const int up = 16; // LED引腳號
const int down = 19; // LED引腳號

RF24 rf24(7,8); // CE腳, CSN腳

const byte addr[] = "1Node";
const byte pipe = 1;  // 指定通道編號

void setup() {
  Serial.begin(9600);
  pinMode(ledL,OUTPUT);//將LED引腳初始化為輸出：
  pinMode(up,OUTPUT);
  pinMode(ledR,OUTPUT);
  pinMode(down,OUTPUT);
  //nRF24
  rf24.begin();
  rf24.setChannel(83);  // 設定頻道編號
  rf24.setPALevel(RF24_PA_MAX);
  rf24.setDataRate(RF24_1MBPS);
  rf24.openReadingPipe(pipe, addr);  // 開啟通道和位址
  rf24.startListening();  // 開始監聽無線廣播
  Serial.println("OK");
}
void loop() {

    if (rf24.available()>0){ 
    char msg[128] = "";
    rf24.read(&msg, sizeof(msg));
    Serial.println(msg[0]); // 顯示訊息內容 
    switch(msg[0]){
      case 'Y':
        digitalWrite(ledL,HIGH);
        digitalWrite(ledR,HIGH);
        delay(200);
        digitalWrite(ledL,LOW);
        digitalWrite(ledR,LOW);
        delay(200);
      break;
      case 'L':
        digitalWrite(ledL,HIGH);
        delay(200);
        digitalWrite(ledL,LOW);
        delay(200);
      break;
      case 'R':
        digitalWrite(ledR,HIGH);
        delay(200);
        digitalWrite(ledR,LOW);
        delay(200);
      break;
      case 'N':
        digitalWrite(ledL,LOW);
        digitalWrite(ledR,LOW);
      break;
      
      }       
    }
  digitalWrite(up,HIGH);
  digitalWrite(down,HIGH);
  delay(80);
  digitalWrite(up,LOW);
  digitalWrite(down,LOW);
  delay(80);
}
