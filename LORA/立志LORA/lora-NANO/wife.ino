 void WiFi_Connect(){
  Serial.println(ATMode);
  delay(500);
  Serial.println(Serial.readString()); 
  Serial.println(ATMUX);
  delay(500);
  Serial.println(Serial.readString());
  Serial.println(TCP);
  delay(500);
  Serial.println(Serial.readString());   
  delay(500);
  GET = SQL_PHP;
  GET += Send_ID_1;
  GET += End;
  cmd="AT+CIPSEND=" + String(GET.length());  
  Serial.println(cmd);
  delay(500);
  Serial.println(GET);
  delay(500);
  Serial.println(GET);
  Serial.println(F("----------------------------------------------------------"));  
  GET="";  
}
