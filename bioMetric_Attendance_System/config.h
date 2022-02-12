#ifndef _CONFIG_H_
#define _CONFIG_H_

#include "allGlobal.h"

typedef struct 
{
    /* data */
}config_t;


bool deviceConfigSetup();
bool isNewConfAvailable();
config_t* getNewConfig (config_t *conf);
bool isValidConfig(config_t *conf);
void setConfig(config_t *conf);

void isTimeforSync();
void deviceSyncLoop();
void buttonPressSyncISR();


#endif //_CONFIG_H_