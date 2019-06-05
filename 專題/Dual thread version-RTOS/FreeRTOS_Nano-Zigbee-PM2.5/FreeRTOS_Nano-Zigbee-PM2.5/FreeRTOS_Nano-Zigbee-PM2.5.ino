//======== [ Arduino - Fire_Edge - LCD-Display_client ] ======== //
// --* 
// --* ---------------------[編碼通訊實驗室]---------------------//
// --* 
// --* version :FreeRTOS  V1.5
// --* 本程式為 Open source software 請注意使用
// --* 本程式專用於 [Fire_Edge - LCD-Display_client]
// --* 注意!! : 若造成任何損失本實驗室不付任何責任
// --* 
// --* ---------------------[編碼通訊實驗室]---------------------//
// --*
//==============================================================//


//--------------[Display_client - 函數庫]--------------//
#include <Arduino_FreeRTOS.h>
#include <PCD8544.h>
#include <SoftwareSerial.h>
#define SOFT_TX 12
#define SOFT_RX 2
// [ PMSx003xx TX ] to [ Arduino PIN 11 ]
SoftwareSerial mySerial(SOFT_RX, SOFT_TX); // RX, TX
unsigned char gucRxBuf[100];
unsigned int pmcount25;
static PCD8544 lcd;
//------------------------ [RGB]------------------------//
#define LEDR A0
#define LEDG A1
#define LEDB A2
//-----------------------[變數宣告]------------------------//
int ArrayNoise;int StateValue;
int average; int PM; 
int Photoresistance;                      
char Temperature[15]; 
char Air_Quality[15]; 
//------------------------ [Zigbee - 傳送封包Data]------------------------//
//---ZigbeeDataTest: Leftaddress=[0x61.0x33]-Right=address=[0x70.0x35]---//
byte STM32HostID[]     = {0xFE,0x05,0x91,0x90,0x10,0x2D,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeRightTest[] = {0xFE,0x05,0x91,0x90,0x70,0x35,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeSendTest[]  = {0xFE,0x05,0x91,0x20,0x70,0x35,0x05,0xFF}; //本機[LED-TEST]

//=====================================//
  void TaskLCD_Display( void *pvParameters );
  void TaskLED_Backlight( void *pvParameters );
//=====================================//


void setup(){
  Serial.begin(115200);
  mySerial.begin(9600);
  lcd.begin(84, 48);
  analogWrite(9,150);
  pinMode(A3,INPUT);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  //-------------------------{- 任務宣告區 -}-------------------------*/
  xTaskCreate(TaskLCD_Display,(const portCHAR *)"",133,NULL,2,NULL );
  xTaskCreate(TaskLED_Backlight,(const portCHAR *)"",55,NULL,1,NULL );
  //-------------------------{- 任務宣告區 -}-------------------------*/  
}


void TaskLCD_Display(void *pvParameters){
(void) pvParameters;
 
for(;;){ 
 float temp;float humi;
  if(mySerial.available()){
    vTaskDelay( 100 / portTICK_PERIOD_MS );
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
      }
    }
  } 

for(int i=0;i<10;i++){
  average+=temp;
  PM+=pmcount25;
  vTaskDelay( 100 / portTICK_PERIOD_MS );
  }
  average=average/10;
  PM=PM/10;
 int total=0;  
    if(average<=30){
      total=0;
      }else if(average>=31){
        total+=1;
        }
    Serial.print("T:");
    Serial.println(total);
  Photoresistance = analogRead(A3);
  Photoresistance/2;
  analogWrite(9,Photoresistance);

  sprintf(Temperature,"Celsius= %d C",average); 
  lcd.setCursor(0,0); 
  lcd.print("FireEdg.Client");
  lcd.setCursor(0,2); 
  lcd.print(Temperature);
  if(pmcount25<=35){ 
    sprintf(Air_Quality,"AQI= Good %C","");
    lcd.setCursor(0,3);lcd.print(Air_Quality);    
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);
} else if(pmcount25>=36&&pmcount25<=53){
    sprintf(Air_Quality,"AQI= Middle %C","");
    lcd.setCursor(0,3);lcd.print(Air_Quality);     
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);
} else if(pmcount25>=84){
    sprintf(Air_Quality,"AQI= Bad %C","");
    lcd.setCursor(0,3);lcd.print(Air_Quality);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
    } 
  lcd.setCursor(0,5);
  lcd.print("Client sensor");

if (total<=29){
       StateValue=0x01;
       STM32HostID[6]=StateValue;
       Serial.write(STM32HostID, sizeof(STM32HostID));
       Serial.write(ZigbeeSendTest, sizeof(ZigbeeSendTest)); 
       lcd.setCursor(0,4); 
       lcd.print(STM32HostID[6]);       
       vTaskDelay( 5000 / portTICK_PERIOD_MS );           
}else if(total>=30){
         StateValue=0x02;
         STM32HostID[6]=StateValue; 
         Serial.write(STM32HostID, sizeof(STM32HostID));
         Serial.write(ZigbeeSendTest, sizeof(ZigbeeSendTest)); 
         vTaskDelay( 5000 / portTICK_PERIOD_MS );          
         }
 StateValue= 0x00;
 average=0; 
 PM=0;   
 }
}


void TaskLED_Backlight(void *pvParameters){
(void) pvParameters;
 for(;;) {
   Photoresistance = analogRead(A3);
   Photoresistance/2;
   analogWrite(9,Photoresistance);
 }
}
//==============================================================//
//==============================================================//
void loop()
{
  // Empty. Things are done in Tasks.
}
