/**
 * @file StateEventMatrix.c
 * @brief Implementation of the state-event transition matrix engine.
 */

#include "StateEventMatrix.h"
#include <string.h>

/**
 * @brief Execute the transition driven by the pending event.
 *
 * Performs exit, entry and running callbacks as required and clears
 * the pending event on completion.
 *
 * @param[in,out] stateMatrix Pointer to the state machine object.
 */
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

/**
 * @brief Initialise the state machine to its starting state.
 *
 * @param[in,out] stateMatrix Pointer to the state machine object.
 */
void StateEventMatrix_Init(StateEventMatrix_t* stateMatrix)
{
    if (stateMatrix != NULL)
    {
        stateMatrix->actualEvent = EVENT_INVALID;
        stateMatrix->actualState = stateMatrix->startingState;
    }
}

/**
 * @brief Set the next event and optionally copy external data.
 *
 * @param[in,out] stateMatrix Pointer to the state machine object.
 * @param[in] event Event to trigger.
 * @param[in] memBuffer Optional pointer to data to copy.
 * @param[in] bufferSize Size of the data in bytes.
 */
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
        /* MISRA C:2023 Rule 17.7 fix: cast return value to void (TC) */
        (void)memcpy(stateMatrix->stateMachineMemoryBuffer, memBuffer, bufferSize);
    }
}

/**
 * @brief Reset the state machine to the starting state and clear memory.
 *
 * @param[in,out] stateMatrix Pointer to the state machine object.
 */
void StateEventMatrix_Reset(StateEventMatrix_t* stateMatrix)
{
    if (stateMatrix != NULL)
    {
        stateMatrix->actualEvent = EVENT_INVALID;
        stateMatrix->actualState = stateMatrix->startingState;
        if (stateMatrix->stateMachineMemoryBuffer != NULL)
        {
            /* MISRA C:2023 Rule 17.7 fix: cast return value to void (TC) */
            (void)memset(stateMatrix->stateMachineMemoryBuffer, 0, STATE_MEMORY);
        }
    }
}

