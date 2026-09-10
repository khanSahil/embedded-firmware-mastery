# Phase 1 — Section 2: Generic CPU Execution Foundations

> Status: **✅ Foundation established**

This section preserves the architecture-neutral CPU execution model established before moving into binary/bit manipulation and, later, Cortex-M-specific architecture. The purpose is to understand what a processor is fundamentally doing beneath C code without prematurely depending on ARM-specific rules.

---

## Interview Refresh

A CPU executes encoded machine instructions. At a simplified level it repeatedly **fetches, decodes, and executes** instructions. Registers provide small, fast working storage inside the CPU; memory provides much larger storage outside that register set. Load/store operations move values between memory and registers, ALU instructions transform register values, the program counter tracks instruction flow, and branches alter that flow.

Function calls add another problem: the machine must preserve enough execution state to return correctly, pass arguments/results according to an agreed convention, and protect values that must survive nested calls. The stack is a RAM-backed LIFO mechanism commonly used for this temporary per-invocation state.

A C local variable is a language-level object, not inherently a stack slot or register. The compiler decides where values live based on semantics, optimization, liveness, addressability, register pressure, and the target architecture/ABI.

---

## 1. Instructions, Machine Code, and Assembly

The CPU does not execute C source directly. It executes binary-encoded **machine instructions** defined by its instruction-set architecture (ISA).

```text
C source
   ↓
compiler
   ↓
assembly representation (conceptually)
   ↓
assembler
   ↓
machine-code instruction bits
   ↓
CPU
```

Assembly is a human-readable representation of machine instructions; it is not machine code itself. A compiler also does not necessarily need to emit a textual assembly file as an intermediate artifact.

During decode, hardware interprets instruction fields according to the ISA and generates the internal control needed to perform the operation. Memory itself only contains bits; meaning comes from how those bits are interpreted.

---

## 2. Fetch → Decode → Execute

A useful foundational model is:

```text
FETCH
  CPU obtains the encoded instruction indicated by the program counter
        ↓
DECODE
  CPU interprets the instruction fields according to the ISA
        ↓
EXECUTE
  CPU performs the requested operation
        ↓
repeat
```

**Fetch retrieves instruction bits, not the instruction's data operands.** Operand accesses occur according to what the decoded instruction requires.

Real processors pipeline and overlap work, so this is a conceptual model rather than a cycle-by-cycle description. Pipeline details belong later.

---

## 3. Registers Versus RAM

Registers are small storage locations tightly integrated with the CPU. They exist because repeatedly accessing larger external memory structures for every intermediate value would be expensive.

```text
CPU
├── registers       small, directly usable working state
├── ALU             arithmetic / logical operations
└── execution logic
        │
        └──────── memory system
```

Registers are not infinite. More registers increase hardware area, wiring/routing, selection complexity, instruction-encoding pressure, power, and timing complexity.

When simultaneously live values exceed conveniently available registers, a compiler may **spill** some values to memory, commonly stack storage, and reload them later.

---

## 4. LOAD, STORE, and ALU Operations

Conceptually:

```text
LOAD  R1, [address]     → read the VALUE stored at address into R1
STORE R1, [address]     → write R1's value to memory at address
ADD   R3, R1, R2        → R3 = R1 + R2
SUB   R3, R1, R2        → R3 = R1 - R2
```

A LOAD from an address obtains the data at that address; it does not automatically mean “load the address itself.” A STORE does not inherently destroy the source register.

This model connects directly to memory-mapped I/O: the same broad idea of a CPU store can target RAM or a peripheral register; the address determines which hardware target responds.

---

## 5. Program Counter and Control Flow

The **program counter (PC)** identifies the instruction stream the CPU is executing. In the simplified model it identifies where the next instruction should be fetched.

Sequential execution advances through instructions according to their encoded size. Address width does **not** determine instruction size. For example, in an imaginary machine with 4-byte instructions, addresses might advance by 4 because each instruction occupies four bytes—not because the machine happens to use 32-bit addresses.

A branch changes normal sequential control flow:

```text
normal:    instruction → next instruction → next instruction
branch:    instruction ───────────────────→ target instruction
```

Conditional branches use condition state produced by earlier operations. For example, a conceptual COMPARE can perform subtraction for condition evaluation without storing the arithmetic result. If the comparison result is zero, a Zero flag can become `Z=1`; a later conditional branch decides whether that flag should redirect execution.

The flag itself does not branch.

---

## 6. Function Calls: Redirect + Remember How to Return

A plain branch redirects execution. A function call must additionally preserve enough information to resume the caller afterward.

```text
caller
  │
  ├── remember return point
  └── redirect execution to callee
              │
              └── callee eventually returns
                         │
                         └── caller resumes
```

We used a generic **return-information register** mental model (similar in purpose to a link register on some architectures), without yet teaching Cortex-M's exact registers or ABI.

Nested calls expose the problem immediately: if A calls B and B calls C, a single return-information register cannot retain every older return point if each call overwrites it. Older return information therefore has to be preserved somewhere, commonly on the stack.

A leaf function may avoid saving return information if it makes no nested call, but “leaf function = no stack frame” is not a valid universal rule.

---

## 7. Stack and Stack Pointer

The stack is an organized region of RAM used for temporary LIFO state. The **stack pointer (SP)** tracks the current stack position; it does not inherently encode total capacity, free bytes, or used bytes.

For our conceptual downward-growing stack:

```text
RAM: 0x2000 ... 0x2FFF
initial SP = 0x3000      ← boundary immediately above stack storage

PUSH 32-bit value:
    SP = SP - 4
    memory[SP] = value

first pushed value occupies 0x2FFC ... 0x2FFF
```

Conceptual POP:

```text
value = memory[SP]
SP = SP + 4
```

POP does not erase the old RAM bits. It changes which part of the stack is active.

The stack stores **values**, not metadata saying which register originally produced each value. Correct code/compiler conventions determine how values are restored.

Stack direction and endianness are separate concepts.

---

## 8. Stack Frames and Per-Invocation State

A **stack frame** is the portion of stack storage associated with an active function invocation. Depending on compiler decisions it can contain saved registers, preserved return information, local objects, compiler temporaries, and call-related state.

Use “per invocation,” not merely “per function,” because recursion can create multiple simultaneously active invocations of the same function.

Example:

```text
B enters with SP = 0x2FF4
save 3 × 32-bit values → 12 bytes
reserve 8 bytes for locals
frame size = 20 bytes
SP reaches 0x2FE0

B must restore its stack consumption before returning:
SP → 0x2FF4
```

A correct callee returns the stack pointer to the state required by the calling convention. Stack imbalance can make the caller restore the wrong values and produce failures far from the original mistake.

---

## 9. Stack Depth and Overflow

Stack safety depends on **peak simultaneous usage**, not average usage.

If each recursive invocation consumes 20 bytes:

```text
5 active invocations = 100 bytes
10 active invocations = 200 bytes
```

If a deeper function adds another 40-byte frame, that must also be included in the peak.

Stack overflow means the stack pointer crosses the storage region allocated for that stack. The consequence depends on the memory map and protection: it might corrupt another valid RAM object, enter unmapped/protected memory and fault, corrupt control state, or manifest much later as an apparently unrelated failure.

A visible crash location is therefore not necessarily the original corruption location.

Where possible, controlled rejection/admission checking is preferable to knowingly allowing stack exhaustion.

---

## 10. Arguments, Return Values, and Calling Conventions

Functions need an agreement describing where inputs arrive, where outputs are returned, what registers may be modified, what state must survive, what stack state is required at return, and how control returns.

We deliberately used an **imaginary convention**, not ARM rules:

```text
R1 = first argument
R2 = second argument
R1 = return value

R1, R2 = caller-saved
R3, R4 = callee-saved
SP must satisfy the convention on return
return information must be preserved correctly
```

Return **control** and return **data** are distinct problems.

Example `add(10, 20)`:

```text
R1 = 10
R2 = 20
CALL add
...
R1 = 30       ← result according to imaginary convention
RETURN
```

If the caller needed its previous `R1` value after the call, it must preserve that value before using/clobbering the caller-saved register. If the returned result is also in R1, the caller must first move/save the result somewhere safe before restoring the old R1 value.

---

## 11. Caller-Saved and Callee-Saved Registers

These terms describe responsibility, not physical register properties.

**Caller-saved:** the caller must preserve a value if it needs that value after making a call that is permitted to clobber the register.

**Callee-saved:** if the callee chooses to modify such a register, the callee must restore the required original value before returning.

Roles are relative:

```text
A calls B → A is caller, B is callee
B calls C → B is caller, C is callee
```

The calling convention specifies the externally required state. The implementation can sometimes preserve values in another safe register instead of memory, provided later operations cannot destroy that temporary copy and all convention requirements remain satisfied.

Do not add unstated nested calls when evaluating such reasoning: a preservation strategy valid for a leaf function may become unsafe only after the requirements change and the function itself calls another function.

---

## 12. Calling Convention Versus ABI

A calling convention is the contract for function-call mechanics: argument/result locations, register preservation, stack rules, and control return.

An **ABI (Application Binary Interface)** is broader. It can include calling convention plus binary-level rules such as data representation, alignment, object layout, symbol conventions, and other interoperability requirements. Exact ARM/Cortex-M ABI details belong later.

---

## 13. C Local Variables Are Not “Stack Variables”

Consider:

```c
int f(void) {
    int x = 10;
    int y = 20;
    return x + y;
}
```

The language describes values and behavior. It does not require `x` and `y` to occupy stack slots. Depending on optimization and context, the compiler may keep values in registers, reuse registers, place an object in memory, transform the calculation, or eliminate the variables entirely (for example by constant-folding the result).

A source-level variable and a physical storage location are different abstraction layers.

---

## 14. Liveness, Register Allocation, and Spilling

A value is **live** while its current value can still be needed by future execution. Once that value is dead, its register can be reused.

Therefore, twenty source-level local variables do not necessarily require twenty registers or a huge stack frame. If only three values are simultaneously live, registers can be reused across different source variables.

When register pressure exceeds the usable register set, the compiler may spill selected live values to memory and reload them later. The decision depends on liveness, future use, cost, optimization, calling convention constraints, and target architecture—not simply on which value is “needed immediately.”

---

## 15. Addressability Changes Storage Requirements

If C code requires the address of an ordinary local object:

```c
int x = 10;
use(&x);
```

`&x` means the memory address of the C object `x`; it does **not** mean “the address of the CPU register currently holding x.”

If the program's observable behavior requires `x` to be addressable, the compiler must arrange suitable memory-backed storage (commonly stack storage for an ordinary automatic local), subject to optimizations that preserve language semantics.

Pointer semantics will be studied deeply in the dedicated Phase-1 pointer section.

---

## 16. Integrated Execution Model

A useful mapping from source concepts to machine concerns is:

```text
C function       → instructions + control flow
argument         → value in convention-defined location
return value     → value in convention-defined location
local variable   → register / memory / transformed / optimized away
function call    → preserve required state + redirect execution
return           → restore required state + redirect back
stack frame      → temporary RAM associated with active invocation
```

Underneath all of this, the CPU still executes instructions through the fetch/decode/execute machinery.

A useful umbrella term is **execution state**:

```text
PC
register values
condition flags
SP
relevant memory state
```

A debugger fundamentally helps us stop execution and inspect or modify pieces of this state. Later, the same mental model will make interrupts, exceptions, faults, and RTOS context switching much easier to reason about.

---

## 17. Boundaries: What We Have Deliberately Not Made Cortex-M-Specific Yet

This section is architecture-neutral on purpose. We have **not yet** locked these concepts to Cortex-M details such as:

- exact R0–R15 meanings
- R13/SP, R14/LR, R15/PC details
- ARM/Thumb instruction encoding
- AAPCS argument/return rules
- exact caller/callee-saved ARM registers
- MSP versus PSP
- xPSR and complete condition flags
- exception entry/return
- NVIC
- Cortex-M stack alignment and exception frames

Those belong to **Phase 2 — ARM Cortex-M Internals**, after Phase 1 is completed deeply.

---

## 18. Foundation Mastery Gate

At this stage, be able to reason naturally about:

- instruction vs machine code vs assembly
- fetch/decode/execute
- registers vs RAM and why registers exist
- LOAD/STORE and basic ALU operations
- PC and sequential/branched control flow
- compare + Zero flag + conditional branch
- why a function call needs return information
- nested calls and preservation of older return state
- SP, PUSH/POP, stack direction, and frame ownership
- stack imbalance and overflow
- peak stack usage
- arguments and return values
- caller-saved versus callee-saved responsibility
- calling convention versus ABI
- locals not inherently living on the stack
- liveness, register allocation, and spilling
- why taking a local object's address can require memory-backed storage
- how these pieces combine into CPU execution state

**Status: ✅ Foundation established.** These ideas will recur and deepen throughout later phases; “foundation established” does not mean the subject is finished forever.
