#define M0 11
#define M1 12
const int bt =2;
const int led = 10;
String car="PO-2560";
#include <SoftwareSerial.h>
SoftwareSerial UART (3,4);//tx-->3   rx-->4
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //SDA->A4SCL->A5
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
String any,in;
int x;
char copy[50];
void setup() {
  Serial.begin(9600);
  UART.begin(9600);
  rtc.begin();
   //RTC();
  pinMode(bt, INPUT);//開關
  pinMode(led, OUTPUT); //LED輸出
  pinMode(M0,OUTPUT);
  pinMode(M1,OUTPUT);
  digitalWrite(M0,LOW);
  digitalWrite(M1,LOW);
  lcd.begin(16,2);
  lcd.noBacklight();
      delay(250);
  lcd.backlight(); 
  lcd.setCursor(0,0); 
  lcd.print("ME:PO-2560");
  lcd.setCursor(0,1); 
  lcd.print("YOU:");
  delay(100);
}
void loop() {    
any=(String(rtc.getDateStr())+"-"+String(rtc.getTimeStr()));
if(digitalRead(bt)==LOW){
    delay(800); 
    UART.print(car);
    UART.print(any); 
    }
  if(UART.available() > 0){
    String input = UART.readString();
    Serial.println(input);
    input.toCharArray(copy,20);
    if(input.length()>7){
       for(x=0;x<=7;x++){
      in=in +copy[x];
      Serial.println(copy[x]); 
               } 
    Serial.println(in);   
    lcd.print(in);
    lcd.setCursor(11,1); 
    lcd.print("         "); 
    digitalWrite(led, 255);  
    }
  }
}
