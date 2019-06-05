#include "U8glib.h"

U8GLIB_SH1106_128X64 u8g(U8G_I2C_OPT_NONE); // I2C / TWI 

const uint8_t bm[] PROGMEM = {
  0b00011000,
  0b00111100,
  0b01111110,
  0b11111111,
  0b11111111,
  0b01111110,
  0b00111100,
  0b00011000
};

static int WIDTH=128;
static int HEIGHT=64;

int x, y;

void setup(void) {
  x = 0;
  y = 0;
}

void loop(void) {

  u8g.firstPage();  
  do {
    u8g.drawBitmapP( x, y, 1, 8, bm);
  } while( u8g.nextPage() );
  
  delay(100);

  x += 8;
  if( x >= WIDTH){
    x = 0;
    y += 8;
    if( y >= HEIGHT){
      y = 0;
    }
  }
}
