#include <SoftwareSerial.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  //SDA->A4SCL->A5
#define SOFT_TX 10
#define SOFT_RX 11
// [ PMSx003xx TX ] to [ Arduino PIN 11 ]
SoftwareSerial mySerial(SOFT_RX, SOFT_TX); // RX, TX
unsigned char gucRxBuf[100];
unsigned int pmcount25;
void setup() {
	Serial.begin(9600);
	mySerial.begin(9600);
 lcd.begin(20,4);
 lcd.noBacklight();
  delay(100);
  lcd.backlight(); 
  delay(100); 
}
void loop() {
  float temp;
  float humi;
	if(mySerial.available()){
		delay(100);
		unsigned char i=0;
		while(mySerial.available()){
			gucRxBuf[i] = mySerial.read();
			i++;
		}
		if (((gucRxBuf[0]==0x42)&&(gucRxBuf[1]==0x4d))&&(i>=12)){
			int chksum=0;
			unsigned char DTL=(gucRxBuf[2]<<8)+gucRxBuf[3];
			for(unsigned char i=0;i<(DTL+2);i++){chksum += gucRxBuf[i];}
			unsigned char csH = (chksum>>8);
			unsigned char csL = (chksum&0xFF);
			if((csH==gucRxBuf[DTL+2])&&(csL==gucRxBuf[DTL+3])){
				Serial.println("========= PMS5003T =========");
				pmcount25=gucRxBuf[22]*256+gucRxBuf[23];  
				temp=(float)(gucRxBuf[24]*256+gucRxBuf[25])/10;  
				humi=(float)(gucRxBuf[26]*256+gucRxBuf[27])/10; 
				Serial.print("PMcount2.5:");   
        Serial.println(pmcount25);
				Serial.print("Temperature:");  
        Serial.print(temp,1);       
        Serial.println(" C");
				Serial.print("Humidity:");     
				Serial.print(humi,1);       
				Serial.println(" %");
			}
		}
	} 
  lcd.setCursor(0,0); 
  lcd.print("T:");
  lcd.print(temp);
  lcd.print("C");
  lcd.setCursor(0,1); 
  lcd.print("H:");
  lcd.print(humi);
  lcd.print("%");
  lcd.setCursor(0,2);
  lcd.print("PM2.5:");
  lcd.setCursor(6,2); 
  lcd.print(pmcount25);
  if(pmcount25<10){
    lcd.setCursor(7,2); 
    lcd.print("  ");
    }else if(pmcount25<100){
    lcd.setCursor(8,2); 
    lcd.print(" ");
    }
}
