//先加入DFPlayer_Mini_mp3.zip請看步驟1和2
//http://www.dfrobot.com/wiki/index.php/DFPlayer_Mini_SKU:DFR0299  mp3模組說明網址
//https://www.arduino.cc/en/Tutorial/Ping   超音波說明網址
//使用mp3模組和28015 REV C超音波模組
//修改完上傳前要把TX RX的線拔掉才能上傳  上傳完畢再把線插回去
#include <DFPlayer_Mini_Mp3.h>     //加入資料庫
#include <SoftwareSerial.h>
int led = 3;                       //定義腳位
const int sig = 2;                 //超音波輸入腳(SIG)
SoftwareSerial mySerial(0, 1);      // RX, TX
long msTOcm(long ms) {             //超音波的速率換算   ms=microsecond(微秒)  cm=Centimeter(公分)
  return ms / 29 / 2;
  }
void setup() {
     Serial.begin (9600);           //uno傳輸率(鮑率)在這裡固定9600
    //  pinMode(2, OUTPUT); 
    mp3_set_serial (Serial);        //把資料庫和MP3模組做結合 
    mp3_set_volume (100);          //音量大小  
}
void loop() {
long du,cm;                        //du=duration(為期)
pinMode(sig, OUTPUT);              //輸出
digitalWrite(sig, LOW);            //低頻
delayMicroseconds(2);              //2微秒
digitalWrite(sig, HIGH);           //高頻
delayMicroseconds(5);              //5微秒
pinMode(sig, INPUT);               //接受輸入
du = pulseIn(sig, HIGH);
cm = msTOcm(du);
Serial.print(cm);                //參考步驟3
Serial.print("cm");
Serial.println(); 
if( cm >=20 || cm == 0){         //邏輯判斷當cm1>=20和cm1=0  LED不會亮
  digitalWrite(led, LOW);
  }else{                         //否則會亮
   digitalWrite(led,HIGH);
   mp3_play (1);                 //播放第一首歌
   delay(3000);                  //延遲3秒剛好播完這一段話(1000=1秒)
   mp3_stop();                   //停止播放  繼續偵測                        
      }   
  delay(10);                  //控制偵測時間間格   最低10 因為10跟1一樣
}
