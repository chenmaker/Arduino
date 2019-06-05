//for mega2560
//PMS5003GT RX-->pin15
#include <PCD8544.h>
unsigned char gucRxBuf[100];
unsigned int pmcount25;
static PCD8544 lcd;
#define LEDR 8
#define LEDG 9
#define LEDB 10
//============{Arduino wed-MySQL-Upload_Data : LED HIGI or LOW }============//
#include <ArduinoJson.h>
//============= {ESP - AT Command設定} =============//
//#define  AP_Connect  "AT+CWJAP=\"STUWLAN-L0615_2.4G\",\"l0615&l0615\""//AP密碼
#define  AP_Connect  "AT+CWJAP=\"chen\",\"0978578678\""//AP密碼
#define  ATMode      "AT+CWMODE=1"//網卡模式
#define  ATMUX       "AT+CIPMUX=0"//單點連接
#define  CloseIP     "AT+CIPCLOSE"//關閉連線
#define  TCP """AT+CIPSTART=\"TCP\",\"120.119.73.23\",80"""/*建立 TCP/UDP 連線*/

//============= {Upload or download} =============//
#define SQL_PHP  "GET /phpMyAdmin/chen/Fire_IOT.php?key=l0615&query="
#define Send_ID_1  "UPDATE `PM` SET `pm`= '"+a+"',`c`= '"+b+"',`f`= '"+c+"',`h`= '"+d+"'"
#define End "\r\n\r\n"
String a,b,c,d;
String GET , cmd ;
void setup() {
  Serial.begin(9600);
  Serial2.begin(115200);
  Serial3.begin(9600);
  Serial.println("Initialising the Serial1...");    
  Serial2.println(AP_Connect);
  Serial.println(Serial2.readString());
  lcd.begin(84, 48);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}
void WiFi_Connect(){
  Serial2.println(ATMode);
  delay(500);
  Serial.println(Serial2.readString()); 
  Serial2.println(ATMUX);
  delay(500);
  Serial.println(Serial2.readString());
  Serial2.println(TCP);
  delay(500);
  Serial.println(Serial2.readString());  
}
void MySQL_BottonData_1(){ 
  WiFi_Connect();
  delay(500);
  GET = SQL_PHP;
  GET += Send_ID_1;
  GET += End;
  MySQL_SendData();
}

void MySQL_SendData(){
  cmd="AT+CIPSEND=" + String(GET.length());  
  Serial2.println(cmd);
  delay(500);
  Serial2.println(GET);
  delay(500);
  Serial.println(GET);
  Serial.println(F("----------------------------------------------------------"));  
  GET="";  
}
void loop() {
  float temp;
  float humi;
  if(Serial3.available()){
    delay(100);
    unsigned char i=0;
    while(Serial3.available()){
      gucRxBuf[i] = Serial3.read();
      i++;
    }
    if (((gucRxBuf[0]==0x42)&&(gucRxBuf[1]==0x4d))&&(i>=12)){
      int chksum=0;
      unsigned char DTL=(gucRxBuf[2]<<8)+gucRxBuf[3];
      for(unsigned char i=0;i<(DTL+2);i++){chksum += gucRxBuf[i];}
      unsigned char csH = (chksum>>8);
      unsigned char csL = (chksum&0xFF);
      if((csH==gucRxBuf[DTL+2])&&(csL==gucRxBuf[DTL+3])){
        Serial.println("========= PMS5003T =========");
        pmcount25=gucRxBuf[22]*256+gucRxBuf[23];  
        temp=(float)(gucRxBuf[24]*256+gucRxBuf[25])/10;  
        humi=(float)(gucRxBuf[26]*256+gucRxBuf[27])/10; 
        Serial.print("PMcount2.5:");   
        Serial.println(pmcount25);
        Serial.print("Temperature:");  
        Serial.print(temp);       
        Serial.println(" C");
        Serial.print("Humidity:");     
        Serial.print(humi);       
        Serial.println(" %");
         a="PM:"+String(pmcount25)+"C:"+String(temp)+"H"+String(humi);
        // b=temp;
      //   c="";
        // d=humi;
    Serial.println(a);
  //  Serial.println(b);
  //  Serial.println(c);
  //  Serial.println(d);   
    MySQL_BottonData_1();
    delay(3000);
      }
    }
  } 
  lcd.setCursor(30, 0);
  lcd.print("PM2.5");
  lcd.setCursor(0,1); 
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");
  lcd.print("      ");
  lcd.setCursor(0,2); 
  lcd.print("H:");
  lcd.print(humi);
  lcd.print("%");
  lcd.setCursor(0,3); 
  lcd.print("PM2.5:");
  lcd.print(pmcount25);
  if(pmcount25<10){
    lcd.setCursor(42,3); 
    lcd.print("  ");
    }else if(pmcount25<100){
    lcd.setCursor(48,3); 
    lcd.print(" ");
    }
  if(pmcount25<=35){
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
  }else if(pmcount25>=36&&pmcount25<=53){
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
  }else if(pmcount25>=54&&pmcount25<=70){
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
  }else if(pmcount25>=71){
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
    }
   /* lcd.setCursor(0,4); 
    lcd.print("0");
    lcd.setCursor(6,4); 
    lcd.print("0");
    lcd.setCursor(12,4); 
    lcd.print("0");*/
}
