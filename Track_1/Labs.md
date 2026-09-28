# Track 1 – Labs and Hands-On Work

This file records implementation exercises, experiments, debugger work, and larger projects.

## STM32H745I-DISCO documentation

Use ST's [board documentation page](https://www.st.com/en/evaluation-tools/stm32h745i-disco.html#documentation) as the standing starting point. For each board lab, locate the needed facts in the appropriate primary source:

- [Board data brief](https://www.st.com/resource/en/data_brief/stm32h745i-disco.pdf): feature overview.
- [Board user manual UM2488](https://www.st.com/resource/en/user_manual/um2488-discovery-kits-with-stm32h745xi-and-stm32h750xb-mcus-stmicroelectronics.pdf): layout, connectors, power, and on-board debugger.
- [STM32H745XI datasheet DS12923](https://www.st.com/resource/en/datasheet/stm32h745xi.pdf): MCU pinout, specifications, and electrical limits.
- [MCU reference manual RM0399](https://www.st.com/resource/en/reference_manual/rm0399-stm32h745755-and-stm32h747757-advanced-armbased-32bit-mcus-stmicroelectronics.pdf): peripheral registers and behavior.
- A board schematic from the [board documentation page](https://www.st.com/en/evaluation-tools/stm32h745i-disco.html#documentation) that matches the physical board revision: actual signal wiring.

The learner should find and explain the relevant passage, table, or register field before using it in code. Provide section or search hints when needed.

## Current lab progression

**Projects are paused. No active project has been selected.** Use focused C experiments and later board labs to establish core concepts, documentation habits, build/flash/debug competence, and hardware understanding. Labs may stand alone or build on one another. Increase their difficulty with demonstrated skill; do not force an early lab to become product code.

For each lab, locate the relevant facts in primary documentation, predict behavior, implement or inspect a small change, observe it with suitable tools, explain discrepancies, and record the result. Keep reproducible code and configurations in the repository when useful. Intentional-bug exercises remain separate from working examples.

Board acclimation remains planned for Phase 1 Sections 14–15; board-heavy conceptual work follows in Phase 2. After substantial MCU and board foundations are demonstrated, compare multiple production-relevant project options for broad, transferable embedded engineering learning. The [connected device supervisor](Projects/Candidate-Connected-Device-Supervisor.md) is a parked candidate. The [modular source and team workflow](Projects/Engineering-Workflow.md) is reserved for a future chosen project, though Git branches and reviews can be practiced during labs.

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

### Board Lab 00 – First connection and firmware flash

Status: `IN_PROGRESS` (early preview requested 2026-09-27)

Objective: use the board manual to identify power/debug connections, build a minimal firmware image, flash it through the on-board STLINK-V3E, verify execution with the debugger, and relate a visible behavior to hardware documentation.

Hardware and environment: STM32H745I-DISCO, Windows host, STM32CubeIDE, STM32CubeProgrammer, STM32CubeH7 package, USB data cable. The physical board revision and JP8 position must be observed, not assumed.

Documentation checkpoints:
1. UM2488 Figure 5 (board bottom layout): locate the STLINK-V3E USB connector CN14.
2. UM2488 Sections 6.3–6.4: identify embedded debugger, power route, and JP8 selection for CN14.
3. UM2488 Table 7 and revision-matched schematic: identify a user LED and its MCU connection before any GPIO code.
4. MCU datasheet and RM0399 later: locate the relevant GPIO and clock behavior before register-level work.

First interactive checkpoint: learner reports the observed JP8 position and locates CN14 on their board before connecting/programming. Subsequent build/flash/debug and LED observations will be recorded as they occur. No successful flash or running firmware has been claimed yet.

The full board-acclimation sequence remains planned for **Phase 1 Sections 14–15**. The learner requested a narrow build/flash/hardware-documentation preview during Section 6; this preview does not advance conceptual mastery or replace the later sequence.

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