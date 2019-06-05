#include <dht.h>   
#define dht_dpin 8 //定義訊號要從Pin 8 進來  
dht DHT; 
#include <Servo.h>
Servo myservo;  
  
void setup(){   
Serial.begin(9600);   
delay(300);             //Let system settle   
Serial.println("Humidity and temperature\n\n");   
delay(700); //Wait rest of 1000ms recommended delay before   
myservo.attach(9); 
//accessing sensor 
myservo.write(90);  
}
void loop(){   
DHT.read11(dht_dpin);   //去library裡面找DHT.read11  
Serial.print("Humidity = ");   
Serial.print(DHT.humidity);   
Serial.print("% ");   
Serial.print("temperature = ");   
Serial.print(DHT.temperature);   
Serial.println("C ");   
delay(1000); //每1000ms更新一次 
/*if (38<DHT.temperature <42)
  {
    myservo.write(90);
  delay(1000);
  }else if(DHT.temperature < 38){
    myservo.write(70);
  delay(60);
  }else if(DHT.temperature < 30){
    myservo.write(50);
  delay(60);
  }else if(DHT.temperature < 20){
    myservo.write(30);
  delay(60);
  }else if(DHT.temperature < 10){
    myservo.write(10);
  delay(60);
  }else if(DHT.temperature > 42){
    myservo.write(110);
  delay(60);
  }else if(DHT.temperature < 48){
    myservo.write(120);
  delay(60);
  }else if(DHT.temperature < 55){
    myservo.write(140);
  delay(60);
  }else if(DHT.temperature < 60){
    myservo.write(160);
  delay(60);
  }else if(DHT.temperature < 70){
    myservo.write(180);
  delay(60);
  } */
if (DHT.temperature < 29)
  {
    myservo.write(70);
  delay(1000);
  } else {
    myservo.write(110);
  delay(1000);
  }
}



