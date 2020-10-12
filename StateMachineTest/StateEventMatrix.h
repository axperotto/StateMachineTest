#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include "inttypes.h"
#include "State.h"

#define EVENT_INVALID (uint32_t)0xFFFFFFFF
#define STATE_INVALID (uint32_t)0xFFFFFFFF

typedef uint32_t Events_t;
typedef uint32_t StateName_t;

typedef struct
{
	const int stateMaxNum;
	const int eventMaxNum;
	const void* stateMachineMemoryBuffer;
	const StateName_t startingState;
	State_t* const states;
	const StateName_t** stateTransitions;

	Events_t actualEvent;
	StateName_t actualState;
}StateEventMatrix_t;


void StateEventMatrix_ExecuteTrans(StateEventMatrix_t* StateMatrix);
void StateEventMatrix_Init(StateEventMatrix_t* StateMatrix);
void StateEventMatrix_SetEvent(StateEventMatrix_t* StateMatrix, Events_t event, void* memBuffer, uint32_t bufferSize);


#endif // !1