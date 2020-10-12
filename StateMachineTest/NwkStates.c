#include "NwkStates.h"

void* NwkIdleEntry(State_t* this, void* ptr)
{
}
void* NwkIdleRunning(State_t* this, void* ptr)
{
}
void* NwkIdleExit(State_t* this, void* ptr)
{
}

typedef struct {
	uint32_t size;
	uint8_t buffer[1000];
}MsgType_t;


/* NwkSendingMsg */
void* NwkSendingMsgEntry(State_t* this, void* ptr)
{
	MsgType_t* msgType = (MsgType_t*)ptr;
	msgType->buffer[1] = 10;

	this->stateMemory[1] = 2;
	NwkSendingMsg_t* sendingMsg = (NwkSendingMsg_t*)this->stateMemory;
	sendingMsg->actualFrameTx = 0;
	sendingMsg->totalFrame = msgType->size;
	return 0;
}

void* NwkSendingMsgRunning(State_t* this, void* ptr)
{
	MsgType_t* msgType = (MsgType_t*)ptr; 
	NwkSendingMsg_t* sendingMsg = (NwkSendingMsg_t*)this->stateMemory;

	sendingMsg->actualFrameTx++;
	return 0;
}
void* NwkSendingMsgExit(State_t* this, void* ptr)
{
	MsgType_t* msgType = (MsgType_t*)ptr;
	NwkSendingMsg_t* sendingMsg = (NwkSendingMsg_t*)this->stateMemory;
	return 0;
}


/* NwkWaitingForSyncCmdFromGateway */
void* NwkWaitingForSyncCmdFromGatewayEntry(State_t* this, void* ptr)
{
	return 0;
}
void* NwkWaitingForSyncCmdFromGatewayRunning(State_t* this, void* ptr)
{
	return 0;
}
void* NwkWaitingForSyncCmdFromGatewayExit(State_t* this, void* ptr)
{
	return 0;
}

/* NwkCheckMsg */
void* NwkCheckMsgEntry(State_t* this, void* ptr)
{
	return 0;
}
void* NwkCheckMsgRunning(State_t* this, void* ptr)
{
	return 0;
}
void* NwkCheckMsgExit(State_t* this, void* ptr)
{
	return 0;
}


/*  NwkRouteMsg */
void* NwkRouteMsgEntry(State_t* this, void* ptr)
{
	return 0;
}
void* NwkRouteMsgRunning(State_t* this, void* ptr)
{
	return 0;
}
void* NwkRouteMsgExit(State_t* this, void* ptr)
{
	return 0;
}


/*  NwkSendingEDAck */
void* NwkSendingEDAckEntry(State_t* this, void* ptr)
{
	return 0;
}

void* NwkSendingEDAckRunning(State_t* this, void* ptr)
{
	return 0;
}
void* NwkSendingEDAckExit(State_t* this, void* ptr)
{
	return 0;
}

/*  NwkWaitingForEDAck */

void* NwkWaitingForEDAckEntry(State_t* this, void* ptr)
{
	return 0;
}

void* NwkWaitingForEDAckRunning(State_t* this, void* ptr)
{
	return 0;
}

void* NwkWaitingForEDAckExit(State_t* this, void* ptr)
{
	return 0;
}
