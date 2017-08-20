/*
 * Nextion object
*/
#ifndef __NEXTOBJECT_H__
#define __NEXTOBJECT_H__

#include "NextBase.h"
#include "NextEvent.h"

class NextObject: protected NextBase{ 
  public:
    NextObject(byte page_id, byte obj_id, const char *obj_name);
    //void getWidth(uint32_t &number); // get element width
    //void getHeight(uint32_t &number); // get element height
    void getNumber(uint32_t &number, const char *cmd); // get digit by send "get objectName.cmd" command
    void setNumber(uint32_t number, const char *cmd); // set digit value to cmd command
    uint16_t getString(char *buff, const char *cmd, uint16_t len); // get string by send "get objectName.cmd" command
    void setString(const char *buff, const char *cmd); // set string value to cmd command
};

#endif
