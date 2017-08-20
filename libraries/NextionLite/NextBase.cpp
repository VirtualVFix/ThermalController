/*
 * Nextion base class 
*/
#include "NextBase.h"

NextBase::NextBase(const byte page_id, const byte obj_id, const char * const obj_name)
         :__page_id(page_id), __obj_id(obj_id), __obj_name(obj_name){
}

byte NextBase::getPageId(void){
    return this->__page_id;
}

byte NextBase::getObjectId(void){
    return this->__obj_id;
}

const char* NextBase::getObjectName(void){
    return this->__obj_name;
}



