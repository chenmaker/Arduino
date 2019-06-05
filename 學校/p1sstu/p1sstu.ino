//chen
#include <SoftwareSerial.h>//匯入資料庫
#include <Servo.h>
Servo myservo3,myservo4;  //伺服馬達腳位設定
const int trig = 10;      //超音波腳位
const int echo = 9;            
                          //設定CNY70的腳位
int ML = A3;              //ML=左邊的感測器  
int MM = A0;              //MM＝中間的感測器
int MR = A1;              //MR＝右邊的感測器
int RR = A2;              //RR＝最右邊的感測器
int LL = A4;              //LL=最左邊的感測器
int LED =13;              //設定LED燈的腳位
int a;                    //設定變數
int L;
int M;
int R;
int RRR;
int LLL;     
void setup() {           //前置設定
  Serial.begin(9600);    //與序列視窗連接鮑率
  pinMode(ML, INPUT);    //CNY70的輸入
  pinMode(MM, INPUT);
  pinMode(MR, INPUT); 
  pinMode(RR, INPUT); 
  pinMode(LL, INPUT);
  pinMode(LED, OUTPUT);  //LED輸出
  myservo3.attach(3);    //左邊伺服馬達連接
  myservo4.attach(4);    //右邊伺服馬達連接
}
void loop() {
  pinMode (trig, OUTPUT);          //超音波運行
  pinMode (echo, INPUT);  
  float duration, distance;
  digitalWrite(trig, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trig, LOW);
  duration = pulseIn (echo, HIGH);
  distance = (duration/2)/29;
  Serial.print(distance);
  Serial.println(" cm");
  if(distance<8){              //判斷超音波距離長度
     a=1;
     digitalWrite(LED, HIGH);
     Serial.print("a=");
     Serial.print(a);
      }
  Serial.print("ML=");        //讀取CNY70的數值  白＝0 黑＝1
  Serial.print(digitalRead(ML) );
  L = digitalRead(ML);
  Serial.print("MM=");
  Serial.print(digitalRead(MM));
  M = digitalRead(MM);
  Serial.print("MR=");
  Serial.print(digitalRead(MR));
  R = digitalRead(MR);
  Serial.print("RR=");
  Serial.print(digitalRead(RR));
  RRR = digitalRead(RR);
  Serial.print("LL=");
  Serial.print(digitalRead(LL));
  LLL = digitalRead(LL);
  Serial.println("--");
  if(distance<15&&a==2){   //當a==2而且超音波小於15cm時啟動避障動作
    digitalWrite(LED, LOW);
     myservo3.write(0);
      myservo4.write(90);
      delay(500);
      myservo3.write(0);
      myservo4.write(170);
      delay(1700);
      myservo3.write(90);
      myservo4.write(170);
      delay(1000);
      myservo3.write(0);
      myservo4.write(170);
      delay(2000);
      myservo3.write(0);
      myservo4.write(90);
       delay(600);
       myservo3.write(0);
      myservo4.write(170);
      digitalWrite(LED, HIGH);
     }else if(a==2){      //左右相反  當a==2啟動右轉後動作
    if(R==0&&L==0&&M==0){ //停
      myservo3.write(90); //右邊馬達
      myservo4.write(90); //左邊馬達
      }else if(L==1&&M==1&&R==1&&LL==1){
        myservo3.write(0);
        myservo4.write(100);
      }else if(L==1&&M==1&&R==1&&LL==0){
      myservo3.write(750);
      myservo4.write(170);
      }else if(L==1&&M==1&&R==1&&RR==0){
      myservo3.write(0);
      myservo4.write(110);
      }else if(L==0&&M==1&&R==1){
      myservo3.write(65);
      myservo4.write(170);
      }else if(L==1&&M==1&&R==0){
      myservo3.write(0);
      myservo4.write(120);
      }else if(L==1&&M==0&&R==1){//前
     myservo3.write(0);
    myservo4.write(170);
        }
    }else if(a==1){        //當a==1啟動循線功能  
     if(RRR==0&&R==0){    //右轉
      delay(300);
      myservo3.write(0);
      myservo4.write(0);
      a=2;               //當a==2進入到啟動右轉後動作
      delay(800);
      myservo3.write(0);
      myservo4.write(170);
      delay(500);
      }else if(L==1&&M==1&&R==1&&LL==0){
      myservo3.write(180);
      myservo4.write(30);;
      }else if(L==1&&M==1&&R==1&&RR==0){
      myservo3.write(180);
      myservo4.write(80);;
      }else if(L==0&&M==1&&R==1){//向左修
      myservo3.write(180);
      myservo4.write(50);
      }else if(L==1&&M==1&&R==0){//向右修
      myservo3.write(180);
      myservo4.write(70);
     }else if(L==1&&M==0&&R==1){//前
     myservo3.write(180);
    myservo4.write(60);
    }
  }
}
