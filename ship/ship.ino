#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
SoftwareSerial I2CBT(12,13);//定義PIN10及PIN11分別為RX及TX腳位
#include <SparkFun_TB6612.h>
#define AIN1 8   // 控制輸入A1
#define AIN2 7   // 控制輸入A2
#define BIN1 10  // 控制輸入B1
#define BIN2 9   // 控制輸入B2
#define PWMA 6
#define PWMB 5
#define STBY 11  // 「待機」控制接Arduino的11腳
char val;
const int offsetA = 1;  // 正反轉設定A，可能值為1或-1。
const int offsetB = 1;  // 正反轉設定B，可能值為1或-1。
Motor motor1 = Motor(AIN1, AIN2, PWMA, offsetA, STBY);
Motor motor2 = Motor(BIN1, BIN2, PWMB, offsetB, STBY);
void setup(){
Serial.begin(9600);
I2CBT.begin(9600); 
}
void loop() {
 if (I2CBT.available()>0) {
    val = I2CBT.read();
  }
  else {
    switch(val){
      case 'a':
    motor1.drive(255,1000); 
    digitalWrite(AIN1,255);
    break;
      case 'b':
    motor1.drive(100,1000); 
    break;
     case 'c':
    motor1.drive(-255,1000); 
    break;
     case 'd':
    motor1.drive(100,1000); 
    break;
      }  
    }    
}
