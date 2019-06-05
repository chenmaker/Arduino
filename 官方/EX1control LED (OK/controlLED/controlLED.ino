#include <SoftwareSerial.h>
#include <Wire.h>
int LED = 13;
SoftwareSerial I2CBT(11,10);
void setup() {
  Serial.begin(9600);
  I2CBT.begin(9600);//bluetooth baud rate  
  
  pinMode(13, OUTPUT);    
}
void loop() {

  byte cmmd[20];
  int insize; 
  while(1){
/*
read message from bluetooth
*/
    if ((insize=(I2CBT.available()))>0){
       Serial.print("input size = "); 
       Serial.println(insize);
       for (int i=0; i<insize; i++){
         Serial.print(cmmd[i]=char(I2CBT.read()));
         Serial.print(" "); 
       }
      
    }  
      switch (cmmd[0]) {
        case 97: //"a"     
          digitalWrite(13,HIGH);        
          break;  
      case 98://"b"
          Serial.println("Get b");
          digitalWrite(13,LOW);         
          break;  
      } //Switch
      
  } //while

}
