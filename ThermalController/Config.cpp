#include "Config.h"

dinamic_config CONFIG;

void printMemory(const char* msg){
   debugPrintln("");
   debugPrint(msg);
   debugPrint(" free ram: ");
   debugPrintln(freeMemory());
   debugPrintln("");
}

//LimitedList::LimitedList(){
//  __count = 0;
//  __limit = 195;
//  for (byte i=0; i<__limit; i++){
//    wave[i] = 0;
//  }
//}
//
//void LimitedList::add(byte value){
//  if (__count < __limit){
//    wave[__count++] = value;
//  }else{  
//    for (byte i=0; i<__limit-1; i++){
//      wave[i] = wave[i+1];
//    }
//    wave[__limit-1] = value;
//  }
//  
//  for (byte i=0; i<__count; i++){
//    debugPrint(wave[i]);
//    debugPrint(" ");
//  }
//  debugPrintln("");
//  debugPrintln(__count);
//}
