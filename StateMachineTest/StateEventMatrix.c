#include "StateEventMatrix.h"
#include <string.h>

void StateEventMatrix_ExecuteTrans(StateEventMatrix_t* stateMatrix)
{
    if ((stateMatrix == NULL) || (stateMatrix->states == NULL) ||
        (stateMatrix->stateTransitions == NULL) ||
        (stateMatrix->actualEvent >= stateMatrix->eventMaxNum) ||
        (stateMatrix->actualState >= stateMatrix->stateMaxNum))
    {
        return;
    }

    if (stateMatrix->actualEvent != EVENT_INVALID)
    {
        uint32_t idx = (stateMatrix->actualState * stateMatrix->eventMaxNum) +
                       stateMatrix->actualEvent;
        StateName_t newState = stateMatrix->stateTransitions[idx];
        State_t* actualStateDesc = &stateMatrix->states[stateMatrix->actualState];
        if (newState != STATE_INVALID)
        {
            /* Exit from actual state */
            if (actualStateDesc->exitFnc_ptr != NULL)
            {
                actualStateDesc->exitFnc_ptr(actualStateDesc,
                                             stateMatrix->stateMachineMemoryBuffer);
            }

            /* Enter new state */
            stateMatrix->actualState = newState;
            actualStateDesc = &stateMatrix->states[stateMatrix->actualState];
            if (actualStateDesc->entryFnc_ptr != NULL)
            {
                actualStateDesc->entryFnc_ptr(actualStateDesc,
                                              stateMatrix->stateMachineMemoryBuffer);
            }
        }

        /* Run the state */
        actualStateDesc = &stateMatrix->states[stateMatrix->actualState];
        if (actualStateDesc->runningFnc_ptr != NULL)
        {
            actualStateDesc->runningFnc_ptr(actualStateDesc,
                                            stateMatrix->stateMachineMemoryBuffer);
        }

        stateMatrix->actualEvent = EVENT_INVALID;
    }
}

void StateEventMatrix_Init(StateEventMatrix_t* stateMatrix)
{
    if (stateMatrix != NULL)
    {
        stateMatrix->actualEvent = EVENT_INVALID;
        stateMatrix->actualState = stateMatrix->startingState;
    }
}

void StateEventMatrix_SetEvent(StateEventMatrix_t* stateMatrix, Events_t event,
                               void* memBuffer, uint32_t bufferSize)
{
    if (stateMatrix == NULL)
    {
        return;
    }
    stateMatrix->actualEvent = event;
    if ((memBuffer != NULL) && (stateMatrix->stateMachineMemoryBuffer != NULL) &&
        (bufferSize <= (uint32_t)STATE_MEMORY))
    {
        memcpy(stateMatrix->stateMachineMemoryBuffer, memBuffer, bufferSize);
    }
}

