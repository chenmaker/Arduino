#include <SoftwareSerial.h>//call appinvetonr sound
const int pingPin = 7;
const int TX   = 10;
const int RX   = 11;
const int delay_time = 1000;
SoftwareSerial BT(RX, TX);
void setup() {
  Serial.begin(9600);
  BT.begin(9600);
  pinMode(pingPin, OUTPUT);
  Serial.println("Start!!!");
}

long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}
void loop() {
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(delay_time);
  int sendData = (int) (cm * 100); //cm 可以改成in
  byte packet[3]; 
  packet[0] = 97; //key send to phone
  packet[1] = sendData / 256; //divides sendData to two 1 byte packets
  packet[2] = sendData % 256;
  if(BT.available() > 0) //check BT is succeed
    if(BT.read() == 97) //check recieve key from phone
    {
      Serial.println("succeed!");
      for(int i = 0; i < 3; i++) 
        BT.write(packet[i]); //send packet to phone
    }
 }
