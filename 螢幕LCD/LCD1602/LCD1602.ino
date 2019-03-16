#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //SDA->A4SCL->A5
void setup()   
{ lcd.begin(16,2);
    /*lcd.backlight();
    delay(250);*/    
  lcd.noBacklight();
      delay(250);
  lcd.backlight(); 
  lcd.setCursor(0,0); 
  lcd.print("HELLO00000000000000000000");
  delay(100);
}
void loop()  
{
}
