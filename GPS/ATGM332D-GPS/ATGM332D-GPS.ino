void setup()    
{
  Serial.begin(9600);           //定义波特率9600
  Serial.println("Wating...");
}

void loop()     
{
  while (Serial.available()) {   
     Serial.write(Serial.read());//收到GPS数据则通过串口输出
  }
}
