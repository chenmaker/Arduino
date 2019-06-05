void WiFi_Connect(){
  UART.println(ATMode);
  delay(500);
  Serial.println(UART.readString()); 
  UART.println(ATMUX);
  delay(500);
  Serial.println(UART.readString());
  UART.println(TCP);
  delay(500);
  Serial.println(Serial.readString());   
  delay(500);
  GET = SQL_PHP;
  GET += Send_ID_1;
  GET += End;
  MySQL_SendData();
}
void MySQL_SendData(){
  cmd="AT+CIPSEND=" + String(GET.length());  
  UART.println(cmd);
  delay(500);
  UART.println(GET);
  delay(500);
  Serial.println(GET);
  Serial.println(F("----------------------------------------------------------"));  
  GET="";  
}
