//for mega2560
//PMS5003GT RX-->pin15
#include <PCD8544.h>
unsigned char gucRxBuf[100];
unsigned int pmcount25;
void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
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
        }
    }
  }
}
