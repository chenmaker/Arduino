int p=2;
int l=13;
int total=0;
int x = 0;
volatile unsigned pulse;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(l, OUTPUT);
pinMode(p,INPUT);
attachInterrupt(digitalPinToInterrupt(p),count_pulse,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulse=0;
  interrupts();
  delay(500);
  noInterrupts();
  if(pulse>=1000){
    digitalWrite(l, HIGH);
    
    }
    else{
      digitalWrite(l, LOW);
      
      }
      delay(100);

  Serial.print("p");
  Serial.println(pulse);
  total = 0;
  
}
void count_pulse()
{
  pulse++;
  }
