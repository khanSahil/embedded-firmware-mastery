# Track 1 board labs — Lab 2 checkpoint

Saved: 2026-10-11 (America/Los_Angeles).

Learner-written STM32H745I-DISCO firmware, developed with STM32CubeIDE 2.2.0 on Windows. Source and IDE configuration are preserved from the reviewed ZIP; generated Debug/Release output is excluded.

## Layout and build

- CM7/Src/Labs/Lab01_LED/main.c: preserved Lab 1 entry point (excluded from the current build).
- CM7/Src/Labs/Lab02_Blink/main.c: active Lab 2 entry point.
- CM7/Src/systick.c and CM7/Inc/systick.h: polling SysTick delay module.
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

Debug includes STM32H745xx and CORE_CM7 plus both CMSIS include paths. Release lacks these additions and is not validated. Lab 1 is excluded in the saved configurations; select exactly one lab main when switching labs.

The submitted source is preserved unchanged. Deferred until the next lab: move private SysTick constants into systick.c, update the Lab 2 main comment, document the delay API contract, and configure Release. The existing FPU warning remains unresolved. Polling owns SysTick and can miss elapsed periods during long interruptions; this is a blocking learning implementation.

Validation here: archive integrity, source preservation, and repository checks only; no independent rebuild or hardware test. Vendor copyright headers are retained. The header subset targets GCC/CM7 without USE_HAL_DRIVER; other cores, toolchains, and devices require additional vendor headers.
