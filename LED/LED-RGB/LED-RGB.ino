#define LEDR 11 //定義角位
#define LEDG 10
#define LEDB 9

void setup() {                
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

int r = 0;
int g = 0;
int b = 0;
void loop() {
  r = random(0, 0);
  g = random(0, 0);
  b = random(0, 100);
  analogWrite(LEDR, r);
  analogWrite(LEDG, g);
  analogWrite(LEDB, b);
  delay(1000);
}
