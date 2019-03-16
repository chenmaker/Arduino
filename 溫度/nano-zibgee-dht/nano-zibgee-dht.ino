//======== [ Zigbee - Send Data ] ======== //
#include <SoftwareSerial.h>
//SoftwareSerial UART (12,11);
SoftwareSerial UART (1,0);
//------------------------ [Zigbee - 傳送封包Data]------------------------//
//---ZigbeeDataTest: Leftaddress=[0x61.0x33]-Right=address=[0x70.0x35]---//
byte STM32HostID[]     = {0xFE,0x05,0x91,0x90,0x10,0x2D,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeRightTest[] = {0xFE,0x05,0x91,0x90,0x70,0x35,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeSendTest[]  = {0xFE,0x05,0x91,0x20,0x61,0x33,0x05,0xFF}; //本機[LED-TEST]
int ArrayNoise;

#include <dht.h>   
#define dht_dpin 2 //定義訊號要從Pin 2 進來  
dht DHT;  
int out;

void setup() {
  Serial.begin(9600);
  UART.begin(115200); 
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
}else if(average>=31){
         out=0x01;
         STM32HostID[6]=out; 
         UART.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));
         UART.write(STM32HostID, sizeof(STM32HostID));
}
/*STM32HostID[6]=out;
  for(int i=0 ; i<8 ; i++){
    Serial.print(STM32HostID[i],HEX); 
    Serial.print(',');
    if(i>=7){Serial.println(STM32HostID[6]);}
  }*/
  
 
}
