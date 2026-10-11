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
- `Track-1-Embedded-Firmware-Mastery.md` — durable detailed learning reference; Sections 1–8 consolidated
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
- **Section 8 – Concurrency Foundations**
- status: `COMPLETED` for the current conceptual-validation pass; not permanently mastered
- checkpoint recorded: 2026-10-11

Validation completed:
- 15-question cumulative assessment covering Sections 1–8
- Q15 5/5; Q14 4/4; Q13 credited 4/4 because head-index convention was unspecified
- Q12 corrected to 3/3 because the original configuration already had the requested MODE
- earlier Q10, Q7, Q3 each 3/4; no aggregate score reconstructed

Latest demonstrated evidence:
- Q15 SPSC ring-buffer capacity `BUFFER_SIZE - 1`
- drop-newest on full and payload-before-head publication
- ISR can continue while main is delayed; separate producer head / consumer tail ownership under assessed assumptions
- separate writers do not alone prove portable atomic access or memory ordering

Current concept section:
- **Section 9 – Compiler & Build Pipeline**
- status: `IN_PROGRESS`, starting **preprocessing**
- no completed Section 9 assessment claimed

Phase 1 overview:
- Sections 1–5: covered previously / foundation established
- Sections 6–8: completed for the current conceptual-validation pass
- Sections 10–15: `NOT_STARTED`
- foundation/completion status does not imply blanket `MASTERED`

Remaining revision targets:
- signed arithmetic overflow/conversions
- portable wire serialization and struct padding
- DMA lifecycle/cache coherency
- pointer byte offsets
- earlier refinement items remain in `Concepts/Revision-Queue.md`

Assessment preference: short concept blocks with questions after each concept; cumulative assessments cover all previously covered sections, including demonstrated strengths.

Technical correctness/depth remains the priority; Principal-level phrasing can be polished after the model is solid.

## Design & Architecture

Current reviewed design:
- **02 — Development board debug access**
- status: completed as a guided MCU-independent conceptual design on 2026-09-30
- external probe selected for the single-board architecture; the probe-to-target signal diagram is under `Design/assets/`
- target-specific protocol/connector/reset behavior and hardware validation remain open
- Design 01 startup readiness LED remains a completed guided design with board-specific implementation open

Current design readiness:
- may use concepts established through Phase 1 Section 8
- appropriate themes now include buffer/pointer interfaces, ownership/lifetime, MMIO/register boundaries, safe field/mask handling, W1C/read-to-clear awareness, representation/serialization choices, startup/safe-state policy, low-level debuggability, bounded queue policies, and ISR/main shared-state ownership

Do not silently assume later concepts such as interrupt architecture, DMA ownership, RTOS synchronization, memory-ordering/barrier design, linker/startup internals, cache-maintenance design, or boot/update architecture. Label those as previews until formally learned.

## Hands-On Labs & Board

Latest completed lab:
- **Board Lab 01 — Register-level LED on/off** (2026-10-06)
- learner reported successful build/flash and both LED states verified on hardware
- Board Lab 00 narrow connection/build/flash preview completed; formal Sections 14–15 board acclimation remains later
- reviewed source/project saved under `Labs/Board/Track1_Board_Labs`

Verified practical checkpoints:
- STLINK-V3E connection and flash download verification working
- physical board MB1381-H745XI-B03; active-low LD7/PJ2
- factory 2 MiB internal-Flash backup saved and compared before programming
- volatile register access, RCC readback, output preload before mode, direct BSRR commands
- shared LED module and `Src/Labs/Lab01_LED` folder; missing-main source-folder link error repaired

Next lab:
- **Board Lab 02 — timed LED blinking** (planned)
- establish clock/timing assumptions before writing delay code
- preserve one IDE project with per-lab folders and only one lab main in each build
- apply professional review/refactoring practice to each lab

Open limitations:
- FPU initialization warning unresolved
- derive remaining literal pin masks and improve reason-focused comments when revisiting the shared module
- vendor CMSIS header integration and generic GPIO deferred

No large Track 1 project is currently active. Project selection remains paused until stronger MCU/board foundations are demonstrated.

## Integrated readiness

Design and Labs may consume Concepts through Section 8 as established prerequisites.

The streams do **not** need to be at identical positions. They must remain coherent:
- Concepts establishes readiness.
- Design applies concepts and exposes tradeoffs.
- Labs validates behavior and exposes practical gaps.
- Lab/design evidence can feed back into Concepts revision/mastery decisions.

See `Integration/Learning-Map.md` and `Integration/Dependency-Graph.md` for the synchronized dependency boundary through Section 8 foundations under explicit access/ordering assumptions.

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

**2026-10-11 — Reference notes restored:** Sections 6–8 now have detailed handbook notes in the same format as Sections 1–5. Progress/mastery/revision files complement the handbook. Future completed sections should be consolidated in that format. This documentation checkpoint adds no new practical or mastery evidence; Section 9 remains active at preprocessing.

**2026-10-11:** Section 8 completed for the current conceptual-validation pass after the 15-question cumulative Sections 1–8 assessment; Q15 5/5, Q14 4/4, Q13 credited 4/4, Q12 corrected 3/3, earlier Q10/Q7/Q3 each 3/4. Section 9 is active, starting preprocessing. The four revision targets remain open; no permanent mastery or new Design/Labs completion is claimed. Detailed checkpoint: `Integration/History/2026-10-11-Section-8-Completion.md`.

**2026-10-06:** Section 8 – Concurrency Foundations confirmed `IN_PROGRESS`; handbook Phase 1 dashboard, repository/Track 1 overviews, Concepts, and Integration synchronized. Sections 9–15 remain `NOT_STARTED`. Design/Labs established prerequisite readiness remains through Section 7.

**2026-10-03:** Section 7 – Embedded-C Semantics completed for the current conceptual-validation pass, including a 15-question integrated validation. Section 8 – Concurrency Foundations is next; Design and Labs may now consume concepts through Section 7. Integration readiness/dependency files are synchronized to the same boundary.

**2026-09-30:** Design 02 debug access completed as a guided conceptual exercise, with an MCU-independent probe-to-target signal diagram. Probe fleet sizing remains a later scaling question.

**2026-09-28:** Section 6 conceptual validation completed and the Track 1 Concepts / Design / Labs / Integration repo model was fully migrated and synchronized.

Detailed milestones: `Integration/Milestones.md`.

Last synchronized: 2026-10-11
