/*
 * Nextion event module for serial communication
*/
#include "NextEvent.h"

// send command to display
void __sendCommand(const char* cmd){
  while (Serial.available() > 0){
    Serial.read();
  }
  Serial.print(cmd);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}

void sendCommand(const char* cmd){
    __sendCommand("");
    __sendCommand(cmd);
    debugPrintln("");
}

// read number
void reciveNumber(uint32_t &number){
  byte data[7] = {0};
  byte current = 0;
  Serial.setTimeout(10);
  
  unsigned long timestamp = millis();
  // wait for recive number after send get command
  while (millis()-timestamp < NEXT_EVENT_WAIT_NUMBER_TIMEOUT){
    current = Serial.read();
    if (current == NEXT_EVENT_NUMBER){
      if (sizeof(data) != Serial.readBytes((char *)data, sizeof(data))){
        continue;
      }else{
        if (data[4] == 0xff && data[5] == 0xff && data[6] == 0xff){
          number = ((uint32_t)data[3] << 24) | ((uint32_t)data[2] << 16) | (data[1] << 8) | (data[0]);
          
          //debugPrintln("RECIVED ");
          //for (int8_t i=-1; i<7; i++){
          //  debugPrint("0x");
          //  debugPrintHEX(i==-1 ? current : data[i]);
          //  debugPrint(" ");
          //}
          debugPrintln("");
          debugPrint("| NUMBER: ");
          debugPrintln(number);
          //debugPrint(" | TIME: ");
          //debugPrintln(millis()-timestamp);
          
          return;
        }
      }
    }
  }
  debugPrintln("WAIT FOR NUMBER TIMEOUT EXPIRED !");
}

// recive string value. Returns length of string
uint16_t reciveString(char *buffer, uint16_t len){
  byte current = 0;
  byte _0xff = 0;
  String result = String("");
  Serial.setTimeout(10);
  bool start_flag = false;
    
  unsigned long timestamp = millis();
  // wait for recive number after send get command
  while (millis()-timestamp < NEXT_EVENT_WAIT_NUMBER_TIMEOUT){
    if (Serial.available() > 0){
        current = Serial.read();
        if (start_flag){
            if (current == 0xff){
                _0xff++;
                if (_0xff >= 3){
                    uint16_t _length = result.length();
                    _length = _length > len ? len: _length;
                    strncpy(buffer, result.c_str(), _length);
                    
                    debugPrintln("");
                    debugPrint("STRING: ");
                    debugPrintln(result.c_str());
                    //debugPrint(" | TIME: ");
                    //debugPrintln(millis()-timestamp);
                    //debugPrintln(" ");
                    
                    return _length;
                }
            }else{
                result += (char)current;
            }
        }else if (current == NEXT_EVENT_STRING){
            start_flag = true;
        }
    }
  }
  debugPrintln("WAIT FOR STRING TIMEOUT EXPIRED !");
  return 0;
}

// read page id
byte getCurrentPageId(){
  // send page request
  sendCommand("sendme");
  
  byte data[4] = {0};
  byte current = 0;
  byte number;
  Serial.setTimeout(5);
  
  unsigned long timestamp = millis();
  // wait for recive number after send get command
  while (millis()-timestamp < NEXT_EVENT_WAIT_NUMBER_TIMEOUT){
    current = Serial.read();
    if (current == NEXT_EVENT_PAGE_ID){
      if (sizeof(data) != Serial.readBytes((char *)data, sizeof(data))){
        continue;
      }else{
        if (data[1] == 0xff && data[2] == 0xff && data[3] == 0xff){          
          number = data[0];
          
          //debugPrintln("RECIVED ");
          //for (int8_t i=-1; i<4; i++){
          //  debugPrint("0x");
          //  debugPrintHEX(i==-1 ? current : data[i]);
          //  debugPrint(" ");
          //}
          //debugPrint("| NUMBER: ");
          //debugPrint(number);
          //debugPrint(" | TIME: ");
          //debugPrintln(millis()-timestamp);
          
          return number;
        }
      }
    }
  }
  debugPrintln("WAIT FOR NUMBER TIMEOUT EXPIRED !");
  return 255;
}

// nextion callback loop
void nextLoop(NextTouch **list){
  byte data[6] = {0};
  byte current = 0;
  NextTouch *obj = NULL;
  Serial.setTimeout(10);
  
  while (Serial.available() > 0){
    current = Serial.read();
    // find touch event
    if (current == NEXT_EVENT_TOUCH){
      if (sizeof(data) != Serial.readBytes((char *)data, sizeof(data))){
        return;
      }
      debugPrintln("");
      debugPrint("TOUCH EVENT ");
      for (int8_t i=-1; i<6; i++){
        debugPrint("0x");
        debugPrintHEX(i==-1 ? current : data[i]);
        debugPrint(" ");
      }
      
      // check if data is full
      if (data[3] == 0xff && data[4] == 0xff && data[5] == 0xff){
        for (byte i=0; (obj = list[i]) != NULL; i++){
          // check element by id
          if ((byte)data[0] == obj->getPageId() && (byte)data[1] == obj->getObjectId()){
            if (data[2] == NEXT_EVENT_PRESS){ // press event 
              //debugPrintln("PRESSS EVENT");
              obj->pressCallback();
            }else if (data[2] == NEXT_EVENT_RELEASE){ // release event
              //debugPrintln("RELEASE EVENT");
              obj->releaseCallback();
            }
            return;
          }
        }
       //debugPrintln("CALLBACK N/A");
      }
    }
  }
}