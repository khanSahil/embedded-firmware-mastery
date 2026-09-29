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

## Current integrated checkpoint — 2026-09-28

### Concepts

Section 6 — **C Memory & Pointer Foundations** is complete for the current conceptual-validation pass.

Validated readiness includes:
- pointer and array semantics
- object lifetime
- alignment and representation basics
- strict-aliasing basics
- MMIO pointer reasoning
- `volatile` compiler semantics
- read-to-clear / W1C awareness
- `volatile` vs atomicity
- `volatile` vs cache coherency at a conceptual level
- pointer/data corruption debugging
- stack/delayed-fault reasoning

Next concept section: **Section 7 — Embedded-C Semantics**.

### Design

Completed reviewed exercise:
- **01 — Startup readiness LED** (guided conceptual design)

Currently appropriate design themes based on concept readiness:
- buffer/pointer API choices
- ownership/lifetime reasoning
- MMIO/register access boundaries
- startup/safe-state decisions
- debuggability of low-level firmware interfaces

Do not yet assume mastery of interrupt architecture, DMA ownership, RTOS synchronization, linker/startup internals, or cache-coherency design.

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

This preview does not move the Concepts curriculum ahead of Section 7.

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
