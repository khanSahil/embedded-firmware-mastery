# Track 1 board labs — Lab 1 checkpoint

Saved: 2026-10-06 (America/Los_Angeles).

Learner-written STM32H745I-DISCO firmware, developed with STM32CubeIDE 2.2.0 on Windows. Source and IDE configuration are preserved from the reviewed ZIP; generated Debug/Release output is excluded.

## Layout and build

- CM7/Src/Labs/Lab01_LED/main.c: Lab 1 application entry point.
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
- Vendor CMSIS header integration and a generic GPIO driver are deferred.
- Standalone dual-core startup behavior has not been independently validated.

For every lab: implement, verify on hardware, review/refactor, then rebuild and verify again. Keep abstraction proportional to the exercised use cases.
