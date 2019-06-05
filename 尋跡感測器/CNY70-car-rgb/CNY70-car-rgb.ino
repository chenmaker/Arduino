#include <SoftwareSerial.h>
int pinReceptor = A0; //Establecemos el pin a leer
int sensorVal; //Declaramos una variable para almacenar el valor de la lectura
const byte IN1 = 3;
const byte IN2 = 2;
const byte ENA = 9;
const byte IN3 = 4;
const byte IN4 = 5;
const byte ENB = 10;
int speed1;
int speed2;
int C1 = 12;
int C2 = 13;
int v1 = 0;
int v2 = 0;
void setup(){
Serial.begin(9600); // Abrimos comunicación Serial
  pinMode(1, OUTPUT);//r
  pinMode(6, OUTPUT);//g
  pinMode(7, OUTPUT); //b 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  speed1 = 0;
  speed2 = 0;
  pinMode(C1,INPUT);
  pinMode(C2,INPUT);
}
void loop(){
   v1 = digitalRead(C1);
   v2 = digitalRead(C2);
   Serial.print("v1=");
   Serial.println(v1);
   Serial.print("v2=");
   Serial.println(v2);
   delay(300);
sensorVal = analogRead(pinReceptor);
Serial.println(sensorVal); 
  if(sensorVal>=11&&sensorVal<=13){
    digitalWrite(11, HIGH);
  }else if(sensorVal>=7&&sensorVal<=8){
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }else if(sensorVal>=14&&sensorVal<=16){
    digitalWrite(9, HIGH);
  }else {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
  if(v1==0&v2==0)
    {
    go(0,255);
    }
 if(v1==1&v2==0)
    {
    l(0,255);
    }
 if(v1==0&v2==1)
    {
    r(255,0);
    }
 if(v1==1&v2==1)
    {
    sp(0,0);
    }
}
void go(byte speed1,byte speed2)
{    
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, speed1);  
      analogWrite(ENB, speed2);     
  }
  void l(byte speed1,byte speed2)
{     
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, HIGH);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, speed1);  
      analogWrite(ENB, speed2);
  }
    void r(byte speed1,byte speed2)
{     
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, speed1);  
      analogWrite(ENB, speed2);
  }
  void sp(byte speed1,byte speed2)
{     
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, LOW);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, LOW);
      analogWrite(ENA, speed1);  
      analogWrite(ENB, speed2);
  }  
