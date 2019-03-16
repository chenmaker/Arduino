#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //SDA->A4SCL->A5
int p=A1;
void setup()   
{ lcd.begin(16,2);
    /*lcd.backlight();
    delay(250);*/    
  lcd.noBacklight();
      delay(250);
  lcd.backlight(); 
  lcd.setCursor(0,0); 
  lcd.print("HELLO");
  delay(100);
}
void loop()  
{  int sv =analogRead(p);
float tt=sv*(5.0/1023.0);
if(sv<1000){
  lcd.setCursor(3,1);
    lcd.print(" ");
  }
  if(sv<100){
    lcd.setCursor(2,1);
    lcd.print(" ");
    }
    if(sv<10){
      lcd.setCursor(1,1);
    lcd.print(" ");
      }
  lcd.setCursor(0,1); 
 // lcd.print(sv,DEC);
 lcd.print(tt);
 lcd.print("V");
}
