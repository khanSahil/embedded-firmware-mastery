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
| 4 | Integer Representation / Arithmetic | ✅ Foundation established |
| 5 | Memory Representation | ✅ Foundation established |
| 6 | C Memory & Pointer Foundations | ⬜ Not started — next |
| 7 | Embedded-C-Specific Semantics | ⬜ Not started |
| 8 | Concurrency Foundation | ⬜ Not started |
| 9 | Compiler & Build Pipeline | ⬜ Not started |
| 10 | Program Memory Layout | ⬜ Not started |
| 11 | ELF Fundamentals | ⬜ Not started |
| 12 | Linker Script Fundamentals | ⬜ Not started |
| 13 | Startup / Boot Fundamentals | ⬜ Not started |
| 14 | Bare-Metal Firmware Structure | ⬜ Not started |
| 15 | Debugging Foundations | ⬜ Not started |

After every completed section, design practice integrates all concepts covered so far using an evolving template appropriate to the current learning depth. The current Sections 1–4 mini-design is intentionally paused during travel and will resume from the existing control-flow step rather than restart. At the end of Phase 1 we will do a cumulative test across all Phase-1 material, review/re-test weaknesses, and perform a final Phase-1 consolidation before moving to Phase 2.

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

# Phase 1 — Sections 6–15: Planned Sequence

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
    ├── Section 4 — Integer Representation         ✅
    ├── Section 5 — Memory Representation          ✅
    └── Section 6 — C Memory & Pointer Foundations ← NEXT
```

Sections 1–5 have been consolidated into this single handbook. Section 6 — C Memory & Pointer Foundations is the next active learning block. The guided mini-design remains paused and will resume from its existing control-flow step when convenient.

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
**Current section:** Section 6 — C Memory & Pointer Foundations (next)  
**Primary RTOS:** FreeRTOS  
**Secondary RTOS:** Zephyr (later)  
**Primary languages:** C and C++  
**Primary debugging path:** GDB + ST-LINK/SWD + measurement tools  
**End goal:** Senior/Principal-level transferable embedded firmware mastery