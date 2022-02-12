#ifndef _TRANSFER_H_
#define _TRANSFER_H_
#include "allGlobal.h"

typedef enum
{
    XFER_READ_LOG,
    XFER_SERVER_SEND,
    XFER_WAIT_FOR_ACK,
    XFER_SEND_SUCCESS,
    XFER_FAILED
} xferState_t;

typedef uint8_t* (*read_t) (void) ;
typedef void (*send_t) (uint8_t*);
typedef int (*ackWait_t) (void);


void xferBegin(read_t read, send_t send, ackWait_t ackWait);
void isTimeforXfer();
void xferLoop();
void buttonPressXferISR();


#endif //_TRANSFER_H_