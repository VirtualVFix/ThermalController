/*
 * Nextion base class 
*/
#ifndef __NEXTBASE_H__
#define __NEXTBASE_H__

#include "NextConfig.h"
 
class NextBase{
  const byte __page_id; // page id
  const byte __obj_id; // element id
  const char * const __obj_name; // element name
  public:
    NextBase(const byte page_id, const byte obj_id, const char * const obj_name);
    byte getPageId(void);    
    byte getObjectId(void);
    const char *getObjectName(void);
};

#endif
