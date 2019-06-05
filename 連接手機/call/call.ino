//chen
#include <SoftwareSerial.h>
#include <NewPing.h> 
#define TRIGGER_PIN  7
#define ECHO_PIN     7
#define MAX_DISTANCE 200
NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);
#include <Wire.h>
SoftwareSerial I2CBT(10,11);//定義PIN10及PIN11分別為RX及TX腳位
int LED1 = 1;
int LED2 = 2;
int LED3 = 3;

void setup(){
  Serial.begin(9600);
  I2CBT.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);            
}
void loop (){
  String a,b,c;
  int i= analogRead(A0);
  int v = analogRead(A5);
  int uS = sonar.ping();
  Serial.print("cm:");
  Serial.println(uS / US_ROUNDTRIP_CM);
  Serial.print("i:");
  Serial.println(i); 
  Serial.print("v:"); 
  Serial.println(v);
  if (uS / US_ROUNDTRIP_CM>101){//超音波
    a="a";
    }else if(uS / US_ROUNDTRIP_CM<100){
     a="b"; 
      }
  if (i>101){//光感
    b="c";
    }else if(i<100){
      b="d";
      }
  if (v<100){//雨滴感測
     c="e";
    }else if(v>101){
       c="f";
      }
  //String a="距離:"+String(uS / US_ROUNDTRIP_CM)+"光線敏感度:"+String(i)+"有無下雨:"+String(v);
  String d=String(a)+String(b)+String(c);
  Serial.print("a:");
  Serial.print(a);
  Serial.print("-b:");
  Serial.print(b);
  Serial.print("-c:");
  Serial.println(c);
  I2CBT.print(d);
  delay(500);
}
