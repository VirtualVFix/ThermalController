/*
 * Nextion variable element
*/
#include "NextVariable.h"

NextVariable::NextVariable(byte page_id, byte obj_id, const char *obj_name)
             :NextObject(page_id, obj_id, obj_name){
          
}

void NextVariable::setText(const char *text){
  setString(text, "txt");
}

uint16_t NextVariable::getText(char *text, uint16_t len){
  return getString(text, "txt", len);
}

void NextVariable::setValue(uint32_t number){
  setNumber(number, "val");
}

void NextVariable::getValue(uint32_t &number){
  getNumber(number, "val");
}
