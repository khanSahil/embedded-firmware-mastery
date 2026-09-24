# Track 1 – Labs and Hands-On Work

This file records implementation exercises, experiments, debugger work, and larger projects.

## Lab tracking format

For each lab record:

- objective
- hardware / emulator / environment
- source files
- expected behavior
- observed behavior
- bugs encountered
- debugging method
- lessons learned
- mastery topics exercised

---

## Phase 1 labs

## Phase 1 board-acclimation labs

These are intentionally deferred until **Phase 1 Sections 14–15**.

Goal:

Become comfortable with the STM32H745I-DISCO development/debug workflow before Phase 2 becomes board-heavy.

Planned skills:

- create/build a firmware project
- flash firmware to the board
- reset / run / halt
- set and hit breakpoints
- set a watchpoint
- inspect CPU registers
- inspect memory
- inspect SP / stack contents / call stack
- use Step Into / Step Over / Step Return
- perform instruction stepping
- inspect disassembly
- observe a simple bare-metal superloop
- perform a basic fault-inspection exercise

Exit criterion before Phase 2:

Basic tooling mechanics should feel routine. Phase 2 should focus on MCU architecture and hardware concepts rather than spending lesson time learning how to flash firmware or operate the debugger.

---


### Pointer arithmetic micro-lab

Status: `PLANNED`

Goal:

Demonstrate how pointer arithmetic differs across pointed-to types.

Suggested experiment:

```c
#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint8_t  a8[4]  = {0};
    uint16_t a16[4] = {0};
    uint32_t a32[4] = {0};

    printf("%p %p\n", (void *)&a8[0],  (void *)&a8[1]);
    printf("%p %p\n", (void *)&a16[0], (void *)&a16[1]);
    printf("%p %p\n", (void *)&a32[0], (void *)&a32[1]);

    return 0;
}
```

Expected conceptual observation:

- `uint8_t * + 1` advances by 1 byte
- `uint16_t * + 1` advances by 2 bytes
- `uint32_t * + 1` advances by 4 bytes on systems where these types have the conventional widths

The semantic rule is based on `sizeof(*ptr)`, not on a hard-coded byte count.

### Pointer subtraction micro-lab

Status: `PLANNED`

Goal:

Verify that pointer subtraction returns an element distance.

Suggested experiment:

```c
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

int main(void) {
    uint32_t arr[5];

    uint32_t *p1 = &arr[1];
    uint32_t *p2 = &arr[4];

    ptrdiff_t d1 = p2 - p1;
    ptrdiff_t d2 = p1 - p2;

    printf("%td\n", d1);
    printf("%td\n", d2);

    return 0;
}
```

Expected:

```text
3
-3
```

Important constraint:

Do not extend this experiment by subtracting unrelated pointers and treating the result as meaningful C behavior.

---

## Future lab categories

- memory layout experiments
- compiler/assembly inspection
- linker map inspection
- MMIO simulation
- volatile optimization experiment
- interrupt latency measurement
- UART driver
- SPI driver
- I2C bus recovery
- DMA experiment
- RTOS scheduling lab
- bootloader lab
- Linux driver lab
- OpenBMC service/debugging lab