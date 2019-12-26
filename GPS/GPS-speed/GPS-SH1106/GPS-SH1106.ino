//GPS
#include <TinyGPS++.h>
#include <SoftwareSerial.h>
//OLED
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9//SDA
#define OLED_CLK   10//SCL
#define OLED_DC    11
#define OLED_CS    12
#define OLED_RESET 13
Adafruit_SH1106 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);
//GPS  
static const int RXPin = 4, TXPin = 3;//GPS TX-->4 RX-->3
static const uint32_t GPSBaud = 9600;//與GPS包綠
TinyGPSPlus gps;
SoftwareSerial ss(RXPin, TXPin);

void setup()
{
  Serial.begin(115200);
  ss.begin(GPSBaud);
  display.begin(SH1106_SWITCHCAPVCC);
  display.clearDisplay();
  display.setTextSize(3);             
  display.setTextColor(WHITE);       
  display.setCursor(25,20);            
  display.println("Hello");
  display.display();
  delay(1500);
}

void loop()
{ //Serial.println(gps.speed.kmph());
 // delay(100);
  while (ss.available() > 0)
    if (gps.encode(ss.read()))
      displayInfo();

  if (millis() > 5000 && gps.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
    while(true);
  }
  display.clearDisplay();
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(0,0);             
  display.println(gps.location.lat());
  display.setTextSize(2);             
  display.setTextColor(WHITE);        
  display.setCursor(0,32);             
  display.println(gps.location.lng());
  /*display.setTextSize(1);             
  display.setTextColor(WHITE);        
  display.setCursor(0,50);             
  display.println(gps.time.second());*/
  display.display();
}
