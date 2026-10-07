# Track 1 – Labs Progress

This file records implementation exercises, experiments, debugger work, board observations, and practical milestones for the **Hands-On Labs & Board** chat.

Labs should consume concepts that are ready in `../Concepts/` and may apply reviewed designs from `../Design/`. Cross-stream readiness is summarized in `../Active-Context.md` and mapped in `../Integration/`.

## Lab workflow

- Read `../Active-Context.md` before starting substantive lab work.
- Use the primary documentation register at `../docs/README.md` for board/MCU facts.
- Let the learner locate hardware facts and write lab code first; provide progressively stronger hints only as needed.
- Define a small observable goal, predict behavior, implement, inspect evidence, explain deviations, and record the result.
- Keep intentional-bug exercises separate from known-good examples.
- Lab evidence can support mastery, but concept-status promotion belongs in `../Concepts/Mastery-Ledger.md`.
- Refresh `../Active-Context.md` after a meaningful lab checkpoint.

## Current lab state

### Board Lab 00 – First connection and firmware flash

Status: `COMPLETED` for the narrow connection/build/flash preview (2026-10-06); formal board-acclimation sequence remains later.

Purpose: become comfortable with the STM32H745I-DISCO development/debug path before the formal Phase 1 Sections 14–15 board-acclimation sequence.

Hardware/environment:
- STM32H745I-DISCO
- physical board: MB1381-H745XI-B03
- Windows host
- STM32CubeIDE
- STM32CubeProgrammer
- on-board STLINK-V3E

Verified/observed checkpoints:

- **2026-09-27:** JP8 observed at STLK; CN14 connected to PC; LD4 power LED on.
- **2026-09-27:** STM32CubeProgrammer connected successfully; device ID `0x450`, target voltage about 3.25 V, and internal Flash read succeeded.
- **2026-09-27:** LCD was white during active programmer/debug connection and later showed the ST demonstration menu after disconnecting; preloaded demonstration firmware is present. Whether debug attachment halted the application was not proven.
- **2026-09-27:** learner identified LD6/LD7, selected LD7, found MCU pin PJ2, and used the B03 schematic to determine that LD7 is **active low**: PJ2 low sinks current through the LED path; PJ2 high turns it off.
- **2026-09-28:** learner used STM32CubeProgrammer Read All / Save As to back up the full 2 MiB internal Flash to a BIN file.
- **2026-09-28:** the backup artifact is stored under `../firmware-backups/`; recorded SHA-256: `961d7faa8833fb785141d3e9af8d6dee751661c4c3f67a3680e709d6a91d562c`.
- **2026-09-28:** STM32CubeProgrammer **Compare flash memory with file** reported “No difference found with file” across `0x08000000`–`0x08200000`, verifying the saved internal-Flash image before new firmware is flashed.

Completed practical checkpoint (2026-10-06): learner wrote, built, flashed, and debugged LED firmware. Flash log reported successful download verification; learner verified both LED on and off on the board. The project was reorganized into a shared LED module and per-lab source folders. A missing-main link failure after moving outside the configured source root was repaired by placing Labs under Src.

### Board Lab 01 – Register-level LED on/off

Status: `COMPLETED` for the stated hardware-control objective (2026-10-06).

Source/project: [Board/Track1_Board_Labs](Board/Track1_Board_Labs/README.md).

Environment: STM32CubeIDE 2.2.0, CM7, STM32H745I-DISCO / MB1381-H745XI-B03; ST-LINK over SWD, connect under reset, flash verification enabled.

Evidence: learner-written volatile MMIO accesses; GPIOJ clock bit 9 and readback; PJ2 push-pull, low speed, no pulls; initial high before output mode; direct BSRR on/off commands. Compiler disassembly was inspected, and learner reported board verification of both states. Reviewed ZIP contains guarded public declarations, shared implementation, and Src/Labs/Lab01_LED/main.c. Reviewer did not independently rebuild or execute hardware.

Known limitations: FPU startup warning unresolved; literal masks and explanatory comments remain cleanup; vendor-header integration/generic GPIO deferred. Saved main calls on then off without delay and ends off. Formal concepts and blanket mastery are not advanced by this preview.

Next: Board Lab 02 — timed LED blinking (planned), reusing the shared LED module. Establish clock/timing assumptions before implementing the delay. Keep all labs in one IDE project and exclude inactive lab folders per build configuration. Professional code review/refactoring remains part of every lab.

This early board preview does **not** advance the conceptual curriculum position. Formal board acclimation remains in Phase 1 Sections 14–15.

## Planned host/C micro-labs

### Pointer arithmetic micro-lab

Status: `PLANNED`

Goal: observe element-size scaling for 8-bit, 16-bit, and 32-bit pointer arithmetic.

### Pointer subtraction micro-lab

Status: `PLANNED`

Goal: verify same-array pointer subtraction and element-distance semantics.

These are optional reinforcement labs rather than blockers now that Section 6 conceptual validation is complete.

## Future lab categories

- memory-layout experiments
- compiler/assembly inspection
- linker-map inspection
- MMIO/register experiments
- volatile optimization experiments
- interrupt/timing measurement
- UART/SPI/I2C
- DMA and cache-coherency experiments
- RTOS scheduling/debugging
- bootloader/update work
- production fault-injection and recovery exercises

## Project policy

No large Track 1 project is currently active. Current labs should be chosen for learning value and observable evidence, not forced into a product architecture. Revisit multiple project options after stronger MCU and board foundations are demonstrated. Existing parked project ideas remain under `../Projects/`.
