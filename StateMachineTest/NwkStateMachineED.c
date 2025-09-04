#include "NwkStates.h"
#include "StateEventMatrix.h"

extern State_t NWKIdle;
extern State_t NwkSendingMsg;
extern State_t NwkWaitingForSyncCmdFromGateway;
extern State_t NwkCheckMsg;
extern State_t NwkRouteMsg;
extern State_t NwkSendingEDAck;

State_t  NwkStatesED[] =
{
	/*NWKIDLE,							  */
        {
                NwkIdleEntry,
                NwkIdleRunning,
                NwkIdleExit,
                {0}
        },
	/*NWKSENDINGMSG,					  */
        {
                NwkSendingMsgEntry,
                NwkSendingMsgRunning,
                NwkSendingMsgExit,
                {0}
        },
	/*NWKWAITINGFORSYNCCMDFROMGATEWAY,	  */
        {
                NwkWaitingForSyncCmdFromGatewayEntry,
                NwkWaitingForSyncCmdFromGatewayRunning,
                NwkWaitingForSyncCmdFromGatewayExit,
                {0}
        },
	/*NWKCHECKMSG,						  */
        {
                NwkCheckMsgEntry,
                NwkCheckMsgRunning,
                NwkCheckMsgExit,
                {0}
        },
	/*NWKROUTEMSG,						  */
        {
                 NwkRouteMsgEntry,
                 NwkRouteMsgRunning,
                 NwkRouteMsgExit,
                 {0}
        },
	/*NWKSENDINGEDACK,				      */
        {
                NwkSendingEDAckEntry,
                NwkSendingEDAckRunning,
                NwkSendingEDAckExit,
                {0}
        }
};

StateName_t NwkStateTransitionsED[NWKSTATESED_MAXNUM][NWK_EVENT_ED_MAXNUM] =
{
/*									  NWK_APP_SENDS_MESSAGE	            NWK_MAC_ERROR	                NWK_MSG_NOT_CORRECT	                NWK_MAC_SENT						NWK_MSG_CORRECT					NWK_MSG_TO_BE_ROUTED					NWK_MSG_RX						NWK_TIMEOUT*/
/*NWKIDLE,							*/{NWKSENDINGMSG,					STATE_INVALID,					STATE_INVALID,					STATE_INVALID,							STATE_INVALID,					STATE_INVALID,							NWKCHECKMSG,					STATE_INVALID,},
/*NWKSENDINGMSG,					*/{STATE_INVALID,					NWKSENDINGMSG,					STATE_INVALID,					NWKWAITINGFORSYNCCMDFROMGATEWAY,		STATE_INVALID,					STATE_INVALID,							STATE_INVALID,					NWKIDLE,          },
/*NWKWAITINGFORSYNCCMDFROMGATEWAY,	*/{STATE_INVALID,					STATE_INVALID,					STATE_INVALID,					STATE_INVALID,							STATE_INVALID,					STATE_INVALID,							NWKCHECKMSG,					NWKIDLE,          },
/*NWKCHECKMSG,						*/{STATE_INVALID,					STATE_INVALID,					NWKIDLE,						STATE_INVALID,							NWKSENDINGEDACK,				NWKROUTEMSG,							STATE_INVALID,					STATE_INVALID,},
/*NWKROUTEMSG,						*/{STATE_INVALID,					NWKROUTEMSG,					STATE_INVALID,					NWKIDLE,								STATE_INVALID,					STATE_INVALID,							STATE_INVALID,					NWKIDLE,          },
/*NWKSENDINGEDACK,					*/{STATE_INVALID,					NWKSENDINGEDACK,				STATE_INVALID,					NWKIDLE,								STATE_INVALID,					STATE_INVALID,							STATE_INVALID,					NWKIDLE,          }
};

uint8_t StateMemoryNwk1[1000];
StateEventMatrix_t NwkStateMachine1 =
{
	/*const int stateMaxNum;				   */  NWKSTATESED_MAXNUM,
	/*const int eventMaxNum;				   */  NWK_EVENT_ED_MAXNUM,
	/*void* stateMachineMemory;                        */  StateMemoryNwk1,
	/*const StateName_t startingState;		   */  NWKIDLE,
	/*const State_t* states;				   */  NwkStatesED,
        /*const StateName_t* stateTransitions;     */  &NwkStateTransitionsED[0][0],
	/*Events_t actualEvent;					   */  EVENT_INVALID,
	/*StateName_t actualState;				   */  STATE_INVALID
};

uint8_t StateMemoryNwk2[1000];
StateEventMatrix_t NwkStateMachine2 =
{
	/*const int stateMaxNum;				   */  NWKSTATESED_MAXNUM,
	/*const int eventMaxNum;				   */  NWK_EVENT_ED_MAXNUM,
	/*void* stateMachineMemory;                        */  StateMemoryNwk2,
	/*const StateName_t startingState;		   */  NWKIDLE,
	/*const State_t* states;				   */  NwkStatesED,
        /*const StateName_t* stateTransitions;     */  &NwkStateTransitionsED[0][0],
	/*Events_t actualEvent;					   */  EVENT_INVALID,
	/*StateName_t actualState;				   */  STATE_INVALID
};

uint8_t StateMemoryNwk3[1000];
StateEventMatrix_t NwkStateMachine3 =
{
	/*const int stateMaxNum;				   */  NWKSTATESED_MAXNUM,
	/*const int eventMaxNum;				   */  NWK_EVENT_ED_MAXNUM,
	/*void* stateMachineMemory;                        */  StateMemoryNwk3,
	/*const StateName_t startingState;		   */  NWKIDLE,
	/*const State_t* states;				   */  NwkStatesED,
        /*const StateName_t* stateTransitions;     */  &NwkStateTransitionsED[0][0],
	/*Events_t actualEvent;					   */  EVENT_INVALID,
	/*StateName_t actualState;				   */  STATE_INVALID
};

