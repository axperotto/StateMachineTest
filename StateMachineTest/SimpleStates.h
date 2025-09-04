#ifndef SIMPLESTATES_H
#define SIMPLESTATES_H

#include "State.h"

typedef enum
{
    SIMPLE_STATE_IDLE,
    SIMPLE_STATE_WORK,
    SIMPLE_STATE_DONE,
    SIMPLE_STATE_MAX
} SimpleState_t;

typedef enum
{
    SIMPLE_EVENT_START,
    SIMPLE_EVENT_FINISH,
    SIMPLE_EVENT_RESET,
    SIMPLE_EVENT_MAX
} SimpleEvent_t;

/* Idle state */
void IdleEntry(State_t* this, void* ptr);
void IdleRunning(State_t* this, void* ptr);
void IdleExit(State_t* this, void* ptr);

/* Work state */
void WorkEntry(State_t* this, void* ptr);
void WorkRunning(State_t* this, void* ptr);
void WorkExit(State_t* this, void* ptr);

/* Done state */
void DoneEntry(State_t* this, void* ptr);
void DoneRunning(State_t* this, void* ptr);
void DoneExit(State_t* this, void* ptr);

#endif
