#include "SimpleStateMachine.h"
#include <stdio.h>

int main(void)
{
    Events_t events[] = { SIMPLE_EVENT_START, SIMPLE_EVENT_FINISH, SIMPLE_EVENT_RESET };
    size_t i;

    StateEventMatrix_Init(&SimpleStateMachine);
    State_t* initState = &SimpleStateMachine.states[SimpleStateMachine.actualState];
    initState->entryFnc_ptr(initState, SimpleStateMachine.stateMachineMemoryBuffer);
    initState->runningFnc_ptr(initState, SimpleStateMachine.stateMachineMemoryBuffer);

    for (i = 0U; i < sizeof(events)/sizeof(events[0]); i++)
    {
        StateName_t preState = SimpleStateMachine.actualState;
        StateEventMatrix_SetEvent(&SimpleStateMachine, events[i], NULL, 0U);
        StateEventMatrix_ExecuteTrans(&SimpleStateMachine);
        printf("PreState: %u Event: %u NewState: %u\n", preState, events[i], SimpleStateMachine.actualState);
    }

    return 0;
}
