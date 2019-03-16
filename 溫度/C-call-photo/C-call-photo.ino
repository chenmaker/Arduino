//chen2017/12/18
#include <SoftwareSerial.h>
#include <Wire.h>
//#include <Thermistor.h>
//Thermistor temp(0);
#include <LiquidCrystal_I2C.h>
#include <dht.h> 
#define dht_dpin 8
dht DHT;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);//SDA->A4SCL->A5
SoftwareSerial I2CBT(10,11);//定義PIN10及PIN11分別為RX及TX腳位
//byte serialA;
const int pingPin = 7;
int LED1 = 1;
int LED2 = 2;
int LED3 = 3;
int i= A0;
void setup(){
    Serial.begin(9600);
    I2CBT.begin(9600); 
    Serial.println("Humidity and temperature\n\n");   
   lcd.begin(16,2);
    /*lcd.backlight();
    delay(250);*/
  lcd.noBacklight();
 //delay(250);
  lcd.backlight(); 
  lcd.setCursor(0,0); 
  lcd.print("HELLO");
 // delay(100);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);            
}
long microsecondsToInches(long microseconds) {
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
void loop (){
  int d =analogRead(i);
  DHT.read11(dht_dpin);
  lcd.setCursor(0,1);
  //lcd.print(DHT.temperature);
  lcd.print(d);
  //delay(100);
  lcd.setCursor(5,1);
  lcd.print("C");
 // delay(100);
  lcd.setCursor(8,1);
  lcd.print(DHT.humidity);
  lcd.setCursor(14,1);
  lcd.print("%");
  //delay(100);
Serial.print("i ");   
Serial.print(i); 
Serial.print("Humidity = ");   
Serial.print(DHT.humidity);   
Serial.print("% ");   
Serial.print("temperature = ");   
Serial.print(DHT.temperature);   
Serial.println("C ");
  //int temperature = temp.getTemp();
   /*byte Data[2];                         //此變數為封包 
   byte cmmd[20];
   int insize;
   int i=DHT.temperature;//讀取感應器值
   serialA=I2CBT.read();                 //接收 Android 藍芽資料
   
   //   將感應器數值包成封包，由於類比腳位的值為0~1023，加上'a'，因此使用了三個Byte來傳送。
   //   readingIR 除以 256 以及對 256 取餘數就是以位元組（8 bits）為單位來拆封包噢！ 
   Data[0]='a';                    //確認碼
   //Data[1]=readingTemp/256;
   Data[1]=i/256;
   //Data[2]=readingTemp%256;
   Data[2]=i%256;
   Serial.println(i);    //顯示感應器數值
   if (serialA == 49){    //判斷從手機接收到的訊號是否為"49"
   /* 傳送封包 */
  /* for(int j=0;j<2;j++)
     I2CBT.write(Data[j]);   
   serialA=0;   
   }
   delay(100);*/
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println(); 
   
  if (cm<10){
    lcd.setCursor(9,0);
    lcd.print(" ");
    lcd.setCursor(10,0);
    lcd.print(" ");
     digitalWrite(LED1, LOW);
     digitalWrite(LED2, HIGH);
     digitalWrite(LED3, LOW);     
  }else if(cm<100){
    lcd.setCursor(10,0);
    lcd.print(" ");
    digitalWrite(LED1, LOW);
     digitalWrite(LED2, LOW);
     digitalWrite(LED3, HIGH);
  }  else if (cm>200){
   digitalWrite(LED1, HIGH);
   digitalWrite(LED2, LOW);
   digitalWrite(LED3, LOW);
      }
  lcd.setCursor(8,0);
  lcd.print(cm);
  lcd.setCursor(14,0);
  lcd.print("cm");
 // delay(100);
  String a="H:"+String(DHT.humidity)+"\n"+"T:"+String(DHT.temperature)+"\n"+"cm"+String(cm);
  /* String a="H:";
   a+=String(DHT.humidity);
   a+="\n";
   a+="T:";
   a+=String(DHT.temperature);
   a+="\n";
   a+="cm:";
   a+=String(cm);*/
   I2CBT.print(a);
   delay(500);
}

