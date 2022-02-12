#ifndef _ALL_GLOBAL_H
#define _ALL_GLOBAL_H

#include "includefile.h"




typedef enum
{
    CHECK_HARDWARE,
    SYNC_TIME,
    SYNC_CONF,
    RUN_DEVICE,
    STOP
} mainState_t;

extern mainState_t mainState;

void systemSetup();
bool isHardwareOK();
void runDeviceTask();



#endif //_ALL_GLOBAL_H
