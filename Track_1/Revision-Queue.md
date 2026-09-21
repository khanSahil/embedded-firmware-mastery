# Track 1 – Revision Queue

This file contains topics that should be revisited because they are weak, subtle, easy to forget, or foundational for later work.

## Active review items

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

---

## Backfill queue

- Recover exact Section 1–5 titles from the original Track 1 chat.
- Recover any earlier exercises or weak areas worth preserving.
- Mark earlier topics with proper mastery states rather than assuming full mastery.