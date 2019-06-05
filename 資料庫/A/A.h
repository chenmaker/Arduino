#ifndef A_h
#define A_h
#include<inttypes.h>
class A
{public:
  uint8_t m_v;
  int D=4;
  
  A(void);
  void set(uint8_t pin);
  void update(void);
  };
#endif