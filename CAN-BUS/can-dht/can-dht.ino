
#include <mcp_can.h>
#include <SPI.h>
#include <dht.h>   
#define dht_dpin 8
dht DHT;   
// the cs pin of the version after v1.1 is default to D9
// v0.9b and v1.0 is default D10
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
}

unsigned char stmp[1] = {0};
void loop()
{
    DHT.read11(dht_dpin);
    Serial.print("temperature = "); 
    Serial.println(DHT.temperature);
    delay(250); 
 if(DHT.temperature<=30){
  /*    stmp[7] = stmp[7]+1;
    if(stmp[7] == 100)
    {
        stmp[7] = 0;
        stmp[6] = stmp[6] + 1;
        
        if(stmp[6] == 100)
        {
            stmp[6] = 0;
            stmp[5] = stmp[6] + 1;
        }
    }*/
    stmp[0]=1;
    CAN.sendMsgBuf(0x00, 0, 1, stmp);
    delay(100);    
  }else if(DHT.temperature>31){
    
     
     stmp[0]=0;
     
     CAN.sendMsgBuf(0x00, 0, 1, stmp);
    delay(100); 
    
 
    }
  
    // send data:  id = 0x00, standrad frame, data len = 8, stmp: data buf
                   // send data per 100ms
}

// END FILE
