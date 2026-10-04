# Track 1 – Concepts Revision Queue

This file contains topics that should be revisited because they are subtle, easy to forget, foundational for later work, or still need greater precision.

Section 7 was completed for the current conceptual-validation pass on 2026-10-03. Items below are **reinforcement targets**, not blockers for moving to Section 8.

## Active review items

### Strict aliasing / effective-type reasoning

Priority: High

Review later:

A pointer cast changes the pointer type but does not create a new object of the cast-to type. Accessing an object through an incompatible typed pointer can invoke undefined behavior even when the numeric address, size, and hardware alignment all appear valid.

Progress update 2026-10-03:

The learner now correctly identifies incompatible typed dereference as the problem and prefers `memcpy` for portable bit-pattern copying. The remaining precision gap is *why* character types are specially permitted to inspect object representation; do not reduce this to "they move one byte at a time."

### W1C register semantics

Priority: Medium

Review later:

For write-one-to-clear registers, writing `1` clears a flag and writing `0` leaves it unchanged. Ordinary read-modify-write idioms can therefore clear unrelated flags or otherwise violate the register's documented semantics.

Progress update 2026-10-03:

The learner correctly explained the `0b00001010 | 0b00001000` case and why writing the resulting `0b00001010` back to a W1C register clears both bit 3 and bit 1. Keep this active until the same reasoning is demonstrated naturally in real peripheral-register work.

### Cache coherency vs `volatile`

Priority: High

Review later:

`volatile` forces the compiler to preserve accesses; it does not invalidate stale CPU cache lines, provide synchronization, or make DMA/CPU memory coherent.

Progress update 2026-10-03:

The learner understands that `volatile` preserves accesses and separately recognizes RMW races. Reinforce the cache/synchronization side later when DMA, barriers, and concurrency formally arrive.

### Integer promotions / usual arithmetic conversions

Priority: Medium

Review later:

Keep the conversion path explicit:

`small integer type -> integer promotion to int/unsigned int -> usual arithmetic conversions -> operation -> destination conversion`.

Progress update 2026-10-03:

The learner generally predicts outcomes correctly, including mixed signed/unsigned cases, but sometimes jumps directly from a small type to the final common type and skips the intermediate promotion step.

### Shift-count and signed-shift rules

Priority: Medium

Review later:

Unsigned arithmetic wraparound does not make an oversized shift valid. A shift count greater than or equal to the width of the promoted left operand is UB. Signed left shift also requires careful representability reasoning.

Progress update 2026-10-03:

The learner correctly identified `1u << 32` on a 32-bit operand as invalid during the integrated validation.

### Array lvalue vs pointer conversion precision

Priority: Medium

Review later:

For pointer-to-array expressions such as `*p`, distinguish the actual array type/lvalue from the pointer value produced when that array is used in most ordinary expressions.

Progress update 2026-09-28:

The conceptual model is strong; retain for exact C type-language precision.

### Delayed stack corruption vs fault site

Priority: Medium

Review later:

An out-of-bounds write may corrupt saved registers or return state without faulting immediately. The eventual HardFault can occur later when corrupted state is consumed, so the crash site is not necessarily the corruption site.

Progress update 2026-09-28:

The learner now reasons correctly about delayed consumption of corrupted state. Revisit during real fault-debug labs.

### Pointer subtraction / relational comparison domain rules

Priority: Low

Review later:

Pointer subtraction and relational ordering are defined within the appropriate same-array object domain, including the permitted one-past position. Numeric machine-address ordering alone is not a portable C substitute for those language rules.

Progress update 2026-10-03:

The learner correctly handled same-array subtraction, one-past subtraction, and recognized that differences are measured in elements. This is now a light reinforcement item rather than an active weakness.

### `ptrdiff_t`

Priority: Low

Review later:

Remember that pointer subtraction produces `ptrdiff_t`, a signed integer type intended to represent pointer differences.

Progress update 2026-10-03:

The learner initially answered `int` during review, then repaired the rule and subsequently used the element-distance model correctly.

### Bytes vs elements

Priority: Low

Review later:

Pointer arithmetic is expressed in units of the pointed-to type, while raw machine addresses are byte-oriented.

Progress update 2026-10-03:

The learner correctly answered the integrated pointer-subtraction question as `5` elements. Keep only as occasional reinforcement.

### Arithmetic precision under interview pressure

Priority: Low

Review later:

Pause long enough to distinguish element count, byte count, offset, and total object size when doing multidimensional-array or pointer calculations.

Progress update 2026-10-03:

A few arithmetic/value slips still occur, but the underlying models are generally correct.

---

## Backfill queue

- Recover any earlier exercises or weak areas from the original Track 1 chats that are worth preserving.
- Continue refining Sections 1–5 mastery states as new evidence appears rather than assuming full mastery.

The Section 1–5 titles are preserved in `Curriculum.md`.
