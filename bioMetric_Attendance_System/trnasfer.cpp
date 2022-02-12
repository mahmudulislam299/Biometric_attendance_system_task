#include "transfer.h"

xferState_t xferState;

bool _isXferReady;

//Callback functions
read_t _read;
send_t _send;
ackWait_t _ackWait;

void xferBegin(read_t read, send_t send, ackWait_t ackWait)
{
    _read = read;
    _send = send;
    _ackWait = ackWait;
}

void isTimeforXfer()
{
    static uint32_t prevMillisXFER=0;
    if(millis()-prevMillisXFER > XFER_INTERVAL)
    {
        prevMillisXFER = millis();
        _isXferReady = true;
    }
}

void buttonPressXferISR()
{
    _isXferReady = true;
}

void xferLoop()
{
    isTimeforXfer();
    static uint8_t *_ptr = NULL;
    static uint8_t _tryCount;
    static int _ackCode;

    if(_isXferReady)
    {
        switch(xferState)
        {
            case XFER_READ_LOG:
                _ptr = _read();
                if(_ptr != NULL)
                {
                    xferState = XFER_SERVER_SEND;
                    _tryCount = 0;
                }
                else
                {
                    _isXferReady = false;
                }
                break;
            case XFER_SERVER_SEND:
                if(_ptr)
                {
                    _send(_ptr);
                    _tryCount++;
                    xferState = XFER_WAIT_FOR_ACK;
                }
                else
                {
                    xferState = XFER_READ_LOG;
                }
                break;
            case XFER_WAIT_FOR_ACK:
                _ackCode = _ackWait();
                if(_ackCode == ACKCODE)
                {
                    xferState = XFER_SEND_SUCCESS;
                }
                else
                {
                    xferState = XFER_FAILED;
                }
                break;
            case XFER_SEND_SUCCESS:
                _isXferReady = true;
                xferState = XFER_READ_LOG;
                break;
            case XFER_FAILED:
                if(_tryCount < XFER_MAX_TRY_COUNT)
                {
                    xferState = XFER_SERVER_SEND;
                }
                break;
            default:
                xferState = XFER_READ_LOG;
                break;
        }
    }
}