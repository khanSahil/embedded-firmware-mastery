# Track 1 – Revision Queue

This file contains topics that should be revisited because they are weak, subtle, easy to forget, or foundational for later work.

## Active review items

### Strict aliasing / effective-type reasoning

Priority: High

Review later:

A pointer cast changes the pointer type but does not create a new object of the cast-to type. Accessing an object through an incompatible typed pointer can invoke undefined behavior even when the numeric address, size, and hardware alignment all appear valid.

Reason to revisit:

The learner recognizes the UB but should make the compiler/object-model reasoning automatic, especially why optimization may exploit aliasing assumptions and why `-O0` vs `-O2` can differ.

### W1C register semantics

Priority: High

Review later:

For write-one-to-clear registers, writing `1` clears a flag and writing `0` leaves it unchanged. Ordinary read-modify-write idioms such as `reg &= ~BIT` can therefore clear unrelated flags while failing to clear the intended one.

Reason to revisit:

This was repaired during Section 6 and should become automatic before heavy peripheral-register work.

### Array lvalue vs pointer conversion precision

Priority: Medium

Review later:

For pointer-to-array expressions such as `*p`, distinguish the actual array type/lvalue from the pointer value produced when that array is used in most ordinary expressions.

Reason to revisit:

The conceptual model is strong, but exact type wording matters for advanced C reasoning and interviews.

### Delayed stack corruption vs fault site

Priority: Medium

Review later:

An out-of-bounds write may corrupt saved registers or return state without faulting immediately. The eventual HardFault can occur later when corrupted state is consumed, so the crash site is not necessarily the corruption site.

Reason to revisit:

The learner understood delayed corruption but should keep the distinction between the original bad write and the later consumer of corrupted state precise.

### Pointer subtraction domain rule

Priority: Medium

Review later:

Pointer subtraction is only defined for pointers into the same array object, including the permitted one-past position.

Reason to revisit:

This rule becomes important when discussing undefined behavior, compiler optimization, iterators/ranges, DMA buffers, MMIO, and low-level pointer manipulation.

### `ptrdiff_t`

Priority: Low

Review later:

Remember that pointer subtraction produces `ptrdiff_t`, a signed integer type intended to represent pointer differences.

### Bytes vs elements

Priority: Medium

Review later:

Pointer arithmetic is expressed in units of the pointed-to type, while raw address differences are byte-oriented at the machine level.

This distinction should become automatic before moving into arrays, buffers, DMA descriptors, and MMIO.

### Arithmetic precision under interview pressure

Priority: Low

Review later:

Pause long enough to distinguish element count from byte count when computing multidimensional-array sizes and offsets.

Reason to revisit:

A few arithmetic slips occurred despite otherwise correct type and layout reasoning.

---

## Backfill queue

- Recover any earlier exercises or weak areas from the original Track 1 chat that are worth preserving.
- Mark earlier Sections 1–5 with proper mastery states rather than assuming full mastery.

The exact Section 1–5 titles have now been recovered and are preserved in `Track_1/Curriculum.md`.
