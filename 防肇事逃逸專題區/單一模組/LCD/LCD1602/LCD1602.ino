//Import Wire.h.h and LiquidCrystal_I2C.h
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//LCD I2通訊設定
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //SDA->A4  SCL->A5
void setup()   
{
lcd.begin(16,2);  //設定螢幕長寬
  lcd.backlight(); //開啟背光
    delay(250);    
  lcd.noBacklight(); //關掉背光
      delay(250);
  lcd.backlight(); 
  lcd.setCursor(0,0);      //設定哪個點開始
  lcd.print(“HELLO”);    //從設定點開始顯示文字
  delay(100);
}
void loop(){}
