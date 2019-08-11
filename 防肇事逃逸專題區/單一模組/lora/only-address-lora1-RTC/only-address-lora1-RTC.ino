#define M0 11          //lora M0接腳
#define M1 12          //lora M1接腳
const int bt =2;       //微動開關腳位
const int led = 10;    //LED燈腳位
String car="MC-4180";  //我方車牌設定
#include <SoftwareSerial.h>
SoftwareSerial UART (3,4);//lora接腳   tx-->3   rx-->4  
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>//匯入LCD函示庫
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //設定LCD腳位  SDA->A4SCL->A5 
#include <DS3231.h>    //時間模組函示庫
DS3231  rtc(SDA, SCL); //時間模組腳位
String any,in;
int x;
char copy[50];
void setup() {
  Serial.begin(9600);
  UART.begin(9600);
  rtc.begin();
  //RTC();                 //註解時為無法改寫時間
  pinMode(bt, INPUT);      //開關
  pinMode(led, OUTPUT);    //LED輸出
  pinMode(M0,OUTPUT);      //M0輸出
  pinMode(M1,OUTPUT);      //M1輸出
  digitalWrite(M0,LOW);    //設定M0狀態
  digitalWrite(M1,LOW);    //設定M1狀態
  lcd.begin(16,2);         //LCD規格
  lcd.noBacklight();       //LCD關閉背光
      delay(250);
  lcd.backlight();         //LCD開啟背光
  lcd.setCursor(0,0);      //顯示開始位置
  lcd.print("ME:MC-4180"); //顯示我方車牌
  lcd.setCursor(0,1);      
  lcd.print("YOU:");       
  delay(100);
}
void loop() {  
any=(String(rtc.getDateStr())+"-"+String(rtc.getTimeStr())); //時間資訊及合成any字串
if(digitalRead(bt)==LOW){              //當微動開關碰撞時
    delay(400); 
    UART.print(car);                   //透UART把car的資訊傳出去
    UART.print(any);                   //透UART把any的資訊傳出去
    }
 if(UART.available() > 0){             //當UART有接受到大於0的資料時
    String input = UART.readString();  //設定String input為接受到的東西
    Serial.println(input);             //列印出input的東西
    input.toCharArray(copy,20);        //分解input字串變成一個字元單獨放到copy的陣列裡面
    if(input.length()>7){              //當input總長度大於7的時候
       for(x=0;x<=7;x++){              //從第0個位置開始
      in=in +copy[x];                  //把相對應的字元放到in
      Serial.println(copy[x]);         
               } 
    Serial.println(in);               //列印出in的東西
    lcd.print(in);                    //在LCD上面顯示
    lcd.setCursor(11,1);              //清空後面的亂碼
    lcd.print("         "); 
    digitalWrite(led, 255);           //讓LED燈亮
    }
  }
}
