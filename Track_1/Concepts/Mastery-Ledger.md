# Track 1 – Concepts Mastery Ledger

This file tracks demonstrated capability, not merely whether a topic was discussed.

## Status scale

- `NOT_STARTED`
- `INTRODUCED`
- `UNDERSTOOD`
- `PRACTICED`
- `DEBUGGED`
- `DESIGNED_WITH`
- `MASTERED`
- `NEEDS_REVIEW`

`MASTERED` requires successful transfer to unfamiliar scenarios; a completed lesson or quiz alone is not enough.

## Phase 0 – Tooling, Board, and Debug Environment Orientation

Overall status: `PRACTICED` / phase `COMPLETED`

Evidence:
- 20-question validation completed 2026-09-23
- score: 19/20
- the only miss was a wording/misread issue; the underlying precise-vs-imprecise fault concept was immediately stated correctly

Strong evidence includes build/debug-chain reasoning, ST-LINK/SWD layering, breakpoints/watchpoints, LR/call-stack reasoning, fault-time stacked context, CFSR/HFSR/BFAR concepts, effective-address reconstruction, and reset/reflash behavior.

## Phase 1 – Sections 1–5

Status: `COVERED_PREVIOUSLY`

Do not assume blanket `MASTERED`. Later integrated questions, labs, designs, and revision provide additional evidence.

## Phase 1 – Section 6: C Memory & Pointer Foundations

Conceptual-validation status: `COMPLETED` on 2026-09-28.

Overall capability status: `PRACTICED`, with selected `DEBUGGED` evidence.

| Area | Status | Evidence |
|---|---|---|
| Pointer declaration, address-of, dereference | PRACTICED | Correctly reasoned about pointer values, targets, and indirection |
| Pointer arithmetic / one-past / subtraction | PRACTICED | Strong element-scaling and range reasoning; subtraction-domain precision remains in revision |
| Arrays, `arr` vs `&arr`, multidimensional arrays | PRACTICED | Correct row-stride, layout, offset, and pointer-to-array reasoning |
| Pointer-to-pointer and 2D parameters | PRACTICED | Correctly distinguished true 2D arrays from `int **` and explained column-stride requirement |
| `const` pointer combinations | PRACTICED | Correctly distinguished pointee constness from pointer constness |
| Structures, padding, alignment | PRACTICED | Correct layout reasoning and `memcmp` padding caveat |
| `void *`, null, dangling, wild pointers | PRACTICED | Correct generic-pointer and lifetime/failure reasoning |
| Object lifetime | PRACTICED | Correct automatic/static/dynamic lifetime reasoning |
| Pointer casts / strict aliasing | UNDERSTOOD | Core rule understood; effective-type and optimizer precision remains a revision target |
| Integer-pointer conversion / `uintptr_t` | PRACTICED | Correct pointer-width/truncation reasoning |
| Function pointers | PRACTICED | Correct declarations, callbacks, and dispatch-table reasoning |
| MMIO pointers | PRACTICED | Correct connection from address to peripheral transaction and side effects |
| `volatile` compiler semantics | PRACTICED | Correctly distinguishes compiler access preservation from hardware destination |
| Read-to-clear / W1C register behavior | UNDERSTOOD | Core semantics repaired; W1C RMW hazards remain a deliberate revision item |
| `volatile` vs atomicity | PRACTICED | Correctly explained read-modify-write races and why volatile is not synchronization |
| `volatile` vs cache coherency | PRACTICED | Understands DMA/cache stale-data problem and that cache maintenance is separate from volatile |
| Pointer-related UB | PRACTICED | Correctly diagnosed out-of-bounds, dangling, wild, misaligned, aliasing, and one-past dereference cases |
| Pointer/data corruption debugging | DEBUGGED | Correctly chose watchpoints on pointer storage vs target data |
| Firmware failure scenarios | DEBUGGED | Correctly reasoned about silent corruption, delayed stack faults, and MMIO side effects |
| Optimization-sensitive UB | UNDERSTOOD | Understands why optimized builds may exploit language assumptions |

## Section 6 validation evidence

Completed on 2026-09-28:

- 20 hard Section 6-only questions
- 20 hard integrated Sections 1–6 questions

Observed strengths:

- pointer/array reasoning
- stack and delayed-corruption reasoning
- CPU effective-address reasoning
- bit manipulation and integer representation
- endianness and memory representation
- MMIO vs RAM address-space reasoning
- pointer-copy and pointer-to-pointer semantics
- `volatile` vs synchronization/cache-coherency distinctions
- debugger/watchpoint reasoning

Section 6 is complete for the current pass and does **not** block Section 7. It is not yet labeled `MASTERED`; future lab, design, debugging, and unfamiliar-scenario evidence should drive any later promotion.

## Phase 1 – Section 7: Embedded-C Semantics

Conceptual-validation status: `COMPLETED` on 2026-10-03.

Overall capability status: `PRACTICED`.

| Area | Status | Evidence |
|---|---|---|
| `volatile` access semantics | PRACTICED | Correctly explains required accesses and why repeated volatile reads/writes cannot be casually collapsed |
| `volatile` vs atomicity / synchronization | PRACTICED | Correctly identifies RMW races and separates access preservation from atomicity |
| `const` / `const volatile` | PRACTICED | Correctly distinguishes software write restrictions, hardware-updated state, and underlying-object constness |
| Fixed-width integer types | PRACTICED | Correctly reasons about exact-width intent, `int` width assumptions, and register access width vs field width |
| Safe bit manipulation | PRACTICED | Correct mask/shift reasoning, field clearing/insertion, validation, and oversized-shift UB recognition |
| MMIO RMW / W1C / read-to-clear | PRACTICED | Integrated validation correctly explained stale-snapshot races and accidental W1C flag clearing |
| Signed/unsigned overflow | PRACTICED | Correctly distinguishes defined unsigned modulo arithmetic from signed-overflow UB |
| Integer promotions | UNDERSTOOD | Core rule understood; occasionally skips the explicit intermediate `int`/`unsigned int` promotion step when explaining |
| Usual arithmetic conversions | UNDERSTOOD | Correctly predicts mixed signed/unsigned comparison and arithmetic outcomes on the assumed 32-bit target |
| Implementation-defined vs unspecified vs UB | PRACTICED | Correctly classified representative cases after repair of negative signed right shift |
| Compiler assumptions around UB | UNDERSTOOD | Understands why the optimizer can assume signed overflow does not occur in defined executions |
| Uninitialized / invalid pointer use | PRACTICED | Correctly reasons about indeterminate locals, NULL, dangling pointers, invalid free, double free, and aliases |
| Pointer bounds / one-past / `ptrdiff_t` | PRACTICED | Correctly reasons about legal one-past formation and pointer differences in elements |
| Strict aliasing / effective type | UNDERSTOOD | Correctly identifies incompatible typed access and `memcpy` as portable bit-copy technique; character-type exception rationale needs reinforcement |
| Sequencing / short-circuit semantics | PRACTICED | Correctly distinguishes unsequenced UB and uses `&&`/`||` guards safely |
| Struct padding / object representation | PRACTICED | Correctly explains padding, tail padding, `memcmp` caveats, and member reordering impact |
| Serialization / endianness | PRACTICED | Correctly rejects raw struct layout as a portable wire/Flash contract and prefers explicit byte order |
| Bit-fields | UNDERSTOOD | Correctly recognizes implementation-dependent layout and prefers masks/shifts for MMIO/persistent formats |

## Section 7 validation evidence

Completed on 2026-10-03:

- 15 integrated questions spanning promotions/conversions, volatile, W1C, aliasing, struct representation, pointer arithmetic, UB, sequencing, short-circuit guards, shifts, and MMIO RMW hazards

Observed strengths:

- W1C/RMW reasoning improved materially from the Section 6 revision state
- signed/unsigned conversion consequences are generally predicted correctly
- pointer lifetime, one-past, and subtraction rules are solid
- UB/implementation-defined/unspecified distinctions are substantially clearer
- struct-padding and serialization reasoning is strong
- `volatile` is no longer conflated with atomicity

Non-blocking refinement targets:

- state the complete integer-promotion path before the usual arithmetic conversion
- reinforce why character types are specially permitted to inspect object representation
- continue separating compiler visibility (`volatile`) from synchronization/cache coherency
- demonstrate W1C/direct-mask behavior again in real peripheral work

Section 7 is complete for the current pass and does **not** block Section 8. It is not yet labeled `MASTERED`; future lab, design, debugging, and unfamiliar-scenario evidence should drive later promotion.

See also `Revision-Queue.md` and `../Integration/Milestones.md`.
