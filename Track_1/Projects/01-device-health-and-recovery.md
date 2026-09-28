# Project 1 – Device Health and Recovery System

Status: **selected for planning; implementation has not started**

## Goal

Build firmware on the STM32H745I-DISCO that can report its state, record useful events, diagnose failures, and recover safely. Later, add a small Linux-side management tool for viewing logs and interacting with the device. The first working versions should use only the board and a development computer; additional hardware can be considered when a lab needs it.

This is the first substantial Track 1 project, not the only one. Later projects can focus on other domains such as protocol gateways or audio processing.

## User-visible behavior, built incrementally

1. Boot into a known state and show a heartbeat/status indication.
2. Accept simple local commands and report firmware version, uptime, and health.
3. Record timestamped events and reset/fault information.
4. Preserve important records across resets and make them inspectable.
5. Expose status to a host over a communication interface.
6. Detect selected failures and enter a defined recovery path.

The exact interface and storage implementation will be chosen during the appropriate labs from board documentation and measurements. Do not assume a feature is complete merely because a demo runs once.

## Provisional lab milestones

The numbers are planning ranges, not prerequisites or a fixed 50-lab promise. Independent labs may build separate modules; related labs may extend an existing module. Each regular lab contributes to this repository and is integrated when verified.

| Labs | Milestone | Example contributions |
| --- | --- | --- |
| P1-L01–L04 | Portable foundations | Build layout, event representation, bounded buffer, host-side checks and debugging notes |
| P1-L05–L08 | Board bring-up | Build/flash/debug workflow, startup observation, status LED, input event |
| P1-L09–L12 | Time and diagnostics | Time base, event timestamps, reset information, local diagnostic commands |
| P1-L13–L16 | Durable records | Storage abstraction, integrity check, record retrieval, reset/recovery tests |
| P1-L17–L20 | Host communication | Device status protocol, host tool, flow control, disconnection behavior |
| P1-L21–L24 | Reliability | Watchdog strategy, fault capture, long-run observation, recovery validation |
| Later, if useful | Extensions | Display, RTOS migration, DMA/cache exercise, dual-core coordination, firmware update |

Only schedule board-heavy labs when the curriculum supports them. Phase 1 Sections 14–15 are the planned board acclimation point; earlier C labs can add portable modules, tests, or tools that serve a real project need.

## How a lab becomes part of the project

- Start from a known working revision. An independent module may be built separately before integration.
- Use the relevant ST user manual, revision-matched schematic, MCU datasheet, and reference manual to find the facts needed for implementation.
- Record expected behavior, implementation, observation, debugging evidence, and the contribution in `Track_1/Labs.md`.
- Check the new behavior and the previously established capabilities affected by the change. Keep prior lab revisions reproducible with Git commits or tags.
- Keep intentional-bug exercises in separate branches or copies. Integrate only verified fixes with a regression check.

The first detailed lab specification should be written when the relevant concept and tools are ready. Adjust the backlog as actual hardware observations and demonstrated mastery warrant.
