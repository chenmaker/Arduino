void setup() 
{
    Serial.begin(9600);
}
void loop() 
{
    float val = analogRead(A0);
    float v=val*(5.0/1024.0);
    Serial.print("V");
    Serial.println(V);
    delay(250);
}
