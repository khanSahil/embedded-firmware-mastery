# Track 1 – Design Concept Coverage

Last updated: 2026-10-03

This file tracks the difference between:

1. concepts that are **available for design** because they have been learned/validated in the Concepts stream, and
2. concepts that have actually been **demonstrated in reviewed design work**.

This is not a claim that every available concept is mastered.

Canonical concept sources:
- `../Concepts/Curriculum.md`
- `../Concepts/Progress.md`
- `../Concepts/Mastery-Ledger.md`
- `../Concepts/Revision-Queue.md`
- `../Active-Context.md`

## Concepts currently available for design

### Phase 0 – Tooling, Board, and Debug Environment Orientation

Available:
- development/build chain
- PC -> USB -> debug probe -> SWD -> target path
- on-board vs external debug probe concepts
- SWD signal roles
- IDE/GDB/GDB-server/probe layering
- hardware/software breakpoints
- watchpoints
- source vs instruction stepping
- Step Into / Over / Return
- LR, return-address preservation, call stack, and unwinding
- fault-time stacked context and basic fault-status reasoning
- reset/restart/reflash and Flash-vs-RAM runtime behavior

### Phase 1 Sections 1–5

Available:
- MCU and memory-map mental model
- Flash / SRAM / peripheral regions
- MMIO fundamentals
- clocks/reset/GPIO electrical foundations
- CPU registers, PC, LOAD/STORE, stack/SP/LR, function calls
- binary/hex and bit manipulation
- signed/unsigned, two's complement, integer ranges, overflow concepts
- byte-addressed memory, endianness, alignment, object representation

### Phase 1 Section 6 – C Memory & Pointer Foundations

Status: conceptually validated and available for design.

Available:
- pointer/address/dereference semantics
- pointer arithmetic, same-array rules, one-past
- arrays, `arr` vs `&arr`, pointer-to-array
- multidimensional arrays and 2D parameter reasoning
- pointer-to-pointer
- const pointer combinations
- structures/padding/alignment
- `void *`
- null/dangling/wild pointers and object lifetime
- pointer casts and strict-aliasing basics
- integer/pointer conversion and `uintptr_t`
- function pointers / callbacks / dispatch tables
- MMIO pointers and volatile pointer forms
- read-to-clear / W1C awareness
- `volatile` vs atomicity / cache-coherency distinctions
- pointer-related UB and optimization-sensitive failure
- watchpoint-based memory-corruption debugging
- delayed stack/control-flow corruption reasoning

### Phase 1 Section 7 – Embedded-C Semantics

Status: conceptually validated and available for design as of 2026-10-03.

Available:
- `volatile`, `const`, and `const volatile` API/register intent
- fixed-width integer type selection
- integer-promotion and signed/unsigned conversion awareness
- safe masks, shifts, and register-field manipulation
- access-width vs field-width reasoning
- MMIO read-modify-write hazards
- W1C / read-to-clear aware register handling
- implementation-defined, unspecified, and undefined behavior awareness
- compiler assumptions around UB
- sequencing / short-circuit safety
- strict-aliasing / object-representation constraints
- struct padding and layout tradeoffs
- explicit serialization / endianness contracts
- bit-field portability limits

Important limits:
- strict-aliasing precision, character-type object-representation rationale, cache coherency vs `volatile`, and real-peripheral W1C transfer remain reinforcement items in `../Concepts/Revision-Queue.md`.
- availability for design does **not** imply mastery of interrupt architecture, DMA ownership, RTOS synchronization, memory barriers/order, linker/startup internals, cache-maintenance architecture, bootloader, or security architecture.
- Section 8 and later concepts are not yet part of the established design baseline unless explicitly labeled as previews.

## Concepts actually demonstrated in reviewed designs

| Exercise | Demonstrated design concepts | Guidance / limits |
|---|---|---|
| [01 — Startup readiness LED](01-startup-readiness-led.md) | Requirements clarification; reset/default off-state reasoning; GPIO output policy; required clock as readiness condition; separation of startup policy from low-level GPIO control; failure-safe behavior; RAM error evidence observable through debug path; validation thinking | Guided exercise. Board-specific implementation and independent transfer remain open. This does not make every involved concept `DESIGNED_WITH` or `MASTERED`. |
| [02 — Development board debug access](02-development-board-debug-access.md) | On-board versus external probe placement; host/probe/target responsibility boundaries; reset-dependent early-failure recovery; shared GND and target-voltage reference; image readback/build-ID/ELF matching; finite hardware debug resources; focused validation | Guided, MCU-independent one-board design. Actual protocol, wiring, measurements, and independent transfer remain open. The 20-board sharing analysis was exploratory, not the core design. |

Do not infer that all concepts available above have been used in design. Only reviewed evidence in this table counts as demonstrated design coverage.

## Next design increment

Choose one genuinely new design dimension from concepts already available through Section 7. Before starting:

1. name the one new concept and its curriculum location
2. identify previously demonstrated design concepts that naturally carry forward
3. identify learned concepts intentionally left for later
4. ask the learner to clarify requirements first
5. update this file only after the reviewed write-up is complete

Debug-probe placement was exercised in Design 02. Select the next small increment using the latest `../Active-Context.md`; do not repeat probe placement as if it were new.
