const int motor1a = 4;
const int motor2a = 3;
int Botton_1;
int Botton_2;
int Botton_3;

void setup() {
  Serial.begin(9600);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(motor1a,OUTPUT);
  pinMode(motor2a,OUTPUT);
  
}
 int i=1;
 int n=1;
 int t=1;
void loop() {
  Botton_1 = digitalRead(5);
  Botton_2 = digitalRead(6);
  Botton_3 = digitalRead(7);
  delay(100);
   
  if(Botton_1 == HIGH){
    if(i==2&&Botton_1 == HIGH){  
        digitalWrite(motor1a,LOW);
        digitalWrite(motor2a,LOW);
        delay(100); 
        i=1; 
        }else  if(i == 1  ||  i==2){
        digitalWrite(motor1a,HIGH);
        digitalWrite(motor2a,LOW);
        delay(500);
        digitalWrite(motor1a,LOW);
        digitalWrite(motor2a,HIGH);
        delay(500);
        i=2;
      }
  }else if(Botton_1 == LOW&&i==1){
    digitalWrite(motor1a,LOW);
        digitalWrite(motor2a,LOW);
    delay(100); 
    }else if(Botton_1 == LOW&&i==2){
    digitalWrite(motor1a,HIGH);
        digitalWrite(motor2a,LOW);
        delay(500);
        digitalWrite(motor1a,LOW);
        digitalWrite(motor2a,HIGH);
        delay(500);
    }
    

   if(Botton_2 == HIGH){
    if(n==2&&Botton_2 == HIGH){  
        digitalWrite(motor1a,LOW);
        digitalWrite(motor2a,LOW);
        delay(100); 
        n=1;   
        }else  if(n == 1  ||  n==2){
        Serial.print("Botton_2 HIGH = ");
        Serial.println(Botton_2);
        digitalWrite(motor1a,HIGH);
        digitalWrite(motor2a,LOW);        
        digitalWrite(motor1a,LOW);
        digitalWrite(motor2a,HIGH);
        delay(500);
        n=2;
      }
  }
    if(Botton_3 == HIGH){
    if(t==2&&Botton_3 == HIGH){  
        digitalWrite(motor1a,LOW);
        digitalWrite(motor2a,LOW);
        delay(100); 
        t=1;   
        }else  if(t == 1  ||  t==2){
        Serial.print("Botton_3 HIGH = ");
        Serial.println(Botton_3);
        digitalWrite(motor1a,HIGH);
        digitalWrite(motor2a,LOW);
        digitalWrite(motor1a,LOW);
        digitalWrite(motor2a,HIGH);
        delay(1000);
        t=2;
      }
     }
}
