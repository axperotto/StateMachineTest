/**
 * @file main.c
 * @brief Demonstration program for the state machine library.
 */

#include "SimpleStateMachine.h"
#include <stdio.h>

/**
 * @brief Program entry point.
 *
 * Runs a sequence of transitions and demonstrates the reset feature.
 *
 * @return Zero on successful execution.
 */
int main(void)
{
    Events_t events[] = { SIMPLE_EVENT_START, SIMPLE_EVENT_FINISH, SIMPLE_EVENT_RESET };
    size_t i;

    StateEventMatrix_Init(&SimpleStateMachine);
    State_t* initState = &SimpleStateMachine.states[SimpleStateMachine.actualState];
    if ((initState->entryFnc_ptr != NULL) &&
        (initState->runningFnc_ptr != NULL))
    {
        initState->entryFnc_ptr(initState,
                                SimpleStateMachine.stateMachineMemoryBuffer);
        initState->runningFnc_ptr(initState,
                                  SimpleStateMachine.stateMachineMemoryBuffer);
    }

    for (i = 0U; i < sizeof(events)/sizeof(events[0]); i++)
    {
        StateName_t preState = SimpleStateMachine.actualState;
        StateEventMatrix_SetEvent(&SimpleStateMachine, events[i], NULL, 0U);
        StateEventMatrix_ExecuteTrans(&SimpleStateMachine);
        (void)printf("PreState: %u Event: %u NewState: %u\n", preState, events[i], SimpleStateMachine.actualState);
    }

    StateEventMatrix_Reset(&SimpleStateMachine);
    (void)printf("Reset to state: %u\n", SimpleStateMachine.actualState);

    return 0;
}
