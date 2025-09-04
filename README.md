# State Machine Test

This project contains a small C example of a network state machine refactored for stricter MISRA-C and DO-178C style.  Each state exposes typed entry, run, and exit handlers and the transition matrix enforces bounds-checked lookups.

## Building

```sh
cd StateMachineTest
gcc -std=c99 -Wall -Wextra main.c NwkStateMachineED.c NwkStates.c State.c StateEventMatrix.c -o statemachine
```

## Running

```sh
./statemachine | head -n 5
```
The program prints a trace of the first few state transitions, for example:

```
Buffer: 0 - PreState: 1 - Event: 6 - New State: 1
Buffer: 0 - PreState: 1 - Event: 1 - New State: 1
Buffer: 0 - PreState: 1 - Event: 3 - New State: 2
Buffer: 0 - PreState: 2 - Event: 1 - New State: 2
Buffer: 0 - PreState: 2 - Event: 7 - New State: 0
```

## Project layout

- `StateMachineTest/` – sources for the sample state machine
  - `NwkStates.c/h` – network state implementations
  - `NwkStateMachineED.c` – driver setting up the state machine
  - `State.c/h` and `StateEventMatrix.c/h` – generic state/transition utilities
  - `main.c` – deterministic harness exercising the state machine

## Notes

The code is intended as a starting point for experimentation in safety‑critical environments.  Additional verification and platform integration are required before production use.
