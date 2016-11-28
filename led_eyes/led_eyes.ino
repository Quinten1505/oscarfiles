#include <math.h>
#include "Wire.h"

int happy[8] = {
  B00000000,
  B00011000,
  B00111100,
  B01100110,
  B01000010,
  B01000010,
  B00000000,
  B00000000};
int wink[8] = {
  B00000000,
  B00000000,
  B00000000,
  B01111110,
  B01111110,
  B00000000,
  B00000000,
  B00000000};
int neutral[8] = {
  B00111100,
  B01111110,
  B11111111,
  B11111111,
  B11111111,
  B11111111,
  B01111110,
  B00111100};
int die[8] = {
  B00000000,
  B01000010,
  B00111100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B00000000};

void setup(){
  Wire.begin(); // wake up I2C bus
  // set I/O pins to outputs

}

void loop(){
  int var = 0;

  switch (var) {
  case 1:
    // be happy
    for (int i = 0; i < 8; i++) {
      eyes(happy[i]);
    }
    break;
  case 2:
    // blink
    for (int i = 0; i < 8; i++) {
      eyes(wink[i]);
    }
    break;
  case 3:
    // die
    for (int i = 0; i < 8; i++) {
      eyes(die[i]);
    }
    break;
  default:
    // neutral expression
    for (int i = 0; i < 8; i++) {
      eyes(neutral[i]);
    }
    break;

  }
}

void eyes(int expr){

  Wire.beginTransmission(0x20);
  Wire.write(0x00); // IODIRA register
  Wire.write(expr); // set all of port A to outputs
  Wire.endTransmission();
  Wire.beginTransmission(0x20);
  Wire.write(0x01); // IODIRB register
  Wire.write(expr); // set all of port B to outputs
  Wire.endTransmission();
}

