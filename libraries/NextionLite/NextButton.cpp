/*
 * Nextion button element
*/
#include "NextButton.h"

NextButton::NextButton(byte page_id, byte obj_id, const char *obj_name)
           :NextObject(page_id, obj_id, obj_name),
            NextTouch(page_id, obj_id, obj_name){
          
}

void NextButton::setBackground(uint32_t number){
  setNumber(number, "picc");
}

void NextButton::getBackground(uint32_t &number){
  getNumber(number, "picc");
}
