//tx-->15   rx-->14
#define M0 13
#define M1 12
//============{Arduino wed-MySQL-Upload_Data : LED HIGI or LOW }============//
#include <ArduinoJson.h>
//============= {ESP - and設AT Comm定} =============//
#define  AP_Connect  "AT+CWJAP=\"chen\",\"0978578678\""//AP密碼
#define  ATMode      "AT+CWMODE=1"//網卡模式
#define  ATMUX       "AT+CIPMUX=0"//單點連接
#define  CloseIP     "AT+CIPCLOSE"//關閉連線
#define  TCP """AT+CIPSTART=\"TCP\",\"120.119.73.23\",80"""/*建立 TCP/UDP 連線*/
//============= {Upload or download} =============//
#define SQL_PHP  "GET /phpMyAdmin/chen/Fire_IOT.php?key=l0615&query="
#define Send_ID_1  "UPDATE `chan` SET `car1`= '"+a+"',`car2`= '"+b+"'" 
#define End "\r\n\r\n"
String a,b,c="";
String GET , cmd ;
int bts=0,x;
const int bt =2;
char copy[50];
void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  pinMode(M0,OUTPUT);
  pinMode(M1,OUTPUT);
  pinMode(bts,INPUT);
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);
  Serial2.begin(9600);
  Serial.println("Initialising the Serial1...");    
  Serial2.println(AP_Connect);
  Serial.println(Serial2.readString());
}
void loop() {  
 if(Serial3.available() > 0){  
          c=Serial3.readString();
          Serial.println(c);
          Serial.println(c.length());
          c.toCharArray(copy, 15);
      if(c.length()>7){ 
          for(x=0;x<=6;x++){
              a= a+copy[x];
              b= b+copy[x+7];
                            }    
              Serial.println(a);
              Serial.println(b);
              WiFi_Connect();
              delay(3000);  
              c="";
              a="";
              b="";      
     }else{
         Serial.println("error");
         }   
    } 
    bts=digitalRead(bt);
    if(bts==LOW){ //傳空白值
      a="";
      b="";
      WiFi_Connect();
              delay(3000);  
    }
}
