#include "Demo.h"

float frame = 0;

float DemoFunc(byte _step, int8_t _min, int8_t _max){
  float range = (_max-_min)/2;
  return range*sin(frame++/_step)+range+_min;
}
