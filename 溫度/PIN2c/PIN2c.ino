//熱敏一端接電阻->A0
//熱敏另一端接5V
//電阻另一端接GND
#include <Thermistor.h>
Thermistor temp(0);
void setup() {
Serial.begin(9600);
}
void loop() {
int temperature = temp.getTemp();
Serial.print("The sensor temperature is: ");
Serial.print(temperature);
Serial.println("C");
delay(1000);
}

