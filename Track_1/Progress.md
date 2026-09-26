# Track 1 – Progress

Last updated: 2026-09-25

## Current location

**Phase 1 – Embedded C and Bare-Metal Foundations**

**Section 6 – C Memory & Pointer Foundations**

Status: `IN_PROGRESS`

## Phase 0 – Tooling, Board, and Debug Environment Orientation

Status: `COMPLETED`

Completed on: 2026-09-23

Covered:

- source -> compiler -> object files -> linker -> ELF / firmware image
- PC -> USB -> ST-LINK -> SWD -> STM32H745 debug path
- ST-LINK MCU vs target STM32H745 MCU
- on-board STLINK-V3E and external SWD probe concept
- SWD signal roles: SWDIO, SWCLK, GND, VTref / 3V3
- IDE / GDB / ST-LINK GDB Server / probe / target relationship
- hardware breakpoints
- software breakpoints and `BKPT` patching
- watchpoints
- finite breakpoint/watchpoint resources
- source stepping vs instruction stepping
- Step Into / Step Over / Step Return
- Link Register and return-address preservation
- leaf vs non-leaf function behavior
- call stack and stack unwinding
- stack corruption effects
- HardFault crash-debug orientation
- stacked PC and stacked register context
- CFSR / HFSR
- BFAR / MMFAR validity
- precise vs imprecise fault concepts
- fault escalation
- reset vs restart vs reflash
- Flash persistence vs RAM runtime state
- end-to-end debug-session flow

Validation:

- Phase 0 test: **19/20**
- The single miss was caused by reading “easier” as “tougher” on the precise-vs-imprecise fault question.
- The learner immediately stated the correct conceptual distinction, so no Phase 0 remediation item is required.
- Phase 0 is considered covered and complete for this pass.

## Current Phase 1 checkpoint

Section 6 core material has now been covered through pointer debugging and firmware failure scenarios.

Established:

- pointer declaration and types
- address-of and dereference
- typed pointer semantics
- pointer size vs pointed-to object size
- pointer arithmetic and element scaling
- pointer subtraction and `ptrdiff_t`
- pointer comparison
- one-past-the-end
- array vs pointer distinction
- `sizeof(array)` vs `sizeof(pointer)`
- `arr` vs `&arr`
- pointer-to-array declarations
- multidimensional array layout
- row-pointer arithmetic
- `m[i][j] == *(*(m + i) + j)`
- true 2D array vs `int **`
- contiguous 2D storage vs array-of-pointers layout
- 2D-array function parameter forms: `int m[][N]` and `int (*m)[N]`
- why the column dimension is required for row stride
- pointer-to-pointer basics
- const pointer combinations
- structures, padding, alignment, and `memcmp` caveat
- `void *`
- null pointers
- dangling pointers
- wild / uninitialized pointers
- object lifetime
- pointer casts
- byte/object representation via character types
- strict-aliasing / incompatible typed access basics
- alignment-sensitive pointer access
- integer / pointer conversion and `uintptr_t`
- function pointers and function-pointer arrays
- MMIO pointers
- volatile pointer patterns and MMIO corner cases
- read-to-clear register behavior
- write-one-to-clear register behavior
- `volatile` vs atomicity / synchronization / cache coherency
- pointer-related undefined behavior
- pointer debugging with watchpoints
- firmware failure scenarios: silent RAM corruption, delayed stack corruption, MMIO side effects, optimization-sensitive UB

## Validation status

A hard 40-question validation pass was planned:

- Questions 1–20: Section 6 only — **completed**
- Questions 21–40: integrated Sections 1–6 — **started**

Section 6 performance was strong overall. Remaining refinement areas are mainly precision rather than broad conceptual gaps:

- strict aliasing / effective-type reasoning and optimizer assumptions
- distinguishing pointer casts from creation of a valid object of the cast-to type
- W1C read-modify-write hazards
- exact array-lvalue vs pointer-conversion wording
- delayed stack corruption vs eventual fault site
- occasional arithmetic slips

## Next planned topic

Resume the integrated Sections 1–6 validation set at **Question 21/40**.

After the integrated pass:

1. decide whether Section 6 can be closed for this pass
2. perform only targeted remediation where needed
3. continue to Section 7 – Embedded-C Semantics

## Section 6 coverage so far

- [x] pointer fundamentals
- [x] pointer declaration
- [x] address-of
- [x] dereference
- [x] typed pointers
- [x] pointer arithmetic
- [x] scaling by pointed-to element size
- [x] pointer subtraction
- [x] pointer comparison
- [x] one-past-the-end
- [x] array vs pointer basics
- [x] `sizeof(array)` vs `sizeof(pointer)`
- [x] `arr` vs `&arr`
- [x] multidimensional arrays
- [x] pointer-to-pointer distinction
- [x] 2D-array function parameters
- [x] const pointer combinations
- [x] structures
- [x] padding and alignment
- [x] void pointers
- [x] null pointers
- [x] dangling pointers
- [x] wild pointers
- [x] object lifetime
- [x] pointer casts
- [x] strict aliasing basics
- [x] alignment-related pointer issues
- [x] integer/pointer conversion
- [x] function pointers
- [x] MMIO pointer usage
- [x] volatile pointer patterns
- [x] pointer-related undefined behavior
- [x] pointer debugging
- [x] firmware-specific failure scenarios
- [x] hard Section 6 interview pass
- [~] integrated Sections 1–6 validation

Legend:

- `[x]` = covered for the current pass
- `[~]` = in progress / not yet closed

## Previous sections

Sections 1–5 were covered in the previous Track 1 chat.

Their exact titles are preserved in `Track_1/Curriculum.md`. Topic-by-topic mastery should continue to be revalidated through the integrated Sections 1–6 question set rather than assumed.
