#ifndef _RFID_H_
#define _RFID_H_
#include "allGlobal.h"


typedef enum
{
    CARD_INIT,
    CARD_DETECT,
    CARD_VALID,
} rfidState_t;

typedef struct 
{
    uint32_t id;
    uint8_t card[4];

} rfidCardLog_t;

void rfidISR();
bool anyCardDetect();
bool isCardValid();
void rfidCardLoop();
void saveCardLog();


#endif //_RFID_H_