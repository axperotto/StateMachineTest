# State Machine Test

The project demonstrates a minimal finite state machine engine designed with MISRA-C style in mind.
A simple example shows three states—IDLE, WORK and DONE—with deterministic transitions driven by events.

## Building

```sh
cd StateMachineTest
gcc -std=c99 -Wall -Wextra main.c SimpleStates.c SimpleStateMachine.c StateEventMatrix.c -o statemachine
```

## Running

```sh
./statemachine
```
Example output:

```
Entering IDLE
Running IDLE
Exiting IDLE
Entering WORK
Running WORK
PreState: 0 Event: 0 NewState: 1
Exiting WORK
Entering DONE
Running DONE
PreState: 1 Event: 1 NewState: 2
Exiting DONE
Entering IDLE
Running IDLE
PreState: 2 Event: 2 NewState: 0
```

## Project layout

- `StateMachineTest/` – source files
  - `State.h` and `StateEventMatrix.*` – generic engine
  - `SimpleStates.*` – sample state implementations
  - `SimpleStateMachine.*` – transition table and instance
  - `main.c` – small driver executing a few transitions

## Notes

The code is intended as a starting point for experimentation in safety-critical environments. Further verification is required before production use.
