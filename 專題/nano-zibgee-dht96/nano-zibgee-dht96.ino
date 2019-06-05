//======== [ Zigbee - Send Data ] ======== //
#include <SoftwareSerial.h>
SoftwareSerial UART (1,0);
//------------------------ [Zigbee - 傳送封包Data]------------------------//
//---ZigbeeDataTest: Leftaddress=[0x61.0x33]-Right=address=[0x70.0x35]---//
byte STM32HostID[]     = {0xFE,0x05,0x91,0x90,0x10,0x2D,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeRightTest[] = {0xFE,0x05,0x91,0x90,0x70,0x35,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeSendTest[]  = {0xFE,0x05,0x91,0x20,0x61,0x33,0x05,0xFF}; //本機[LED-TEST]
int ArrayNoise;
#include <PCD8544.h>
static PCD8544 lcd;
#include <dht.h>   
#define dht_dpin 2 //定義訊號要從Pin 2 進來  
dht DHT;  
int out;
#define LEDR A0
#define LEDG A1
#define LEDB A2
void setup() {
  Serial.begin(9600);
  UART.begin(115200); 
    lcd.begin(84, 48);
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}
void loop() {
int average=0;
DHT.read11(dht_dpin);
/*Serial.print("Humidity = ");   
Serial.print(DHT.humidity);   
Serial.print("% ");   
Serial.print("temperature = ");   
Serial.print(DHT.temperature);   
Serial.println("C ");*/
for(int i=0;i<10;i++){
 //Serial.println(average);
  average+=DHT.temperature;
   delay(100);
  }
  average=average/10;
 // Serial.println(average);
if (average<=30){
       out=0x00;
       STM32HostID[6]=out;
       UART.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));
       UART.write(STM32HostID, sizeof(STM32HostID));
       digitalWrite(LEDR, LOW);
       digitalWrite(LEDG, HIGH);
       digitalWrite(LEDB, LOW);
}else if(average>=31){
         out=0x01;
         STM32HostID[6]=out; 
         UART.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));
         UART.write(STM32HostID, sizeof(STM32HostID));
         digitalWrite(LEDR, HIGH);
         digitalWrite(LEDG, LOW);
         digitalWrite(LEDB, LOW);
   }
  lcd.setCursor(0,1); 
  lcd.print("T:");
  lcd.print(average);
  lcd.print("C");
  if(average<10){
    lcd.setCursor(42,1); 
    lcd.print("  ");
    }else if(average<100){
    lcd.setCursor(48,1); 
    lcd.print(" ");
    }
}
