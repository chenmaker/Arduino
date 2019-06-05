#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "A.h"

A::A(void)
{
  }
void A::set(uint8_t pin)
{ 
  } 
void A::update(void)
{ 
  float val = analogRead(m_v);
  float v=val*(5.0/1024.0);
  Serial.println(v);
  pinMode(D,OUTPUT);
  if(v>=2.3){
	  digitalWrite(D,HIGH);
    }
  else 
  if(v<=2.3){
	  digitalWrite(D,LOW);
    }
   
  }
