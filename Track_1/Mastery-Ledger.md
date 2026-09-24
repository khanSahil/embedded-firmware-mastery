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

Exact topic-by-topic mastery should be backfilled from the original Track 1 chat when needed.

Do not assume `MASTERED` for every subtopic until evidence is recovered or revalidated.

### Section 6 – C Memory & Pointer Foundations

| Topic | Status | Evidence / Notes |
|---|---|---|
| Pointer declaration | UNDERSTOOD | Covered in prior chat |
| Address-of operator | UNDERSTOOD | Covered in prior chat |
| Dereference | UNDERSTOOD | Covered in prior chat |
| Typed pointer semantics | UNDERSTOOD | Covered in prior chat |
| Pointer arithmetic | UNDERSTOOD | Learner correctly reasoned about element scaling |
| Pointer subtraction | UNDERSTOOD | Correctly answered `p2 - p1 == 3`; corrected reading of reverse subtraction |
| Pointer comparison | UNDERSTOOD | Correctly reasoned about same-array ordering; misconception about unrelated-object numeric ordering repaired |
| One-past-the-end | UNDERSTOOD | Correctly reasoned that one-past may be formed, compared/subtracted within the array domain, decremented back into the array, but not dereferenced or advanced further |
| Arrays and pointer decay | UNDERSTOOD | Array vs pointer distinction and `sizeof` behavior covered; multidimensional details still being closed |
| `arr` vs `&arr` | PRACTICED | Correctly reasoned about `int *` vs pointer-to-array types and arithmetic |
| Pointer-to-pointer | UNDERSTOOD | True 2D array vs `int **` distinction covered; function-parameter consolidation remains |
| const pointer combinations | PRACTICED | Covered earlier; correctly distinguished pointer-to-const, const pointer, and const pointer-to-const |
| Structures / padding | PRACTICED | Covered earlier; natural alignment, padding, total struct size, and `memcmp` caveat discussed |
| void pointers | NOT_STARTED | Upcoming |
| null pointers | NOT_STARTED | Upcoming |
| dangling pointers | NOT_STARTED | Upcoming |
| lifetime | NOT_STARTED | Upcoming |
| pointer casts | NOT_STARTED | Upcoming |
| strict aliasing | NOT_STARTED | Upcoming |
| alignment | UNDERSTOOD | Structure padding/alignment covered earlier; broader pointer-alignment hazards remain |
| function pointers | NOT_STARTED | Upcoming |
| MMIO pointers | NOT_STARTED | Upcoming |
| volatile pointer usage | NOT_STARTED | Upcoming |
| pointer UB | NOT_STARTED | Upcoming |
| pointer debugging | NOT_STARTED | Upcoming |

## Mastery policy

`UNDERSTOOD` means the learner has a sound conceptual model.

`PRACTICED` requires solving or implementing examples.

`DEBUGGED` requires diagnosing realistic failures.

`DESIGNED_WITH` requires applying the concept in a system-level design.

`MASTERED` should only be used after the learner can transfer the concept to unfamiliar scenarios without relying on memorized rules.