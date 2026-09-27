# Track 1 — Design & Architecture

This folder contains reviewed design questions, the resulting answers, and their diagrams. Exercises grow cumulatively with the concepts recorded in `../Active-Context.md` and the Track 1 curriculum. Later tracks may use prior-track concepts once they have been learned; do not assume later concepts are mastered in advance.

## Exercise index

| Exercise | Curriculum scope | Status |
|---|---|---|
| [01 — Startup readiness LED](01-startup-readiness-led.md) | Phase 0; Phase 1 hardware, clock, reset, GPIO, basic firmware structure | Guided design completed; board-specific implementation open |

## Design discussion guide

Treat each exercise as an embedded design interview. State the problem without choosing a particular MCU or board; reason in terms of generic hardware and firmware responsibilities. Start by clarifying requirements, constraints, assumptions, and success criteria before proposing components or an implementation. Ask genuine design questions, rather than turning the session into a debugging or device-specific quiz.

Start with one learned concept and add each newly learned concept to subsequent exercises alongside earlier ones. Use only concepts ready in `../Active-Context.md`; identify anything else as a preview. Early designs can be small, and each stage below gets deeper only as the relevant concepts are learned. Revisit earlier designs when new concepts change a decision.

The interviewer initially helps the learner find the next question, prompts one decision at a time, and helps turn the learner's reasoning into a coherent answer. Gradually remove this scaffolding so the learner leads the requirements, structure, and tradeoffs. For each meaningful decision, explain the problem addressed, why the choice fits the constraints, its costs and failure cases, and when an alternative would be preferable.

## Evolving answer flow

Use the relevant parts of this full framework; do not force every section into an early, small exercise.

1. **Requirements and scope:** Functional requirements, quality goals, constraints, assumptions, exclusions, and success criteria.
2. **High-level architecture:** MCU-independent hardware and software blocks, their connections, and the main signal and data flows. Include a clear block diagram when connections matter.
3. **Hardware/software partitioning:** Allocate responsibilities to hardware and firmware, explain why, and define their interfaces.
4. **Detailed subsystems:** Describe each relevant subsystem's hardware role, software architecture, responsibilities, interfaces, state, and normal execution flow.
5. **Deep dives and edge cases:** Defend important decisions and alternatives; cover failure behavior, timing, resource limits, recovery, and diagnosis as the curriculum makes them relevant.
6. **Production and lifecycle:** Explain verification against requirements, testing, observability, updates, maintenance, and relevant reliability and security considerations.

Close with a short decision recap and open questions. Clearly distinguish a conceptual diagram from verified wiring or an implemented system.

After the discussion, assemble the design question, the learner's reasoning, the answer, and any diagram into a complete write-up for learner review **before pushing it to the repo**. `../Design-Exercises.md` remains the compact cross-chat index and evidence record; reviewed designs live here. A design discussion alone does not establish mastery.
