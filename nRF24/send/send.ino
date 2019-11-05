#include <SPI.h>
#include "RF24.h"

//RF24 rf24(D0, D8); // CE腳, CSN腳
RF24 rf24(7,8);
const byte addr[] = "1Node";
const char msg[] = "BMW-8888";

void setup() {
  Serial.begin(9600);
 // pinMode(D1, INPUT);//開關
  rf24.begin();
  rf24.setChannel(83);       // 設定頻道編號
  rf24.openWritingPipe(addr); // 設定通道位址
  rf24.setPALevel(RF24_PA_MAX);   // 設定廣播功率
  rf24.setDataRate(RF24_1MBPS); // 設定傳輸速率
  rf24.stopListening();       // 停止偵聽；設定成發射模式
}

void loop() {
  Serial.println("READ");
 // if(digitalRead(D1)==LOW){ 
  //Serial.println("HIGH");
  rf24.write(&msg, sizeof(msg));  // 傳送資料
 // }
  delay(1000);
}
