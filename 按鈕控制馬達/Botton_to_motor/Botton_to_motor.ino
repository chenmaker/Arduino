// ======= Arduino : Button to motor =======
int motor_1 = 3 , motor_2 = 4;
int Botton_1,Botton_2,Botton_3;

void setup() {
  pinMode(motor_1|motor_2,INPUT);
  pinMode(Botton_1|Botton_2|Botton_3,INPUT);
}

void motor(int Time){
  while(1){
    digitalWrite(motor_1,HIGH);
    digitalWrite(motor_2,LOW);
    delay(Time);
    digitalWrite(motor_1,LOW);
    digitalWrite(motor_2,HIGH);
    delay(Time); 
    Botton_1 = digitalRead(5);
    Botton_2 = digitalRead(6);
    Botton_3 = digitalRead(7);  
    if(Botton_1|Botton_2|Botton_3 == HIGH){
        Stop();
        break;
    }
  } 
}

void Stop(){
  digitalWrite(motor_2,LOW);
  digitalWrite(motor_1,LOW);
  delay(1000);
}

void loop() { 
  Botton_1 = digitalRead(5);
  Botton_2 = digitalRead(6);
  Botton_3 = digitalRead(7);  
  delay(100);

  if(Botton_1 == HIGH){
    motor(100); 
  }  
  if(Botton_2 == HIGH){
    motor(500); 
  } 
  if(Botton_3 == HIGH){
    motor(1000);      
  }
}
