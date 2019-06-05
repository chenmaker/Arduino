#include <SoftwareSerial.h>
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
void setup() 
{
 Serial.begin(9600); 
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  speed1 = 0;
  speed2= 0;
  pinMode(C1,INPUT);
  pinMode(C2,INPUT);
}
void loop() 
{  /* go(200,200);
    delay(10000);*/
   v1 = digitalRead(C1);
   v2 = digitalRead(C2);
   Serial.print("v1=");
   Serial.println(v1);
   Serial.print("v2=");
   Serial.println(v2);
   delay(300);
   //黑=0 白=1
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
 /* if(v1==0&v2==0)
    {
    back(0,0);
    }*/
     /*digitalWrite(IN1, HIGH);       馬達的正反轉接腳編號
      digitalWrite(IN2, LOW);        馬達的正反轉接腳編號
      digitalWrite(IN3, HIGH);       馬達的正反轉接腳編號
      digitalWrite(IN4, LOW);        馬達的正反轉接腳編號
      analogWrite(ENA, speed1);      馬達的 PWM 轉速控制
      analogWrite(ENB, speed2);      馬達的 PWM 轉速控制
      */
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
 /* void back(byte speed1,byte speed2)
{     
      digitalWrite(IN1, LOW);
      digitalWrite(IN2, HIGH);
      digitalWrite(IN3, LOW);
      digitalWrite(IN4, HIGH);
      analogWrite(ENA, speed1);  
      analogWrite(ENB, speed2);
  }*/
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
