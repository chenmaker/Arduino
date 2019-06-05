#include <Servo.h>
Servo myservo3,myservo4;
const int trig = 10;      //超音波腳位
const int echo = 9;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
 myservo3.attach(3);    //左邊伺服馬達連接
  myservo4.attach(4); 
}

void loop() {
  delay(2000);
  // put your main code here, to run repeatedly:
 myservo3.write(180);
   myservo4.write(180); 
   delay(500);
    myservo3.write(90);
   myservo4.write(90);  
 /*  pinMode (trig, OUTPUT);          //超音波運行
  pinMode (echo, INPUT);  
  float duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn (echo, HIGH);
  distance = (duration/2)/29;
  Serial.print(distance);
  Serial.println(" cm");
  if(distance<15){ 
    myservo3.write(0);
      myservo4.write(90);
      delay(500);
      myservo3.write(0);
      myservo4.write(170);
      delay(1500);
      myservo3.write(90);
      myservo4.write(170);
      delay(1000);
      myservo3.write(0);
      myservo4.write(170);
      delay(2000);
      myservo3.write(0);
      myservo4.write(90);
       delay(400);
       myservo3.write(0);
      myservo4.write(170);}
      else if(distance>16){ 
      myservo3.write(0);
      myservo4.write(170);
      } */
     
}
