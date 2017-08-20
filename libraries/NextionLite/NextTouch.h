/*
 * Nextion touch class 
*/
#ifndef __NEXTTOUCH_H__
#define __NEXTTOUCH_H__

#include "NextBase.h"

// callback function type
typedef void (*ObjectCallback)();

class NextTouch: public NextBase{
  ObjectCallback __pressCallback;
  ObjectCallback __releaseCallback;
  
  public:
    NextTouch(byte page_id, byte obj_id, const char *obj_name);
    void addPressCallback(ObjectCallback call);
    void addReleaseCallback(ObjectCallback call);
    void releaseCallback(); // release calback
    void pressCallback(); // press callback
};

#endif
