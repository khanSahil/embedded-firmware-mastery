# Track 1 – Progress

Last updated: 2026-09-20

## Current location

**Phase 1 – Embedded C and Bare-Metal Foundations**

**Section 6 – C Memory & Pointer Foundations**

Status: `IN_PROGRESS`

## Current checkpoint

Pointer comparison and one-past-the-end basics have been understood.

Key points established:

- relational pointer comparison is defined for positions within the same array object, including its one-past position
- relational comparison of pointers to unrelated objects must not be treated as a portable numeric-address ordering
- equality / inequality comparisons are distinct from relational ordering
- a one-past pointer may be formed and used as a boundary
- a one-past pointer may participate in valid comparison and subtraction with pointers in the same array
- a one-past pointer must not be dereferenced
- advancing beyond the one-past position is not permitted
- decrementing a one-past pointer back into the array is valid

Pointer subtraction remains established:

```c
uint32_t arr[5];
uint32_t *p1 = &arr[1];
uint32_t *p2 = &arr[4];

p2 - p1 == 3
p1 - p2 == -3
```

The result is expressed in elements and has type `ptrdiff_t`.

## Next planned topic

Arrays and pointer decay.

Likely sequence after that:

1. array expressions and decay
2. `sizeof(array)` vs `sizeof(pointer)`
3. exceptions to array-to-pointer conversion
4. `arr` vs `&arr`
5. multidimensional arrays
6. pointer-to-pointer
7. pointer UB and firmware consequences

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
- [ ] arrays and pointer decay
- [ ] `arr` vs `&arr`
- [ ] multidimensional arrays
- [ ] pointer-to-pointer
- [ ] const pointer combinations
- [ ] void pointers
- [ ] null pointers
- [ ] dangling pointers
- [ ] wild pointers
- [ ] object lifetime
- [ ] pointer casts
- [ ] strict aliasing
- [ ] alignment-related pointer issues
- [ ] integer/pointer conversion
- [ ] function pointers
- [ ] MMIO pointer usage
- [ ] volatile pointer patterns
- [ ] pointer-related undefined behavior
- [ ] pointer debugging
- [ ] firmware-specific failure scenarios
- [ ] Senior/Principal interview scenarios

## Previous sections

Sections 1–5 were covered in the previous Track 1 chat.

Their exact titles are now recovered and preserved in `Track_1/Curriculum.md`. Topic-by-topic mastery for Sections 1–5 still needs to be recovered or revalidated rather than assumed.