#include<A.h>
#define v1 A0
A t;
void setup() {
  Serial.begin(9600);
  t.set(v1);
}

void loop() {
t.update();
delay(200);
}
