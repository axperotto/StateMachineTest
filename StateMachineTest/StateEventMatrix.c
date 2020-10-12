#include "StateEventMatrix.h"


void StateEventMatrix_ExecuteTrans(StateEventMatrix_t* StateMatrix)
{
	if (StateMatrix->actualEvent != EVENT_INVALID)
	{
		StateName_t* statePointers = &StateMatrix->stateTransitions[StateMatrix->actualState * StateMatrix->eventMaxNum];
		StateName_t newState = statePointers[StateMatrix->actualEvent];
		State_t* actualStateDesc = &StateMatrix->states[StateMatrix->actualState];
		if (newState != STATE_INVALID)
		{
			/* Exit from actual state */
			actualStateDesc->exitFnc_ptr(
				(State_t*)actualStateDesc,
				(void*)StateMatrix->stateMachineMemoryBuffer);

			/* Enter new state */
			StateMatrix->actualState = newState;
			actualStateDesc = &StateMatrix->states[StateMatrix->actualState];
			actualStateDesc->entryFnc_ptr(
				(State_t*)actualStateDesc,
				(void*)StateMatrix->stateMachineMemoryBuffer);
		}

		/* Run the state */
		actualStateDesc = &StateMatrix->states[StateMatrix->actualState];
		/* Run actual state */
		actualStateDesc->runningFnc_ptr(
			(State_t*)actualStateDesc,
			(void*)StateMatrix->stateMachineMemoryBuffer);
	}

	StateMatrix->actualEvent = EVENT_INVALID;
}

void StateEventMatrix_Init(StateEventMatrix_t* StateMatrix)
{
	StateMatrix->actualEvent = EVENT_INVALID;
	StateMatrix->actualState = StateMatrix->startingState;
}

void StateEventMatrix_SetEvent(StateEventMatrix_t* StateMatrix, Events_t event, void* memBuffer, uint32_t bufferSize)
{
	StateMatrix->actualEvent = event;
	if (memBuffer != 0)
	{
		memcpy(StateMatrix->stateMachineMemoryBuffer, memBuffer, bufferSize);
	}
}
