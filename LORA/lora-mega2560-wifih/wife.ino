void WiFi_Connect(){
  Serial2.println(ATMode);
  delay(500);
  Serial.println(Serial2.readString()); 
  Serial2.println(ATMUX);
  delay(500);
  Serial.println(Serial2.readString());
  Serial2.println(TCP);
  delay(500);
  Serial.println(Serial2.readString());   
  delay(500);
  GET = SQL_PHP;
  GET += Send_ID_1;
  GET += End;
  cmd="AT+CIPSEND=" + String(GET.length());  
  Serial2.println(cmd);
  delay(500);
  Serial2.println(GET);
  delay(500);
  Serial.println(GET);
  Serial.println(F("----------------------------------------------------------"));  
  GET="";  
}
