# Track 1 — Design & Architecture

This folder contains reviewed design questions, the resulting answers, and their diagrams. The exercises grow cumulatively with the concepts recorded in `../Active-Context.md` and the Track 1 curriculum. Later tracks may use prior-track concepts once they have been learned; do not assume later concepts are mastered in advance.

## Exercise index

| Exercise | Curriculum scope | Status |
|---|---|---|
| [01 — Startup readiness LED](01-startup-readiness-led.md) | Phase 0; Phase 1 hardware, clock, reset, GPIO, basic firmware structure | Guided design completed; board-specific implementation open |

## Evolving design format

Use these headings where relevant; early exercises can be brief. Add detail as the curriculum covers timing, concurrency, protocols, DMA, RTOS, security, production reliability, and other concerns.

1. Design question and scope
2. Requirements, constraints, and assumptions
3. Hardware blocks and connections
4. Firmware blocks and execution sequence
5. Decisions, alternatives, and reasons
6. Failure behavior and diagnosis
7. Validation
8. Open questions and future extensions

The mentor initially prompts one decision at a time and helps assemble the final answer. Gradually remove prompts as the learner can structure a design independently. For each decision, explain the problem solved, why the choice fits, its costs and failure cases, and when an alternative would be better. Revisit earlier exercises when a newly learned concept changes the design. Distinguish a conceptual diagram from verified board wiring or an implemented system.

`../Design-Exercises.md` remains the compact cross-chat index and evidence record. The complete reviewed designs live here.
