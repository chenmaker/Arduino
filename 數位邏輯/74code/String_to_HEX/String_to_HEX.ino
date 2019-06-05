char copy[60];
int le;
int x;
String c;
void setup(){
Serial.begin(9600);
}
void loop(){
if(Serial.available()){
x= Serial.read();
Serial.write(x);
Serial.print("=");
Serial.println(x,HEX);
  }
}
