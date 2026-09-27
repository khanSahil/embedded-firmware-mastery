# Track 1 – Design Exercises

This file records architecture/design exercises for the dedicated **Design & Architecture** chat.

The purpose is to provide design-level evidence without mixing design work into concept progress or hands-on lab history. The interview flow and evolving answer format are defined in [Design/README.md](Design/README.md).

## Operating rules

- Use only concepts that are marked ready in `Active-Context.md`, unless the exercise is explicitly labeled as a preview; add newly learned concepts cumulatively.
- Frame new questions independently of any specific MCU or board. Begin the interview with requirements, constraints, and assumptions.
- Initially guide the learner one decision at a time and help formulate the design answer; reduce guidance as the learner takes control.
- Apply the relevant portions of the six-stage framework in `Design/README.md`; early small exercises do not need every stage in depth.
- Record the problem, constraints, tradeoffs, proposed design, failure modes, and follow-up gaps. Show the complete write-up for learner review before pushing it to `Design/`.
- When an exercise provides evidence for a mastery-status change, update `Mastery-Ledger.md`.
- After a meaningful design checkpoint, refresh `Active-Context.md` last.
- Do not treat completion of a design discussion alone as `MASTERED`.

## Status values

- `PLANNED`
- `IN_PROGRESS`
- `COMPLETED`
- `NEEDS_REVISIT`

## Exercise template

### Design Exercise: <title>

Status: `PLANNED`

Relevant curriculum:
- Phase / Section:
- Concepts exercised:

Problem:

Constraints:

Design / reasoning:

Tradeoffs considered:

Failure modes / edge cases:

Debuggability / observability considerations:

Performance / reliability considerations:

What was demonstrated:

Gaps discovered:

Mastery-ledger impact:

Next step:

---

## Completed exercises

| [01 — Startup readiness LED](Design/01-startup-readiness-led.md) | `COMPLETED` (guided) | Phase 0 + Phase 1 hardware and GPIO fundamentals; conceptual design only, board implementation pending. |
