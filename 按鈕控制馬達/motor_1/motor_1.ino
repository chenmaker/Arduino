const int motor1a = 4;
const int motor2a = 3;
const int e12 = 5;

const int motor3a = 8;
const int motor4a = 9;
const int e34 = 10;

void setup()
{
  pinMode(motor1a,OUTPUT);
  pinMode(motor2a,OUTPUT);
  pinMode(e12,OUTPUT);

  pinMode(motor3a,OUTPUT);
  pinMode(motor4a,OUTPUT);
  pinMode(e34,OUTPUT);

  digitalWrite(e12,HIGH);
  digitalWrite(e34,HIGH);
}

void loop()
{
  run();
}

void run()
{
  digitalWrite(motor1a,HIGH);
  digitalWrite(motor2a,LOW);
  //digitalWrite(motor3a,HIGH);
  //digitalWrite(motor4a,LOW);
  delay(3000);
  digitalWrite(motor1a,LOW);
  digitalWrite(motor2a,HIGH);
  //digitalWrite(motor3a,LOW);
  //digitalWrite(motor4a,HIGH);
  delay(3000);
}
