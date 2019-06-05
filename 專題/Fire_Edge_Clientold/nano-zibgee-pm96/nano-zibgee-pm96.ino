//======== [ Arduino - Fire_Edge - LCD-Display_client ] ======== //
// --* 
// --* ---------------------[編碼通訊實驗室]---------------------//
// --* 
// --* version : V1.5
// --* 本程式為 Open source software 請注意使用
// --* 本程式專用於 [Fire_Edge - LCD-Display_client]
// --* 注意!! : 若造成任何損失本實驗室不付任何責任
// --* 
// --* ---------------------[編碼通訊實驗室]---------------------//
// --*
//==============================================================//


//--------------[Display_client - 函數庫]--------------//
#include <PCD8544.h>
static PCD8544 lcd;
//------------------------ [PM2.5]------------------------//
#include <SoftwareSerial.h>
#define SOFT_TX 12
#define SOFT_RX 2
// [ PMSx003xx TX ] to [ Arduino PIN 11 ]
SoftwareSerial mySerial(SOFT_RX, SOFT_TX); // RX, TX
unsigned char gucRxBuf[100];
unsigned int pmcount25;
//------------------------ [RGB]------------------------//
#define LEDR A0
#define LEDG A1
#define LEDB A2
//------------------------ [Zigbee - 傳送封包Data]------------------------//
//---ZigbeeDataTest: Leftaddress=[0x61.0x33]-Right=address=[0x70.0x35]---//
byte STM32HostID[]     = {0xFE,0x05,0x91,0x90,0x10,0x2D,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeRightTest[] = {0xFE,0x05,0x91,0x90,0x70,0x35,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeSendTest[]  = {0xFE,0x05,0x91,0x20,0x61,0x33,0x05,0xFF}; //本機[LED-TEST]
int ArrayNoise;  int StateValue;
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  lcd.begin(84, 48);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}
void loop() {
  int average=0;
  int pm=0;
  float temp;
  float humi;
  if(mySerial.available()){
    delay(100);
    unsigned char i=0;
    while(mySerial.available()){
      gucRxBuf[i] = mySerial.read();
      i++;
    }
    if (((gucRxBuf[0]==0x42)&&(gucRxBuf[1]==0x4d))&&(i>=12)){
      int chksum=0;
      unsigned char DTL=(gucRxBuf[2]<<8)+gucRxBuf[3];
      for(unsigned char i=0;i<(DTL+2);i++){chksum += gucRxBuf[i];}
      unsigned char csH = (chksum>>8);
      unsigned char csL = (chksum&0xFF);
      if((csH==gucRxBuf[DTL+2])&&(csL==gucRxBuf[DTL+3])){
        //Serial.println("========= PMS5003T =========");
        pmcount25=gucRxBuf[22]*256+gucRxBuf[23];  
        temp=(float)(gucRxBuf[24]*256+gucRxBuf[25])/10;  
        humi=(float)(gucRxBuf[26]*256+gucRxBuf[27])/10; 
        //Serial.print("PMcount2.5:");   
        //Serial.println(pmcount25);
        //Serial.print("Temperature:");  
        //Serial.print(temp,1);       
        //Serial.println(" C");
        //Serial.print("Humidity:");     
        //Serial.print(humi,1);       
        //Serial.println(" %");
      }
    }
  } 
 
  lcd.setCursor(0,0); 
  lcd.print("FireEdg.Client");
  lcd.setCursor(0,2); 
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0,3); 
  lcd.print("PM2.5:");
  if(pmcount25<=35){
    lcd.print("Good");
    lcd.setCursor(60,3); 
    lcd.print("    ");
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW); 
} else if(pmcount25>=36&&pmcount25<=53){
    lcd.print("Middle");
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
} else if(pmcount25>=84){
    lcd.print("Bad");
    lcd.setCursor(55,3); 
    lcd.print("     "); 
     digitalWrite(LEDR, HIGH);
     digitalWrite(LEDG, LOW);
     digitalWrite(LEDB, LOW);
    } 
  lcd.setCursor(0,5);
  lcd.print("Client sensor");
 
for(int i=0;i<2;i++){
  average+=temp;
  pm+=pmcount25;
  delay(100);
  }
  average=average/2;
  pm=pm/2;
if (average<=30){
       StateValue=0x01;
       STM32HostID[6]=StateValue;
       Serial.write(STM32HostID, sizeof(STM32HostID));
       Serial.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));            
}else if(average>=31){
         StateValue=0x02;
         STM32HostID[6]=StateValue; 
         Serial.write(STM32HostID, sizeof(STM32HostID));
         Serial.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));           
         }
         StateValue= 0x00;
 }
