//tx-->15   rx-->14
#define M0 10 //定義模式腳位(lora)
#define M1 11 //定義模式腳位(lora)
//============{Arduino wed-MySQL-Upload_Data : LED HIGI or LOW }============//
#include <ArduinoJson.h> //匯入資料庫
//============= {ESP - and設AT Comm定} =============//
//#define  AP_Connect  "AT+CWJAP=\"szx\",\"0f9u7c8k\""//AP密碼 //wife相關指令
#define  AP_Connect  "AT+CWJAP=\"chen\",\"0978578678\""
//#define  AP_Connect  "AT+CWJAP=\"STUWLAN-L0615_2.4G\",\"l0615&l0615\""
#define  ATMode      "AT+CWMODE=1"//網卡模式
#define  ATMUX       "AT+CIPMUX=0"//單點連接
#define  CloseIP     "AT+CIPCLOSE"//關閉連線
#define  TCP """AT+CIPSTART=\"TCP\",\"120.119.73.23\",80"""/*建立 TCP/UDP 連線*/
//============= {Upload or download} =============//
#define SQL_PHP  "GET /phpMyAdmin/chen/Fire_IOT.php?key=l0615&query="
#define Send_ID_1  "UPDATE `chan` SET `car1`= '"+a+"',`car2`= '"+b+"'" //傳輸到後端的格式 
#define End "\r\n\r\n"
String a,b,c=""; //設定變數
String GET , cmd ;
int bts=0,x;
const int bt =2;
char copy[60];
#include <SoftwareSerial.h>
SoftwareSerial lorauart(13,12); //lora接腳   tx-->13   rx-->12 
void setup() {
  Serial.begin(9600); 
  lorauart.begin(9600);
  pinMode(M0,OUTPUT);    //M0輸出
  pinMode(M1,OUTPUT);    //M1輸出
  digitalWrite(M0,LOW);  //設定M0狀態
  digitalWrite(M1,LOW);  //設定M1狀態
  pinMode(bts,INPUT);    //讀取按鈕輸入
  Serial.println("Initialising the Serial1...");    
  Serial.println(AP_Connect);
  Serial.println(Serial.readString());
}
void loop() {  
    lora ();
    button();
  //WiFi_Connect();
    delay(3000);  
}
