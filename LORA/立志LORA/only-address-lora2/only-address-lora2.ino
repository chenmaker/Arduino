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
void setup() {
  Serial.begin(9600);
  UART.begin(9600);
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
  if(digitalRead(bt)==LOW){
    delay(800); 
    UART.print(car); 
    }
    if(UART.available() > 0){
    String input = UART.readString(); 
    lcd.print(input);
    lcd.setCursor(11,1); 
    lcd.print("         "); 
    digitalWrite(led, 255);  
  }
}
