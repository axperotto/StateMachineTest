#include "NwkStates.h"

void NwkIdleEntry(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkIdleRunning(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkIdleExit(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}

typedef struct {
	uint32_t size;
	uint8_t buffer[1000];
}MsgType_t;


/* NwkSendingMsg */
void NwkSendingMsgEntry(State_t* this, void* ptr)
{
        MsgType_t* msgType = (MsgType_t*)ptr;
        msgType->buffer[1] = 10U;

        this->stateMemory[1] = 2U;
        NwkSendingMsg_t* sendingMsg = (NwkSendingMsg_t*)this->stateMemory;
        sendingMsg->actualFrameTx = 0U;
        sendingMsg->totalFrame = msgType->size;
}

void NwkSendingMsgRunning(State_t* this, void* ptr)
{
        (void)ptr;
        NwkSendingMsg_t* sendingMsg = (NwkSendingMsg_t*)this->stateMemory;

        sendingMsg->actualFrameTx++;
}
void NwkSendingMsgExit(State_t* this, void* ptr)
{
        (void)ptr;
        (void)this;
}


/* NwkWaitingForSyncCmdFromGateway */
void NwkWaitingForSyncCmdFromGatewayEntry(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkWaitingForSyncCmdFromGatewayRunning(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkWaitingForSyncCmdFromGatewayExit(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}

/* NwkCheckMsg */
void NwkCheckMsgEntry(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkCheckMsgRunning(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkCheckMsgExit(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}


/*  NwkRouteMsg */
void NwkRouteMsgEntry(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkRouteMsgRunning(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkRouteMsgExit(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}


/*  NwkSendingEDAck */
void NwkSendingEDAckEntry(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}

void NwkSendingEDAckRunning(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
void NwkSendingEDAckExit(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}

/*  NwkWaitingForEDAck */

void NwkWaitingForEDAckEntry(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}

void NwkWaitingForEDAckRunning(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}

void NwkWaitingForEDAckExit(State_t* this, void* ptr)
{
        (void)this;
        (void)ptr;
}
