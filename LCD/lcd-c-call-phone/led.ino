void led(){
int t=DHT.temperature;
int h=DHT.humidity;
  if(t>=30){
  digitalWrite(LED1, HIGH);
  }else{
    digitalWrite(LED1, LOW);
    }
}  
