# Track 1 – Integrated Milestones

This file records major checkpoints that matter across Concepts, Design, and Labs. Detailed evidence stays in the owning stream.

## 2026-09-28 — Section 6 conceptual validation completed

Concepts:
- completed 20 hard Section 6-only questions
- completed 20 hard integrated Sections 1–6 questions
- Section 6 moved from active learning/validation to revision-and-transfer mode
- Section 7 – Embedded-C Semantics is next

Strong demonstrated areas:
- pointer/array semantics
- stack and delayed-corruption reasoning
- MMIO vs RAM address-space reasoning
- `volatile` compiler semantics
- `volatile` vs atomicity/thread safety
- pointer/data watchpoint debugging

Non-blocking revision areas:
- strict aliasing/effective-type precision
- W1C read-modify-write hazards
- cache coherency vs `volatile`
- exact array-lvalue/pointer-conversion wording

Cross-stream impact:
- Design may use Section 1–6 concepts as established prerequisites.
- Labs may use Section 1–6 concepts and Phase 0 tooling/debug foundations.
- Section 6 is not yet blanket `MASTERED`; later design/lab/unfamiliar-scenario evidence should drive future promotion.

## 2026-09-28 — Factory internal-Flash backup verified

Labs:
- full 2 MiB STM32H745 internal-Flash image saved before programming new firmware
- backup artifact stored under `../firmware-backups/`
- STM32CubeProgrammer comparison over `0x08000000`–`0x08200000` reported no difference

Cross-stream impact:
- Board Lab 00 can proceed to learner-written firmware with a verified recovery/reference image for internal Flash.

## 2026-09-27 — Board Lab 00 hardware/documentation orientation

Labs:
- STLINK-V3E connection verified
- physical board revision identified as MB1381-H745XI-B03
- LD7 traced to PJ2
- learner correctly derived active-low LED behavior from the schematic

Cross-stream impact:
- practical evidence reinforces Phase 0 debug-path understanding and Phase 1 MMIO/GPIO reasoning without advancing conceptual curriculum position.

## 2026-09-26 — First reviewed design exercise

Design:
- startup readiness LED conceptual design completed with guidance
- requirements, hardware/software boundaries, safe state, clock failure, debug visibility, tradeoffs, and validation discussed

Cross-stream impact:
- demonstrates early application of Phase 0 / Phase 1 concepts
- does not independently establish `DESIGNED_WITH` or `MASTERED` across all involved topics

## 2026-09-28 — Track 1 three-stream repo model adopted

Track 1 repo organization standardized around:
- `../Concepts/`
- `../Design/`
- `../Labs/`
- `../Integration/`
- `../Active-Context.md`

Rule:
- all chats may read all streams for current context
- each stream owns its detailed state
- Integration tracks dependencies/readiness
- Active Context is refreshed last when effective cross-chat state changes

## Next major milestone

Begin Section 7 while continuing Board Lab 00 and design work only at a depth consistent with the latest concept readiness.
