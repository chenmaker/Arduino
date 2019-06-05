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
#include <dht.h> 
#define dht_dpin 2
static  PCD8544 lcd;
char Hum_String[15];                        
char Temp_String[15]; 
dht DHT; 
//---------------[Zigbee - 傳送封包Data]---------------//
//---ZigbeeDataTest: Leftaddress=[0x61.0x33]-Right=address=[0x70.0x35]---//
byte STM32HostID[]     = {0xFE,0x05,0x91,0x90,0x10,0x2D,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeRightTest[] = {0xFE,0x05,0x91,0x90,0x70,0x35,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeSendTest[]  = {0xFE,0x05,0x91,0x20,0x61,0x33,0x05,0xFF}; //本機[LED-TEST]
int ArrayNoise; int StateValue; int temperature; int humidity; int Photoresistance;

//=====================================//
  void TaskLCD_Display( void *pvParameters );
  void TaskLED_Backlight( void *pvParameters );
//=====================================//


void setup(){
  Serial.begin(115200);
  analogWrite(9,150); 
  lcd.begin(84, 48); 
  pinMode(A3,INPUT);

  //-------------------------{- 任務宣告區 -}-------------------------*/
  xTaskCreate(TaskLCD_Display,(const portCHAR *)"",133,NULL,2,NULL );
  xTaskCreate(TaskLED_Backlight,(const portCHAR *)"",55,NULL,1,NULL );
  //-------------------------{- 任務宣告區 -}-------------------------*/  
}

//---------------------------------------------------------------//
//------------------------{- 緒執行區域 -}-----------------------//
//---------------------------------------------------------------//
void TaskLCD_Display(void *pvParameters){
(void) pvParameters;
 
for(;;){ 
  for(int i=0;i<10;i++){
    DHT.read11(dht_dpin);
    temperature+=DHT.temperature;
    humidity+=DHT.humidity;
    vTaskDelay( 100 / portTICK_PERIOD_MS ); 
  }
   
   temperature=temperature/10;
   humidity=humidity/10;
   int total=0;  
    if(temperature<=30){
      total=0;
      }else if(temperature>=31){
        total+=1;
        }
    Serial.print("T:");
    Serial.println(total);
    
    sprintf(Temp_String,"Celsius : %d C",temperature); 
    sprintf(Hum_String,"humidity : %d%%",humidity);
    lcd.setCursor(0,0); 
    lcd.print("FireEdg.Client");
    lcd.setCursor(0,2); 
    lcd.print(Temp_String);
    lcd.setCursor(0,3); 
    lcd.print(Hum_String);
    lcd.setCursor(0,5);
    lcd.print("Client sensor");
    analogWrite(9,Photoresistance);
    
      if (total<=29){
             StateValue=0x01;
             STM32HostID[6]=StateValue;
             Serial.write(STM32HostID, sizeof(STM32HostID));
             Serial.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));       
             vTaskDelay( 5000 / portTICK_PERIOD_MS ); 
      }else if(total>=30){
              StateValue=0x02;
              STM32HostID[6]=StateValue; 
              Serial.write(STM32HostID, sizeof(STM32HostID));
              Serial.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));         
              vTaskDelay( 5000 / portTICK_PERIOD_MS ); 
      }
      StateValue= 0;
     temperature= 0;
    humidity= 0;     
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
