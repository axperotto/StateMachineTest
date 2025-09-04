#include "NwkStates.h"
#include "StateEventMatrix.h"

State_t NwkStatesED[] =
{
        /* NWKIDLE */
        { NwkIdleEntry, NwkIdleRunning, NwkIdleExit, {0} },
        /* NWKSENDINGMSG */
        { NwkSendingMsgEntry, NwkSendingMsgRunning, NwkSendingMsgExit, {0} },
        /* NWKWAITINGFORSYNCCMDFROMGATEWAY */
        { NwkWaitingForSyncCmdFromGatewayEntry, NwkWaitingForSyncCmdFromGatewayRunning, NwkWaitingForSyncCmdFromGatewayExit, {0} },
        /* NWKCHECKMSG */
        { NwkCheckMsgEntry, NwkCheckMsgRunning, NwkCheckMsgExit, {0} },
        /* NWKROUTEMSG */
        { NwkRouteMsgEntry, NwkRouteMsgRunning, NwkRouteMsgExit, {0} },
        /* NWKSENDINGEDACK */
        { NwkSendingEDAckEntry, NwkSendingEDAckRunning, NwkSendingEDAckExit, {0} }
};

const StateName_t NwkStateTransitionsED[NWKSTATESED_MAXNUM][NWK_EVENT_ED_MAXNUM] =
{
        /* NWKIDLE */
        { NWKSENDINGMSG, STATE_INVALID, STATE_INVALID, STATE_INVALID, STATE_INVALID, STATE_INVALID, NWKCHECKMSG, STATE_INVALID },
        /* NWKSENDINGMSG */
        { STATE_INVALID, NWKSENDINGMSG, STATE_INVALID, NWKWAITINGFORSYNCCMDFROMGATEWAY, STATE_INVALID, STATE_INVALID, STATE_INVALID, NWKIDLE },
        /* NWKWAITINGFORSYNCCMDFROMGATEWAY */
        { STATE_INVALID, STATE_INVALID, STATE_INVALID, STATE_INVALID, STATE_INVALID, STATE_INVALID, NWKCHECKMSG, NWKIDLE },
        /* NWKCHECKMSG */
        { STATE_INVALID, STATE_INVALID, NWKIDLE, STATE_INVALID, NWKSENDINGEDACK, NWKROUTEMSG, STATE_INVALID, STATE_INVALID },
        /* NWKROUTEMSG */
        { STATE_INVALID, NWKROUTEMSG, STATE_INVALID, NWKIDLE, STATE_INVALID, STATE_INVALID, STATE_INVALID, NWKIDLE },
        /* NWKSENDINGEDACK */
        { STATE_INVALID, NWKSENDINGEDACK, STATE_INVALID, NWKIDLE, STATE_INVALID, STATE_INVALID, STATE_INVALID, NWKIDLE }
};

static uint8_t StateMemoryNwk1[1000];
StateEventMatrix_t NwkStateMachine1 =
{
        NWKSTATESED_MAXNUM,
        NWK_EVENT_ED_MAXNUM,
        StateMemoryNwk1,
        NWKIDLE,
        NwkStatesED,
        (const StateName_t*)NwkStateTransitionsED,
        EVENT_INVALID,
        STATE_INVALID
};

static uint8_t StateMemoryNwk2[1000];
StateEventMatrix_t NwkStateMachine2 =
{
        NWKSTATESED_MAXNUM,
        NWK_EVENT_ED_MAXNUM,
        StateMemoryNwk2,
        NWKIDLE,
        NwkStatesED,
        (const StateName_t*)NwkStateTransitionsED,
        EVENT_INVALID,
        STATE_INVALID
};

static uint8_t StateMemoryNwk3[1000];
StateEventMatrix_t NwkStateMachine3 =
{
        NWKSTATESED_MAXNUM,
        NWK_EVENT_ED_MAXNUM,
        StateMemoryNwk3,
        NWKIDLE,
        NwkStatesED,
        (const StateName_t*)NwkStateTransitionsED,
        EVENT_INVALID,
        STATE_INVALID
};

