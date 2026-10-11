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

Synchronized 2026-10-11 from [Concepts progress](Concepts/Progress.md). This handbook preserves detailed learning notes for later reference; current curriculum, assessment evidence, and cross-stream state are owned by `Concepts/` and `Active-Context.md`.

Sections 1–8 have established foundations / completed the current conceptual pass, not blanket mastery.

| Section | Topic | Status |
|---:|---|---|
| 1 | MCU / Hardware Foundations | ✅ Foundation established |
| 2 | Generic CPU Execution Foundations | ✅ Foundation established |
| 3 | Binary & Bit Manipulation | ✅ Foundation established |
| 4 | Integer Representation / Arithmetic | ✅ Foundation established |
| 5 | Memory Representation | ✅ Foundation established |
| 6 | C Memory & Pointer Foundations | ✅ Completed — current conceptual-validation pass |
| 7 | Embedded-C Semantics | ✅ Completed — current conceptual-validation pass |
| 8 | Concurrency Foundations | ✅ Completed — current conceptual-validation pass (15-question cumulative Sections 1–8 assessment) |
| 9 | Compiler & Build Pipeline | 🟡 IN_PROGRESS — starting preprocessing |
| 10 | Program Memory Layout | ⬜ Not started |
| 11 | ELF Fundamentals | ⬜ Not started |
| 12 | Linker Script Fundamentals | ⬜ Not started |
| 13 | Startup / Boot Fundamentals | ⬜ Not started |
| 14 | Bare-Metal Firmware Structure | ⬜ Not started |
| 15 | Debugging Foundations | ⬜ Not started |

After every completed section, design practice integrates all concepts covered so far using an evolving template appropriate to the current learning depth. Current design readiness and reviewed exercises are tracked in `Design/Progress.md` and `Active-Context.md`. At the end of Phase 1 we will do a cumulative test across all Phase-1 material, review/re-test weaknesses, and perform a final Phase-1 consolidation before moving to Phase 2.

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

> **Status: ✅ Foundation established**

## Interview Refresh

A fixed-width bit pattern has no inherent signed or unsigned meaning. Interpretation comes from the type/operation applied to the bits.

For an N-bit integer:

```text
Unsigned range:
0 ... 2^N - 1

Signed two's-complement range:
-2^(N-1) ... 2^(N-1) - 1
```

Two's complement is best understood as fixed-width modular arithmetic, not as "one sign bit plus magnitude." For 8 bits:

```text
1000 0000 = -128
1111 1111 = -1
0111 1111 = +127
```

Carry and signed overflow answer different questions:

```text
C → did the addition generate a bit beyond the operation width?
V → is the mathematically correct signed result outside the signed range?
```

Unsigned arithmetic is defined modulo `2^N`; signed overflow must not be assumed to have the same C-language behavior merely because the CPU uses two's complement.

A key C mental model established here is:

```text
expression evaluation width/type
        ≠ necessarily
destination object's width/type
```

Small integer operands can be promoted before arithmetic, and information can be lost later during narrowing. Widening after information has already been discarded cannot reconstruct the original value.

## 4.1 Bits Versus Numeric Interpretation

The same pattern can represent different numbers:

```text
1111 1111

unsigned → 255
signed two's complement → -1
```

The hardware stores bits; the compiler and machine operation determine how those bits participate in arithmetic and comparisons.

Do not confuse two's complement with sign-magnitude. In two's complement, the MSB is not a detachable sign bit. A useful signed-weight model for 8 bits is:

```text
bit:     7    6   5   4   3   2   1   0
weight: -128  64  32  16   8   4   2   1
```

Example:

```text
1111 1100
= -128 + 64 + 32 + 16 + 8 + 4
= -4
```

## 4.2 Two's Complement and Negation

To construct the negative of an ordinary representable value at fixed width:

```text
1. invert every bit
2. add 1
```

Example:

```text
+10 = 0000 1010
invert 1111 0101
+1     1111 0110 = -10
```

This is a derived shortcut for the modular representation, not a separate magical encoding rule.

The most-negative value is a special boundary:

```text
int8_t-like signed range: -128 ... +127

-128 = 1000 0000
```

Mathematically, negating -128 requires +128, which is not representable in the same signed 8-bit width. This asymmetry later matters for C expressions such as negation and absolute-value edge cases.

## 4.3 Addition and Subtraction

Subtraction can be viewed as addition of a negative:

```text
A - B = A + (-B)
```

Example:

```text
  0000 1010   +10
+ 1111 1101    -3
------------
1 0000 0111
```

Keeping the low 8 bits gives 7.

The same binary adder can therefore support both addition and subtraction with appropriate operand transformation/control.

## 4.4 Carry Versus Signed Overflow

These are independent concepts.

Example:

```text
  0111 1111   +127
+ 0000 0001     +1
------------
  1000 0000
```

Mathematical signed result is +128, which is outside the 8-bit signed range. Therefore signed overflow occurred. But there is no carry bit beyond bit 7.

Conversely:

```text
  1111 1111   -1 signed
+ 0000 0001   +1
------------
1 0000 0000
```

Here there is carry-out, but the signed mathematical result is 0 and fits perfectly.

All combinations are possible:

```text
C=0, V=0
C=1, V=0
C=0, V=1
C=1, V=1
```

A useful signed-addition rule:

- positive + positive yielding a negative-looking stored pattern indicates signed overflow;
- negative + negative yielding a non-negative-looking stored pattern indicates signed overflow;
- adding opposite signs cannot overflow the signed range.

## 4.5 Conceptual Z / N / C / V Flags

Architecture-neutral meanings introduced here:

```text
Z → stored result is zero
N → stored result MSB is 1
C → carry out of the operation width
V → signed mathematical result overflowed the signed range
```

Example:

```text
1111 1111 + 0000 0001 → stored 0000 0000

Z=1
N=0
C=1
V=0
```

Important nuance: `N=1` describes the stored result pattern's MSB. If `V=1`, the mathematically correct signed result may not actually be negative.

Exact Cortex-M flag semantics, condition codes, and subtraction carry/borrow behavior belong to Phase 2.

## 4.6 Unsigned Modular Arithmetic and Counter Wraparound

Unsigned fixed-width arithmetic wraps modulo `2^N`.

For 8 bits:

```text
255 + 1 → 0
250 + 10 → 4
```

This is not merely a nuisance; it is useful for free-running counters and timers.

Example:

```text
start = 250
end   = 5

elapsed = (5 - 250) mod 256 = 11
```

However, two snapshots cannot reveal how many complete cycles occurred. If the modulo difference is 7, actual elapsed counts could be:

```text
7
7 + 256
7 + 2*256
...
```

Therefore wrap-safe elapsed-time calculations require a bound that makes the intended interval unambiguous.

## 4.7 Signed Versus Unsigned Comparisons

The same bit pattern can order differently depending on interpretation:

```text
1111 1111 vs 0000 0001

unsigned: 255 > 1 → true
signed:    -1 > 1 → false
```

Mixed signed/unsigned C expressions are dangerous because language conversion rules may change the effective numeric interpretation before the comparison.

For a same-width simplified case:

```text
signed -5 → converted to unsigned → large unsigned value
large unsigned value < 10 → false
```

Do not memorize "signed always becomes unsigned" as a universal rule. Exact rank/range rules belong to Section 7.

## 4.8 Integer Promotions and Expression Width

A small integer object's declared width does not imply that every expression using it is evaluated at that width.

Typical example when `int` can represent all `uint8_t` values:

```c
uint8_t a = 200;
uint8_t b = 100;
uint8_t result = a + b;
```

Conceptually:

```text
a → promoted to int
b → promoted to int
200 + 100 → 300 as int
assignment to uint8_t → 44
```

Therefore:

```c
if (a + b > 255)
```

can be true even though both source objects are 8-bit.

But after narrowing:

```c
uint8_t result = a + b;
if (result > 255)
```

the condition cannot be true because the object already contains only an 8-bit value.

Exact integer-promotion and usual-arithmetic-conversion rules belong to Section 7.

## 4.9 Narrowing and Irrecoverable Information Loss

Once a wider value is converted to a narrower type and high-order information is discarded, later widening cannot restore it.

Example:

```text
260
 ↓ convert to uint8_t
4
 ↓ convert to uint16_t
4
```

Bit view:

```text
0000 0100
      ↓ widen
0000 0000 0000 0100
```

The lost upper bit that distinguished 260 from 4 is gone.

Engineering rule:

> If overflow/range information matters, validate before a narrowing conversion that can discard it.

## 4.10 Unsigned Underflow

Unsigned arithmetic has no negative result domain. At width N:

```text
0 - 1 → 2^N - 1
```

For `unsigned int count = 0;`, `count--` produces `UINT_MAX`, not -1.

This can make an invalid logical state look like a very large valid-looking positive quantity.

Also distinguish `uint8_t` from `unsigned int`: a `uint8_t` may promote to `int` before arithmetic on typical systems, whereas `unsigned int` is already at that type/rank and does not simply become signed `int`.

## 4.11 Logical Versus Arithmetic Right Shift

At the bit-operation level:

```text
logical right shift    → newly vacated high bits are filled with 0
arithmetic right shift → newly vacated high bits replicate the original MSB
```

Example:

```text
1111 1000  (-8)

logical >> 1    → 0111 1100
arithmetic >> 1 → 1111 1100  (-4)
```

Arithmetic right shift can resemble division by powers of two for signed values, but negative odd numbers expose rounding differences:

```text
-7 arithmetic >> 1 → -4
-7 / 2 mathematically → -3.5
```

Exact C semantics for right-shifting negative signed integers belong to Section 7.

## 4.12 Sign Extension Foundation

When widening a negative two's-complement value while preserving its numeric meaning, replicate the original sign bit into all newly introduced upper bits.

Example:

```text
8-bit -5:
1111 1011

16-bit -5:
1111 1111 1111 1011
```

Zero extension would instead produce positive 251 and would not preserve the signed value.

This will recur naturally in memory representation, integer conversions, and later CPU load/instruction behavior.

## 4.13 C-Language Boundary

Do not confuse hardware bit behavior with C-language guarantees.

A CPU may physically use a two's-complement adder, but this does not imply that overflowing a signed C integer is guaranteed to wrap like unsigned arithmetic.

Unsigned arithmetic has defined modulo behavior. Signed-overflow language semantics, implementation-defined conversions, promotions, and undefined behavior are deliberately deferred to Section 7.

Useful layered model:

```text
C language rules
      ↓
compiler transformations / instruction selection
      ↓
machine instructions
      ↓
CPU operates on bit patterns
```

## 4.14 Section 4 Foundation Gate

Be able to reason naturally about:

- bits versus signed/unsigned interpretation
- unsigned and two's-complement ranges
- why two's complement is not sign-magnitude
- negative-weight interpretation
- invert-plus-one negation and the most-negative-value asymmetry
- subtraction as addition of a two's-complement negative
- carry versus signed overflow
- conceptual Z/N/C/V flags
- unsigned modulo arithmetic and counter wraparound
- ambiguity when a counter may have wrapped multiple times
- signed versus unsigned comparison meaning
- integer-promotion foundation
- expression width versus destination width
- narrowing and irreversible information loss
- unsigned underflow
- logical versus arithmetic right shift
- sign extension
- hardware behavior versus C-language guarantees

The cumulative Sections 1–4 test revalidated MMIO/address decoding, CPU/calling-convention reasoning, peak stack usage, register field replacement, read-modify-write lost updates, integer flags, wraparound, compiler storage freedom, GPIO active-low behavior, and signed/unsigned interpretation. A temporary sign-magnitude slip while encoding a negative value was re-tested successfully by deriving `-6` as `1111 1010` through invert-plus-one.

**Status: ✅ Foundation established.** Exact C conversion/overflow semantics will deepen in Section 7; exact Cortex-M flag and shift behavior will deepen in Phase 2.

---

# Phase 1 — Section 5: Memory Representation

> **Status: ✅ Foundation established**

## Interview Refresh

Memory is byte-addressed: each address identifies one byte. Multi-byte objects occupy consecutive addresses, and the object size determines the inclusive address range:

```text
last byte address = start address + size - 1
```

For a multi-byte value, **endianness** determines the order in which its bytes appear in memory:

```text
Value: 0x12345678

Little-endian memory:
lowest address → 78 56 34 12 → highest address

Big-endian memory:
lowest address → 12 34 56 78 → highest address
```

Endianness changes byte order for multi-byte values. It does not reverse bit order inside each byte.

**Alignment** describes constraints or preferences on an object's starting address. Under a common natural-alignment model:

```text
2-byte alignment → address % 2 == 0
4-byte alignment → address % 4 == 0
8-byte alignment → address % 8 == 0
```

Power-of-two alignment can also be recognized from low address bits:

```text
2-byte aligned → lowest 1 bit = 0
4-byte aligned → lowest 2 bits = 00
8-byte aligned → lowest 3 bits = 000
```

Alignment and size are related on many ABIs, but they are not the same concept and must not be treated as universally identical.

A misaligned multi-byte access can span multiple naturally aligned memory blocks. Exact consequences are architecture-specific: it may require multiple internal accesses, be slower, need special handling, or fault for some access types.

Padding is compiler-inserted storage used to satisfy alignment constraints. It can appear:

```text
between members → internal padding
after the final member → tail padding
```

Tail padding is especially important for arrays because the next structure object must begin at an address satisfying the structure's alignment.

The most important mental model from this section is:

> Memory stores bytes/bits. Meaning comes from software type, instruction, format, and context.

The same bit pattern can therefore represent different values:

```text
1111 1111

uint8_t → 255
int8_t  → -1
```

Likewise, the same 32-bit representation can be interpreted as an integer, floating-point value, pointer representation, protocol field, or other format depending on context.

## 5.1 Byte-Addressed Memory

If a 32-bit object begins at `0x2000`, it occupies:

```text
0x2000
0x2001
0x2002
0x2003
```

A byte read from one of those addresses retrieves only that byte. A multi-byte read combines consecutive bytes according to the machine's representation rules.

Do not confuse an object's numeric value with the order in which its bytes are displayed in a raw memory window.

## 5.2 Endianness

For value `0xA1B2C3D4`:

```text
Little-endian:
address +0 → D4
address +1 → C3
address +2 → B2
address +3 → A1

Big-endian:
address +0 → A1
address +1 → B2
address +2 → C3
address +3 → D4
```

A debugger may show:

```text
variable value: 0xAABBCCDD
raw memory:     DD CC BB AA
```

on a little-endian system. Those views are consistent: one shows the logical numeric value, the other the physical byte representation.

When data crosses a machine boundary, a protocol should define a fixed byte order rather than relying on each machine's native endianness.

## 5.3 Alignment

Alignment answers a different question from size:

```text
size      → how many bytes the object occupies
alignment → which starting addresses satisfy its placement requirement
```

Example: a 32-bit object beginning at `0x2002` occupies:

```text
0x2002
0x2003
0x2004
0x2005
```

and spans two 4-byte-aligned blocks:

```text
0x2000–0x2003
0x2004–0x2007
```

The object still occupies four bytes; misalignment does not inherently make the object itself consume more storage. Memory overhead generally appears when compilers insert padding to preserve alignment.

Exact alignment rules depend on the target architecture, ABI, compiler, and type. "An N-byte object always requires N-byte alignment" is not a universal rule.

## 5.4 Structure Padding

Under a simplified ABI where `uint8_t`, `uint16_t`, and `uint32_t` have alignments 1, 2, and 4:

```c
struct Example {
    uint8_t  a;
    uint32_t b;
};
```

can lay out as:

```text
offset 0  a
offset 1  padding
offset 2  padding
offset 3  padding
offset 4  b byte 0
offset 5  b byte 1
offset 6  b byte 2
offset 7  b byte 3
```

The internal padding ensures `b` begins at a 4-byte-aligned address.

Reversing the members:

```c
struct Example {
    uint32_t b;
    uint8_t  a;
};
```

can produce:

```text
offset 0–3  b
offset 4    a
offset 5–7  tail padding
```

The tail padding keeps the total structure size compatible with its alignment, so array elements can be placed back-to-back while each element remains correctly aligned.

## 5.5 Member Ordering and Memory Efficiency

Member order can materially change structure size.

Example:

```c
struct A {
    uint8_t  a;
    uint32_t b;
    uint16_t c;
};
```

may require 12 bytes, while:

```c
struct B {
    uint32_t b;
    uint16_t c;
    uint8_t  a;
};
```

may require only 8 bytes under the same alignment assumptions.

Across 10,000 instances, that difference is:

```text
12 × 10,000 = 120,000 bytes
 8 × 10,000 =  80,000 bytes
saved         = 40,000 bytes ≈ 39.1 KiB
```

A useful engineering heuristic is to consider ordering members from stricter alignment requirements toward weaker ones when layout is under your control and memory efficiency matters.

This is not a universal optimization law. Readability, logical grouping, ABI compatibility, hardware-defined layouts, protocol formats, cache behavior, and external interfaces can matter more.

## 5.6 Packed Structures Are Not a Free Optimization

A packed structure can remove padding, but it can also create misaligned members.

Conceptual packed layout:

```text
0x1000  uint8_t a
0x1001  uint32_t b begins
0x1002
0x1003
0x1004
```

The 32-bit member beginning at `0x1001` crosses a natural 4-byte boundary.

Depending on architecture/access type, this can mean slower access, multiple underlying transactions, special compiler-generated sequences, or a fault.

Therefore:

> First optimize layout while preserving normal alignment. Use packed layouts only for a specific reason and with a clear understanding of the target's access rules.

Legitimate uses can include externally specified binary formats, storage formats, protocol packets, or hardware-defined byte layouts.

## 5.7 Object Representation Versus Logical Value

The physical bytes associated with an object are its object representation. The logical program value is the meaning assigned to those bytes.

For:

```c
uint32_t x = 0x12345678;
```

on a little-endian machine:

```text
logical value          → 0x12345678
object size            → 4 bytes
raw memory             → 78 56 34 12
```

Memory itself does not know whether a bit pattern is signed, unsigned, floating point, or something else.

A debugging consequence is important:

> Correct bytes can still produce an incorrect application value if firmware interprets them using the wrong width, signedness, endianness, type, or external format.

Useful debugging checklist:

```text
Are the raw bytes correct?
Is the width correct?
Is signedness correct?
Is endianness correct?
Is the intended type/format correct?
```

## 5.8 Padding Bytes Are Not Logical Members

A structure's raw representation may include padding bytes that are not named logical members.

For:

```c
struct S {
    uint8_t  a;
    uint32_t b;
};
```

the physical representation may contain:

```text
a + padding + b
```

Assigning values to `a` and `b` does not, in general, imply that padding bytes become meaningful program state or must be maintained as zero.

The language/compiler has no need to perform extra writes solely to keep padding at a canonical value when those bytes are not part of the object's logical members.

This distinction explains why two structures can have the same logical member values while their raw byte representations differ in padding.

## 5.9 Why Raw `memcmp` Is Not General Struct Equality

Suppose two structures have identical logical members but different padding bytes.

A byte-wise comparison:

```c
memcmp(&s1, &s2, sizeof(struct S))
```

examines every byte in the object representation, including padding. It can therefore report a difference even when all meaningful members are equal.

For logical equality, compare the meaningful fields.

Even if a program deliberately initializes complete storage so padding initially happens to match, keep the concepts separate:

```text
logical equality
≠ definitionally the same thing as
raw byte-for-byte equality
```

If every compared byte is identical, `memcmp` will of course report equality, but C does not generally define structure equality in terms of padding or raw object representation.

## 5.10 Serialization and External Formats

Blindly transmitting a structure's in-memory bytes is fragile:

```c
write(uart, &msg, sizeof(msg));
```

Potential problems include:

- compiler-inserted padding,
- different ABI/layout rules,
- different native endianness,
- representation details that are not part of the protocol.

A robust wire/storage format defines its byte representation explicitly.

Example:

```text
bytes 0–1 → id, big-endian
bytes 2–5 → value, big-endian
```

The sender serializes logical fields into that format; the receiver deserializes from it. This decouples the protocol from both machines' native structure layouts.

If a little-endian sender transmits the raw bytes of `0x1234` as:

```text
34 12
```

a big-endian receiver that blindly interprets those bytes as a native 16-bit integer can read `0x3412`. The bytes did not become corrupted; they were interpreted under a different byte-order convention.

## 5.11 Section 5 Foundation Gate

Be able to reason naturally about:

- byte-addressed memory and inclusive object address ranges
- multi-byte object representation
- little-endian versus big-endian byte ordering
- why endian order affects bytes, not bit order inside each byte
- size versus alignment
- power-of-two alignment and low address bits
- aligned versus misaligned accesses
- why a misaligned access can cross natural memory blocks
- implementation/ABI dependence of exact alignment requirements
- internal padding versus tail padding
- why arrays motivate tail padding
- member-order effects on structure size
- why packed structures can trade memory for access cost/restrictions
- logical value versus raw object representation
- same bits under different signed/type interpretations
- padding bytes as non-logical state
- why raw `memcmp` is not general logical struct equality
- why external formats should define byte order and layout explicitly
- why raw struct transmission is not a robust general serialization strategy

The short cumulative Sections 1–5 test revalidated MMIO/base-plus-offset reasoning, register-field replacement, integer flags, alignment/block-boundary reasoning, structure padding, and raw-object comparison. A carry-versus-signed-overflow distinction from Section 4 had a minor slip and is intentionally left for a later unannounced retention check rather than immediate repetition.

**Status: ✅ Foundation established.** Exact C object-model semantics, pointer behavior, structure access, and language-level representation rules will deepen in Sections 6–7; exact Cortex-M misalignment/access behavior will deepen in Phase 2.

---

## Consolidation Basis for Sections 6–8

Consolidated 2026-10-11 from the recorded coverage, demonstrated reasoning, and assessment checkpoints in [Concepts Progress](Concepts/Progress.md), [Mastery Ledger](Concepts/Mastery-Ledger.md), and [Revision Queue](Concepts/Revision-Queue.md), plus the available Q15 conversation answer.

These are durable explanatory notes in the same reference format as Sections 1–5. They are not a recovered verbatim transcript. Illustrative examples clarify recorded topics; they do not claim additional learner submissions, hardware experiments, or mastery. Exact missing assessment questions and undocumented observations have not been reconstructed.

Language reference for follow-up: [WG14 C11 draft N1570](https://www.open-std.org/jtc1/sc22/wg14/www/docs/n1570.pdf), particularly its clauses on lifetime, conversions, expressions, declarators, qualifiers, and object access. Implementation-specific volatile behavior is discussed in [GCC's documentation](https://gcc.gnu.org/onlinedocs/gcc/Volatiles.html). The notes use the C11/C17 learning model and explicitly stated STM32 assumptions; MMIO and ISR guarantees require the actual target/compiler contract.

---

# Phase 1 — Section 6: C Memory & Pointer Foundations

> **Status: ✅ Completed — current conceptual-validation pass (2026-09-28)**

## Interview Refresh

A pointer is an object that stores a pointer value. Its type tells C what object type an access expects and how pointer arithmetic scales. The pointer's own storage, its stored value, and the pointed-to object are three different things.

```text
&p → location of pointer object p
 p → stored pointer value
*p → object designated by that value, if the access is valid
```

An address that looks plausible is not sufficient for a valid dereference. Check lifetime, bounds, alignment, permitted access type, and—for MMIO—the target's access contract.

Pointer arithmetic is in elements. Byte offsets require a byte-oriented view. Arrays are objects, not pointer variables; their conversion to a pointer in many expressions does not erase the distinction.

A cast changes an expression's type. It does not allocate storage, extend lifetime, fix alignment, or create an object of the destination type.

## 6.1 Pointer Objects, Values, and Dereference

```c
uint32_t value = 10;
uint32_t *p = &value;
uint32_t *q = p;

*q = 20;            /* value is now 20 */
q = NULL;           /* changes q, not p or value */
```

Copying a pointer copies the pointer value, not the object it designates. Both pointers initially designate the same object, so writes through either affect that object. Reassigning one pointer does not reassign the other.

A pointer type carries an access interpretation. On a typical STM32 ABI, a pointer to an 8-bit object and a pointer to a 32-bit object have the same pointer storage size, but their dereferences and arithmetic differ. Pointer size is a target/ABI property; do not infer it from the pointee size.

```text
sizeof(p)  → size of pointer object
sizeof(*p) → size of uint32_t object
```

For a non-VLA type, `sizeof(*p)` does not evaluate the dereference. That fact does not make an actual `*p` access valid when p is NULL.

## 6.2 Typed Pointer Arithmetic and Byte Offsets

```c
uint32_t arr[5] = {10, 20, 30, 40, 50};
uint32_t *p = &arr[1];
uint32_t *q = p + 2;       /* &arr[3], not address + 2 bytes */
```

Under the STM32 assumption of 8-bit bytes and four-byte uint32_t:

```text
arr base       = 0x20000000
&arr[1]        = 0x20000004
&arr[3]        = 0x2000000C
element offset = 2
byte offset    = 8
```

These illustrative addresses describe placement, not a license to perform arbitrary integer-address arithmetic in portable C.

For byte inspection within an object's representation:

```c
unsigned char *bytes = (unsigned char *)&arr;
unsigned char third_byte = bytes[2];
```

Character-type access is specifically permitted to inspect object representation. It is not permitted merely because a processor can load one byte.

A common firmware mistake is adding a register offset in bytes to a `uint32_t *`: adding 4 advances four uint32_t elements, typically 16 bytes. Establish the unit of each offset before forming an MMIO address; target-defined integer base-plus-byte-offset conventions are different from ordinary array pointer arithmetic.

## 6.3 Pointer Subtraction and Comparison

The recorded Section 6 example:

```c
uint32_t arr[5];
uint32_t *p1 = &arr[1];
uint32_t *p2 = &arr[4];

ptrdiff_t forward = p2 - p1;  /*  3 elements */
ptrdiff_t reverse = p1 - p2;  /* -3 elements */
```

Use `<stddef.h>` for `ptrdiff_t`. Subtraction is defined in the appropriate same-array domain, including its one-past position, and the result must fit in ptrdiff_t. It is not a portable way to subtract unrelated allocation addresses.

Within the same array, relational comparison can express position:

```c
bool earlier = p1 < p2;  /* true; include <stdbool.h> */
```

Numeric address ordering alone does not justify ordering unrelated objects in portable C. Equality comparisons are useful for NULL checks and identity, but equality and relational ordering have different rules.

## 6.4 One-Past and Bounds

```c
uint32_t arr[5];
uint32_t *begin = arr;
uint32_t *end = arr + 5;     /* legal one-past value */

for (uint32_t *p = begin; p != end; ++p) {
    *p = 0;
}
```

One-past is a range boundary, not an element. `*end` is invalid; forming `arr + 6` is already outside the allowed arithmetic range even without dereferencing it.

A useful checking order is:

```text
validate index / length
        ↓
form an in-range pointer
        ↓
perform the access
```

An address can fall inside mapped SRAM and still be outside the C object being accessed. Hardware accessibility and C bounds are separate checks.

## 6.5 Arrays, Conversion, and sizeof

```c
uint32_t arr[5];
uint32_t *p = arr;
```

In most expressions, arr converts to a pointer to its first element. The array itself still contains five objects.

```text
sizeof(arr) → 5 × sizeof(uint32_t)
sizeof(p)   → sizeof(uint32_t *)
```

The common array-length expression works where the actual array type is available:

```c
size_t count = sizeof(arr) / sizeof(arr[0]);
```

An array parameter is adjusted to a pointer parameter:

```c
void clear_values(uint32_t arr[], size_t count);
```

Inside this function, `sizeof(arr)` is pointer size. Pass the length separately or design an interface that preserves the required shape. A pointer does not carry a general runtime array length.

Arrays do not support whole-array assignment; structures containing arrays can be assigned as structures.

## 6.6 arr Versus &arr

```c
uint32_t arr[5];
uint32_t *element = arr;
uint32_t (*whole)[5] = &arr;
```

These can begin at the same storage location while having different types:

```text
arr, after conversion → uint32_t *
&arr                  → uint32_t (*)[5]

element + 1 → next uint32_t
whole + 1   → one-past the entire five-element array
```

Do not decide that two expressions are interchangeable merely because a debugger prints the same address. Type controls stride and valid use.

`*whole` is an array lvalue. It converts to a pointer to its first element in many ordinary expressions, but `sizeof(*whole)` measures the whole array. This is the array-lvalue versus conversion distinction retained in the revision queue.

## 6.7 Multidimensional Arrays and Row Stride

```c
uint32_t grid[2][3];
uint32_t (*row)[3] = grid;

row[1][2] = 99;    /* grid[1][2] */
```

grid is an array of two row arrays; each row contains three uint32_t objects. Its ordinary conversion produces a pointer to a row, not uint32_t **.

Under the four-byte-element assumption:

```text
row size                  = 3 × 4 = 12 bytes
grid[1][2] byte placement  = (1 × 3 + 2) × 4 = 20 bytes from grid base
row + 1                   = next row, 12 bytes later
```

That offset explains physical layout. Preserve the row type for C indexing rather than assuming a pointer into one inner array permits traversal beyond its bounds.

```c
void process_rows(uint32_t (*rows)[3], size_t row_count);
/* Equivalent adjusted parameter spelling: uint32_t rows[][3] */
```

A uint32_t ** expects pointers to uint32_t, typically a table of row pointers. A true 2D array stores row elements directly. Casting one representation to the other does not create a pointer table.

## 6.8 Pointer-to-Pointer and Changing the Caller

```c
void redirect(uint32_t **out, uint32_t *target)
{
    *out = target;
}

uint32_t a = 1;
uint32_t b = 2;
uint32_t *p = &a;
redirect(&p, &b);     /* p now designates b */
```

Parameters are passed by value. Passing p alone gives the callee a copy of p; passing &p lets it access the caller's pointer object.

```text
uint32_t *  → can designate a uint32_t
uint32_t ** → can designate a uint32_t * object
```

Additional indirection means additional objects and access steps. It does not by itself mean a multidimensional contiguous array.

## 6.9 const Combinations

| Declaration | Can reassign pointer? | Can modify pointee through it? |
|---|---|---|
| `uint32_t *p` | Yes | Yes |
| `const uint32_t *p` | Yes | No |
| `uint32_t * const p = &x` | No | Yes |
| `const uint32_t * const p = &x` | No | No |

Const on an access path does not prove every alias is read-only:

```c
uint32_t x = 1;
const uint32_t *view = &x;
x = 2;              /* valid: underlying object is not const */
```

Conversely, casting away const does not permit modification of an object actually defined const. Pointer-to-pointer qualification is also stricter than adding const to a simple pointee: uint32_t ** cannot simply be treated as const uint32_t **.

## 6.10 Object Lifetime, NULL, and Dangling Pointers

| Storage/lifetime | Useful model |
|---|---|
| Automatic local | Lives during its block execution; returning its address does not extend lifetime |
| Static storage | Lives for program execution; persistent lifetime does not imply synchronization |
| Allocated storage | Lives until released; ownership must determine who may free/reuse it |

Returning a pointer to an automatic local creates a lifetime bug. The old bytes might still appear intact, but a later function can reuse the storage.

A null pointer designates no object or function. It is a language-level null value; do not equate that with a universal physical all-zero representation or safe access to address zero.

An uninitialized pointer has no valid established target. A dangling pointer refers to an object whose lifetime has ended. Neither is repaired by the fact that a debugger still displays a plausible address.

After free, all aliases lose the right to access the released allocation. Setting one variable to NULL does not repair other aliases, and a second free is invalid. In firmware, DMA retaining a pointer to a local or reused buffer can produce delayed corruption; this remains lifecycle reinforcement, not completed DMA implementation evidence.

## 6.11 void Pointers and API Contracts

In C, a void * can represent a generic object pointer and be converted back to a suitable object pointer type. It does not carry the object's size, type, ownership, or lifetime.

```c
void consume_bytes(const void *data, size_t length);
```

The API still needs a contract: length unit, valid access range, whether data is copied or retained, mutability, and lifetime through completion.

Dereferencing void * and arithmetic on void * are not ISO C operations. Some compilers support arithmetic as an extension; do not make an ordinary portable interface depend on it. Function pointers are a separate category from generic object pointers.

## 6.12 Casts, Alignment, and Strict Aliasing

For a typed dereference, ask:

```text
Does an object with a valid lifetime exist here?
Is the access within its bounds?
Is the address suitably aligned?
Is access through this type permitted?
```

A cast answers none of those questions by itself. For example, casting a byte buffer to uint32_t * can introduce alignment and access-type problems as well as endian dependence.

For copying representation, use an appropriate byte copy:

```c
uint32_t bits;
float f = 1.0f;
_Static_assert(sizeof(bits) == sizeof(f), "example requires equal sizes");
memcpy(&bits, &f, sizeof(bits));  /* include <string.h> */
```

This avoids incompatible typed dereference. It still does not establish a universally portable floating-point wire format; float representation is a separate assumption.

For a declared object, its declared type matters. Storage obtained without a declared type has additional effective-type rules. Keep this distinction available for later allocator and optimizer reasoning.

## 6.13 Structures, Padding, and Field Access

```c
struct Sample {
    uint8_t id;
    uint32_t value;
};

struct Sample sample;
struct Sample *p = &sample;
p->value = 42;       /* equivalent member access: (*p).value */
```

Under a common 1/4-byte alignment ABI, value can begin at offset 4 and the structure can occupy 8 bytes. Verify actual layout with sizeof, _Alignof, and offsetof rather than assuming that sum-of-member-sizes is the structure size.

Structure assignment copies logical structure values; padding is not a field-level equality contract. Field comparisons are appropriate for logical equality. Raw struct persistence/transmission inherits padding, ABI, and endian assumptions; Section 7 consolidates the serialization consequence.

## 6.14 Integer Addresses, uintptr_t, and MMIO

uintptr_t, when provided, supports the specified void-pointer/integer round trip. It is optional and does not make arbitrary integers valid pointer values. Storing an address in a narrower integer can lose information.

MMIO uses implementation-defined target/compiler conventions:

```c
/* Illustrative target-specific register address, not a runnable board mapping. */
volatile uint32_t * const reg =
    (volatile uint32_t *)(uintptr_t)0x40000000u;
```

Dereferencing reg requests an access; the memory map determines which hardware responds. Volatile does not make the address mapped, the access width legal, or the register safe to read/write. Check clock/reset state and side effects against the target reference manual.

## 6.15 Function Pointers and Callbacks

```c
typedef void (*handler_t)(uint32_t event);

void on_event(uint32_t event);
handler_t handler = on_event;
handler(7);
```

The declaration describes the callback's return and parameter types. Call through a compatible function type; a cast cannot safely repair a mismatched signature.

A callback API also needs ownership/lifetime rules for any context pointer and a defined execution context. A function pointer stored in corrupted data can turn a data bug into control-flow failure.

## 6.16 Pointer Debugging and Delayed Failures

Choose a watchpoint based on what is changing:

```text
p unexpectedly changes       → watch the pointer object p
*p unexpectedly changes      → watch the designated data
valid p gives bad content    → inspect lifetime, producer, size, and interpretation
```

An out-of-bounds write can corrupt adjacent data or saved return state without faulting at the write. The eventual fault may occur when the corrupted state is consumed. A mapped address is not a proof of valid object access.

Useful failure analysis:

1. Inspect the pointer value, expected target, and containing object.
2. Reconstruct index, element stride, and byte offset.
3. Check whether the target is live and whether storage was reused.
4. Check width, alignment, and access type.
5. Find the earliest incorrect write with a watchpoint where possible.
6. Connect the eventual fault back to corruption rather than treating the fault site as the origin.

## 6.17 Section 6 Foundation Gate and Retention

Be able to explain pointer storage versus target storage; element scaling versus byte offsets; same-array subtraction and ptrdiff_t; one-past boundaries; arrays versus pointers; arr versus &arr; row stride; 2D arrays versus pointer tables; pointer-to-pointer APIs; const placement; lifetime/ownership; generic pointers; casts/alignment/aliasing; MMIO access; callbacks; and delayed-corruption debugging.

Recorded validation: 20 hard Section 6-only questions and 20 hard integrated Sections 1–6 questions completed. Completion is for this pass, not permanent mastery.

Keep reinforcing strict-aliasing rationale, array-lvalue/conversion wording, byte offsets, pointer-domain rules, W1C behavior, and DMA/cache visibility distinctions. Current evidence and open targets remain in [Mastery Ledger](Concepts/Mastery-Ledger.md) and [Revision Queue](Concepts/Revision-Queue.md).

---

# Phase 1 — Section 7: Embedded-C Semantics

> **Status: ✅ Completed — current conceptual-validation pass (2026-10-03)**

## Interview Refresh

C expressions have language rules before they become instructions. Hardware behavior does not override signed-overflow UB, invalid shifts, lifetime rules, or incompatible typed access.

For integer expressions, reason in stages:

```text
operand types
      ↓
integer promotions
      ↓
usual arithmetic conversions, where applicable
      ↓
operation in resulting type
      ↓
conversion to destination type
```

Volatile describes compiler-visible access semantics. Const restricts modification through an access path. Neither is a general synchronization primitive.

For MMIO, the register contract matters as much as the C expression: width, readable/writable fields, W1C/read-to-clear effects, reserved bits, and concurrency determine whether an access is appropriate.

## 7.1 volatile and Observable Accesses

A peripheral, ISR, or other external agent can change data independently of the ordinary execution path being optimized. Volatile-qualified access tells the implementation to treat accesses according to its volatile contract.

```c
volatile uint32_t *status = /* target-defined status address */;
uint32_t first = *status;
uint32_t second = *status;
```

These are distinct volatile access expressions. Do not casually assume the compiler may replace the second read with first. What constitutes a volatile access and its mapping to machine transactions depends on the implementation.

A repeated read can also be undesirable if hardware changes between reads or reading has a side effect:

```c
uint32_t snapshot = *status;
/* Derive several decisions from this one documented snapshot. */
```

Use a snapshot when a coherent single sample is intended. Use repeated reads when fresh accesses are required. This is a semantic choice, not merely a performance choice.

Volatile does not guarantee:

- an atomic multi-step operation;
- mutual exclusion or thread safety;
- ordering of unrelated ordinary memory accesses;
- fresh data from a cache-coherent DMA buffer;
- a valid address or permitted register operation.

[GCC's volatile documentation](https://gcc.gnu.org/onlinedocs/gcc/Volatiles.html) specifically distinguishes volatile accesses from ordering ordinary memory. Inspect target/compiler rules when making a low-level guarantee.

## 7.2 const, const volatile, and Underlying Objects

```c
volatile const uint32_t *status = /* hardware-updated read-only register */;
```

Through this pointer, software may read with volatile semantics and may not assign to the pointed-to object. Hardware may still update the register.

Compare:

```c
uint32_t x = 1;
const uint32_t *view = &x;
x = 2;                       /* underlying x is mutable */

const uint32_t immutable = 1;
/* Modifying immutable through a cast-away-const pointer is UB. */
```

Const is not synonymous with Flash placement, compile-time evaluation, or hardware immutability. Placement and hardware effects are separate implementation/target properties.

For pointer declarations, distinguish the pointee qualifier from the pointer qualifier:

```c
volatile uint32_t * const reg = /* fixed pointer to volatile register */;
```

reg cannot be reassigned; the register can be accessed through it.

## 7.3 Widths, CHAR_BIT, and Fixed-Width Types

sizeof counts C bytes. CHAR_BIT from <limits.h> describes bits per byte. STM32 examples normally assume CHAR_BIT == 8; make that explicit when discussing octets on a wire.

Exact-width types such as uint32_t are provided where a suitable exact-width type exists. They express representation intent; they do not override promotions in an expression.

```text
C type width          → language representation
CPU instruction width → generated access/operation
register width        → hardware access contract
implemented bits      → fields meaningful within register
```

A register with only eight meaningful bits can still require a 32-bit access. Do not substitute uint8_t access solely because the field fits in eight bits.

Use size_t for sizes and lengths, ptrdiff_t for pointer differences, and suitable fixed-width types for explicit external numeric fields. Signedness must match the intended domain, not merely the available storage width.

## 7.4 Integer Promotions Before Arithmetic

On a target with 32-bit int that can represent every uint8_t and uint16_t value:

```c
uint8_t a = 250;
uint8_t b = 10;
int sum = a + b;      /* both promote to int; sum is 260 */
uint8_t small = a + b;/* int result 260 converts to uint8_t: 4 */
```

The addition did not overflow in eight bits. The narrowing conversion produced 4.

Likewise, ~ on a uint8_t first operates on its promoted type. If an eight-bit complement is intended, explicitly convert the result back to uint8_t and understand the target's integer representation.

Promotion depends on whether int can represent the source type's full range; otherwise the applicable promotion is to unsigned int. Avoid memorizing the final result while skipping the type path.

## 7.5 Mixed Signed/Unsigned Expressions

Under the common 32-bit int/unsigned int model:

```c
int s = -1;
unsigned int u = 1;
bool less = s < u;    /* false: s converts to unsigned int */
```

The comparison operates on a common type. It does not first compare mathematical -1 and 1 and then convert the answer.

For mixed types of different ranks, do not assume that unsigned always wins. Rank and representable ranges determine the common type.

A boundary example is a negative index compared with an unsigned length. Validate negativity before converting:

```c
bool valid_index(int index, size_t count)
{
    return index >= 0 && (size_t)index < count;
}
```

This is useful where nonnegative int values fit size_t, as on the intended STM32 environment. Short-circuiting prevents the second test when index is negative.

Keep the operation type separate from the destination type. Assignment to a wider destination does not retroactively widen an already evaluated narrow operation.

## 7.6 Unsigned Wrap Versus Signed Overflow

Unsigned arithmetic uses modulo arithmetic in its unsigned result type. Signed arithmetic that produces a result outside its representable range has undefined behavior under the C11/C17 model used in these notes.

```c
uint32_t u = UINT32_MAX;
u += 1u;                /* 0 on the intended 32-bit arithmetic model */
```

Do not detect signed overflow by computing the overflowing result first. The optimizer can reason under the assumption that defined execution did not overflow.

For signed int addition, establish preconditions:

```c
bool add_int(int a, int b, int *out)
{
    if ((b > 0 && a > INT_MAX - b) ||
        (b < 0 && a < INT_MIN - b)) {
        return false;
    }
    *out = a + b;
    return true;
}
```

Include <limits.h> and <stdbool.h>; out must designate a writable int on success. The guarded expressions avoid overflowing before the check.

This is a nearby reference example for the retained signed-arithmetic target, not a claim that this exact function was submitted during assessment. Wider intermediate types work only if the widened calculation itself is guaranteed representable.

## 7.7 Undefined, Implementation-Defined, and Unspecified Behavior

| Category | Meaning | Studied example |
|---|---|---|
| Defined | Language rules establish the relevant outcome | Unsigned modulo arithmetic |
| Implementation-defined | Implementation chooses and documents behavior | Negative signed right shift in C11/C17; some integer/pointer conversions |
| Unspecified | Several allowed choices; documentation of the choice is not required | Order of evaluating independent function arguments |
| Undefined | Language imposes no requirements for that execution | Signed overflow, invalid dereference, unsequenced conflicting scalar accesses |

Different unspecified evaluation orders are not automatically UB. UB arises when the operation violates a language rule, such as conflicting unsequenced accesses.

These notes use the C11/C17 model reflected in the learning records. Check language-version and compiler documentation rather than assuming every version defines signed representation, conversions, and shifts identically.

## 7.8 Shifts and Field Masks

Shift operands undergo integer promotions. The shift count must be nonnegative and less than the width of the promoted left operand.

```c
1u << 32    /* UB when unsigned int is 32 bits */
```

Unsigned wraparound does not make that shift legal. Signed left shift requires additional operand/representability conditions; prefer deliberate unsigned types for masks.

For an illustrative two-bit field at bits 5:4 of an ordinary read/write snapshot:

```c
uint32_t field_mask = UINT32_C(3) << 4;
uint32_t value = 2;              /* validate value <= 3 */
uint32_t next = (old & ~field_mask) | (value << 4);
```

Clearing the field before inserting its replacement differs from simply OR-ing in new bits. The latter cannot clear a bit left over from the previous value.

This expression does not establish that a real register can safely be read-modify-written. Its hardware contract and competing writers still matter. If the original MODE already meets the requirement, identify that before proposing an unnecessary change—the retained Q12 correction reflects precisely this grading issue.

## 7.9 MMIO Read-Modify-Write Hazards

```c
*reg |= mask;
```

Conceptually:

```text
read register
      ↓
compute old | mask
      ↓
write result
```

Potential hazards include a competing update between read and write, read side effects, write side effects, and fields that must not be echoed back.

A volatile qualifier preserves the relevant accesses; it does not turn them into one indivisible transaction. Where provided, documented set/clear registers can implement specific field changes without a software read-modify-write of the data register.

Register debugging should distinguish a wrong expression from a correct expression applied to the wrong register semantics.

## 7.10 W1C and Read-to-Clear

For write-one-to-clear flags:

```text
write 1 → clear corresponding flag
write 0 → leave corresponding flag unchanged
```

Recorded revision example:

```text
read status                  = 00001010
desired clear bit            = 00001000
read value OR desired mask   = 00001010
write back to W1C            → clears BOTH bit 3 and bit 1
```

For a dedicated W1C register whose contract permits it, write the intended clear mask directly. Mixed-function registers may require a more specific documented write procedure.

A read-to-clear register changes state when read. Repeated polling, logging, or a debugger memory window can consume evidence. Preserve a suitable snapshot and understand the documented side effect before observing it.

This is why “I only read it” is not sufficient to conclude that software or the debugger had no effect.

## 7.11 Sequencing and Short-Circuit Guards

```c
if (p != NULL && p->ready) {
    /* dereference evaluated only after the NULL test succeeds */
}
```

&& and || evaluate their left operand first and conditionally evaluate the right. Use this ordering for valid guards.

Independent function arguments do not have a general left-to-right evaluation guarantee in C:

```c
consume(read_a(), read_b());  /* do not rely on which read happens first */
```

If hardware accesses must happen in a specific order, separate them into explicitly sequenced steps.

Expressions such as `i++ + i++` have unsequenced modifications of the same scalar and are UB in this C model. Split state changes into clear statements; apparent behavior in one build is not a contract.

## 7.12 Object Representation, Aliasing, and Bit Copies

Section 6's pointer-access checks still apply. Accessing a float through uint32_t * does not become valid simply because both objects occupy four bytes.

Character-type access can inspect an object's representation. memcpy can copy representation into an appropriately sized destination without an incompatible typed dereference. Neither operation independently defines the semantic meaning of an external packet.

Separate these questions:

```text
Can I inspect/copy these bytes legally?
What logical value do those bytes represent?
What representation does the external format require?
```

The remaining strict-aliasing refinement is the language's character-type permission, not a simplistic explanation about moving one byte at a time.

## 7.13 Portable Serialization and Padding

A structure is a logical collection of members with ABI-selected placement. A wire message is an externally defined byte contract.

For an example contract of a two-octet unsigned value in big-endian order, with CHAR_BIT == 8:

```c
void encode_u16_be(uint8_t out[2], uint16_t value)
{
    out[0] = (uint8_t)(value >> 8);
    out[1] = (uint8_t)value;
}

uint16_t decode_u16_be(const uint8_t in[2])
{
    return (uint16_t)(((uint32_t)in[0] << 8) | (uint32_t)in[1]);
}
```

The casts before the shift make the calculation's width/sign intent explicit. The caller must provide at least two valid elements.

For value 0x1234, the defined message is 12 34 regardless of sender-native byte order.

Raw transmission of sizeof(struct Message) can expose padding, change when ABI/member order changes, and use native endian order. A packed attribute does not by itself solve endian order, type representation, bounds, or unaligned typed access.

Compare meaningful fields for logical equality. Define widths, offsets, signed encoding, byte order, length validation, and versioning where needed for external formats.

## 7.14 Bit-Fields and Register Layout

Bit-fields can provide compact language-level members, but allocation order, storage details, and some access behavior depend on the implementation. Do not assume a C bit-field declaration is a portable hardware or wire map.

For MMIO, the generated access width and read-modify-write behavior can matter. Masks/shifts applied under the documented register contract often make those assumptions clearer. Compiler-specific bit-field mappings require an explicit target contract and verification.

## 7.15 Optimization-Sensitive Failure Analysis

When debug and optimized builds differ, investigate lifetime violations, uninitialized state, aliasing, bounds, sequencing, and signed arithmetic before concluding that the compiler is broken.

Useful questions:

- Did the operation have defined language semantics?
- Were the required external accesses represented through the right qualifiers/interface?
- Was the read-modify-write vulnerable to a competing writer?
- Did the code confuse CPU cache state with compiler access preservation?
- Does generated assembly perform the expected width and number of accesses?

Compiler inspection is evidence for a particular build. It cannot turn an undefined source operation into a portable guarantee.

## 7.16 Section 7 Foundation Gate and Retention

Be able to separate volatile, const, atomicity, synchronization, and cache coherency; trace promotions and common-type selection; distinguish operation overflow from destination conversion; check shifts; classify behavior; reason about MMIO/W1C/read side effects; use sequencing guards; and define portable serialization independently of struct layout.

Recorded validation: 15 integrated Section 7 questions completed. Current capability is practiced conceptual reasoning, with remaining refinement recorded in the canonical ledger.

Signed arithmetic/conversions and portable serialization/padding remain active reinforcement after the later Sections 1–8 cumulative assessment. Preserve the complete promotion path and demonstrate real-peripheral W1C transfer later. Completion is for this pass, not permanent mastery.

---

# Phase 1 — Section 8: Concurrency Foundations

> **Status: ✅ Completed — current conceptual-validation pass (checkpoint recorded 2026-10-11)**

## Interview Refresh

Concurrency means multiple execution contexts or agents can affect shared state. They need not execute simultaneously: an interrupt can interleave with main on a single CPU.

The central questions are:

```text
Who writes each object?
Who reads it?
Which operations must be indivisible?
When is the payload valid?
What publishes that validity?
What happens if the consumer falls behind?
```

A source statement is not necessarily an atomic operation. Volatile does not provide ownership, mutual exclusion, cache coherence, or a general publication-order guarantee.

A queue preserves events only within its capacity and overflow policy. A latest-value mailbox serves a different requirement: preserve freshness rather than every intermediate sample.

## 8.1 Interleaving on One CPU

Consider main and an ISR both incrementing a counter. A conceptual interleaving is:

```text
counter initially 10

main: read 10
interrupt:
    ISR: read 10
    ISR: add 1
    ISR: write 11
main resumes:
    main: add 1 to its old value
    main: write 11

two increments requested; final counter is 11, not 12
```

Each individual read or write may be indivisible on a given target while the combined increment is not. A shared read-modify-write can lose an update even with a volatile counter.

Real timing bugs often disappear under stepping because observation changes the interleaving. Reason about all permitted interleavings rather than only one observed execution.

## 8.2 Atomicity Depends on the Operation

```text
single access atomic?
      ≠
read + compute + write atomic?
      ≠
several related fields updated atomically?
```

For an MCU access, width, alignment, instruction selection, memory region, and target rules affect whether another participant can observe a torn value.

A wide counter accessed through several smaller instructions can produce a mixed snapshot. Reading two individually atomic fields also does not establish that the pair comes from the same logical update.

Define the invariant first. “This variable is 32-bit” does not prove every operation on it is safe.

## 8.3 Shared-State Ownership

Document ownership at object granularity:

| Shared object | Writer | Reader | What must be established |
|---|---|---|---|
| SPSC head | Producer | Consumer | Valid publication of initialized payload |
| SPSC tail | Consumer | Producer | Slot released only after consumption |
| Queue slot | Producer while free; consumer while occupied | Depends on ownership phase | No premature reuse |
| Drop counter | Assigned owner or protected writers | Monitoring code | Correct update/snapshot semantics |

A single writer removes competing writes to that object. Readers can still race with the writer unless accesses and ordering follow a valid implementation contract.

“Both contexts write different variables” is useful ownership evidence; it is not a complete portable synchronization proof for the whole shared structure.

## 8.4 Critical Sections and Their Limits

For a single-core main/ISR shared operation, temporarily excluding the relevant interrupt can prevent that ISR from interleaving with the operation.

```text
save relevant interrupt state
      ↓
exclude relevant ISR
      ↓
perform minimal protected operation
      ↓
restore prior state
```

Restore the prior state rather than unconditionally enabling interrupts, which could violate an enclosing critical section.

A critical section must be short and have a clear scope. Delaying interrupt service can affect latency and overflow elsewhere. Avoid slow I/O or waiting for an event that requires the excluded interrupt.

Disabling interrupts on one core does not stop DMA, another core, or every possible execution context. Exact masking, barriers, and interrupt architecture belong in later formal sections. The reference lesson here is to match the protection mechanism to the actual competing agent.

## 8.5 Flags, Check-and-Clear, and Event Loss

A flag answers “has something happened?” but cannot represent an arbitrary count of events.

```text
event sets flag
another event sets already-set flag
consumer reads flag once
      → cannot distinguish one event from two
```

A check followed by a later clear can also discard an intervening event:

```text
main sees flag set
ISR sets flag for another event
main clears flag
      → new event indication lost
```

Decide whether the requirement is a Boolean condition, a count, latest state, or a sequence of payloads. Then choose an appropriately protected snapshot/consume operation or a queue.

The flag and payload must be treated as a protocol: when does a flag publish valid data, and when may the producer overwrite it? A volatile flag alone does not answer those questions.

## 8.6 Producer/Consumer Rates and Queue Growth

Let producer rate be lambda and consumer service rate be mu:

```text
lambda > mu over sustained operation → backlog grows until finite capacity fills
lambda < mu on average              → bursts can still fill a queue
```

A finite buffer absorbs temporary rate mismatch; it does not fix a permanently slower consumer.

For a pause of T seconds with no consumption, incoming demand is approximately lambda × T samples. Allow for existing occupancy, bursts, service variability, and capacity actually usable by the chosen implementation.

Illustrative sizing exercise, not a recorded board measurement:

```text
producer:         100 samples/second
consumer pause:   0.2 second
arrivals in pause: 20 samples

N = 16, reserved-slot ring → usable capacity 15
empty ring still cannot retain all 20 arrivals
```

Measure or bound worst-case delay rather than sizing only from average throughput. Define what happens when the bound is exceeded.

## 8.7 State the Ring-Buffer Convention First

For the convention used in the Q15 consolidation:

```text
head → next producer write position
tail → next consumer read position
N    → total storage slots, N >= 2

advance(i) = (i + 1) modulo N
empty      = head == tail
full       = advance(head) == tail
capacity   = N - 1
```

One slot is reserved to distinguish full from empty without another full-state flag or count.

For N = 4:

```text
head=0, tail=0 → empty
produce at 0; head=1
produce at 1; head=2
produce at 2; head=3
advance(head)=0 equals tail → full, 3 occupied slots
```

These formulas are convention-dependent. A scheme using counts, full flags, monotonically increasing counters, or “head names last written slot” has different details.

Q13 was credited 4/4 because the head-index convention was not specified. Declare the convention before grading an index calculation.

## 8.8 Payload Before Publication

The producer must initialize the slot before making it visible as occupied:

```text
producer obtains free slot
      ↓
write complete payload
      ↓
publish new head
```

Publishing head first can tell the consumer data is available while the slot still contains old or incomplete data. If the code also uses the already-advanced head to select the slot, it may write the wrong slot under the stated convention.

Consumption follows the complementary lifecycle:

```text
observe occupied slot
      ↓
read/copy complete payload
      ↓
publish new tail, releasing slot
```

Advancing tail before the read is complete can allow premature producer reuse.

This is a required logical order. Source order alone is not a universal compiler/CPU synchronization mechanism. A real implementation must establish the relevant atomic access and visibility/order guarantees using the target's ISR contract or an appropriate language/platform mechanism.

Detailed acquire/release, barriers, multicore coherence, and DMA maintenance are later topics; this section preserves the invariant without claiming those mechanisms were implemented.

## 8.9 Q15 Producer/Consumer Walkthrough

The following is algorithm pseudocode that explains the assessed model. It is not ready-to-use portable concurrent C or a board lab solution.

```text
ISR producer(sample):
    next = advance(head)
    if next == tail:
        record/drop incoming sample
        return FULL
    slot[head] = sample
    publish head = next
    return ACCEPTED

main consumer:
    if tail == head:
        return EMPTY
    sample = slot[tail]
    publish tail = advance(tail)
    process local sample
```

Assumptions to check before implementation:

- Exactly one producer and one consumer; producer cannot reenter concurrently.
- Producer writes head, consumer writes tail.
- Shared index accesses cannot tear under the target contract.
- Payload visibility precedes head publication.
- Consumption completes before slot release through tail.
- Slot objects remain live; indices remain in range.
- The selected overflow policy preserves these ownership rules.

Processing a copied local sample after releasing the slot can keep queue occupancy lower. A consumer that retains a pointer into a released slot instead of copying needs a different ownership/lifetime contract.

## 8.10 Drop-Newest Versus Drop-Oldest

| Policy | When full | Requirement/tradeoff |
|---|---|---|
| Drop newest | Reject incoming sample; preserve queued samples | Simple reserved-slot SPSC ownership; retained backlog may become stale |
| Drop oldest | Discard oldest retained sample to admit new one | Favors freshness; requires safe coordination of tail/slot ownership |
| Backpressure | Slow or pause producer if supported | Only possible where source/protocol permits it |
| Latest-value mailbox | Replace stored state with current sample | Does not preserve every intermediate event |

Q15 assessed **drop-newest**. When full, the ISR can execute, but it discards the incoming sample until capacity is released.

An earlier temperature-telemetry discussion proposed drop-oldest. In the basic SPSC ring above, producer-side tail advancement would give tail two writers. It can conflict with a consumer that is reading the oldest slot. Do not turn drop-newest into drop-oldest by casually advancing tail; design and validate the altered protocol.

Policy selection starts with the requirement. A command/event log can value completeness/order, while temperature telemetry may value latest state. Neither policy is universally best.

## 8.11 What Happens While Main Is Delayed?

If main stops consuming but interrupts remain enabled, the ISR can continue accepting samples while free slots remain. Once full, drop-newest rejects further arrivals.

```text
main delayed
      ↓
ISR still executes
      ↓
occupancy grows
      ↓
queue full
      ↓
new samples discarded until main releases capacity
```

“Main is busy” and “interrupts are disabled” are different situations. If interrupts are excluded, peripheral hardware may accumulate or lose events according to its own FIFO/status behavior; that is a separate boundary from software queue capacity.

Q15's 5/5 evidence includes recognizing this distinction.

## 8.12 DMA Lifecycle and Cache Visibility: Retained Boundary

DMA is another agent, not an ordinary C function that necessarily finishes before returning.

```text
prepare live buffer
      ↓
transfer ownership / start operation
      ↓
keep storage valid and respect ownership
      ↓
observe completion
      ↓
apply required visibility/cache steps
      ↓
consume or reuse buffer
```

CPU-written data can remain in cache when DMA needs RAM contents; DMA-written RAM can coexist with stale CPU cache data. Volatile does not solve either case.

Detailed cache clean/invalidate sequences depend on direction, memory attributes, cache-line boundaries, target rules, and the DMA engine's reachable memory. Those mechanisms remain future formal work. This section preserves the conceptual distinction and the open lifecycle/coherency revision target, without asserting a verified DMA implementation.

## 8.13 Debugging Concurrency and Overflow

Useful observations include queue high-water mark, accepted/dropped counts, longest consumer delay, and where ownership changes. Instrumentation must itself use a correct access/update contract.

For intermittent corruption:

1. Identify every reader/writer, including ISR, DMA, and another core.
2. Separate a lost update from a torn access or stale visibility.
3. Check index convention and empty/full tests.
4. Check payload publication and slot release order.
5. Confirm the actual overflow policy and observe saturation.
6. Check buffer lifetime and pointer retention.
7. Consider how breakpoints, logging, or masking changed timing.

A stable result under stepping does not prove the race is absent. A lack of hardware faults does not prove the queue preserved data correctly.

## 8.14 Section 8 Foundation Gate and Assessment

Be able to reason about interleaving, atomic access versus atomic operation, lost updates, ownership, critical-section scope, flag/event loss, queue rates/bursts, reserved-slot capacity, index conventions, publication order, slot reuse, and overflow requirements.

The 15-question cumulative Sections 1–8 assessment is completed for this pass:

| Question | Confirmed result | Retained correction/evidence |
|---|---|---|
| Q15 | 5/5 | N - 1 capacity, drop-newest, payload-before-head, ISR progress while main delayed, separate index writers |
| Q14 | 4/4 | Confirmed result |
| Q13 | 4/4 credited | Head-index convention unspecified |
| Q12 | 3/3 corrected | Original configuration already had requested MODE |
| Q10 | 3/4 | Earlier confirmed result retained |
| Q7 | 3/4 | Earlier confirmed result retained |
| Q3 | 3/4 | Earlier confirmed result retained |

No missing individual scores or aggregate are reconstructed. Exact Q1–Q14 question text is unavailable in the accessible checkpoint; illustrative examples in these notes are not replacements for that missing assessment transcript.

Remaining revision targets: signed arithmetic overflow/conversions; portable wire serialization/struct padding; DMA lifecycle/cache coherency; pointer byte offsets.

Completion is not permanent mastery. Independent implementation, debugging, design, measurements, and transfer remain future evidence. Section 9 — Compiler & Build Pipeline is active, starting preprocessing.

---

# Phase 1 — Sections 9–15: Sequence Reference

Section 9 is active, starting preprocessing; Sections 10–15 are not started. These future-section outlines preserve the planned sequence. Consolidate detailed reference notes here as each section is studied and completed; progress and assessment records remain in `Concepts/`.

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
    ├── Section 4 — Integer Representation         ✅
    ├── Section 5 — Memory Representation          ✅
    ├── Section 6 — C Memory & Pointer Foundations ✅ Current pass completed
    ├── Section 7 — Embedded-C Semantics           ✅ Current pass completed
    ├── Section 8 — Concurrency Foundations        ✅ Current pass completed
    ├── Section 9 — Compiler & Build Pipeline      🟡 IN_PROGRESS — preprocessing
    └── Sections 10–15                            ⬜ Not started
```

Sections 1–8 have detailed reference notes consolidated into this handbook. Sections 6–8 are completed for the current conceptual-validation pass. Section 8's 15-question cumulative assessment covers Sections 1–8; completion does not imply permanent mastery. Section 9 — Compiler & Build Pipeline is active, starting preprocessing. Current design/lab checkpoints are maintained in `Design/Progress.md`, `Labs/Progress.md`, and `Active-Context.md`.

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
**Current section:** Section 9 — Compiler & Build Pipeline (`IN_PROGRESS`, starting preprocessing)  
**Primary RTOS:** FreeRTOS  
**Secondary RTOS:** Zephyr (later)  
**Primary languages:** C and C++  
**Primary debugging path:** GDB + ST-LINK/SWD + measurement tools  
**End goal:** Senior/Principal-level transferable embedded firmware mastery