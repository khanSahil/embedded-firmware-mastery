# Track 1 – Concepts Revision Queue

This file contains topics that should be revisited because they are subtle, easy to forget, foundational for later work, or still need greater precision.

Section 6 was completed for the current conceptual-validation pass on 2026-09-28. Items below are **reinforcement targets**, not blockers for moving to Section 7.

## Active review items

### Strict aliasing / effective-type reasoning

Priority: High

Review later:

A pointer cast changes the pointer type but does not create a new object of the cast-to type. Accessing an object through an incompatible typed pointer can invoke undefined behavior even when the numeric address, size, and hardware alignment all appear valid.

Progress update 2026-09-28:

The learner recognizes the UB and can connect it to `-O0` vs `-O2`. Continue reinforcing the object-model and optimizer-assumption explanation until it becomes automatic.

### W1C register semantics

Priority: High

Review later:

For write-one-to-clear registers, writing `1` clears a flag and writing `0` leaves it unchanged. Ordinary read-modify-write idioms such as `reg &= ~BIT` can therefore clear unrelated flags while failing to clear the intended one.

Progress update 2026-09-28:

The rule was repaired during Section 6. Keep it active until direct-mask writes and RMW hazards are demonstrated naturally in real peripheral-register work.

### Cache coherency vs `volatile`

Priority: High

Review later:

`volatile` forces the compiler to preserve accesses; it does not invalidate stale CPU cache lines or make DMA/CPU memory coherent.

Progress update 2026-09-28:

The learner understands the distinction conceptually. Reinforce it later with DMA/cache maintenance, memory attributes, and barriers when those topics formally arrive.

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

Priority: Medium

Review later:

Pointer subtraction and relational ordering are defined within the appropriate same-array object domain, including the permitted one-past position. Numeric machine-address ordering alone is not a portable C substitute for those language rules.

Progress update 2026-09-28:

The same-array comparison rule was repaired during the integrated validation and confirmed with a nearby example.

### `ptrdiff_t`

Priority: Low

Review later:

Remember that pointer subtraction produces `ptrdiff_t`, a signed integer type intended to represent pointer differences.

### Bytes vs elements

Priority: Medium

Review later:

Pointer arithmetic is expressed in units of the pointed-to type, while raw machine addresses are byte-oriented.

### Arithmetic precision under interview pressure

Priority: Low

Review later:

Pause long enough to distinguish element count, byte count, offset, and total object size when doing multidimensional-array calculations.

Progress update 2026-09-28:

A few arithmetic slips occurred despite otherwise correct type/layout reasoning.

---

## Backfill queue

- Recover any earlier exercises or weak areas from the original Track 1 chats that are worth preserving.
- Continue refining Sections 1–5 mastery states as new evidence appears rather than assuming full mastery.

The Section 1–5 titles are preserved in `Curriculum.md`.
