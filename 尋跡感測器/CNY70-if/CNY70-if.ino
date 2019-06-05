int pinReceptor = A0; 
int sensorVal; 
void setup(){
Serial.begin(9600); 
pinMode(13, OUTPUT); 
pinMode(2, OUTPUT);
}

void loop(){
sensorVal = analogRead(pinReceptor); 
Serial.println(sensorVal); 
if(sensorVal>=19&&sensorVal<=20){
  digitalWrite(13,HIGH);
  }else{
    digitalWrite(13,LOW);
    }
if(sensorVal>=27&&sensorVal<=30){
  digitalWrite(2,HIGH);
  }else{
    digitalWrite(2,LOW);
    }
}
