/*
 * Nextion object
*/
#include "NextObject.h"

NextObject::NextObject(byte page_id, byte obj_id, const char *obj_name)
           :NextBase(page_id, obj_id, obj_name){
}

void NextObject::getNumber(uint32_t &number, const char *cmd){
  String str = "";
  str += "get ";
  str += getObjectName();
  str += ".";
  str += cmd;
  sendCommand(str.c_str());
  reciveNumber(number);
}

uint16_t NextObject::getString(char *buff, const char *cmd, uint16_t len){
  String str = "";
  str += "get ";
  str += getObjectName();
  str += ".";
  str += cmd;
  sendCommand(str.c_str());
  return reciveString(buff, len);
}

void NextObject::setString(const char *buff, const char *cmd){
  String str = "";
  str += getObjectName();
  str += ".";
  str += cmd;
  str += "=\"";
  str += buff;
  str += "\"";
  sendCommand(str.c_str());
}

void NextObject::setNumber(uint32_t number, const char *cmd){
  char num[12] = {0};
  String str = "";
  utoa(number, num, 10);
  str += getObjectName();
  str += ".";
  str += cmd;
  str += "=";
  str += num;
  sendCommand(str.c_str());
}

//void NextObject::getWidth(uint32_t &number){
//  getNumber(number, "w");
//}

//void NextObject::getHeight(uint32_t &number){
//  getNumber(number, "h");
//}

