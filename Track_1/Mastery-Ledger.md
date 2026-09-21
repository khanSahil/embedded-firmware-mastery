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
| Arrays and pointer decay | NOT_STARTED | Upcoming |
| `arr` vs `&arr` | NOT_STARTED | Upcoming |
| Pointer-to-pointer | NOT_STARTED | Upcoming |
| const pointer combinations | NOT_STARTED | Upcoming |
| void pointers | NOT_STARTED | Upcoming |
| null pointers | NOT_STARTED | Upcoming |
| dangling pointers | NOT_STARTED | Upcoming |
| lifetime | NOT_STARTED | Upcoming |
| pointer casts | NOT_STARTED | Upcoming |
| strict aliasing | NOT_STARTED | Upcoming |
| alignment | NOT_STARTED | Upcoming |
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