//tx-->15   rx-->14
#define M0 13 //定義模式腳位(lora)
#define M1 12 //定義模式腳位(lora)
//============{Arduino wed-MySQL-Upload_Data : LED HIGI or LOW }============//
#include <ArduinoJson.h> //匯入資料庫
//============= {ESP - and設AT Comm定} =============//
#define  AP_Connect  "AT+CWJAP=\"chen\",\"12345678\""//AP密碼 //wife相關指令
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
void setup() {
  Serial.begin(9600); //序列視窗
  Serial3.begin(9600);//arduino跟lora
  pinMode(M0,OUTPUT);
  pinMode(M1,OUTPUT);
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);
  pinMode(bts,INPUT);
  Serial2.begin(9600);//arduino跟wife
  Serial.println("Initialising the Serial1...");    
  Serial2.println(AP_Connect);
  Serial.println(Serial2.readString());
}
void loop() {  
    lora ();
    //button();
}
