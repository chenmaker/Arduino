#include <SPI.h>
#include "RF24.h"

const int ledN = 4; // LED引腳號
const int ledL = 5; // LED引腳號
const int ledR = 6; // LED引腳號
RF24 rf24(7,8); // CE腳, CSN腳

const byte addr[] = "1Node";
//const byte pipe = 1;  // 指定通道編號

void setup() {
  Serial.begin(9600);
  pinMode(ledN,OUTPUT);//將LED引腳初始化為輸出：
  pinMode(ledL,OUTPUT);//將LED引腳初始化為輸出：
  pinMode(ledR,OUTPUT);//將LED引腳初始化為輸出：
  digitalWrite(ledN,HIGH);
  //nRF24
  rf24.begin();
  rf24.setChannel(83);  // 設定頻道編號
  rf24.openWritingPipe(addr);
  rf24.setPALevel(RF24_PA_MAX);
  rf24.setDataRate(RF24_1MBPS);
 // rf24.openReadingPipe(pipe, addr);  // 開啟通道和位址
  rf24.startListening();  // 開始監聽無線廣播
}
void loop() {
    if (rf24.available()>0){ 
    char msg[128] = "";
    rf24.read(&msg, sizeof(msg));
    Serial.println(msg[0]); // 顯示訊息內容        
    if (msg[0] == 'Y') {
        digitalWrite(ledL,HIGH);
        digitalWrite(ledR,HIGH);
        delay(200);
        digitalWrite(ledL,LOW);
        digitalWrite(ledR,LOW);
        delay(200);
        }else if (msg[0] == 'L') {
        digitalWrite(ledL,HIGH);
        delay(200);
        digitalWrite(ledL,LOW);
        delay(200);
        }else if (msg[0] == 'R') {
        digitalWrite(ledR,HIGH);
        delay(200);
        digitalWrite(ledR,LOW);
        delay(200);
        }else if (msg[0] == 'N') {
        digitalWrite(ledL,LOW);
        digitalWrite(ledR,LOW);
        delay(200); 
        }
    }
}
