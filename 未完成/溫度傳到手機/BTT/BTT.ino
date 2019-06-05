#include <SoftwareSerial.h>
#include <dht.h>   
#define dht_dpin A0 //定義訊號要從Pin A0 進來  
dht DHT;   
const int TX   = 10;
const int RX   = 11;
SoftwareSerial BT(RX, TX); 
void setup(){   
Serial.begin(9600); 
 BT.begin(9600); 
Serial.println("Start!!!"); 
}
  
void loop(){   
DHT.read11(dht_dpin);   //去library裡面找DHT.read11  
float duration; //duration to record the time of every back and forth 
Serial.print("Humidity = ");   
Serial.print(DHT.humidity);   
Serial.print("% ");  
Serial.print("temperature = ");   
Serial.print(DHT.temperature);   
Serial.println("C ");   
delay(1000);            //每1000ms更新一次   
  byte packet[3]; 
  packet[0] = 97; //key send to phone
  packet[1] = sendData / 256; //divides sendData to two 1 byte packets
  packet[2] = sendData % 256;
  
  
  if(BT.available() > 0) //check BT is succeed
    if(BT.read() == 97) //check recieve key from phone
    {
      Serial.println("succeed!");
      for(int i = 0; i < 3; i++) 
        BT.write(packet[i]); //send packet to phone
    }
}  
