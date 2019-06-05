#include <SoftwareSerial.h>//call appinventor wow
#include <Wire.h>//引用二個函式庫SoftwareSerial及Wire
SoftwareSerial I2CBT(0,1);//定義PIN0->RX和PIN11->TX腳位  燒入前先拔除RX及TX
#include <Thermistor.h>
Thermistor temp(0);
#include <Servo.h>
Servo s0;
Servo s1;
Servo s2;
//int ledPin = 11;
//int ledPin1 = 12;
void setup() {
  Serial.begin(9600); //Arduino起始鮑率：9600
  I2CBT.begin(9600);
  //藍牙鮑率：57600(注意！每個藍牙晶片的鮑率都不太一樣，請務必確認 
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);  
//pinMode(ledPin, OUTPUT);
//pinMode(ledPin1, OUTPUT);
  s0.attach(3);
  s1.attach(5);
  s2.attach(6);
}
void loop() {
  int temperature = temp.getTemp();
Serial.print("The sensor temperature is: ");
Serial.print(temperature);
Serial.println("C");
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
      s0.write(20); 
      break;
    case 98://b
      s0.write(20);
      break;   
    case 99://c
      s0.write(20);
      break;
    case 100://d
     s0.write(20); 
      break;
    case 101: //e
      s0.write(20);
      break;
    case 102://f
      digitalWrite(4,LOW);
      break;  
    case 103://g
      digitalWrite(5,HIGH);
      break;
    case 104://h
      digitalWrite(5,LOW);
      break;  
    case 105: //i 
      digitalWrite(6,HIGH);
      break;
    case 106://j
      digitalWrite(6,LOW);
      break;
    case 107://k
      digitalWrite(7,HIGH);
      break;
    case 108://l
      digitalWrite(7,LOW);
      break;
    case 109: //m 
      digitalWrite(8,HIGH);
      break;
    case 110://n
      digitalWrite(8,LOW);
      break;
    case 111://o
      digitalWrite(9,HIGH);
      break;
    case 112://p
      digitalWrite(9,LOW);
      break;
    case 113: //q 
      digitalWrite(10,HIGH);
      break;
    case 114://r開特燈
      digitalWrite(13,HIGH);
      break;   
    case 115://s關特燈
      digitalWrite(13,LOW);
      break;
    case 116://t  啟動引擎
    digitalWrite(11, HIGH); 
    digitalWrite(12, HIGH);
      break;     
    case 117: //u 關掉引擎
    digitalWrite(11, LOW); 
    digitalWrite(12, LOW);
      break;
    case 118://v 檔位  C1
    delay(1000);
    digitalWrite(11, HIGH); 
    digitalWrite(12, HIGH);
      break; 
    case 119://w 檔位  C2
    delay(1000);
    digitalWrite(11, HIGH); 
    digitalWrite(12, HIGH);
      break;
    case 120://x 檔位  C3
    delay(1000);
    digitalWrite(11, HIGH); 
    digitalWrite(12, HIGH);
      break;
    case 121://y 檔位  CR
    delay(1000);
    digitalWrite(11, HIGH); 
    digitalWrite(12, HIGH);
      break;
    case 122://z 檔位  CN
    delay(1000);
    digitalWrite(11, HIGH); 
    digitalWrite(12, HIGH);
      break;  
    } //Switch
  } //while
}//loop
