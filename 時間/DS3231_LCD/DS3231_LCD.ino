#include <DS3231.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//DS3231 Clock;
bool Century=false;
bool h12;
bool PM;
byte ADay, AHour, AMinute, ASecond, ABits;
bool ADy, A12h, Apm;
byte year, month, date, DoW, hour, minute, second;

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
void setup() {
// Start the I2C interface
Wire.begin();
Clock.setSecond(10);//Set the second
Clock.setMinute(44);//Set the minute
Clock.setHour(2); //Set the hour
Clock.setDoW(4); //Set the day of the week
Clock.setDate(7); //Set the date of the month
Clock.setMonth(2); //Set the month of the year
Clock.setYear(19); //Set the year (Last two digits of the year)
// Start the serial interface
Serial.begin(9600);

// 初始化 LCD，一行 16 的字元，共 2 行，預設開啟背光
lcd.begin(16, 2);
lcd.noBacklight(); // 關閉背光
delay(250);
lcd.backlight();
}
void loop() {
 int second,minute,hour,date,month,year,temperature;
second=Clock.getSecond();
minute=Clock.getMinute();
hour=Clock.getHour(h12, PM);
date=Clock.getDate();
month=Clock.getMonth(Century);
year=Clock.getYear();
temperature=Clock.getTemperature();
Serial.print("20");
Serial.print(year,DEC);
Serial.print("-");
Serial.print(month,DEC);
Serial.print("-");
Serial.print(date,DEC);
Serial.print(" ");
Serial.print(hour,DEC);
Serial.print(":");
Serial.print(minute,DEC);
Serial.print(":");
Serial.print(second,DEC);
Serial.print("\n");
Serial.print("Temperature=");
Serial.print(temperature);
Serial.print("\n");
lcd.setCursor(0, 0); // 設定游標位置在第一行行首
lcd.print("time");
lcd.setCursor(0, 1);
lcd.print("Time=");
lcd.setCursor(5, 1); // 設定游標位置在第二行行首
lcd.print(hour,DEC);
lcd.setCursor(7, 1);
lcd.print(":");
lcd.setCursor(8, 1);
lcd.print(minute,DEC);
lcd.setCursor(10, 1);
lcd.print(":");
lcd.setCursor(11, 1);
lcd.print(second,DEC);
delay(1000);
}
