# Track 1 – Active Context

This file is the cross-chat synchronization snapshot for Track 1.

It is **not** an independent source of truth. If it conflicts with `Curriculum.md`, `Progress.md`, `Mastery-Ledger.md`, `Revision-Queue.md`, `Labs.md`, or `Design-Exercises.md`, the canonical file wins and this snapshot must be refreshed.

## Chat roles

Track 1 uses three coordinated chat types:

1. **Concepts & Mastery**
   - deep teaching
   - section-by-section conceptual progression
   - quizzes and mastery validation
   - interview-depth reasoning
   - revision of weak areas

2. **Hands-On Labs & Board**
   - coding
   - STM32H745I-DISCO work
   - build / flash / debug
   - register-level experiments
   - fault injection and measurements
   - mini-projects and lab troubleshooting

3. **Design & Architecture**
   - firmware design questions
   - subsystem and API design
   - tradeoffs
   - reliability / performance / debuggability
   - Principal-level design exercises

All three chats use the same GitHub repository as the durable source of truth.

## Current curriculum location

- Phase 1 – Embedded C and Bare-Metal Foundations
- Section 6 – C Memory & Pointer Foundations
- Section status: `IN_PROGRESS`

## Current conceptual checkpoint

Section 6 core material has now been covered across:

- pointer declaration, address-of, dereference, typed-pointer semantics
- pointer size vs pointed-to object size
- pointer arithmetic, subtraction, comparison, and one-past rules
- arrays vs pointers, `sizeof`, `arr` vs `&arr`
- multidimensional arrays, pointer-to-array, true 2D arrays vs `int **`
- 2D array function parameters and row-stride reasoning
- const pointer combinations
- structures, padding, alignment, and `memcmp` caveats
- `void *`
- null, dangling, and wild pointers
- object lifetime
- pointer casts
- byte/object representation and character-type inspection
- strict-aliasing / incompatible typed access basics
- alignment-sensitive pointer access
- integer / pointer conversion and `uintptr_t`
- function pointers and dispatch tables
- MMIO pointers
- volatile pointer patterns and important corner cases
- pointer-related undefined behavior
- pointer debugging with watchpoints
- firmware failure scenarios including silent corruption, delayed faults, and MMIO side effects

A 20-question hard Section 6 interview pass was completed. The learner showed strong conceptual and firmware-debug reasoning, with a few precision areas still worth revisiting.

## Current weak / refinement areas

These are not broad conceptual failures; they are precision areas to reinforce:

- strict aliasing / effective-type reasoning and optimizer assumptions
- distinguishing pointer casts from creation of a valid object of the cast-to type
- W1C register semantics and why read-modify-write can be unsafe
- precise explanation of delayed stack corruption vs the later fault site
- exact type wording for array lvalues vs pointer conversion in expressions
- occasional arithmetic slips while otherwise reasoning correctly

Principal-level wording is secondary for now; technical depth and correctness take priority.

## Current validation activity

Planned validation sequence:

- Questions 1–20: hard Section 6 only — completed
- Questions 21–40: hard integrated questions across Sections 1–6 — started

The integrated set is paused after beginning Question 21 so project organization could be formalized.

## Hands-on readiness

- Dedicated hands-on work should live in the **Hands-On Labs & Board** chat.
- Relevant coding experiments can be done as concepts become ready.
- The curriculum still intentionally ramps board usage, with light STM32H745I-DISCO acclimation in Phase 1 Sections 14–15 and board-heavy conceptual work from Phase 2 onward.
- Do not turn Phase 1 Sections 1–13 into board-heavy work unless there is a deliberate reason to preview something.
- The learner requested early STM32H745I-DISCO build, flash, and documentation practice. `Labs.md` Board Lab 00 is `IN_PROGRESS` as a narrow Section 6 preview; the conceptual checkpoint and planned Sections 14–15 board acclimation remain in place. Physical JP8 at STLK, LD4 power LED on, STM32CubeProgrammer target connection, device ID 0x450, and flash read were observed on 2026-09-27. The LCD was white during the CubeProgrammer connection, then showed an ST-branded demonstration menu after disconnecting; this is consistent with preloaded demonstration firmware. Whether the debugger halted the application is not yet proven. No new firmware has been flashed yet.
- Primary document sources, revisions, lab usage, and the America/Los_Angeles date each source was added are indexed in [`docs/README.md`](docs/README.md); the physical board is MB1381-H745XI-B03 and its schematic is linked; the learner chose LD7 (PJ2) and traced its active-low drive through the B03 schematic. A 2,048 KB BIN backup of internal flash was saved on 2026-09-28 PT; the learner must compare it with device flash before programming. External demo assets were not backed up. UM2237 is indexed in the docs register. Lab policy is documented in `Project-Instructions.md` and `Track_1/Labs.md`: use focused standalone or related C/board labs, primary-document lookups, observation, and gradually harder debugging. The learner explicitly wants to find hardware facts and write all lab code independently. Start each lookup by naming only the primary document and asking one open-ended question; wait for their answer before confirming, correcting, or offering sections/pins/LEDs as hints. Review submitted code and observations. Avoid starter implementations or solution snippets unless explicitly requested. **Project planning is paused; no project is active.** Do not require current labs to contribute to a larger product. Revisit several project options after substantial MCU and board foundations are demonstrated. The [device supervisor](Projects/Candidate-Connected-Device-Supervisor.md) remains a parked candidate; the [engineering workflow](Projects/Engineering-Workflow.md) is for a future chosen project.

## Design readiness

The **Design & Architecture** chat may currently use concepts established through Phase 1 Sections 1–6.

Good current design areas include:

- memory and pointer API choices
- array / buffer interfaces
- ownership and lifetime reasoning
- MMIO access abstractions
- volatile/register-access design
- failure containment and pointer-debuggability considerations

Do not assume mastery of later concepts such as interrupt architecture, DMA ownership models, RTOS synchronization, cache coherency design, boot/update architecture, or linker/startup internals until those sections are taught. Previewing is allowed only when explicitly labeled.

## Design & Architecture checkpoint

- The reviewed introductory startup readiness LED design is recorded in [`Design/01-startup-readiness-led.md`](Design/01-startup-readiness-led.md), with the hardware diagram in `Design/assets/` and the evolving format in `Design/README.md`.
- It covers hardware connections, firmware responsibility boundaries, reset/off-state behavior, required clock gating, safe failure handling, and validation. It was guided design work, not implemented or independently mastered.
- Design exercises should advance one learned concept at a time, retain earlier concepts cumulatively, and use the standard format at a depth appropriate to current readiness. Do not silently assume later-track concepts.
- The learned-concept baseline, demonstrated design coverage, and proposed next single-concept increment are in [`Design/Concept-Coverage.md`](Design/Concept-Coverage.md). Before each design question, state the new concept and curriculum location, plus relevant earlier design concepts; mark design coverage only after a reviewed write-up. The six-stage MCU-independent interview flow lives in `Design/README.md`.

## Cross-chat synchronization rule

Before substantive work, each chat should:

1. read `Active-Context.md`
2. read the canonical file(s) relevant to that chat
3. align the work with the current curriculum and readiness state

After a meaningful checkpoint, the chat should:

1. update the relevant canonical file(s)
2. update `Mastery-Ledger.md` if demonstrated capability changed
3. update `Revision-Queue.md` if a persistent gap was discovered or resolved
4. refresh `Active-Context.md` **last**

## When this file must be refreshed

Refresh `Active-Context.md` when the effective project state changes in a way another chat needs to know, including:

- a topic or section is completed
- a mastery status changes
- a meaningful weak area is added or resolved
- a lab milestone is completed
- a design exercise is completed
- hands-on or design readiness changes
- the current / next topic changes
- project workflow or chat organization changes

Do not refresh it for every individual message or minor correction. Use checkpoint-based updates.

## Next recommended concept step

Resume the integrated Sections 1–6 validation set at Question 21/40, then use the results to decide whether Section 6 can be closed or whether a small targeted revision pass is needed before Section 7.

## Synchronization checkpoint

This snapshot was refreshed after the latest updates to:

- `Progress.md`
- `Mastery-Ledger.md`
- `Revision-Queue.md`
- `Design-Exercises.md`
- `Project-Instructions.md`
- `Labs.md` (early Board Lab 00)
- `docs/README.md` (primary-document register)

Last synchronized: 2026-09-27
