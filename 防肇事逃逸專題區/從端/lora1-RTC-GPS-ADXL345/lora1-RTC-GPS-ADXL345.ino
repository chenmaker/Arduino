#define M0 11          //lora M0接腳
#define M1 12          //lora M1接腳
const int led = 10;    //LED燈腳位
String car="RBO-2266";  //我方車牌設定
#include <SoftwareSerial.h>
SoftwareSerial UART (3,4);//lora接腳   tx-->3   rx-->4  
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>//匯入LCD函示庫
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //設定LCD腳位  SDA->A4SCL->A5 
#include <DS3231.h>    //時間模組函示庫
DS3231  rtc(SDA, SCL); //時間模組腳位
String any,in;
char copy[50];
//三軸感測器
#include <SparkFun_ADXL345.h> 
ADXL345 adxl = ADXL345(); 
void ADXL_ISR(); 
//GPS接腳   tx-->0   rx-->1  
struct
{
    char GPS_Buffer[80];
    bool isGetData;     //是否獲取到GPS數據
    bool isParseData;   //是否解析完成
    char UTCTime[11];   //UTC时间
    char latitude[11];  //緯度
    char N_S[2];        //N/S
    char longitude[12]; //經度
    char E_W[2];        //E/W
    bool isUsefull;     //定位信息是否有效
} Save_Data;
const unsigned int gpsRxBufferLength = 600;
char gpsRxBuffer[gpsRxBufferLength];
unsigned int ii = 0;

void setup() {
  Serial.begin(9600);
  UART.begin(9600);
  rtc.begin();
//RTC();                   //註解時為無法改寫時間
  pinMode(led, OUTPUT);    //LED輸出
  pinMode(M0,OUTPUT);      //M0輸出
  pinMode(M1,OUTPUT);      //M1輸出
  digitalWrite(M0,LOW);    //設定M0狀態
  digitalWrite(M1,LOW);    //設定M1狀態
  LCDS();
  ADXLS();
  GPSS();
}
void loop() {  
ADXL();
gps();
//lcd.setCursor(5,2);
//RTC 
//lcd.print(String(rtc.getDateStr())+"-"+String(rtc.getTimeStr())); //在LCD顯示日期和時間
//any=(String(rtc.getDateStr())+"-"+String(rtc.getTimeStr())); //時間資訊及合成any字串
lorauart();
}
