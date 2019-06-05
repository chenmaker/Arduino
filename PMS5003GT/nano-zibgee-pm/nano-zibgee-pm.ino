//======== [ Zigbee - Send Data ] ======== //
#include <SoftwareSerial.h>
SoftwareSerial UART (12,11);

//------------------------ [Zigbee - 傳送封包Data]------------------------//
//---ZigbeeDataTest: Leftaddress=[0x61.0x33]-Right=address=[0x70.0x35]---//
byte STM32HostID[]     = {0xFE,0x05,0x91,0x90,0x10,0x2D,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeRightTest[] = {0xFE,0x05,0x91,0x90,0x70,0x35,0x00,0xFF}; //本機[Send-Data]
byte ZigbeeSendTest[]  = {0xFE,0x05,0x91,0x20,0x61,0x33,0x05,0xFF}; //本機[LED-TEST]
int ArrayNoise;

int out;
unsigned char gucRxBuf[100];
unsigned int pmcount25;
void setup() {
  Serial.begin(9600);
  UART.begin(115200); 
}
void loop() {
int average=0;
int pm=0;
 float temp;
 float humi;
  if(Serial.available()){
    delay(100);
    unsigned char i=0;
    while(Serial.available()){
      gucRxBuf[i] = Serial.read();
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
        /*Serial.print("PMcount2.5:");   
        Serial.println(pmcount25);
        Serial.print("Temperature:");  
        Serial.print(temp);       
        Serial.println(" C");
        Serial.print("Humidity:");     
        Serial.print(humi);       
        Serial.println(" %");*/  
 for(int i=0;i<10;i++){
  average+=temp;
  pm+=pmcount25;
   delay(100);
  }
  average=average/10;
  pm=pm/10;
if (average<=30&&pm<=100){
       out=0x00;
       STM32HostID[6]=out;
       UART.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));
       UART.write(STM32HostID, sizeof(STM32HostID));
}else if(average>=31&&pm>=101){
         out=0x01;
         STM32HostID[6]=out; 
         UART.write(ZigbeeSendTest, sizeof(ZigbeeSendTest));
         UART.write(STM32HostID, sizeof(STM32HostID));
            }
        }
     }
   }
 }
