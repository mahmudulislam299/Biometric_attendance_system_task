#include "allGlobal.h"

mainState_t mainState;


void systemSetup()
{
    //all the peripheral and others
    // will setup here
}

bool isHardwareOK()
{
    //check all the hardware
    bool f;
    return f;
}

void runDeviceTask()
{   
    displayTimeonLCD();
    rfidCardLoop();
    fpSensorLoop();
    deviceHealthLogLoop();
    xferLoop();
    deviceSyncLoop();
    syncTime();
}
