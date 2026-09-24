# Track 1 – Progress

Last updated: 2026-09-23

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

Before the Phase 0 detour, Section 6 had progressed well beyond the old pointer-comparison checkpoint.

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
- `&m[i]` vs `&m[i][j]`
- pointer-to-pointer basics
- const pointer combinations (covered earlier)
- structures, padding, and alignment (covered earlier)

## Next planned topic

Resume **Phase 1 -> Section 6** and finish the remaining 2D-array/function-parameter material:

1. `void f(int m[][4])`
2. `void f(int (*m)[4])`
3. why those parameter forms are equivalent
4. why the column dimension is required
5. a small `sizeof` / bounds consolidation

Then continue with the remaining Section 6 pointer topics.

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
- [~] multidimensional arrays
- [~] pointer-to-pointer
- [x] const pointer combinations
- [x] structures
- [x] padding and alignment
- [ ] void pointers
- [ ] null pointers
- [ ] dangling pointers
- [ ] wild pointers
- [ ] object lifetime
- [ ] pointer casts
- [ ] strict aliasing
- [ ] alignment-related pointer issues beyond struct layout
- [ ] integer/pointer conversion
- [ ] function pointers
- [ ] MMIO pointer usage
- [ ] volatile pointer patterns
- [ ] pointer-related undefined behavior
- [ ] pointer debugging
- [ ] firmware-specific failure scenarios
- [ ] Senior/Principal interview scenarios

Legend:

- `[x]` = covered for the current pass
- `[~]` = in progress / not yet closed

## Previous sections

Sections 1–5 were covered in the previous Track 1 chat.

Their exact titles are preserved in `Track_1/Curriculum.md`. Topic-by-topic mastery for Sections 1–5 should still be recovered or revalidated rather than assumed.
