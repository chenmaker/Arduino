#include <SPI.h>
#include "mcp_can.h"
const int SPI_CS_PIN = 10;

MCP_CAN CAN(SPI_CS_PIN);                                    // Set CS pin

void setup()
{
    Serial.begin(115200);

   while (CAN_OK != CAN.begin(CAN_500KBPS))              // init can bus : baudrate = 500k
    {
        Serial.println("CAN BUS Shield init fail");
        Serial.println(" Init CAN BUS Shield again");
        delay(100);
    }
    Serial.println("CAN BUS Shield init ok!");
    pinMode(7,OUTPUT);
    pinMode(6,OUTPUT);
}


void loop()
{   
  
  unsigned char len = 0;
    unsigned char buf[8];

    if(CAN_MSGAVAIL == CAN.checkReceive())            // check if data coming
    {
        CAN.readMsgBuf(&len, buf);    // read data,  len: data length, buf: data buf

        unsigned long canId = CAN.getCanId();
        
        Serial.println("-----------------------------");
        Serial.print("Get data from ID: 0x");
        Serial.println(canId, HEX);

     /*   for(int i = 0; i<len; i++)    // print the data
        {
            Serial.print(buf[i], HEX);
            Serial.print("\t");
        }
        Serial.println();*/
    }
    Serial.print(buf[0], HEX);
    Serial.println("can");
    delay(1000);
    if(buf[0]==0){
      digitalWrite(7, HIGH);
      digitalWrite(6,HIGH);
      Serial.println("0");
      delay(100);
      }
    else if(buf[0]==1){
      digitalWrite(7,LOW);
      digitalWrite(6,LOW);
      Serial.println("1");
      delay(100);
      }
  /*  digitalWrite(7, HIGH);
    Serial.println("1");
    delay(250);
     digitalWrite(7, LOW);
    Serial.println("0");
    delay(250);*/

    
    
}
