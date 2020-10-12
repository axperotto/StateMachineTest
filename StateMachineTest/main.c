#include "NwkStates.h"
#include "StateEventMatrix.h"
#include<stdio.h>

typedef struct {
	uint32_t size;
	uint8_t buffer[1000];
}MsgType_t;

extern StateEventMatrix_t NwkStateMachine1, NwkStateMachine2, NwkStateMachine3;

StateEventMatrix_t* NwkStateMachines[] = { &NwkStateMachine1 , &NwkStateMachine2 , &NwkStateMachine3 };
int main()
{
	int s = sizeof(State_t);
	MsgType_t buffer;
	StateEventMatrix_Init(&NwkStateMachine1);
	StateEventMatrix_Init(&NwkStateMachine2);
	StateEventMatrix_Init(&NwkStateMachine3);

	for (int I = 0; I < sizeof(buffer.buffer); I++)
	{
		buffer.buffer[I] = I;
	}

	NwkStateMachines[0]->states[1].stateMemory[0] = 0;

	StateEventMatrix_SetEvent(NwkStateMachines[0], 0, (void*)&buffer, sizeof(buffer));
	StateEventMatrix_ExecuteTrans(NwkStateMachines[0]);

	buffer.size = rand() % sizeof(buffer.buffer);
	for (int i = 0; i < 100; i++)
	{
		int actualBuffer = 0;

		StateName_t preState = NwkStateMachines[actualBuffer]->actualState;

		NWK_EventsED_t evt = rand() % NWK_EVENT_ED_MAXNUM;
		StateEventMatrix_SetEvent(NwkStateMachines[actualBuffer], evt, (void*)&buffer, sizeof(buffer));
		StateEventMatrix_ExecuteTrans(NwkStateMachines[actualBuffer]);
		printf("Buffer: %d - PreState: %d - Event: %d - New State: %d\r\n",
			actualBuffer, preState, evt, NwkStateMachines[actualBuffer]->actualState);
	}
}