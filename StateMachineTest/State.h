#ifndef STATE_H
#define STATE_H

#include "inttypes.h"

#define STATE_MEMORY 100

typedef struct _State_t
{
	const void* (*entryFnc_ptr)(struct _State_t*, void*);
	const void* (*runningFnc_ptr)(struct _State_t*, void*);
	const void* (*exitFnc_ptr)(struct _State_t*, void*);

	uint8_t stateMemory[STATE_MEMORY];
}State_t;


#endif