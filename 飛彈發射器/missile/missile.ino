#include <SoftwareSerial.h>//call appinventor wow
#include <Wire.h>//引用二個函式庫SoftwareSerial及Wire
SoftwareSerial I2CBT(0,1);//定義PIN0->RX和PIN11->TX腳位  燒入前先拔除RX及TX
void setup() {
  Serial.begin(9600); //Arduino起始鮑率：9600
  I2CBT.begin(9600);
  //藍牙鮑率：57600(注意！每個藍牙晶片的鮑率都不太一樣，請務必確認
  pinMode(2, OUTPUT); 
  pinMode(3, OUTPUT); 
  pinMode(4, OUTPUT); 
  pinMode(5, OUTPUT); 
  pinMode(6, OUTPUT); 
  pinMode(7, OUTPUT); 
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT); 
  pinMode(10, OUTPUT); 
  pinMode(11, OUTPUT); 
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);  
  //設定 pin13 為輸出
}
void loop() {
  byte cmmd[20];
  int insize;
  while(1){
    if ((insize=(I2CBT.available()))>0){ //讀取藍牙訊息
      Serial.print("input size = ");
      Serial.println(insize);
      for (int i=0; i<insize; i++){
        Serial.print(cmmd[i]=char(I2CBT.read()));
        Serial.print(" ");
      }//
    }
    switch (cmmd[0]) { //讀取第一個字
     // ASCII CODE
    case 97: //a 
      digitalWrite(2,HIGH);//點亮LED
      break;
    case 98://b
      Serial.println("Get b");
      digitalWrite(2,LOW);//熄滅LED
      break;
      
    case 99://c
      digitalWrite(3,HIGH);//點亮LED
      break;
    case 100://d
      Serial.println("Get d");
      digitalWrite(3,LOW);//熄滅LED
      break;
      
    case 101: //e
      digitalWrite(4,HIGH);//點亮LED
      break;
    case 102://f
      Serial.println("Get f");
      digitalWrite(4,LOW);//熄滅LED
      break;
      
    case 103://g
      digitalWrite(5,HIGH);//點亮LED
      break;
    case 104://h
      Serial.println("Get h");
      digitalWrite(5,LOW);//熄滅LED
      break;
      
    case 105: //i 
      digitalWrite(6,HIGH);//點亮LED
      break;
    case 106://j
      Serial.println("Get j");
      digitalWrite(6,LOW);//熄滅LED
      break;
      
    case 107://k
      digitalWrite(7,HIGH);//點亮LED
      break;
    case 108://l
      Serial.println("Get l");
      digitalWrite(7,LOW);//熄滅LED
      break;
      
    case 109: //m 
      digitalWrite(8,HIGH);//點亮LED
      break;
    case 110://n
      Serial.println("Get n");
      digitalWrite(8,LOW);//熄滅LED
      break;
      
    case 111://o
      digitalWrite(9,HIGH);//點亮LED
      break;
    case 112://p
      Serial.println("Get p");
      digitalWrite(9,LOW);//熄滅LED
      break;
       
    case 113: //q 
      digitalWrite(10,HIGH);//點亮LED
      break;
    case 114://r
      Serial.println("Get r");
      digitalWrite(10,LOW);//熄滅LED
      break;
      
    case 115://s
      digitalWrite(11,HIGH);//點亮LED
      break;
    case 116://t
      Serial.println("Get t");
      digitalWrite(11,LOW);//熄滅LED
      break;
     
     case 117: //u
      digitalWrite(12,HIGH);//點亮LED
      break;
    case 118://v
      Serial.println("Get v");
      digitalWrite(12,LOW);//熄滅LED
      break;
      
    case 119://w
      digitalWrite(13,HIGH);//點亮LED
      break;
    case 120://x
      Serial.println("Get x");
      digitalWrite(13,LOW);//熄滅LED
      break;
      
    } //Switch
  } //while
}//loop
