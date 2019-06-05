#include <SoftwareSerial.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <dht.h> 
#define dht_dpin 8
dht DHT;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);//SDA->A4SCL->A5
SoftwareSerial I2CBT(10,11);//定義PIN10及PIN11分別為RX及TX腳位藍芽
int LED1 = 13;
int LED2 = 2;
int LED3 = 3;
void setup(){
Serial.begin(9600);
I2CBT.begin(9600); 
pinMode(LED1,OUTPUT);
lcd.begin(16,2);
lcd.backlight();
delay(250);
lcd.noBacklight();
delay(250);
  lcd.backlight(); 
  lcd.setCursor(0,0); 
  lcd.print("HELLO");
  delay(500);
}
void loop() {
  DHT.read11(dht_dpin);
  lcd.setCursor(0,1);
  lcd.print(DHT.temperature);
  lcd.setCursor(5,1);
  lcd.print("C");
  lcd.setCursor(8,1);
  lcd.print(DHT.humidity);
  lcd.setCursor(14,1);
  lcd.print("%");
Serial.print("Humidity = ");   
Serial.print(DHT.humidity);   
Serial.print("% ");   
Serial.print("temperature = ");   
Serial.print(DHT.temperature);   
Serial.println("C ");
led();
String a="H:"+String(DHT.humidity)+"\n"+"T:"+String(DHT.temperature)+"\n";
I2CBT.print(a);
   delay(500);
}
