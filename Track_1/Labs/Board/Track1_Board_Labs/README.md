# Track 1 board labs — Lab 3 checkpoint

Updated: 2026-10-23 (America/Los_Angeles).

Learner-written STM32H745I-DISCO firmware, developed with STM32CubeIDE 2.2.0 on Windows. Current development and pushes use Git directly from CubeIDE. Generated Debug/Release output is excluded.

## Layout and build

- CM7/Src/Labs/Lab01_LED/main.c: preserved Lab 1 entry point (excluded from the current build).
- CM7/Src/Labs/Lab02_Blink/main.c: preserved Lab 2 entry point (excluded).
- CM7/Src/Labs/Lab03_NonBlockingBlink/main.c: active Lab 3 entry point.
- CM7/Src/systick.c and CM7/Inc/systick.h: polling delay and separate interrupt timebase APIs; select one mode, do not mix them.
- CM7/Drivers/CMSIS: required STM32H745 / Cortex-M7 GCC headers from the submitted ZIP; unrelated devices/cores omitted.
- CM7/Src/led7.c and CM7/Inc/led7.h: shared LED7 init/on/off module.
- CM7/Startup, linker scripts, runtime support, and IDE settings: build support.
- CM4: original companion project; not used in this lab. Closing it in the IDE does not disable the physical core.

In CubeIDE, import existing projects from this directory, select Track1_Board_Labs_CM7, and build Debug. Connect CN14 to the on-board ST-LINK, use the saved CM7 debug configuration, download and verify firmware, then resume/step execution. Review host-specific settings if importing on another machine.

Future labs belong under CM7/Src/Labs. Include only one lab main.c in each build; exclude inactive lab folders from the selected build configuration.

## Lab 1 behavior and evidence

LD7 USER2 is active low on PJ2. Initialization enables the GPIOJ clock with RCC readback, preloads output high (LED off), selects push-pull/low speed/no pulls, and selects output mode last. Direct BSRR writes turn the LED on and off without a read-modify-write operation.

The learner reported successful builds, flash verification, and board tests of both LED states. The reviewer checked source and archive integrity; no independent board execution or rebuild was performed here.

The saved main calls init, on, then off with no delay, and ends in an infinite loop. Normal execution therefore ends with LED7 off; debugger stepping allows observing both states. Timed blinking is Lab 2.

## Known limitations and next work

- Existing FPU initialization warning remains; startup SystemInit had no implementation in the reviewed project. Do not assume FPU initialization has occurred.
- Masks still contain literal pin-related positions 4, 5, 18, and 2; deriving them from GPIOJ_PIN_BIT is deferred cleanup.
- Comments explaining RCC readback and the initial safe output state can be improved.
- CMSIS headers are integrated for Debug; generic GPIO remains deferred.
- Standalone dual-core startup behavior has not been independently validated.

For every lab: implement, verify on hardware, review/refactor, then rebuild and verify again. Keep abstraction proportional to the exercised use cases.

## Lab 2 — polling blink checkpoint (2026-10-11)

The learner confirmed successful build, flash, and visible alternating LED7 on/off, with a requested 1000 ms delay for each state. SysTick uses the assumed 64 MHz processor clock, LOAD = 63999, processor clock source, and no interrupt. A software loop polls 1000 COUNTFLAG events per second. Main is blocked during each delay. Timing was not independently measured.

Debug and Release CMSIS paths/symbols were corrected in the Lab 2 cleanup. The learner now chooses Debug-only validation for labs. Select exactly one lab main when switching labs.

Lab 2 cleanup is complete: private constants, main brief, API contract, and Release setup. The existing FPU warning remains unresolved. Polling owns SysTick and can miss elapsed periods during long interruptions; this is a blocking learning implementation.

Validation here: archive integrity, source preservation, and repository checks only; no independent rebuild or hardware test. Vendor copyright headers are retained. The header subset targets GCC/CM7 without USE_HAL_DRIVER; other cores, toolchains, and devices require additional vendor headers.

## Lab 3 — interrupt timebase checkpoint (2026-10-23)

Saved in commit `1c32cb9`. SysTick requests an interrupt every nominal millisecond; `SysTick_Handler` increments a private volatile counter. Main uses unsigned elapsed-time subtraction and `>= 1000U` to change LED state without a blocking delay. The LED starts OFF. The learner verified the handler breakpoint and visible one-second ON/OFF behavior after correcting a case-sensitive handler-name typo. Code was reviewed; no independent reviewer build, hardware test, or timing measurement is claimed.

Debug-only builds are the current lab preference. FPU initialization remains unresolved. See [lab progress](../../Progress.md) for evidence, limitations, and the proposed button-input/debouncing lab.

## Development Environment

- IDE: STM32CubeIDE 2.2.0
- Board: STM32H745I-DISCO
- MCU cores: Cortex-M7 and Cortex-M4
- Version control: Git and GitHub

### Verified Setup

- [x] Imported existing projects from Git repository
- [x] CM7 firmware builds successfully
- [ ] CM4 firmware build verification
- [x] CM7 Lab 3 flash/debug and visible blink verification reported by learner (Debug)