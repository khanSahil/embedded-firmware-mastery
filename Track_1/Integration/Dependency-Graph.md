# Track 1 – Dependency Graph

## Principle

Track 1 is one mastery program with three synchronized dimensions: **Concepts**, **Design**, and **Labs**.

They may advance at different speeds, but they must remain coherent.

## Core dependency flow

```text
Concepts
  ├─ establish mental models
  ├─ define prerequisites
  └─ expose language/hardware constraints
        ↓
Design
  ├─ applies learned concepts
  ├─ introduces tradeoffs
  └─ defines interfaces / failure policies / architecture
        ↓
Labs
  ├─ implement and observe behavior
  ├─ validate assumptions
  └─ expose practical gaps and failure modes
        ↓
Feedback returns to Concepts and Design
```

The flow is not strictly one-way. A lab may reveal a missing concept; a design may expose a weak assumption; those become concept-revision or future-curriculum inputs.

## Ownership model

### Concepts owns
- curriculum position
- conceptual progress
- mastery/evidence state
- revision queue

Canonical paths:
- `../Concepts/Curriculum.md`
- `../Concepts/Progress.md`
- `../Concepts/Mastery-Ledger.md`
- `../Concepts/Revision-Queue.md`

### Design owns
- design exercise progress
- reviewed design artifacts
- design concept-coverage evidence

Canonical paths:
- `../Design/Progress.md`
- `../Design/Design-Index.md`
- `../Design/Concept-Coverage.md`

### Labs owns
- lab progression
- board/software observations
- build/flash/debug checkpoints
- measurement/debug evidence

Canonical paths:
- `../Labs/Progress.md`
- `../Labs/Lab-Index.md`

### Integration owns
- dependencies between streams
- major cross-stream milestones
- readiness mapping

Canonical paths:
- `Learning-Map.md`
- `Dependency-Graph.md`
- `Milestones.md`

### Active Context

`../Active-Context.md` is a **derived dashboard**, not an independent truth source.

Every Track 1 chat reads it first, then reads the canonical stream files relevant to its work.

## Write rules across chats

- A Concepts chat updates Concepts files and may update Integration when readiness changes.
- A Design chat updates Design files and may add evidence/dependencies to Integration.
- A Labs chat updates Labs files and may add evidence/dependencies to Integration.
- Any chat may **read all streams** to get the latest project state.
- A chat should not silently promote another stream's detailed state. Cross-stream evidence is recorded first; mastery/status changes should follow the owning stream's rules.
- After a meaningful checkpoint that affects other chats, refresh `../Active-Context.md` last.

## Current dependency boundary

As of 2026-09-28:

- Concepts are ready through Phase 1 Section 6; Section 7 is next.
- Design may use concepts through Section 6 without calling them previews.
- Labs may use concepts through Section 6 and Phase 0 tooling/debug foundations.
- Later concepts such as interrupts, DMA ownership, RTOS synchronization, cache-maintenance mechanics, linker/startup internals, and boot/update architecture must be labeled preview material until formally learned.
