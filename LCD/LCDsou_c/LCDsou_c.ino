//熱敏一端接電阻->A0
//熱敏另一端接5V
//電阻另一端接GND
#include <Wire.h>  // Comes with Arduino IDE
#include <LiquidCrystal_I2C.h>
#include <Thermistor.h>
Thermistor temp(0);
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //SDA->A4    SCL->A5
const int pingPin = 7;  //SIG->7˙
void setup()   
{
  Serial.begin(9600);   
   lcd.begin(16,2);  
  lcd.noBacklight();
  lcd.backlight(); 
}
long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
void loop() {
  int temperature = temp.getTemp();
  Serial.print("The sensor temperature is: ");
  Serial.print(temperature);
  Serial.println("C");
  lcd.setCursor(10,0);
  lcd.print(temperature);
  lcd.setCursor(12,0);
  lcd.print("C"); 
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  if (cm<10){
    lcd.setCursor(1,0);
    lcd.print(" ");
    lcd.setCursor(2,0);
    lcd.print(" ");
  }else if(cm<100){
    lcd.setCursor(2,0);
    lcd.print(" ");
      }
  if (inches<10){
    lcd.setCursor(1,1);
    lcd.print(" ");
    lcd.setCursor(2,1);
    lcd.print(" ");
  }else if(inches<100){
    lcd.setCursor(2,1);
    lcd.print(" ");
      }
  lcd.setCursor(0,0);
  lcd.print(cm);
  lcd.setCursor(3,0);
  lcd.print("cm");
  lcd.setCursor(0,1);
  lcd.print(inches); 
  lcd.setCursor(3,1);
  lcd.print("inches"); 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(500);
    }
