#include <SoftwareSerial.h>//call appinventor wow
#include <Servo.h>
Servo myservo3,myservo4;
const int trig = 10;
const int echo = 9;
const int inter_time = 100;
int time = 0;
int a;
int ML = A3;   
int MM = A0;
int MR = A1;
int RR = A2;
int L;
int M;
int R;
int LED =13;
void setup() {
Serial.begin(9600); // Abrimos comunicación Serial
  pinMode(13, OUTPUT);//r
  pinMode(ML, INPUT);
  pinMode(MM, INPUT);
  pinMode(MR, INPUT); 
  pinMode(LED, OUTPUT);
    myservo3.attach(3); //左
    myservo4.attach(4); //右 
}

void loop() {
 pinMode (trig, OUTPUT);
  pinMode (echo, INPUT);  
  float duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn (echo, HIGH);
  distance = (duration/2)/29;
  Serial.print(distance);
  Serial.println(" cm");
  time = time + inter_time;
  delay(inter_time);
  if(distance<8){
  a=1;
  digitalWrite(LED, HIGH);
  Serial.print("a4=");
    Serial.print(a);
      }
Serial.print("ML=");
  Serial.print(analogRead(ML) );
  L = analogRead(ML);
  Serial.print("MM=");
  Serial.print(analogRead(MM));
  M = analogRead(MM);
  Serial.print("MR=");
  Serial.print(analogRead(MR));
  R = analogRead(MR);
  Serial.print("RR=");
  Serial.print(analogRead(RR));
  RR = analogRead(RR);
  Serial.println("--");
 // delay(500);
  if(a==1){
    if(RR>=200&&RR<=400&&R>=200&&R<=400){
      myservo3.write(180);
      myservo4.write(90);
      delay(3000);
     }else if(L>=300&&M>=700&&R>=800){
      myservo3.write(180);
      myservo4.write(60);
     }else if(L>=800&&M>=700&&R>=300){
      myservo3.write(180);
      myservo4.write(74);
     }else if(L>=800&&M>=200&&R>=800){
    //前
     myservo3.write(180);
    myservo4.write(67);
    }
  }
}
