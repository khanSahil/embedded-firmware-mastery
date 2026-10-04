# Track 1 – Active Context

This file is the short cross-chat dashboard for Track 1.

It is **derived state**, not an independent source of truth. If it conflicts with the owning stream files, the owning stream wins and this dashboard must be refreshed.

## Track 1 working model

Three synchronized chat/learning streams:

1. **Concepts & Mastery**
2. **Design & Architecture**
3. **Hands-On Labs & Board**

All three may read the full repo for context. Each stream owns its detailed state; `Integration/` tracks dependencies/readiness between them.

Repo-structure migration status: `COMPLETE` (2026-09-28).

## Canonical paths

### Concepts
- `Concepts/Curriculum.md`
- `Concepts/Progress.md`
- `Concepts/Mastery-Ledger.md`
- `Concepts/Revision-Queue.md`

### Design
- `Design/Progress.md`
- `Design/Design-Index.md`
- `Design/Concept-Coverage.md`
- reviewed design artifacts under `Design/`

### Labs
- `Labs/Progress.md`
- `Labs/Lab-Index.md`
- supporting docs/artifacts under `docs/`, `firmware-backups/`, and related folders

### Integration
- `Integration/Learning-Map.md`
- `Integration/Dependency-Graph.md`
- `Integration/Milestones.md`

---

# Current dashboard

## Concepts & Mastery

Current phase: **Phase 1 – Embedded C and Bare-Metal Foundations**

Last completed section:
- **Section 7 – Embedded-C Semantics**
- status: `COMPLETED` for the current conceptual-validation pass
- completion date: 2026-10-03

Validation completed:
- 15-question integrated Section 7 validation pass

Strong demonstrated areas:
- `volatile` access semantics and separation from atomicity
- W1C / MMIO read-modify-write hazards
- signed/unsigned conversion consequences
- signed-overflow UB and compiler assumptions
- pointer lifetime, one-past, and `ptrdiff_t` reasoning
- sequencing and short-circuit safety
- struct padding, serialization, and bit-field portability

Next concept section:
- **Section 8 – Concurrency Foundations**
- status: `READY_TO_START`

Non-blocking refinement areas:
- complete integer-promotion-path wording
- strict aliasing / character-type object-representation rationale
- cache coherency vs `volatile`
- W1C/direct-mask transfer to real peripheral work
- array-lvalue vs pointer-conversion wording
- delayed-corruption vs eventual fault-site wording
- occasional arithmetic precision under interview pressure

Technical correctness/depth remains the priority; Principal-level phrasing can be polished after the model is solid.

## Design & Architecture

Current reviewed design:
- **02 — Development board debug access**
- status: completed as a guided MCU-independent conceptual design on 2026-09-30
- external probe selected for the single-board architecture; the probe-to-target signal diagram is under `Design/assets/`
- target-specific protocol/connector/reset behavior and hardware validation remain open
- Design 01 startup readiness LED remains a completed guided design with board-specific implementation open

Current design readiness:
- may use concepts established through Phase 1 Section 7
- appropriate themes now include buffer/pointer interfaces, ownership/lifetime, MMIO/register boundaries, safe field/mask handling, W1C/read-to-clear awareness, representation/serialization choices, startup/safe-state policy, and low-level debuggability

Do not silently assume later concepts such as interrupt architecture, DMA ownership, RTOS synchronization, memory-ordering/barrier design, linker/startup internals, cache-maintenance design, or boot/update architecture. Label those as previews until formally learned.

## Hands-On Labs & Board

Current active lab:
- **Board Lab 00 – First connection and firmware flash**
- status: `IN_PROGRESS`
- this is a narrow early preview; formal board acclimation still belongs to Phase 1 Sections 14–15

Verified practical checkpoints:
- STLINK-V3E connection working
- physical board identified as MB1381-H745XI-B03
- target/device read through STM32CubeProgrammer
- LD7 traced to PJ2 and correctly identified as active low
- 2 MiB factory internal-Flash BIN backup saved
- backup stored under `firmware-backups/`
- full `0x08000000`–`0x08200000` compare reported **No difference found with file** before new firmware programming

Next lab checkpoint:
- learner writes first LD7 firmware
- build
- flash
- observe/debug behavior

No large Track 1 project is currently active. Project selection remains paused until stronger MCU/board foundations are demonstrated.

## Integrated readiness

Design and Labs may consume Concepts through Section 7 as established prerequisites.

The streams do **not** need to be at identical positions. They must remain coherent:
- Concepts establishes readiness.
- Design applies concepts and exposes tradeoffs.
- Labs validates behavior and exposes practical gaps.
- Lab/design evidence can feed back into Concepts revision/mastery decisions.

See `Integration/Learning-Map.md` for the current dependency map.

---

# Cross-chat operating protocol

Before substantive Track 1 work:

1. Read this file.
2. Read the owning stream's canonical files.
3. Read other stream files when their latest state affects the task.
4. Use `Integration/Learning-Map.md` / `Dependency-Graph.md` when choosing work that crosses streams.

After a meaningful checkpoint:

1. Update the owning stream's canonical file(s).
2. Record cross-stream dependency/evidence changes in `Integration/` when relevant.
3. Update concept mastery/revision state only when the evidence supports it.
4. Refresh this file **last** if another chat needs to know the effective state changed.

## Refresh triggers

Refresh this dashboard when:
- a concept topic/section completes
- mastery status meaningfully changes
- a significant revision item is added/resolved
- a lab milestone completes
- a reviewed design completes
- design/lab readiness changes
- current/next work changes
- project workflow/structure changes

Do not refresh it for every individual message or small correction.

## Latest milestone

**2026-10-03:** Section 7 – Embedded-C Semantics completed for the current conceptual-validation pass, including a 15-question integrated validation. Section 8 – Concurrency Foundations is next; Design and Labs may now consume concepts through Section 7.

**2026-09-30:** Design 02 debug access completed as a guided conceptual exercise, with an MCU-independent probe-to-target signal diagram. Probe fleet sizing remains a later scaling question.

**2026-09-28:** Section 6 conceptual validation completed and the Track 1 Concepts / Design / Labs / Integration repo model was fully migrated and synchronized.

Detailed milestones: `Integration/Milestones.md`.

Last synchronized: 2026-10-03
