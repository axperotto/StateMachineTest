#include "SimpleStates.h"
#include "StateEventMatrix.h"

State_t SimpleStatesDesc[SIMPLE_STATE_MAX] =
{
    { IdleEntry, IdleRunning, IdleExit, {0} },
    { WorkEntry, WorkRunning, WorkExit, {0} },
    { DoneEntry, DoneRunning, DoneExit, {0} }
};

const StateName_t SimpleTransitions[SIMPLE_STATE_MAX][SIMPLE_EVENT_MAX] =
{
    /* IDLE */
    { SIMPLE_STATE_WORK, STATE_INVALID, STATE_INVALID },
    /* WORK */
    { STATE_INVALID, SIMPLE_STATE_DONE, SIMPLE_STATE_IDLE },
    /* DONE */
    { STATE_INVALID, STATE_INVALID, SIMPLE_STATE_IDLE }
};

static uint8_t SimpleMemory[STATE_MEMORY];

StateEventMatrix_t SimpleStateMachine =
{
    SIMPLE_STATE_MAX,
    SIMPLE_EVENT_MAX,
    SimpleMemory,
    SIMPLE_STATE_IDLE,
    SimpleStatesDesc,
    (const StateName_t*)SimpleTransitions,
    EVENT_INVALID,
    STATE_INVALID
};

