# Track 1 – Mastery Ledger

This file tracks demonstrated mastery rather than merely whether a topic was discussed.

## Status scale

- `NOT_STARTED`
- `INTRODUCED`
- `UNDERSTOOD`
- `PRACTICED`
- `DEBUGGED`
- `DESIGNED_WITH`
- `MASTERED`
- `NEEDS_REVIEW`

---

## Phase 0 – Tooling, Board, and Debug Environment Orientation

Overall status: `PRACTICED` / phase `COMPLETED`

Validation evidence:

- 20-question Phase 0 test completed on 2026-09-23
- score: 19/20
- the single miss was a haste/misread on precise vs imprecise fault wording; the learner immediately explained the correct distinction
- no active Phase 0 remediation item required

| Topic | Status | Evidence / Notes |
|---|---|---|
| Development/build chain | PRACTICED | Correctly reasoned about compiler, linker, ELF, programming/debug path |
| ST-LINK vs STM32H745 target | PRACTICED | Correctly distinguished debugger MCU from application MCU |
| SWD physical/debug path | PRACTICED | Correctly identified SWD purpose and SWDIO / SWCLK roles |
| External debugger connection basics | UNDERSTOOD | Understood VTref / 3V3, GND, SWDIO, SWCLK purpose |
| GDB / GDB Server / probe layering | PRACTICED | Correctly diagnosed that GDB cannot reach target registers if probe path is broken |
| Hardware breakpoints | PRACTICED | Correctly explained comparator-based breakpoint behavior |
| Software breakpoints | PRACTICED | Correctly explained temporary `BKPT` replacement and restore/step/reinsert flow |
| Watchpoints | PRACTICED | Correctly chose watchpoints for unknown memory overwrite |
| Source vs instruction stepping | PRACTICED | Correctly distinguished source stepping from machine-instruction stepping |
| Step Into / Over / Return | PRACTICED | Correctly reasoned about call-depth behavior |
| LR and return-address preservation | PRACTICED | Correctly explained why non-leaf functions preserve LR |
| Call stack / unwinding | UNDERSTOOD | Correctly explained how stack corruption can break return flow and backtraces |
| Fault-time stacked context | PRACTICED | Correctly preferred stacked PC/registers over live handler state |
| CFSR / HFSR / BFAR concepts | PRACTICED | Correctly reasoned about FORCED escalation and BFARVALID |
| Precise vs imprecise faults | UNDERSTOOD | Concept correctly stated after a wording misread |
| Effective-address reconstruction | PRACTICED | Correctly decoded `STR/LDR` base + offset/register forms |
| Reset vs reflash / Flash vs RAM | PRACTICED | Correctly reasoned that reset preserves application Flash |
| End-to-end debug-session model | PRACTICED | Correctly localized a probe-to-target SWD failure |

## Phase 1 – Embedded C and Bare-Metal Foundations

### Sections 1–5

Status: `COMPLETED_PREVIOUSLY`

Exact topic-by-topic mastery should continue to be revalidated through the integrated Sections 1–6 question set.

Do not assume `MASTERED` for every subtopic until evidence is recovered or revalidated.

### Section 6 – C Memory & Pointer Foundations

Overall status: `PRACTICED` with selected `DEBUGGED` evidence; section validation still in progress.

| Topic | Status | Evidence / Notes |
|---|---|---|
| Pointer declaration | PRACTICED | Correctly interpreted pointer and pointer-to-array declarations in exercises |
| Address-of operator | PRACTICED | Correctly reasoned about object addresses and pointer targets |
| Dereference | PRACTICED | Correctly distinguished valid dereference from one-past, null, dangling, wild, misaligned, and incompatible typed access |
| Typed pointer semantics | PRACTICED | Strong overall; exact object-model wording still being polished |
| Pointer arithmetic | PRACTICED | Correctly reasoned about element scaling and byte movement |
| Pointer subtraction | UNDERSTOOD | Correctly reasoned about same-array domain and `ptrdiff_t`; keep as revision item |
| Pointer comparison | UNDERSTOOD | Correctly reasoned about same-array ordering and portability limits for unrelated objects |
| One-past-the-end | PRACTICED | Correctly reasoned about what may be formed/compared/subtracted vs dereferenced |
| Arrays and pointer conversion | PRACTICED | Correctly handled `sizeof`, array vs pointer, and multidimensional cases; occasionally needs exact array-lvalue wording |
| `arr` vs `&arr` | PRACTICED | Correctly reasoned about `int *` vs pointer-to-array types and arithmetic |
| Multidimensional arrays | PRACTICED | Correctly reasoned about row stride, contiguous layout, offsets, and 2D indexing |
| 2D function parameters | PRACTICED | Correctly explained `int m[][N]` / `int (*m)[N]`, row stride, and loss of row count |
| Pointer-to-pointer | PRACTICED | Correctly distinguished true 2D arrays from `int **` / array-of-pointers layout |
| const pointer combinations | PRACTICED | Correctly distinguished pointer-to-const, const pointer, and const pointer-to-const |
| Structures / padding | PRACTICED | Natural alignment, padding, total size, and `memcmp` caveat covered |
| void pointers | PRACTICED | Correctly reasoned about generic object pointers, casts, dereference restrictions, and standard-C arithmetic limitation |
| null pointers | PRACTICED | Correctly distinguished null from merely invalid/dangling pointers |
| dangling pointers | PRACTICED | Correctly reasoned about ended object lifetime and alias persistence after `free` |
| wild / uninitialized pointers | PRACTICED | Correctly identified indeterminate-address UB and firmware consequences |
| lifetime | PRACTICED | Correctly distinguished automatic, static, and dynamic lifetimes |
| pointer casts | UNDERSTOOD | Knows cast changes pointer type, not underlying object; reinforce object-model precision |
| strict aliasing / effective type | UNDERSTOOD | Recognizes incompatible typed dereference as UB; optimizer reasoning and wording still need reinforcement |
| alignment | PRACTICED | Correctly identified misaligned typed access and MMIO alignment hazards |
| integer / pointer conversion | PRACTICED | Correctly explained pointer-width truncation and why `uintptr_t` is preferable when provided |
| function pointers | PRACTICED | Correctly interpreted declarations, callbacks, and dispatch-table usage |
| MMIO pointers | PRACTICED | Correctly connected pointers to peripheral register access and hardware side effects |
| volatile pointer usage | PRACTICED | Strong distinction among volatile pointee, volatile pointer, read-to-clear behavior, and compiler visibility |
| W1C register semantics | UNDERSTOOD | RMW hazard repaired; should be revisited until direct-mask write semantics are automatic |
| volatile vs atomicity | PRACTICED | Correctly explained RMW race in `counter++`; volatile does not provide synchronization |
| volatile vs cache coherency | PRACTICED | Correctly explained DMA-written RAM may remain stale in CPU cache on Cortex-M7-class systems |
| pointer UB | PRACTICED | Correctly diagnosed one-past dereference, dangling, wild, misaligned, aliasing, and out-of-bounds cases |
| pointer debugging | DEBUGGED | Correctly selected watchpoint on pointer storage vs target memory depending on corruption mode |
| firmware failure scenarios | DEBUGGED | Correctly reasoned about silent RAM corruption, delayed stack/control-flow faults, and MMIO side effects |
| optimization-sensitive UB | UNDERSTOOD | Recognizes `-O0` vs `-O2` behavior and strict-aliasing connection; deepen compiler-assumption explanation |
| Section 6 interview validation | PRACTICED | Completed 20 hard Section 6 questions; overall strong with targeted precision gaps |

## Current validation state

- Section 6 hard-question pass: completed
- Integrated Sections 1–6 hard-question pass: started
- Section 6 should not yet be labeled `MASTERED`; practical implementation, broader integrated transfer, and later hands-on/design evidence are still required.

## Mastery policy

`UNDERSTOOD` means the learner has a sound conceptual model.

`PRACTICED` requires solving or implementing examples.

`DEBUGGED` requires diagnosing realistic failures.

`DESIGNED_WITH` requires applying the concept in a system-level design.

`MASTERED` should only be used after the learner can transfer the concept to unfamiliar scenarios without relying on memorized rules.
