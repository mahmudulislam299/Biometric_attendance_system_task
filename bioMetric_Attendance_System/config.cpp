#include "config.h"

config_t config, confTemp;
bool _isReadyForSync;

bool isNewConfAvailable()
{
    //
    bool f;
    return f;
}

bool isValidConfig(config_t *conf)
{
    bool f;
    return f;
}

config_t* getNewConfig (config_t *conf)
{
    return conf;
}

void setConfig(config_t *conf)
{

}

bool deviceConfigSetup()
{
    if(isNewConfAvailable())
    {
        getNewConfig(&confTemp);
        if(isValidConfig(&confTemp))
        {
            setConfig(&config);
            return true;
        }
        else
        {
            //config is not valid
            return false;
        }
    }
    else
    {
        // no new config 
        //device use previous config
        return true;
    }
}

void isTimeforSync()
{
    static uint32_t prevMillisSYNC=0;
    if(millis()-prevMillisSYNC > SYNC_INTERVAL)
    {
        prevMillisSYNC = millis();
        _isReadyForSync = true;
    }
    else
    {
        _isReadyForSync = false;
    }
}

void deviceSyncLoop()
{
    isTimeforSync();
    if( _isReadyForSync)
    {
        _isReadyForSync = false;
        deviceConfigSetup();
    }
}

void buttonPressSyncISR()
{
    _isReadyForSync = true;
}