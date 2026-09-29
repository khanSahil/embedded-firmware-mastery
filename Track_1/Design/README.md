# Track 1 — Design & Architecture

This folder contains reviewed design questions, their resulting answers, diagrams, and design-progress tracking. Exercises grow cumulatively with concepts recorded in `../Concepts/` and the readiness summarized in `../Active-Context.md`. Do not assume later concepts are mastered in advance.

## Design tracking

- `Progress.md` — current design progress and operating rules
- `Design-Index.md` — concise reviewed-design index
- `Concept-Coverage.md` — learned concepts vs concepts actually demonstrated in reviewed designs

## Exercise index

| Exercise | Curriculum scope | Status |
|---|---|---|
| [01 — Startup readiness LED](01-startup-readiness-led.md) | Phase 0; Phase 1 hardware, clock, reset, GPIO, basic firmware structure | Guided design completed; board-specific implementation open |

## Design discussion guide

The [concept coverage tracker](Concept-Coverage.md) lists concepts learned through the current curriculum checkpoint separately from concepts actually used in reviewed designs. Before each new question, announce its one new concept and Phase/Section/Topic, identify earlier design concepts that naturally carry forward, and show which learned concepts remain for later. Add design coverage only after a reviewed design demonstrates it.

Treat each exercise as an embedded design interview. State the problem without choosing a particular MCU or board unless device specificity is itself the exercise. Reason first in terms of generic hardware and firmware responsibilities. Start by clarifying requirements, constraints, assumptions, and success criteria before proposing components or an implementation.

Use only concepts ready in `../Active-Context.md` and `../Concepts/Progress.md`; identify anything else as a preview. Revisit earlier designs when newly learned concepts materially change a decision.

The interviewer initially helps the learner find the next question, prompts one decision at a time, and helps turn the learner's reasoning into a coherent answer. Gradually remove this scaffolding so the learner leads the requirements, structure, and tradeoffs.

## Evolving answer flow

Use the relevant parts of this full framework; do not force every section into an early, small exercise.

1. **Requirements and scope:** Functional requirements, quality goals, constraints, assumptions, exclusions, and success criteria.
2. **High-level architecture:** MCU-independent hardware and software blocks, their connections, and the main signal and data flows.
3. **Hardware/software partitioning:** Allocate responsibilities to hardware and firmware, explain why, and define their interfaces.
4. **Detailed subsystems:** Describe each relevant subsystem's hardware role, software architecture, responsibilities, interfaces, state, and normal execution flow.
5. **Deep dives and edge cases:** Defend important decisions and alternatives; cover failure behavior, timing, resource limits, recovery, and diagnosis as the curriculum makes them relevant.
6. **Production and lifecycle:** Explain verification against requirements, testing, observability, updates, maintenance, and relevant reliability/security considerations.

Close with a short decision recap and open questions. Clearly distinguish a conceptual diagram from verified wiring or an implemented system.

After the discussion, assemble the design question, learner reasoning, answer, and any diagram into a complete write-up for learner review before pushing it to the repo. Update `Progress.md`, `Design-Index.md`, and `Concept-Coverage.md` as appropriate. A design discussion alone does not establish mastery; mastery evidence belongs in `../Concepts/Mastery-Ledger.md` under the cross-stream evidence rules.
