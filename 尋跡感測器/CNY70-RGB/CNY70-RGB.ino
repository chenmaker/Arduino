int pinReceptor = A0; //Establecemos el pin a leer
int sensorVal; //Declaramos una variable para almacenar el valor de la lectura
void setup(){
Serial.begin(9600); // Abrimos comunicación Serial
  pinMode(11, OUTPUT);//r
  pinMode(10, OUTPUT);//g
  pinMode(9, OUTPUT); //b 
}

void loop(){
sensorVal = analogRead(pinReceptor);
Serial.println(sensorVal); 
  if(sensorVal>=44&&sensorVal<=50){
    digitalWrite(11, HIGH);
  }else if(sensorVal>=7&&sensorVal<=8){
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
  }else if(sensorVal>=14&&sensorVal<=16){
    digitalWrite(9, HIGH);
  }else {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    }
    delay(300);
}
