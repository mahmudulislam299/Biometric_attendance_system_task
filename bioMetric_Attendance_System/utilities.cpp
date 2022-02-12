#include "utilities.h"

deviceHealthLog_t deviceHeathLog;
devHealthLogState_t devHealthLogState;

deviceHealthLog_t* getDevHealthLog(deviceHealthLog_t *devHelLog)
{
    // devHelLog->member = ;
    return devHelLog;
}

void saveHeathLog(deviceHealthLog_t *devHelLog)
{

}

bool isTimeforHeathLog()
{
    static uint32_t prevMillisDHL=0;
    if(millis()-prevMillisDHL > DEV_HEALTH_LOG_INTERVAL)
    {
        prevMillisDHL = millis();
        return true;
    }
    return false;
}

void deviceHealthLogLoop()
{
    switch(devHealthLogState)
    {
        case DHL_WAIT:
            if(isTimeforHeathLog())
            {
                devHealthLogState = DHL_GET;
            }
            break;
        case DHL_GET:
            getDevHealthLog(&deviceHeathLog);
            devHealthLogState = DHL_SAVE;
            break;
        case DHL_SAVE:
            saveHeathLog(&deviceHeathLog);
            devHealthLogState = DHL_WAIT;
            break;
    }
}