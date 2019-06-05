#include <SoftwareSerial.h>//call appinventor wow
#include <Wire.h>//引用二個函式庫SoftwareSerial及Wire
#include <Servo.h>
Servo myservo2,myservo3,myservo4;
SoftwareSerial I2CBT(0,1);//定義PIN0->RX和PIN11->TX腳位  燒入前先拔除RX及TX
void setup() {
  Serial.begin(9600); //Arduino起始鮑率：9600
  I2CBT.begin(38400);
  //藍牙鮑率：57600(注意！每個藍牙晶片的鮑率都不太一樣，請務必確認
   myservo2.attach(2); 
    myservo3.attach(3); //左
     myservo4.attach(4); //右
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
    /*case 97: //a //夾
      myservo2.write(-180);
      break;*/
    case 98://b
      myservo2.write(175);
      break;
      
   /* case 99://c放
     myservo2.write(90);
      break;*/
    case 100://d
      myservo2.write(60);
      break;
      
    case 101: //e前
      myservo3.write(0);
      myservo4.write(180);
      break;
    case 102://f
      myservo3.write(90);
      myservo4.write(90);
      break;
      
    case 103://g後
      myservo3.write(180);
      myservo4.write(0);
      break;
    case 104://h
      myservo3.write(90);
      myservo4.write(90);
      break;
      
    case 105: //i 右
      myservo3.write(0);
      myservo4.write(0);
      break;
    case 106://j
       myservo3.write(90);
      myservo4.write(90);
      break;
    case 107://k左
      myservo3.write(180);
      myservo4.write(180);
      break;
    case 108://l
       myservo3.write(90);
      myservo4.write(90);
      break;
    }
  }
}
