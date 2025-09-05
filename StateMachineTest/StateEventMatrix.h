#ifndef STATE_EVENT_MATRIX_H
#define STATE_EVENT_MATRIX_H

#include <stdint.h>
#include <stddef.h>
#include "State.h"

/** Invalid event identifier */
#define EVENT_INVALID (UINT32_MAX)

/** Invalid state identifier */
#define STATE_INVALID (UINT32_MAX)

/** Event identifier type */
typedef uint32_t Events_t;

/** State identifier type */
typedef uint32_t StateName_t;

/**
 * @brief State-event transition matrix object.
 *
 * Stores the description of all states, allowed transitions and the
 * execution context for a single instance of the state machine.
 */
typedef struct
{
    uint32_t stateMaxNum;                  /**< Number of states available */
    uint32_t eventMaxNum;                  /**< Number of events available */
    uint8_t* stateMachineMemoryBuffer;     /**< Working buffer for state memory */
    StateName_t startingState;             /**< Initial state identifier */
    State_t* states;                       /**< Array of state descriptions */
    const StateName_t* stateTransitions;   /**< Transition matrix stored as 1D array */
    Events_t actualEvent;                  /**< Pending event for next transition */
    StateName_t actualState;               /**< Currently active state */
} StateEventMatrix_t;

/**
 * @brief Execute the transition driven by the pending event.
 *
 * Performs exit, entry and running callbacks as required and clears
 * the pending event on completion.
 *
 * @param[in,out] stateMatrix Pointer to the state machine object.
 */
void StateEventMatrix_ExecuteTrans(StateEventMatrix_t* stateMatrix);

/**
 * @brief Initialise the state machine to its starting state.
 *
 * Sets the current state and clears any pending event.
 *
 * @param[in,out] stateMatrix Pointer to the state machine object.
 */
void StateEventMatrix_Init(StateEventMatrix_t* stateMatrix);

/**
 * @brief Set the next event and optionally copy external data.
 *
 * External data is copied into the internal memory buffer if the
 * pointers are valid and the size does not exceed STATE_MEMORY.
 *
 * @param[in,out] stateMatrix Pointer to the state machine object.
 * @param[in] event Event to trigger.
 * @param[in] memBuffer Optional pointer to data to copy.
 * @param[in] bufferSize Size of the data in bytes.
 */
void StateEventMatrix_SetEvent(StateEventMatrix_t* stateMatrix, Events_t event, void* memBuffer, uint32_t bufferSize);

/**
 * @brief Reset the state machine to the starting state and clear memory.
 *
 * The internal memory buffer is zeroed. Compliance with MISRA C:2023
 * Rule 17.7 is ensured by casting ignored return values to void.
 *
 * @param[in,out] stateMatrix Pointer to the state machine object.
 */
void StateEventMatrix_Reset(StateEventMatrix_t* stateMatrix);

#endif /* STATE_EVENT_MATRIX_H */
