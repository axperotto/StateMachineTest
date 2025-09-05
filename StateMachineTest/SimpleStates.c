#include "SimpleStates.h"
#include <stdio.h>

void IdleEntry(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Entering IDLE\n");
}

void IdleRunning(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Running IDLE\n");
}

void IdleExit(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Exiting IDLE\n");
}

void WorkEntry(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Entering WORK\n");
}

void WorkRunning(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Running WORK\n");
}

void WorkExit(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Exiting WORK\n");
}

void DoneEntry(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Entering DONE\n");
}

void DoneRunning(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Running DONE\n");
}

void DoneExit(State_t* this, void* ptr)
{
    (void)this;
    (void)ptr;
    printf("Exiting DONE\n");
}

