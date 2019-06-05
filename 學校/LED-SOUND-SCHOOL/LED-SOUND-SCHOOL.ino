int p=2;
//int l=13;
int total=0;
int x = 0;
//int r = 13;
//int g = 12;
//int b = 11;
const byte c[]={11,12,13};
int i;
volatile unsigned pulse;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
for(i=0;i<3;i++){
  pinMode(c[i],OUTPUT);
  }
pinMode(p,INPUT);
attachInterrupt(digitalPinToInterrupt(p),count_pulse,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
  pulse=0;
  //interrupts();
  delay(500);
  //noInterrupts();
  if(pulse>=1000){
    for(i=0;i<3;i++){
      digitalWrite(c[i],HIGH);
      delay(500);
      digitalWrite(c[i],LOW);
      delay(500);
    }}
    else{
      digitalWrite(c[0], LOW);
      digitalWrite(c[1], LOW);
      digitalWrite(c[2], LOW);
      }
      delay(500);

  Serial.print("p");
  Serial.println(pulse);
  total = 0;
  
}
void count_pulse()
{
  pulse++;
  }
