#ifndef STATE_H
#define STATE_H

#include <stdint.h>

#define STATE_MEMORY 100

typedef struct _State_t
{
    void (*entryFnc_ptr)(struct _State_t*, void*);
    void (*runningFnc_ptr)(struct _State_t*, void*);
    void (*exitFnc_ptr)(struct _State_t*, void*);
    uint8_t stateMemory[STATE_MEMORY];
} State_t;

#endif /* STATE_H */
