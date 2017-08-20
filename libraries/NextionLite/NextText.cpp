/*
 * Nextion text element
*/
#include "NextText.h"

NextText::NextText(byte page_id, byte obj_id, const char *obj_name)
        :NextObject(page_id, obj_id, obj_name){
          
}

void NextText::setText(const char *text){
  setString(text, "txt");
}

uint16_t NextText::getText(char *text, uint16_t len){
  return getString(text, "txt", len);
}

void NextText::setBackground(uint32_t number){
  setNumber(number, "picc");
}
