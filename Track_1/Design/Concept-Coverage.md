# Design concept coverage — starting baseline

Snapshot: 2026-09-26. Sources: `../Curriculum.md`, `../Progress.md`, `../Mastery-Ledger.md`, `../Active-Context.md`, and [Design 01](01-startup-readiness-led.md).

This is a **learning inventory and design coverage tracker**, not a claim of mastery. Phase 0 is complete; Phase 1 Sections 1–5 were covered previously without item-by-item mastery evidence; Section 6 core topics were covered but integrated validation is still in progress. A concept is counted as **designed with** only when an exercise explicitly applies it; an incidental mention does not count.

## Learned or covered concepts available for design

### Phase 0 — tooling, board, debug environment

1. Development chain: source → compiler → object files → linker → ELF and firmware image.
2. Host-to-target debug path: PC → USB → debug probe → SWD → target.
3. Probe's controller versus the target MCU.
4. On-board probe versus external probe.
5. SWD signals: SWDIO, SWCLK, ground, target-voltage reference, and reset context.
6. IDE, GDB, GDB server, probe, and target responsibilities.
7. Hardware breakpoints and limited comparator resources.
8. Software breakpoints and temporary instruction patching.
9. Watchpoints and hardware data-comparator model.
10. Source stepping versus instruction stepping.
11. Step Into, Step Over, and Step Return.
12. Link Register, return-address preservation, and leaf versus non-leaf calls.
13. Call stack and stack unwinding.
14. Effects of stack corruption on returns and backtraces.
15. Fault-debug orientation: HardFault and fault-time stacked PC/registers.
16. Fault status and address validity: CFSR, HFSR, BFAR/MMFAR concepts.
17. Precise versus imprecise faults and fault escalation.
18. Reset versus restart versus reflash.
19. Flash persistence versus RAM runtime state.
20. End-to-end debug-session reasoning.

### Phase 1, Section 1 — MCU and hardware foundations

21. MCU mental model.
22. Memory map and Flash, RAM, and peripheral regions.
23. Memory-mapped I/O (MMIO) and software access to registers.
24. Clocks and reset.
25. GPIO electrical foundations.

### Phase 1, Section 2 — generic CPU execution

26. Instructions and CPU registers.
27. Program Counter, fetch–decode–execute, arithmetic, and branches.
28. LOAD/STORE data movement.
29. Stack, Stack Pointer, Link Register, and function calls.
30. Stack frames and recursion.

### Phase 1, Section 3 — binary and bit manipulation

31. Binary and hexadecimal representation.
32. AND, OR, XOR, NOT, and shifts.
33. Masks and setting, clearing, toggling, and testing bits.
34. Register-field manipulation.

### Phase 1, Section 4 — integer representation and arithmetic

35. Signed/unsigned integers and two's complement.
36. Integer ranges, unsigned wraparound, and signed-overflow concerns.
37. CPU arithmetic flags at a conceptual level.

### Phase 1, Section 5 — memory representation

38. Byte-addressed memory and multi-byte objects.
39. Endianness and integer byte representation.
40. Alignment and object representation.

### Phase 1, Section 6 — C memory and pointers

41. Pointer declaration/types, address-of, dereference, and typed-pointer semantics.
42. Pointer size versus pointed-to object size.
43. Pointer arithmetic and scaling by element size.
44. Pointer subtraction, comparison, and one-past-the-end rules.
45. Arrays versus pointers, conversion in expressions, and `sizeof`.
46. `arr` versus `&arr` and pointer-to-array types.
47. Multidimensional array layout, row stride, indexing, and 2D function parameters.
48. True 2D arrays versus `T **` / arrays of pointers.
49. Const pointer combinations and `void *`.
50. Structures, padding, alignment, and `memcmp` caveats.
51. Null, dangling, and wild/uninitialized pointers; object lifetime.
52. Pointer casts; byte inspection through character types.
53. Strict aliasing/effective type and incompatible typed access basics.
54. Alignment-sensitive pointer access and integer/pointer conversions (`uintptr_t`).
55. Function pointers, callbacks, and dispatch tables.
56. MMIO pointers, volatile pointer forms, and hardware side effects.
57. Read-to-clear and write-one-to-clear register behavior; read-modify-write hazards.
58. Volatile versus atomicity, synchronization, and cache coherency (conceptual distinctions).
59. Pointer-related undefined behavior and optimization-sensitive failure.
60. Pointer debugging with watchpoints.
61. Firmware failure patterns: silent RAM corruption, delayed stack faults, and MMIO side effects.

Section 6 topics 53 and 57 have known precision gaps; see `../Active-Context.md`. Some Section 6 distinctions are previews of later full sections, not permission to assume mastery of concurrency, DMA, or cache design. Sections 7 onward are not yet part of this baseline.

## Concepts actually applied in completed designs

| Exercise | Design concepts demonstrated | Guidance / limits |
|---|---|---|
| [01 — Startup readiness LED](01-startup-readiness-led.md) | Reset/default electrical off state; GPIO output and output-latch order; required clock as a readiness condition; startup policy separated from GPIO control; failure-safe behavior and RAM error evidence readable through the debug path; validation of success and failure. | Guided exercise. SWD/debugger was used as a diagnostic assumption, not a complete debug-access architecture. Generic concepts remain useful, though the archived answer used a named board. This is not independent mastery. |

Do not mark all 61 learned concepts as covered in design. The table above is the starting design baseline.

## Next design increment — proposed

**One new design concept:** on-board versus external debug-probe placement (Phase 0 item 4). Phase 0 items 5–6 are supporting knowledge, not additional new design targets for this exercise. Design 01 assumed a probe could access the target; it did not compare where to place that probe. Discuss requirements first and stay MCU independent. Keep previously applied reset, power, and diagnosis ideas where relevant, without artificially inserting an LED into the new problem. The concept becomes design-covered only after the discussion and reviewed write-up.

## Rule for each subsequent exercise

The numbered entries above are compact groups of closely related subtopics. Select **one atomic subtopic** from a group when advancing a design; never require the entire numbered group at once. Before asking the design question, show: (1) the single new concept and its Phase/Section/Topic, (2) concepts already applied in reviewed designs that will naturally carry over, and (3) any learned concepts intentionally left for later. Ask the learner to clarify requirements first. After the write-up is reviewed, update the applied-concepts table with actual evidence and identify the next increment. A newly learned topic enters the learning inventory first; it enters the design-covered list only after use in a completed design. New tracks can add concepts from earlier tracks once learned.
