/*
 * Nextion touch class 
*/
#ifndef __NEXTCONFIG_H__
#define __NEXTCONFIG_H__

#include <Arduino.h>

/* Nextion config  */
#define DEBUG_ENABLED // enable debug mode

// debug serial
#ifdef DEBUG_ENABLED
  #define debugPrint(a)    Serial.print(a)
  #define debugPrintHEX(a) Serial.print(a,HEX)
  #define debugPrintln(a)  Serial.println(a)
#else
  #define debugPrint(a)
  #define debugPrintHEX(a)
  #define debugPrintln(a)
#endif

#define NEXT_EVENT_FINISH 0x01 // finish header
#define NEXT_EVENT_PRESS 0x01 // press header
#define NEXT_EVENT_RELEASE 0x00 // release header 
#define NEXT_EVENT_NUMBER 0x71 // digit header
#define NEXT_EVENT_STRING 0x70 // string event
#define NEXT_EVENT_TOUCH 0x65 // touch header
#define NEXT_EVENT_PAGE_ID 0x66 // current page id header
#define NEXT_EVENT_WAIT_NUMBER_TIMEOUT 200 // timeout for wait number after send get command
/* ----------------- */

#endif
