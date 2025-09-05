#ifndef STATE_EVENT_MATRIX_H
#define STATE_EVENT_MATRIX_H

#include <stdint.h>
#include <stddef.h>
#include "State.h"

#define EVENT_INVALID ((uint32_t)0xFFFFFFFFU)
#define STATE_INVALID ((uint32_t)0xFFFFFFFFU)

typedef uint32_t Events_t;
typedef uint32_t StateName_t;

typedef struct
{
    uint32_t stateMaxNum;
    uint32_t eventMaxNum;
    uint8_t* stateMachineMemoryBuffer;
    StateName_t startingState;
    State_t* states;
    const StateName_t* stateTransitions; /* Matrix stored as 1D array */
    Events_t actualEvent;
    StateName_t actualState;
} StateEventMatrix_t;

void StateEventMatrix_ExecuteTrans(StateEventMatrix_t* stateMatrix);
void StateEventMatrix_Init(StateEventMatrix_t* stateMatrix);
void StateEventMatrix_SetEvent(StateEventMatrix_t* stateMatrix, Events_t event, void* memBuffer, uint32_t bufferSize);

#endif /* STATE_EVENT_MATRIX_H */
