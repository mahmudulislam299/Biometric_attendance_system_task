#include "allGlobal.h"



void setup()
{
    systemSetup();
    mainState = CHECK_HARDWARE;
}

void loop()
{
    switch(mainState)
    {
        case CHECK_HARDWARE:
            if(isHardwareOK())
            {
                mainState = SYNC_TIME;
            }
            else
            {
                mainState = STOP;
            }
            break;
        case SYNC_TIME:
            if(syncDeviceTime())
            {
                mainState = SYNC_CONF;
            }
            break;        
        case SYNC_CONF:
            if(deviceConfigSetup())
            {
                mainState = SYNC_CONF;
            }
            break;
        case RUN_DEVICE:
            runDeviceTask();
            break;
        case STOP:
            break;         
        default:
            mainState = CHECK_HARDWARE;
            break;
    }

    
}
