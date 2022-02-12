#include "syncTime.h"


static uint32_t prevMillis = 0;
volatile uint32_t _unixtime;

bool syncDeviceTime()
{
    //syncDeviceTime
    bool f; 
    return f;
}

uint32_t getUnixtimeFromServer()
{
   uint32_t unixTimeServer;
   //
   return unixTimeServer;
}

void syncTime()
{
   if(millis() - prevMillis > SYNC_TIME_DELAY) 
   {
       uint32_t unix;
       unix = getUnixtimeFromServer();
       if(checkTimeValidity(unix))
       {
           _unixtime = unix;
           prevMillis = millis();
       }
       else
       {
           prevMillis = 0;
           return;
       }
   }
   
}

bool checkTimeValidity(uint32_t time)
{
    bool f;
    return f;
}
