#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#include <dht.h>   
#define dht_dpin 8 //定義訊號要從Pin 8 進來  
dht DHT;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //SDA->A4SCL->A5
void setup()   
{
  Serial.begin(9600); 
delay(300);             //Let system settle   
Serial.println("Humidity and temperature\n\n");   
delay(700);   
   lcd.begin(16,2);
    /*lcd.backlight();
    delay(250);*/
  lcd.noBacklight();
 //     delay(250);
  lcd.backlight(); 
  lcd.setCursor(0,0); 
  lcd.print("HELLO");
  delay(100);
}
void loop()  
{
DHT.read11(dht_dpin);
 lcd.setCursor(0,1);
  lcd.print(DHT.temperature);
  delay(100);
  lcd.setCursor(5,1);
  lcd.print("C");
  delay(100);
  lcd.setCursor(8,1);
  lcd.print(DHT.humidity);
  lcd.setCursor(14,1);
  lcd.print("%");
  delay(100);
Serial.print("Humidity = ");   
Serial.print(DHT.humidity);   
Serial.print("% ");   
Serial.print("temperature = ");   
Serial.print(DHT.temperature);   
Serial.println("C ");
}
