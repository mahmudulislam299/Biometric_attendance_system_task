#ifndef _SYNCTIME_H_
#define _SYNCTIME_H_
#include <Arduino.h>
#include "allGlobal.h"

bool syncDeviceTime();
void syncTime();
bool checkTimeValidity(uint32_t time);
uint32_t getUnixtimeFromServer();

#endif //_SYNCTIME_H_
