#include "StateEventMatrix.h"
#include <string.h>


void StateEventMatrix_ExecuteTrans(StateEventMatrix_t* StateMatrix)
{
        if ((StateMatrix == NULL) || (StateMatrix->states == NULL) ||
            (StateMatrix->stateTransitions == NULL) ||
            (StateMatrix->actualEvent >= StateMatrix->eventMaxNum) ||
            (StateMatrix->actualState >= StateMatrix->stateMaxNum))
        {
                return;
        }

        if (StateMatrix->actualEvent != EVENT_INVALID)
        {
                uint32_t idx = (StateMatrix->actualState * StateMatrix->eventMaxNum) +
                                StateMatrix->actualEvent;
                StateName_t newState = StateMatrix->stateTransitions[idx];
                State_t* actualStateDesc = &StateMatrix->states[StateMatrix->actualState];
                if (newState != STATE_INVALID)
                {
                        /* Exit from actual state */
                        actualStateDesc->exitFnc_ptr(actualStateDesc,
                                                     StateMatrix->stateMachineMemoryBuffer);

                        /* Enter new state */
                        StateMatrix->actualState = newState;
                        actualStateDesc = &StateMatrix->states[StateMatrix->actualState];
                        actualStateDesc->entryFnc_ptr(actualStateDesc,
                                                     StateMatrix->stateMachineMemoryBuffer);
                }

                /* Run the state */
                actualStateDesc = &StateMatrix->states[StateMatrix->actualState];
                actualStateDesc->runningFnc_ptr(actualStateDesc,
                                                StateMatrix->stateMachineMemoryBuffer);

                StateMatrix->actualEvent = EVENT_INVALID;
        }
}

void StateEventMatrix_Init(StateEventMatrix_t* StateMatrix)
{
        if (StateMatrix != NULL)
        {
                StateMatrix->actualEvent = EVENT_INVALID;
                StateMatrix->actualState = StateMatrix->startingState;
        }
}

void StateEventMatrix_SetEvent(StateEventMatrix_t* StateMatrix, Events_t event,
                               void* memBuffer, uint32_t bufferSize)
{
        if (StateMatrix == NULL)
        {
                return;
        }
        StateMatrix->actualEvent = event;
        if ((memBuffer != NULL) && (StateMatrix->stateMachineMemoryBuffer != NULL) &&
            (bufferSize <= (uint32_t)STATE_MEMORY))
        {
                memcpy(StateMatrix->stateMachineMemoryBuffer, memBuffer, bufferSize);
        }
}
