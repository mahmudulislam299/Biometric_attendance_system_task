#ifndef _FPSENSOR_H_
#define _FPSENSOR_H_
#include "allGlobal.h"

typedef enum
{
    FPS_INIT,
    FPS_DETECT,
    FPS_VALID,
} fpSensorState_t;

typedef struct 
{
    

} fpSensorLog_t;


void fpsISR();
bool anyFPSDetect();
bool isFPSValid();
void fpSensorLoop();
void saveFPSLog();

#endif // _FPSENSOR_H_