/*
 * Nextion event module for serial communication
*/
#ifndef __NEXTEVENT_H__
#define __NEXTEVENT_H__

#include "NextConfig.h"
#include "NextTouch.h"

// send command to display
void sendCommand(const char* cmd);
// read number 
void reciveNumber(uint32_t &number); 
// recive string value. Returns length of string
uint16_t reciveString(char *buffer, uint16_t len);
// read page id
byte getCurrentPageId();
// nextion callback loop
void nextLoop(NextTouch **list);

#endif
