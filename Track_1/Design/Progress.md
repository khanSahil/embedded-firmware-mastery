# Track 1 – Design Progress

This file records design/architecture progress for the dedicated **Design & Architecture** chat.

Design work applies concepts already learned in `../Concepts/` and should not silently assume later-track material. Cross-stream readiness is summarized in `../Active-Context.md` and mapped in `../Integration/`.

## Operating rules

- Read `../Active-Context.md` before substantive design work.
- Use only concepts currently ready unless an item is explicitly labeled as a preview.
- Maintain `Concept-Coverage.md` to distinguish concepts learned from concepts actually demonstrated in design.
- Frame exercises independently of a specific MCU unless board-specific detail is the point of the exercise.
- Before each new design, show the proposed question and a concise coverage map: relevant framework aspects, expected depth, and exclusions/deferred topics. Let the learner adjust it before beginning the interview; do not pre-answer the requirements.
- Start with requirements, constraints, assumptions, and success criteria before proposing architecture.
- Record tradeoffs, failure modes, observability/debuggability, and open questions.
- A design discussion alone does not establish `MASTERED`; concept-status promotion belongs in `../Concepts/Mastery-Ledger.md` and must follow the mastery policy.
- Refresh `../Active-Context.md` after a meaningful design checkpoint.

## Status values

- `PLANNED`
- `IN_PROGRESS`
- `COMPLETED`
- `NEEDS_REVISIT`

## Current state

### 01 — Startup readiness LED

Status: `COMPLETED` (guided conceptual design)

Artifact: `01-startup-readiness-led.md`

Demonstrated:
- requirements and scope clarification
- hardware/software responsibility boundaries
- startup ready/not-ready policy
- GPIO off-state reasoning
- clock-failure behavior
- debuggable safe state
- SWD-readable error state
- tradeoff and validation thinking

Open:
- board-specific implementation
- exact pin/register implementation details
- measurements on hardware
- independent transfer without guidance

This design can inform labs that use GPIO/MMIO concepts, but it does not force a lab sequence and does not advance conceptual curriculum position by itself.

### 02 — Development board debug access

Status: `COMPLETED` (guided conceptual design)

Artifact: `02-development-board-debug-access.md`, with `assets/debug-probe-to-target-signals.png`.

Demonstrated:
- clarification of programming and debugging capabilities for a board whose application may fail before startup
- PC → external probe → board/target debug path and the external-probe placement tradeoff
- separation of host ELF/symbol work, probe communication, target debug hardware, and application firmware
- GND and target-voltage reference roles; reset access for early-failure recovery
- readback verification and build-ID matching to the ELF
- breakpoint/watchpoint resource and timing tradeoffs, and a focused recovery validation plan

Open:
- actual target protocol, connector/pinout, probe model, reset/halt mechanism, and flash algorithm
- measurements and tests on real hardware
- independent transfer to an unfamiliar debug-access scenario

The original exercise is one-board architecture. The 20-board/eight-engineer discussion was a scaling example; shared-probe counts and queueing are not settled by this design. Guided discussion does not establish independent mastery.

## Next design work

Choose the next exercise from concepts already marked ready in `../Concepts/Progress.md` and `../Active-Context.md`. Announce its one new design dimension and carry relevant earlier concepts forward. Do not assume any target-specific validation has occurred for Design 02.
