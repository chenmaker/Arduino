char copy[60];
int i;
String a,chr,c;
String data[10];
void setup() {
Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {
    // 讀取傳入的字元值
    c=Serial.readString();
    c.toCharArray(copy, 60);
    Serial.println(copy);
    }                           
}
