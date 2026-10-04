# Track 1 – Integrated Learning Map

## Purpose

Track 1 has three synchronized learning streams:

1. **Concepts & Mastery** — understand the technical foundations
2. **Design & Architecture** — apply learned concepts to engineering decisions
3. **Labs & Hardware** — implement, observe, debug, and measure on real hardware

They are not independent tracks. Concepts create readiness; design applies readiness; labs validate assumptions and create new evidence. Lab/design discoveries can feed revision items back into Concepts.

## Canonical state by stream

### Concepts
- `../Concepts/Curriculum.md`
- `../Concepts/Progress.md`
- `../Concepts/Mastery-Ledger.md`
- `../Concepts/Revision-Queue.md`

### Design
- `../Design/Progress.md`
- `../Design/Design-Index.md`
- `../Design/Concept-Coverage.md`
- reviewed design artifacts under `../Design/`

### Labs
- `../Labs/Progress.md`
- `../Labs/Lab-Index.md`
- supporting documentation/artifacts under `../docs/`, `../firmware-backups/`, and relevant lab/project folders

`../Active-Context.md` is the short dashboard for all chats. It is derived from these canonical files.

---

## Current integrated checkpoint — 2026-10-03

### Concepts

Section 7 — **Embedded-C Semantics** is complete for the current conceptual-validation pass.

Validated readiness now includes Sections 1–7, with Section 7 adding/reinforcing:
- `volatile`, `const`, and `const volatile`
- fixed-width integer reasoning
- integer promotions and usual arithmetic conversions
- safe shifts and field masking
- MMIO read-modify-write hazards
- W1C / read-to-clear semantics
- implementation-defined, unspecified, and undefined behavior
- compiler assumptions around UB
- sequencing and short-circuit safety
- strict-aliasing / object-representation reasoning
- struct padding, serialization, and bit-field portability limits

Remaining non-blocking reinforcement includes:
- complete integer-promotion-path wording
- strict-aliasing / character-type exception rationale
- cache coherency vs `volatile`
- W1C/direct-mask transfer to real peripheral work

Next concept section: **Section 8 — Concurrency Foundations**.

### Design

Completed reviewed exercises:
- **01 — Startup readiness LED** (guided conceptual design)
- **02 — Development board debug access** (guided conceptual design)

Currently appropriate design themes based on concept readiness through Section 7:
- buffer/pointer API choices
- ownership/lifetime reasoning
- MMIO/register access boundaries
- safe bit manipulation and register-field policy
- W1C/read-to-clear aware register handling
- startup/safe-state decisions
- representation/serialization choices
- low-level debuggability

Do not yet assume mastery of interrupt architecture, DMA ownership, RTOS synchronization, memory-ordering/barrier design, linker/startup internals, or cache-maintenance architecture. Section 8 and later material should remain previews until formally learned.

### Labs

Board Lab 00 is `IN_PROGRESS` as a narrow early preview.

Verified practical readiness/evidence:
- STLINK-V3E connection
- target identification and Flash read
- factory internal-Flash backup
- full Flash-vs-file comparison before new programming
- LD7/PJ2 schematic trace and active-low reasoning

Next lab checkpoint:
- learner-written LD7 firmware -> build -> flash -> observe/debug

Labs may now rely on concepts established through Section 7, while keeping true concurrency, interrupt architecture, DMA/cache maintenance, linker/startup internals, and later topics explicitly labeled as previews.

---

## Dependency rule for choosing work

Before starting a new design or lab:

1. Read `../Active-Context.md`.
2. Check the relevant concept prerequisites in `../Concepts/Progress.md` and `../Concepts/Mastery-Ledger.md`.
3. Check whether an existing reviewed design should guide the lab, or whether the lab itself is exploratory.
4. Label any use of not-yet-learned material as a **preview**, not as mastered knowledge.
5. After completion, record evidence in the owning stream and add cross-stream impact here only when readiness/dependencies actually changed.

## Evidence loop

```text
Concepts establish readiness
        ↓
Design applies and exposes tradeoffs
        ↓
Labs implement / measure / debug
        ↓
Evidence and surprises
        ↓
Concept revision + design refinement
```

The objective is not to keep the three streams at identical positions. The objective is to keep them **coherent**: Design and Labs should know what Concepts has established, while Concepts should receive practical/design evidence without silently treating discussion as mastery.
