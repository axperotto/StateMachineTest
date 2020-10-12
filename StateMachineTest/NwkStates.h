#ifndef NWKSTATES_H
#define NWKSTATES_H

#include "State.h"

typedef enum {
	NWKIDLE,
	NWKSENDINGMSG,
	NWKWAITINGFORSYNCCMDFROMGATEWAY,
	NWKCHECKMSG,
	NWKROUTEMSG,
	NWKSENDINGEDACK,
	NWKSTATESED_MAXNUM
}NwkStatesED_t;


typedef enum {
	NWK_APP_SENDS_MESSAGE,
	NWK_MAC_ERROR,
	NWK_MSG_NOT_CORRECT,
	NWK_MAC_SENT,
	NWK_MSG_CORRECT,
	NWK_MSG_TO_BE_ROUTED,
	NWK_MSG_RX,
	NWK_TIMEOUT,
	NWK_EVENT_ED_MAXNUM
}NWK_EventsED_t;


/* NwkIdle */
void* NwkIdleEntry(State_t* this, void* ptr);
void* NwkIdleRunning(State_t* this, void* ptr);
void* NwkIdleExit(State_t* this, void* ptr);

/* NwkSendingMsg */
typedef struct {
	int actualFrameTx;
	int totalFrame;
}NwkSendingMsg_t;

void* NwkSendingMsgEntry(State_t* this, void* ptr);
void* NwkSendingMsgRunning(State_t* this, void* ptr);
void* NwkSendingMsgExit(State_t* this, void* ptr);

/* NwkWaitingForSyncCmdFromGateway */
void* NwkWaitingForSyncCmdFromGatewayEntry(State_t* this, void* ptr);
void* NwkWaitingForSyncCmdFromGatewayRunning(State_t* this, void* ptr);
void* NwkWaitingForSyncCmdFromGatewayExit(State_t* this, void* ptr);

/* NwkCheckMsg  */
void* NwkCheckMsgEntry(State_t* this, void* ptr);
void* NwkCheckMsgRunning(State_t* this, void* ptr);
void* NwkCheckMsgExit(State_t* this, void* ptr);

/* NwkRouteMsg  */
void* NwkRouteMsgEntry(State_t* this, void* ptr);
void* NwkRouteMsgRunning(State_t* this, void* ptr);
void* NwkRouteMsgExit(State_t* this, void* ptr);

/* NwkSendingEDAck */
void* NwkSendingEDAckEntry(State_t* this, void* ptr);
void* NwkSendingEDAckRunning(State_t* this, void* ptr);
void* NwkSendingEDAckExit(State_t* this, void* ptr);

/* NWKWaitingForEDAck */
void* NwkWaitingForEDAckEntry(State_t* this, void* ptr);
void* NwkWaitingForEDAckRunning(State_t* this, void* ptr);
void* NwkWaitingForEDAckExit(State_t* this, void* ptr);


#endif