#include "RFID.h"

rfidState_t rfidState;

volatile uint8_t _rfidDetectFlag = 0;

void rfidISR()
{
    _rfidDetectFlag++;
}

bool anyCardDetect()
{
    if(_rfidDetectFlag)
    {
        _rfidDetectFlag --;
        return true;
    }
    return false;
}

bool isCardValid()
{
    bool f;
    return f;
}

void saveCardLog()
{
    //log will be saved in flash memory
}
void rfidCardLoop()
{
    switch(rfidState)
    {
        case CARD_INIT:
            if(anyCardDetect())
            {
                rfidState = CARD_DETECT;
            }
            else
            {
                rfidState = CARD_INIT;
            }
            break;
        case CARD_DETECT:
            if(isCardValid())
            {
                rfidState = CARD_VALID;
            }
            else
            {
                rfidState = CARD_INIT;
            }
            break;
        case CARD_VALID:
            saveCardLog();
            rfidState = CARD_INIT;
            break;
        default:
            rfidState = CARD_INIT;  
            break;      

    }

}