#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
#include <DS3231.h>
DS3231  rtc(SDA, SCL);
String any;
void setup()
{
  Serial.begin(9600);
  rtc.begin();
  
  //The following lines can be uncommented to set the date and time
  rtc.setDOW(THURSDAY);     // Set Day-of-Week to SUNDAY
  rtc.setTime(3,25,10);     // Set the time to 12:00:00 (24hr format)
  rtc.setDate(7, 2, 2019);   // Set the date to January 1st, 2014
 lcd.begin(16, 2);
lcd.noBacklight(); // 關閉背光
delay(250);
lcd.backlight();
}

void loop()
{
  // Send Day-of-Week
  Serial.print(rtc.getDOWStr());
  Serial.print(" ");
  
  // Send date
  Serial.print(rtc.getDateStr());
  Serial.print(" -- ");

  // Send time
  Serial.println(rtc.getTimeStr());
  
  // Wait one second before repeating :)
 //any=(String(rtc.getDOWStr())+" "+String(rtc.getDateStr())+"--"+String(rtc.getTimeStr())); 
 any=(String(rtc.getDateStr())+"-"+String(rtc.getTimeStr())); 
 Serial.println(any);
lcd.setCursor(0, 0); // 設定游標位置在第一行行首
lcd.print("time");
lcd.setCursor(0, 1);
lcd.print("Time=");
lcd.setCursor(5, 1); // 設定游標位置在第二行行首
lcd.print(rtc.getTimeStr());
delay (1000);
}
