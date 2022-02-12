#include "fpSensor.h"

fpSensorState_t fpSensorState;
volatile uint8_t _fpsDetectFlag;

void fpsISR()
{
    _fpsDetectFlag++;
}


bool anyFPSDetect()
{
    if(_fpsDetectFlag)
    {
        _fpsDetectFlag--;
        return true;
    }
    return false;
}

bool isFPSValid()
{
    bool f;
    return f;
}

void saveFPSLog()
{
    //log will be saved in flashmemory
}

void fpSensorLoop()
{
    switch(fpSensorState)
    {
        case FPS_INIT:
            if(anyFPSDetect())
            {
                fpSensorState = FPS_DETECT;
            }
            else
            {
                fpSensorState = FPS_INIT;
            }
            break;
        case FPS_DETECT:
            if(isFPSValid())
            {
                fpSensorState = FPS_VALID;
            }
            else
            {
                fpSensorState = FPS_INIT;
            }
            break;
        case FPS_VALID:
            saveFPSLog();
            fpSensorState = FPS_INIT;
            break;
        default:
            fpSensorState = FPS_INIT;  
            break;      

    }

}