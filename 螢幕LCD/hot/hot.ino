#include <Thermistor.h>
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);   //SDA->A4    SCL->A5
Thermistor temp(0);
void setup() {
Serial.begin(9600);
delay(300);             //Let system settle   
Serial.println("Humidity and temperature\n\n");   
delay(700);   
  lcd.begin(16,2);  
  lcd.noBacklight();
      delay(250);
  lcd.backlight(); 
  lcd.setCursor(2,0); 
  lcd.print("temperature");
  delay(100);
}
void loop() {
int temperature = temp.getTemp();
Serial.print("holle");
Serial.print("The sensor temperature is: ");
Serial.print(temperature);
Serial.println("C");
delay(1000);
lcd.setCursor(5,1); 
  lcd.print(temperature);
  delay(100);
  lcd.setCursor(8,1); 
  lcd.print("C");
  delay(100);
}
