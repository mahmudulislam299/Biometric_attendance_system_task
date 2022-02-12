#ifndef _UTILITIES_H_
#define _UTILITIES_H_
#include "allGlobal.h"

typedef enum
{
    DHL_WAIT,
    DHL_GET,
    DHL_SAVE

}devHealthLogState_t;

typedef struct 
{
    // time, device restrat count, device input voltage,
    // battery voltage, others will be created
}deviceHealthLog_t;


deviceHealthLog_t* getDevHealthLog(deviceHealthLog_t *devHelLog);
void saveHeathLog(deviceHealthLog_t *devHelLog);
bool isTimeforHeathLog();
void deviceHealthLogLoop();

#endif //_UTILITIES_H_