# Track 1 – Design Progress

This file records design/architecture progress for the dedicated **Design & Architecture** chat.

Design work applies concepts already learned in `../Concepts/` and should not silently assume later-track material. Cross-stream readiness is summarized in `../Active-Context.md` and mapped in `../Integration/`.

## Operating rules

- Read `../Active-Context.md` before substantive design work.
- Use only concepts currently ready unless an item is explicitly labeled as a preview.
- Maintain `Concept-Coverage.md` to distinguish concepts learned from concepts actually demonstrated in design.
- Frame exercises independently of a specific MCU unless board-specific detail is the point of the exercise.
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

## Next design work

Choose the next exercise from concepts already marked ready in `../Concepts/Progress.md` and `../Active-Context.md`. Add only a genuinely new design dimension at a time while carrying earlier design concepts forward.
