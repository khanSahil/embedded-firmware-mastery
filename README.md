# Embedded Systems Mastery

This repository is the canonical source of truth for the multi-year Embedded Systems Mastery program.

## Tracks

1. **Track 1 – Embedded Firmware Mastery** — current active track.
2. **Track 2 – Embedded Linux / Linux Device Drivers** — planned after Track 1 if selected next.
3. **Track 3 – Jetson / CUDA / Edge AI / Computer Vision / Robotics** — planned after Track 1 if selected next.

See [Tracks-Overview.md](Tracks-Overview.md) for the cross-track roadmap.

## Source-of-truth rule

GitHub is authoritative for curriculum, progress, mastery evidence, revision queues, labs, design work, and cross-stream integration. Chat history is supporting context, not the durable project state.

## Track 1 structure

Track 1 is organized as three synchronized learning streams plus an integration layer:

```text
Track_1/
├── Concepts/
│   ├── Curriculum.md
│   ├── Progress.md
│   ├── Mastery-Ledger.md
│   └── Revision-Queue.md
├── Design/
│   ├── Progress.md
│   ├── Design-Index.md
│   ├── Concept-Coverage.md
│   └── reviewed design artifacts
├── Labs/
│   ├── Progress.md
│   └── Lab-Index.md
├── Integration/
│   ├── Learning-Map.md
│   ├── Dependency-Graph.md
│   └── Milestones.md
└── Active-Context.md
```

Concepts establish readiness, Design applies the learned concepts, and Labs validate them in code/hardware. Design and lab evidence can feed back into concept revision and mastery.

Any Track 1 chat may read all three streams for current context. Each stream owns its detailed state. `Track_1/Active-Context.md` is the short synchronized dashboard and should be refreshed last after meaningful cross-chat state changes.

## Current active checkpoint

Track 1 → Phase 1 (as of 2026-10-06).

- Sections 1–5: foundation established / covered previously.
- Section 6 – C Memory & Pointer Foundations: completed for the current conceptual-validation pass (2026-09-28).
- Section 7 – Embedded-C Semantics: completed for the current conceptual-validation pass (2026-10-03; 15-question integrated validation).
- Section 8 – Concurrency Foundations: `IN_PROGRESS`.
- Sections 9–15: `NOT_STARTED`.

Foundation/completion status does not imply blanket `MASTERED` status.

- Board Lab 00 remains in progress as a narrow early preview.
- Reviewed designs: startup readiness LED and development board debug access (guided conceptual designs).

See `Track_1/Active-Context.md` for the latest synchronized state.
