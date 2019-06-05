#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // Pin10->TX Pin11->RX
//T1 115200
//AT+NAME:自訂名稱
//AT+NAME?查詢名稱
//AT+UART:115200,0,0
//AT+UART?
//AT+PSWD=自訂密碼
//AT+ORGL還原設置
//AT+VERSION?版本查詢
//
void setup()
{
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTSerial.begin(115200);  // HC-05 default speed in AT command more
}

void loop()
{

  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (BTSerial.available())
    Serial.write(BTSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    BTSerial.write(Serial.read());
}
