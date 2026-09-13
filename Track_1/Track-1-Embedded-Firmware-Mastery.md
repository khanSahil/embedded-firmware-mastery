# Track 1 — Embedded Firmware Mastery

> A living, curated handbook for mastering MCU firmware, ARM Cortex-M, RTOS, debugging, multicore systems, bootloaders, OTA, security, reliability, and production embedded architecture.

---

## 1. Purpose

This is the **single long-term knowledge reference for Track 1**.

It is not a transcript of our discussions and it is not intended to become a generic embedded-systems textbook. It should contain the knowledge worth retaining after we have actually studied, implemented, broken, debugged, measured, and reasoned about a concept.

The handbook has two purposes:

1. **Deep reference while learning** — preserve mental models, internals, experiments, debugging discoveries, failure modes, architecture decisions, and connections between topics.
2. **Senior/Principal interview refresh** — make it possible to revisit Track 1 months or years later without reconstructing everything from tutorials and scattered notes.

---

## 2. North Star

> Give me an unfamiliar Cortex-M system, datasheet, reference manual, schematic, compiler, and debugger, and I'm confident I can understand it, bring it up, write/debug the firmware, diagnose difficult failures, and explain my architectural decisions in an interview.

The STM32H745I-DISCO is our training platform, **not our specialization**. The real objective is transferable embedded-engineering ability.

---

## 3. Learning Philosophy

```text
Concept
   ↓
Implement
   ↓
Break
   ↓
Debug
   ↓
Explain
   ↓
Improve
```

We do **not** consider a topic mastered merely because an example works.

For every important concept, progression should eventually include fundamentals, first principles, internals, implementation, observation, deliberate failure, debugging, edge cases, performance, production engineering, architecture/tradeoffs, interview scenarios, and teach-back.

**Do not skip fundamentals. Compress fundamentals that are already demonstrated.**

Previous professional exposure does not automatically mean mastery. A topic should be assessed through explanation, implementation, debugging, failure analysis, and design reasoning.

---

## 4. Mastery Scale

| Level | Meaning |
|---|---|
| 0 | Never worked with it |
| 1 | Theory / conceptual familiarity |
| 2 | Tutorial or lab experience |
| 3 | Professional use |
| 4 | Independent implementation and debugging |
| 5 | Understand internals and difficult failure modes |
| 6 | Can architect, defend tradeoffs, and teach it |

For important Senior/Principal topics, the target is generally **Level 5–6**.

Status labels used in this handbook:

- ⬜ Not started
- 🟡 Learning
- ✅ Foundation established
- 🔵 Deep understanding
- 🏆 Mastery demonstrated

`✅ Foundation established` means the foundational mental model has been demonstrated. It does **not** mean the topic is finished forever; important ideas recur at greater depth later.

---

# 5. Track 1 Mastery Stack

```text
                 PRINCIPAL-LEVEL SYSTEM DESIGN
                            ↑
              Architecture & Trade-off Decisions
                            ↑
          Reliability / Diagnostics / Fault Recovery
                            ↑
             Security / Secure Boot / Trust
                            ↑
              Firmware Update / OTA / A-B
                            ↑
                 Custom Bootloader
                            ↑
              Multicore Architecture M7 ↔ M4
                            ↑
             Real-Time System Engineering
                            ↑
                FreeRTOS → Zephyr
                            ↑
         Networking / USB / Storage / Display
                            ↑
              Drivers / DMA / Zero-Copy
                            ↑
          Interrupts / Timers / Concurrency
                            ↑
             Cache / MPU / Memory Barriers
                            ↑
          Memory Architecture / Linker Scripts
                            ↑
          Startup / Vector Table / Exceptions
                            ↑
                ARM Cortex-M Architecture
                            ↑
              Assembly / Compiler / ELF
                            ↑
                  Embedded C / C++
                            ↑
                Electronics / Protocols
                            ↑
             STM32H745I-DISCO Hardware
```

---

# 6. Primary Lab Platform — STM32H745I-DISCO

Track 1 uses the **STM32H745I-DISCO** as the primary physical platform.

Important capabilities include STM32H745XI dual-core MCU, Cortex-M7 up to 480 MHz, Cortex-M4 up to 240 MHz, 2 MB internal Flash, 1 MB internal RAM, external SDRAM, external QSPI NOR, onboard eMMC, Ethernet, CAN FD, USB, LCD/touch, audio/microphone hardware, onboard STLINK-V3E, Arduino Uno V3 expansion, and STMod+ expansion.

The development board is **not** the MCU. External components introduce additional latency, bandwidth, initialization, signal, DMA, cache, reliability, and failure considerations.

---

# 7. Track 1 Roadmap

The schedule is deliberately flexible. **Mastery determines progression, not calendar time.** A rough depth-first journey is approximately 12–15 months at 7–10 hours/week, but taking longer is completely acceptable.

| Phase | Area | Rough duration |
|---|---|---:|
| 0 | Board & toolchain | 1–2 weeks |
| 1 | Embedded C + bare metal | 5–6 weeks |
| 2 | ARM Cortex-M internals | 4–5 weeks |
| 3 | Drivers + interrupts + DMA | 6–8 weeks |
| 4 | Embedded C++ | 4–5 weeks |
| 5 | FreeRTOS + real-time engineering | 8–10 weeks |
| 6 | Cache + memory + performance | 4–5 weeks |
| 7 | Connectivity + storage | 4–6 weeks |
| 8 | Dual-core M7 ↔ M4 | 5–7 weeks |
| 9 | Bootloader + OTA + security | 6–8 weeks |
| 10 | Zephyr | 4–6 weeks |
| 11 | Principal capstone | 6–8 weeks |

Target balance: approximately **60% hands-on / 40% theory**.

---

# 8. Phase 1 — Embedded C + Bare-Metal Foundations

> **Status: 🟡 In progress**

Phase 1 is intentionally architecture-neutral wherever possible. We establish strong CPU, binary, memory, C, build, startup, and bare-metal foundations before entering Cortex-M-specific architecture in Phase 2.

## Phase 1 Progress Dashboard

| Section | Topic | Status |
|---:|---|---|
| 1 | MCU / Hardware Foundations | ✅ Foundation established |
| 2 | Generic CPU Execution Foundations | ✅ Foundation established |
| 3 | Binary & Bit Manipulation | ✅ Foundation established |
| 4 | Integer Representation / Arithmetic | ⬜ Not started — next |
| 5 | Memory Representation | ⬜ Not started |
| 6 | C Memory & Pointer Foundations | ⬜ Not started |
| 7 | Embedded-C-Specific Semantics | ⬜ Not started |
| 8 | Concurrency Foundation | ⬜ Not started |
| 9 | Compiler & Build Pipeline | ⬜ Not started |
| 10 | Program Memory Layout | ⬜ Not started |
| 11 | ELF Fundamentals | ⬜ Not started |
| 12 | Linker Script Fundamentals | ⬜ Not started |
| 13 | Startup / Boot Fundamentals | ⬜ Not started |
| 14 | Bare-Metal Firmware Structure | ⬜ Not started |
| 15 | Debugging Foundations | ⬜ Not started |

After Sections 1–4, we will do the first integrated mini-design exercise using only concepts covered so far. At the end of Phase 1 we will do a cumulative test across all Phase-1 material, review/re-test weaknesses, and perform a final Phase-1 consolidation before moving to Phase 2.

---

# Phase 1 — Section 1: MCU / Hardware Foundations

> **Status: ✅ Foundation established**

## Interview Refresh

A microcontroller is much more than a CPU. A useful first mental model is:

```text
CPU(s)
+ memories
+ peripherals
+ interconnect / buses
+ clocks / reset
+ interrupt system
+ DMA
+ caches
+ debug infrastructure
+ power management
```

Important ideas:

- An address does not inherently mean RAM.
- The system memory map determines which hardware responds to an address.
- Peripheral registers are exposed through memory-mapped addresses.
- A CPU store instruction can therefore alter physical hardware.
- Peripheral clocks and reset state matter for correct peripheral operation.
- DMA can move data without the CPU executing one copy instruction per byte.
- Interrupts allow hardware events to request CPU attention asynchronously.
- Multiple bus masters can compete for memory/interconnect resources.
- The STM32H745 contains two CPU cores, making ownership and synchronization first-class concerns later.

## 1.1 What Is Actually Inside an MCU?

```text
                     ┌───────────────┐
                     │      CPU      │
                     └───────┬───────┘
                             │
                     ┌───────┴───────┐
                     │ Interconnect  │
                     └───────┬───────┘
         ┌───────────────────┼───────────────────┐
         │                   │                   │
       Flash               SRAM             Peripherals
                                                 │
                                  ┌──────────────┼─────────────┐
                                  GPIO          UART          SPI ...
```

Other important participants include DMA controllers, interrupt logic, clocks/reset, debug infrastructure, caches, and—on STM32H745—the second CPU core and hardware engines such as Ethernet/USB.

## 1.2 Memory Map and Address Decoding

A CPU address is not synonymous with RAM. Hardware address decoding determines which target responds.

```text
CPU issues address
       ↓
interconnect examines address
       ↓
address decoder determines target
       ↓
Flash / SRAM / peripheral / other target responds
```

A system interconnect can first select a peripheral region, after which the peripheral internally decodes the register offset.

Example conceptual GPIO block:

```text
GPIO base = 0x9000
MODE      = base + 0x00
OUTPUT    = base + 0x04
INPUT     = base + 0x08
PULL      = base + 0x0C
```

The same broad CPU STORE mechanism can therefore write RAM or alter a peripheral register. The **address determines the destination**.

An access to an unmapped/unsupported address may produce an error or exception depending on the architecture and implementation. Exact Cortex-M fault behavior belongs later.

## 1.3 Memory-Mapped I/O

Most MCU peripherals expose configuration, control, status, and data registers inside the processor address space.

```text
C code
   ↓
compiler
   ↓
machine STORE instruction
   ↓
CPU issues address + value
   ↓
address decoder selects peripheral
   ↓
peripheral register receives value
   ↓
hardware circuitry changes state
   ↓
physical signal can change
```

This is one of the fundamental bridges between software and electronics.

A GPIO input register exposes a digital interpretation of the sensed physical pin state. It does not directly tell software the exact analog voltage.

## 1.4 Clocks and Reset

A peripheral clock is **not** a clock that pushes CPU data onto the bus. CPU, interconnect, and peripherals can participate in different clock domains.

Clock gating saves dynamic power and can stop clock-dependent state progression.

Important nuance: do **not** assume universally that a CPU register access must fail merely because the peripheral functional clock is disabled. Bus-facing register access and peripheral functional logic may have different clocking behavior. The reference manual defines exact behavior.

Clock gating and reset are different:

```text
Clock gated
→ clock-dependent state stops progressing
→ retained state may remain intact

Reset asserted
→ peripheral state/registers are driven to defined reset/default conditions
```

A useful peripheral-debugging hierarchy is:

```text
Power
  ↓
Reset
  ↓
Clock
  ↓
Pin mux / mode
  ↓
Peripheral configuration
  ↓
Data path
  ↓
Interrupt / DMA
  ↓
Application logic
```

## 1.5 GPIO Mode and Output State

GPIO mode controls whether an output driver is allowed to drive the physical pin. The output-data register can retain a value even while the pin is configured as input. This means firmware can sometimes preload an output value before switching the pin to output mode to avoid an unwanted transition/glitch.

Exact behavior is MCU-specific and should be verified in the reference manual.

## 1.6 GPIO Electrical Boundary

A GPIO pin is a physical connection on the MCU package. Behind it is internal circuitry that can sense pin voltage and, when configured for output, drive the pin.

```text
                 INSIDE MCU                         OUTSIDE MCU
        ┌────────────────────────┐
        │   Input Data Register  │
        │          ▲             │
        │   Input sensing        │
        │      circuitry         │
        │          ▲             │
        │          ●─────────────┼──── external circuit
        │       GPIO PIN         │
        │          │             │
        │     Output driver      │
        │          ▲             │
        │   Output Data Register │
        └────────────────────────┘
```

Input path:

```text
physical pin voltage
        ↓
GPIO input circuitry
        ↓
HIGH / LOW interpretation
        ↓
input data register bit
        ↓
CPU reads 0 or 1
```

## 1.7 High-Impedance Inputs and Floating Nodes

A digital input is designed to sense voltage while drawing very little current. A simple DC mental model is a very large input resistance, but real inputs are better characterized by leakage current, parasitic capacitance, protection structures, and input thresholds rather than one literal fixed resistor.

If an input has no meaningful path to VDD or ground, its voltage is not established deterministically. It is **floating** and can be influenced by stored charge, leakage, noise, nearby signals, or touch.

A crucial principle:

> Zero current does not imply zero voltage, and it does not imply VDD either. Voltage is established by circuit conditions and electrical connections.

## 1.8 Pull-Ups and Pull-Downs

A pull-up creates a weak resistive path toward VDD; a pull-down creates a weak resistive path toward ground.

```text
3.3 V                GPIO
  │                    │
 [R]                  [R]
  │                    │
 GPIO                  GND
pull-up              pull-down
```

The resistor makes the bias weak: it establishes a default state when nothing stronger controls the node, but a lower-resistance external path can override it safely.

Example with 3.3 V and 10 kΩ:

```text
I = V / R = 3.3 / 10000 = 0.33 mA
```

Without the resistor, closing a switch directly between VDD and ground would create a near-short rather than a safe logic transition.

Internal MCU pull resistors add a weak bias path but do not mean the input sensing circuitry itself is no longer high impedance.

## 1.9 Active-Low Signals

A common button arrangement is:

```text
3.3 V
  │
[pull-up]
  │
  ● GPIO
  │
 button
  │
 GND
```

```text
Button released → HIGH → inactive
Button pressed  → LOW  → active
```

This is an **active-low** signal: the logical function is asserted when the signal is LOW. Common naming styles include `RESET_N`, `/RESET`, `nRESET`, and `RESET#`.

“Active” describes logical meaning, not merely whether current is flowing.

## 1.10 Digital Thresholds

Datasheets specify guaranteed input regions rather than a universal midpoint threshold.

```text
VIL(max) = highest voltage guaranteed LOW
VIH(min) = lowest voltage guaranteed HIGH

0 V ─── VIL(max) ───── undefined/not-guaranteed region ───── VIH(min) ─── VDD
```

The voltage between VIL(max) and VIH(min) does not create a third digital value. Hardware still resolves to a digital state, but the result is not guaranteed by the specification.

Output guarantees:

```text
VOH(min) = minimum voltage guaranteed when output drives HIGH
VOL(max) = maximum voltage guaranteed when output drives LOW
```

A useful reconstruction:

```text
V = Voltage
I = Input / receiver
O = Output / sender
H = High
L = Low

HIGH → minimum matters
LOW  → maximum matters
```

## 1.11 Logic-Level Compatibility and Noise Margin

For Chip A driving Chip B:

```text
HIGH: VOH(min) ≥ VIH(min)
LOW:  VOL(max) ≤ VIL(max)
```

Noise margins:

```text
HIGH noise margin = VOH(min) - VIH(min)
LOW  noise margin = VIL(max) - VOL(max)
```

Datasheet guarantees matter more than behavior observed on a few boards because production behavior must remain valid across specified voltage, loading, temperature, and process conditions.

## 1.12 Output Loading

A GPIO output is not an ideal voltage source. Its output driver has nonzero effective resistance, so load current can cause HIGH voltage to droop and LOW voltage to rise.

```text
Vdrop = I × Rinternal
```

This is why VOH/VOL guarantees are tied to stated load-current conditions.

## 1.13 Pull-Resistor Selection Tradeoff

There is no universal “always use 10 kΩ” rule.

Smaller resistance generally provides stronger bias, better noise immunity, and faster RC transitions, but consumes more current when overridden. Larger resistance saves power but is more sensitive to leakage/noise and can create slower transitions with capacitance.

A large resistor produces a large voltage drop only when current actually flows: `V = I × R`.

## 1.14 Early Interrupt, DMA, Multicore, and Debug Mental Models

These are previews only; deep treatment comes later.

```text
Peripheral event → interrupt request → CPU attention → handler → return
```

DMA allows a hardware engine to transfer data after CPU configuration rather than requiring one CPU load/store pair per byte.

Potential bus masters include CPU cores, DMA, Ethernet, USB, and other engines. Performance/correctness can therefore depend on contention, ownership, memory placement, and synchronization.

On STM32H745, M7 and M4 can share resources. Shared state is not automatically safe.

Debug path:

```text
Development PC
      ↓ USB
STLINK-V3E
      ↓ SWD
STM32 debug infrastructure
      ↓
Cortex-M7 / Cortex-M4
```

## 1.15 Section 1 Foundation Gate

Be able to explain naturally:

- MCU as CPU + memory + peripherals + interconnect + clocks/reset + other engines
- address decoding and memory-mapped I/O
- why an address does not inherently mean RAM
- clock gating versus reset
- GPIO mode versus output-data state
- high-impedance inputs and floating nodes
- pull-ups/pull-downs and why the resistor matters
- active-low signals
- VIL/VIH/VOL/VOH
- logic compatibility and noise margin
- why output voltage changes with load
- why datasheet guarantees matter
- early roles of interrupts, DMA, multicore ownership, and SWD debugging

---

# Phase 1 — Section 2: Generic CPU Execution Foundations

> **Status: ✅ Foundation established**

This section intentionally uses an architecture-neutral CPU model. The goal is to understand what a processor fundamentally does beneath C code before depending on ARM/Cortex-M-specific register names, calling conventions, exception behavior, or instruction details.

## Interview Refresh

A CPU executes encoded machine instructions. At a simplified level it repeatedly **fetches, decodes, and executes** instructions. Registers provide small, fast working storage inside the CPU; memory provides much larger storage outside that register set. Load/store operations move values between memory and registers, ALU instructions transform register values, the program counter tracks instruction flow, and branches alter that flow.

Function calls add another problem: the machine must preserve enough execution state to return correctly, pass arguments/results according to an agreed convention, and protect values that must survive nested calls. The stack is a RAM-backed LIFO mechanism commonly used for this temporary per-invocation state.

A C local variable is a language-level object, not inherently a stack slot or register. The compiler decides where values live based on semantics, optimization, liveness, addressability, register pressure, and the target architecture/ABI.

## 2.1 Instructions, Machine Code, and Assembly

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

Assembly is a human-readable representation of machine instructions; it is not machine code itself. A compiler also does not necessarily emit a textual assembly file as an intermediate artifact.

During decode, hardware interprets instruction fields according to the ISA and generates internal control signals needed to perform the operation. Memory itself stores bits; meaning comes from context and interpretation.

## 2.2 Fetch → Decode → Execute

```text
FETCH
  obtain encoded instruction indicated by the PC
        ↓
DECODE
  interpret instruction fields according to the ISA
        ↓
EXECUTE
  perform requested operation
        ↓
repeat
```

**Fetch retrieves instruction bits, not the instruction's data operands.** Operand accesses occur according to what the decoded instruction requires.

Real processors can pipeline and overlap operations. Fetch/decode/execute is therefore a foundational mental model, not necessarily a literal one-operation-per-cycle description.

## 2.3 Registers Versus RAM

Registers are small storage locations tightly integrated with the CPU. They provide fast working state for operations.

```text
CPU
├── registers       small, directly usable working state
├── ALU             arithmetic / logical operations
└── execution logic
        │
        └──────── memory system
```

Registers are not infinite. Increasing their number has costs in area, wiring/routing, selection logic, instruction encoding, power, and timing.

When simultaneously live values exceed conveniently available registers, a compiler may **spill** selected values to memory, commonly stack storage, and reload them later.

## 2.4 LOAD, STORE, and ALU Operations

Conceptually:

```text
LOAD  R1, [address]     → read VALUE stored at address into R1
STORE R1, [address]     → write R1's value to memory at address
ADD   R3, R1, R2        → R3 = R1 + R2
SUB   R3, R1, R2        → R3 = R1 - R2
```

A LOAD obtains the data at an address; it does not automatically mean “load the address itself.” A STORE does not inherently destroy the source register.

This connects directly to MMIO: the same broad CPU store mechanism can target RAM or a peripheral register; the target address determines which hardware responds.

## 2.5 Program Counter and Control Flow

The **program counter (PC)** identifies the instruction stream the CPU is executing. In our simplified model it identifies where the next instruction should be fetched.

Sequential execution advances according to instruction size. Address width does **not** determine instruction size. In an imaginary machine using 4-byte instructions, PC progression by 4 occurs because each instruction occupies four bytes, not because addresses happen to be 32 bits wide.

Branches change normal sequential flow:

```text
normal:    instruction → next instruction → next instruction
branch:    instruction ───────────────────→ target instruction
```

A conceptual COMPARE can perform subtraction for condition evaluation without storing the arithmetic result. If the comparison result is zero, a Zero flag can become `Z=1`; a later conditional branch may inspect that state.

**The flag itself does not branch.**

## 2.6 Function Calls: Redirect + Remember How to Return

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

We used a generic return-information-register model without yet making it Cortex-M-specific.

Nested calls expose why one return register is insufficient for arbitrary call depth. If A calls B and B calls C, the newer call can overwrite the current return information, so older return information must be preserved somewhere—commonly the stack.

A leaf function may avoid saving return information if it makes no nested call, but **leaf function does not universally mean no stack frame**.

## 2.7 Stack and Stack Pointer

The stack is an organized region of RAM used for temporary LIFO state. The **stack pointer (SP)** tracks the current stack position; it does not inherently encode total capacity, free bytes, or used bytes.

For our conceptual downward-growing stack:

```text
          higher addresses
                ↑
0x3000          ← initial SP boundary
0x2FFF   ┌───────────────┐
         │ stack storage │
         │      ...      │
0x2000   └───────────────┘
                ↓
          lower addresses

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

POP does not erase the old RAM bits. It changes which region is considered active stack state.

The stack stores **value bits**, not metadata describing which register originally produced them. Correct compiler/code conventions determine how values are restored.

Stack direction and endianness are separate concepts.

## 2.8 Stack Frames and Per-Invocation State

A **stack frame** is the portion of stack storage associated with an active function invocation. Depending on compiler decisions it can contain saved registers, preserved return information, local objects, compiler temporaries, and call-related state.

Use **per invocation**, not merely “per function,” because recursion can create multiple simultaneously active invocations of the same function.

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

A correct callee restores stack state as required by the calling convention. Stack imbalance can cause the caller to restore the wrong values and create failures far from the original mistake.

## 2.9 Stack Depth and Overflow

Stack safety depends on **peak simultaneous usage**, not average usage.

If each recursive invocation consumes 20 bytes:

```text
5 active invocations  = 100 bytes
10 active invocations = 200 bytes
```

If the deepest path calls another function needing 40 bytes, that must be added to the peak.

Stack overflow means SP crosses the region allocated for that stack. Consequences depend on the memory map and protection. It may overwrite another RAM object, enter unmapped/protected memory and fault, corrupt control state, or manifest much later as an apparently unrelated failure.

A visible crash location is therefore not necessarily the original corruption location.

Where possible, controlled rejection/admission checking is preferable to knowingly permitting stack exhaustion.

## 2.10 Arguments, Return Values, and Calling Conventions

Functions need an agreement describing where inputs arrive, where results are returned, what registers can be clobbered, what state must survive, what stack state is required at return, and how control returns.

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

Example:

```text
R1 = 10
R2 = 20
CALL add
...
R1 = 30      ← return data according to our imaginary convention
RETURN
```

If the caller needs its previous `R1` value after the call, it must preserve it before the call. If the result also arrives in R1, the caller must move/save that result somewhere safe before restoring the old R1 value.

## 2.11 Caller-Saved and Callee-Saved Registers

These terms describe **responsibility**, not physical properties of particular registers.

**Caller-saved:** the caller preserves a value if it needs that value after making a call that is permitted to clobber the register.

**Callee-saved:** if a callee modifies such a register, the callee restores the required original value before returning.

Roles are relative:

```text
A calls B → A is caller, B is callee
B calls C → B is caller, C is callee
```

The calling convention specifies externally required state. An implementation can sometimes preserve a value in another safe register instead of memory, provided later operations cannot destroy that temporary copy and the convention remains satisfied.

Do not silently add unstated nested-call requirements while reasoning about a scenario: a strategy valid for a leaf function can become unsafe only after the requirements change and the function itself calls something else.

## 2.12 Calling Convention Versus ABI

A **calling convention** defines function-call mechanics: argument/result locations, register-preservation responsibility, stack rules, and control return.

An **ABI (Application Binary Interface)** is broader. It can include calling convention plus binary-level rules such as data representation, alignment, object layout, symbol conventions, and interoperability requirements.

Exact ARM/Cortex-M ABI details belong to Phase 2.

## 2.13 C Local Variables Are Not “Stack Variables”

```c
int f(void) {
    int x = 10;
    int y = 20;
    return x + y;
}
```

The C language describes program semantics. It does not require `x` and `y` to occupy stack slots. Depending on optimization/context, the compiler may keep values in registers, reuse registers, place an object in memory, transform the calculation, or eliminate variables entirely—for example by constant-folding the result.

A source-level variable and a physical storage location belong to different abstraction layers.

## 2.14 Liveness, Register Allocation, and Spilling

A value is **live** while its current value can still be needed by future execution. Once dead, the register holding it can be reused.

Therefore twenty source-level local variables do not necessarily require twenty registers or a large stack frame. If only three values are simultaneously live, registers can be reused across variables.

When register pressure exceeds the usable register set, the compiler may spill selected live values to memory and reload them later. The decision depends on liveness, future use, cost, optimization, calling-convention constraints, and target architecture—not simply on which value is “needed immediately.”

## 2.15 Addressability Changes Storage Requirements

```c
int x = 10;
use(&x);
```

`&x` means the memory address of the C object `x`; it does **not** mean “the address of the CPU register currently holding x.”

If observable program behavior requires `x` to be addressable, the compiler must arrange suitable memory-backed storage, commonly stack storage for an ordinary automatic local, subject to optimizations that preserve language semantics.

Pointer semantics will be studied deeply in the dedicated Phase-1 pointer section.

## 2.16 Integrated Execution Model

```text
C function       → instructions + control flow
argument         → value in convention-defined location
return value     → value in convention-defined location
local variable   → register / memory / transformed / optimized away
function call    → preserve required state + redirect execution
return           → restore required state + redirect back
stack frame      → temporary RAM associated with active invocation
```

Underneath these abstractions, the CPU still executes encoded instructions through the fetch/decode/execute machinery.

A useful umbrella is **execution state**:

```text
PC
register values
condition flags
SP
relevant memory state
```

A debugger fundamentally helps us halt execution and inspect or modify pieces of this state. The same model later supports reasoning about interrupts, faults, and RTOS context switching.

## 2.17 Deliberate Phase Boundary

This section is architecture-neutral on purpose. We have **not yet** locked these concepts to Cortex-M specifics such as exact R0–R15 meanings, R13/SP, R14/LR, R15/PC behavior, ARM/Thumb instructions, AAPCS rules, MSP/PSP, xPSR, exception entry/return, NVIC, or Cortex-M stack frames.

Those belong to **Phase 2 — ARM Cortex-M Internals**, after Phase 1 is completed deeply.

## 2.18 Section 2 Foundation Gate

Be able to reason naturally about:

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

**Status: ✅ Foundation established.** These ideas will recur and deepen throughout later phases.

---

# Phase 1 — Section 3: Binary & Bit Manipulation

> **Status: ✅ Foundation established**

## Interview Refresh

Embedded firmware frequently needs to interpret and modify individual bits inside hardware registers. The key mental model is that a register is a fixed-width pattern of bits; hexadecimal is simply a compact way to represent that pattern.

```text
1 hex digit = 4 bits
8 bits      = 1 byte
32 bits     = 8 hex digits
```

The core operations are:

```text
TEST:    reg &  mask
SET:     reg |  mask
CLEAR:   reg & ~mask
TOGGLE:  reg ^  mask
```

For a multi-bit field, replacing the old field value safely requires **clear then insert**, not OR alone:

```c
reg = (reg & ~FIELD_MASK) |
      ((value << FIELD_POS) & FIELD_MASK);
```

Correct bit math is only one layer of correctness. A read-modify-write sequence can still lose another execution context's update if the complete sequence is not atomic.

## 3.1 Binary, Hexadecimal, and Bit Positions

Bit numbering conventionally starts at zero from the least-significant bit:

```text
Bit:   7 6 5 4 3 2 1 0
Value: 1 0 1 0 0 1 0 1
```

For an unsigned N-bit pattern there are `2^N` combinations and the largest representable value is `2^N - 1`.

Examples:

```text
only bit 6 set = 0100 0000 = 0x40 = 64
1101 1010      = 0xDA
0xA5           = 1010 0101
```

Leading zeroes can be valuable because they make the intended register width visible even though they do not change the numeric value.

## 3.2 Shifts

A left shift moves bits toward more-significant positions; a right shift moves bits toward less-significant positions.

```text
0000 0001 << 4 → 0001 0000
0100 0000 >> 1 → 0010 0000
```

At fixed width, bits shifted beyond the available width are not retained in that stored pattern. Exact C behavior for signed values, promotions, invalid shift counts, and overflow belongs to later integer/C-semantics sections.

A highly useful mask idiom is:

```c
1U << bit_position
```

For example, bit 4 corresponds to `1U << 4`, which is `0x10`.

## 3.3 AND, OR, XOR, and NOT

### AND — select/test or clear

```text
x & 0 = 0
x & 1 = x
```

AND with a mask preserves selected bits and clears unselected bits in the result.

### OR — set

```text
x | 0 = x
x | 1 = 1
```

OR can force selected bits to 1, but it cannot clear an existing 1.

### XOR — toggle

```text
x ^ 0 = x
x ^ 1 = NOT x
```

Applying the same XOR mask twice restores the original value:

```text
x ^ mask ^ mask = x
```

### NOT — invert

NOT flips every bit in the operand. It is commonly used with AND to create a clear mask:

```c
reg &= ~(1U << bit_position);
```

## 3.4 Constructing and Testing Masks

To select multiple independent bits, OR their individual masks:

```c
mask = (1U << 6) | (1U << 2);
```

For multiple selected bits:

```c
(reg & mask) == 0U      // none selected bits are set
(reg & mask) != 0U      // at least one selected bit is set
(reg & mask) == mask    // all selected bits are set
```

Do not assume a bit-test result is literally `1`. For example:

```c
REGISTER & (1U << 4)
```

returns either `0` or the mask value (`0x10` here), so this is generally wrong:

```c
(REGISTER & (1U << 4)) == 1U
```

Prefer:

```c
(REGISTER & (1U << 4)) != 0U
```

or normalize deliberately:

```c
(REGISTER >> 4) & 1U
```

## 3.5 Multi-Bit Fields

A notation such as `MODE[5:3]` means that the field occupies bits 5, 4, and 3. A three-bit field has eight possible bit patterns (`000` through `111`).

For a field of `width` bits beginning at `position`:

```c
FIELD_MASK = ((1U << width) - 1U) << position;
```

Example for a 3-bit field at bits `[5:3]`:

```text
base three-bit mask = 0000 0111
shift left by 3     = 0011 1000 = 0x38
```

Extract a field by masking and shifting it down to bit zero:

```c
value = (reg & FIELD_MASK) >> FIELD_POS;
```

Example:

```text
register          = 1101 0011
field [6:4] mask  = 0111 0000
masked            = 0101 0000
shift right by 4  = 0000 0101 = 5
```

## 3.6 Replacing a Field Safely

OR alone is not a general field-replacement operation because OR cannot clear old 1 bits.

Suppose an old field is `101` and the requested new field is `010`:

```text
101
OR 010
------
111    ← wrong replacement
```

The correct generic pattern is:

```c
reg = (reg & ~FIELD_MASK) |
      ((value << FIELD_POS) & FIELD_MASK);
```

Conceptually:

```text
1. clear the old field
2. constrain and position the new value
3. OR the new field into the cleared register
```

OR-only insertion is valid if the old field is guaranteed to be all zeroes, but that guarantee should be explicit rather than assumed.

## 3.7 Field Width, Validation, and Truncation

A three-bit unsigned field can represent values `0..7`.

Masking an oversized value constrains it to the field width, but can silently transform the caller's request:

```text
input  = 1010 (10)
mask   = 0111
result = 0010 (2)
```

This prevents neighboring-field corruption but does not prove the input was valid.

For a production API, when out-of-range input is an error, validate and reject/report it rather than relying on silent truncation. Masking can still be useful as a defensive boundary after validation.

## 3.8 Operator Precedence Pitfalls

Unary `~` binds more tightly than shifts. Therefore:

```c
reg & ~1U << 5
```

is interpreted like:

```c
reg & ((~1U) << 5)
```

not:

```c
reg & ~(1U << 5)
```

The intended and readable form is:

```c
reg &= ~(1U << 5);
```

For the operators used here, a useful precedence slice is:

```text
unary ~
   ↓
<<  >>
   ↓
&
   ↓
^
   ↓
|
```

Even when precedence makes an expression technically correct, parentheses are often preferable in register code because they make intent obvious during review and debugging.

## 3.9 Read-Modify-Write and Lost Updates

An expression such as:

```c
reg |= mask;
```

is conceptually a read-modify-write operation:

```text
READ register
MODIFY local/read value
WRITE complete register value back
```

If two execution contexts update different bits in the same register and their sequences overlap, one can overwrite the other's update.

Example:

```text
Initial REG = 0000 0000

Main reads      → 0000 0000
Interrupt reads → 0000 0000
Interrupt sets bit 1 and writes → 0000 0010
Main sets bit 0 in stale copy and writes → 0000 0001
```

The desired combined state was `0000 0011`, but the interrupt update was lost.

Important rule:

> Correct masking does not imply concurrency safety.

Full treatment of atomicity, critical sections, hardware set/clear registers, and why `volatile` does not solve races belongs to Section 8 and later peripheral work.

## 3.10 Reading Datasheet Register Diagrams

For each register field, translate the datasheet into four questions:

```text
Where is the field?        → high:low / position / width
How do I select it?        → mask
How do I read it?          → mask + shift down
How do I replace it?       → clear + shift/mask + insert
```

Do not infer neighboring-bit behavior from field names alone. Preserve unrelated fields unless the datasheet explicitly specifies special write behavior. Later peripheral sections will add real hardware semantics such as read-only bits, write-one-to-clear fields, set/clear aliases, reserved bits, and side effects.

## 3.11 Section 3 Foundation Gate

Be able to reason naturally about:

- bit positions, powers of two, binary, and hexadecimal
- unsigned N-bit combinations and maximum value
- left/right shifts at the bit-pattern level
- AND/OR/XOR/NOT behavior
- constructing one-bit and multi-bit masks
- set, clear, toggle, and test patterns
- why a masked bit test may return the mask value rather than `1`
- field position, width, mask construction, extraction, and insertion
- why OR alone cannot generally replace a field
- validation versus masking/truncation
- precedence pitfalls such as `~1U << n`
- read-modify-write lost-update reasoning
- the distinction between bit-manipulation correctness and concurrency correctness

The cumulative Sections 1–3 test also revalidated MMIO/address decoding, stack/calling-convention reasoning, compiler storage freedom, and integration between register manipulation and CPU execution. Minor notation slips around STORE direction and MMIO-vs-RAM identification were re-tested successfully.

**Status: ✅ Foundation established.** These concepts will recur at much greater depth in peripheral drivers, concurrency, Cortex-M atomic operations, and real register-level firmware.

---

# Phase 1 — Section 4: Integer Representation / Arithmetic

> **Status: ⬜ Not started — next**

Planned topics include signed versus unsigned integers, two's complement, ranges, overflow/wraparound, promotions/conversions, and conceptual CPU condition flags such as Z/N/C/V.

---

# Phase 1 — Sections 5–15: Planned Sequence

## Section 5 — Memory Representation
Endianness, alignment, object representation basics.

## Section 6 — C Memory & Pointer Foundations
Pointers, addresses, dereferencing, arrays versus pointers, pointer arithmetic, `const`, structures, padding/alignment.

## Section 7 — Embedded-C-Specific Semantics
`volatile`, `const volatile`, fixed-width types, safe register bit operations, undefined and implementation-defined behavior.

## Section 8 — Concurrency Foundation
Atomicity, read-modify-write, race conditions, and why `volatile` does not mean atomic.

## Section 9 — Compiler & Build Pipeline
Preprocessing, compilation, assembly, object files, linking, symbols, relocations, optimization implications.

## Section 10 — Program Memory Layout
`.text`, `.rodata`, `.data`, `.bss`, stack, heap.

## Section 11 — ELF Fundamentals
Sections, symbols, map files, `objdump`, `readelf`, `nm` concepts.

## Section 12 — Linker Script Fundamentals
Flash/RAM placement, `MEMORY`, `SECTIONS`, VMA/LMA, linker symbols.

## Section 13 — Startup / Boot Fundamentals
Reset, initial stack concept, startup code, `.data` copy, `.bss` zeroing, calling `main()`.

## Section 14 — Bare-Metal Firmware Structure
Initialization, superloop, polling, state-machine thinking, driver/application separation.

## Section 15 — Debugging Foundations
Debugger mental model, breakpoints, watchpoints, registers/memory, disassembly, stepping, and optimized-code debugging concepts.

---

# 9. Phase 2 — ARM Cortex-M Internals

> **Status: ⬜ Not started**

Phase 2 begins only after Phase 1 has been completed deeply and passed its cumulative test/review gate.

Planned areas include common Cortex-M architecture first, followed by meaningful M4-versus-M7 differences: core registers, Thumb instructions, real function execution, AAPCS/ABI, xPSR/flags, MSP/PSP, Thread/Handler modes, privilege, vector table, exception entry/return, NVIC, faults, SysTick, masking registers, pipeline fundamentals, memory ordering/barriers, and exclusive/atomic access.

---

# 10. Later Track 1 Phases

## Phase 3 — Drivers + Interrupts + DMA
Register-level peripheral drivers, polling, interrupts, timers, DMA, buffering, async APIs, zero-copy, failure recovery, and measurement.

## Phase 4 — Embedded C++
References, RAII, ownership, constructors/destructors, templates, `constexpr`, interfaces, allocation policy, STL tradeoffs, exceptions/RTTI policy, and zero-cost abstractions.

## Phase 5 — FreeRTOS + Real-Time Engineering
Tasks, scheduling, context switching, priorities, queues, mutexes, semaphores, event groups, notifications, timers, ISR-safe APIs, stack sizing, priority inversion, starvation, deadlocks, latency, jitter, deadlines, and WCET reasoning.

## Phase 6 — Cache + Memory + Performance
Cache lines, clean/invalidate, DMA coherency, MPU attributes, memory barriers, TCM versus SRAM, shared memory, memory placement, zero-copy, and benchmarking.

## Phase 7 — Connectivity + Storage
Ethernet/TCP-IP, Wireshark, USB, CAN FD, eMMC, QSPI, persistent data, filesystems, storage integrity, and error recovery.

## Phase 8 — Multicore M7 ↔ M4
Boot order, resource ownership, IPC, shared memory, HSEM, cache/coherency, fault isolation, watchdog ownership, restart strategies, and firmware compatibility.

## Phase 9 — Bootloader + OTA + Security
Custom bootloader, validation/jump, CRC/integrity, Flash programming, A/B slots, rollback, power-failure safety, signatures, secure boot, anti-rollback, dual-core image coordination, and trust model.

## Phase 10 — Zephyr
Apply existing MCU/RTOS understanding in another ecosystem and compare device/driver models, DeviceTree, Kconfig/build, scheduling, synchronization, portability, and architecture tradeoffs.

## Phase 11 — Principal Capstone
Integrate dual-core partitioning, real-time control, networking, storage, UI, OTA, security, diagnostics, watchdog/recovery, automated testing, deliberate fault injection, and Principal-level architecture defense.

---

# 11. Parallel Track — Debugging & Measurement

Debugging is not a chapter that comes after programming. It develops throughout Track 1:

```text
printf
  ↓
GDB
  ↓
SWD / ST-LINK
  ↓
register and memory inspection
  ↓
disassembly / watchpoints
  ↓
logic analyzer / oscilloscope
  ↓
RTOS tracing / performance profiling
  ↓
fault reconstruction
  ↓
production crash diagnostics
```

---

# 12. Parallel Track — Engineering Practice

Production engineering includes Git, GCC/CMake, warnings/formatting, tests, static analysis, mocks/integration tests, Python automation, CI, hardware-in-the-loop testing, fault injection, automated flashing/testing, artifact/version management, OTA/rollback validation, and reproducible release engineering.

---

# 13. Failure Notebook

Real failures encountered during Track 1 should be preserved because debugging experience is one of the highest-value outputs of the track. Each entry should preserve symptoms, context, hypotheses, experiments, observations, root cause, fix, why it works, misleading fixes, unfamiliar-MCU diagnostic approach, prevention/production design, and interview variations.

---

# 14. Interview Preparation Index

This section will eventually aggregate questions and scenarios accumulated during learning across C/C++, Cortex-M, assembly/ABI, compiler/linker/startup, memory, clocks/reset, peripherals, interrupts/faults, DMA, cache/MPU/barriers, RTOS, networking/storage, multicore, bootloader, OTA/security, reliability, debugging, performance, and Senior/Principal architecture.

---

# 15. Current Learning Position

```text
Track 1
└── Phase 1 — Embedded C + Bare-Metal Foundations  🟡
    ├── Section 1 — MCU / Hardware Foundations     ✅
    ├── Section 2 — Generic CPU Execution          ✅
    ├── Section 3 — Binary & Bit Manipulation      ✅
    └── Section 4 — Integer Representation         ← NEXT
```

Sections 1–3 have been consolidated into this single handbook. Section 4 is the next active learning block. After Section 4, the first mini-design will integrate concepts from Sections 1–4.

---

# 16. Handbook Maintenance Rule

This handbook should **not** be updated after every conversation message.

```text
Learn deeply in conversation
        ↓
Reason through questions
        ↓
Implement / experiment
        ↓
Break and debug
        ↓
Demonstrate understanding
        ↓
Identify durable lessons
        ↓
Consolidate into handbook
        ↓
Commit to GitHub
```

We will normally consolidate and push after each completed Phase-1 section. Later cumulative tests and mini-design exercises can expose weaknesses, and subsequent commits can refine earlier sections.

---

## Track 1 Status

**Primary board:** STM32H745I-DISCO  
**Current phase:** Phase 1 — Embedded C + Bare-Metal Foundations  
**Current section:** Section 4 — Integer Representation / Arithmetic (next)  
**Primary RTOS:** FreeRTOS  
**Secondary RTOS:** Zephyr (later)  
**Primary languages:** C and C++  
**Primary debugging path:** GDB + ST-LINK/SWD + measurement tools  
**End goal:** Senior/Principal-level transferable embedded firmware mastery