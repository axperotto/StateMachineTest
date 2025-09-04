#include "NwkStates.h"
#include "StateEventMatrix.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	uint32_t size;
	uint8_t buffer[1000];
}MsgType_t;

extern StateEventMatrix_t NwkStateMachine1, NwkStateMachine2, NwkStateMachine3;

static StateEventMatrix_t* const NwkStateMachines[] = { &NwkStateMachine1, &NwkStateMachine2, &NwkStateMachine3 };

int main(void)
{
        MsgType_t buffer;
        uint32_t i;

        StateEventMatrix_Init(&NwkStateMachine1);
        StateEventMatrix_Init(&NwkStateMachine2);
        StateEventMatrix_Init(&NwkStateMachine3);

        for (i = 0U; i < (uint32_t)sizeof(buffer.buffer); i++)
        {
                buffer.buffer[i] = (uint8_t)i;
        }

        NwkStateMachines[0]->states[1].stateMemory[0] = 0U;

        StateEventMatrix_SetEvent(NwkStateMachines[0], 0U, (void*)&buffer, sizeof(buffer));
        StateEventMatrix_ExecuteTrans(NwkStateMachines[0]);

        srand(0U);
        buffer.size = (uint32_t)(rand() % sizeof(buffer.buffer));

        for (i = 0U; i < 100U; i++)
        {
                uint32_t actualBuffer = 0U;

                StateName_t preState = NwkStateMachines[actualBuffer]->actualState;

                NWK_EventsED_t evt = (NWK_EventsED_t)(rand() % NWK_EVENT_ED_MAXNUM);
                StateEventMatrix_SetEvent(NwkStateMachines[actualBuffer], evt, (void*)&buffer, sizeof(buffer));
                StateEventMatrix_ExecuteTrans(NwkStateMachines[actualBuffer]);
                printf("Buffer: %u - PreState: %u - Event: %u - New State: %u\n",
                        actualBuffer, preState, evt, NwkStateMachines[actualBuffer]->actualState);
        }

        return 0;
}