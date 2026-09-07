# Track 1 — Embedded Firmware Mastery

> A living, curated handbook for mastering MCU firmware, ARM Cortex-M, RTOS, debugging, multicore systems, bootloaders, OTA, security, reliability, and production embedded architecture.

---

## 1. Purpose

This is the **single long-term knowledge reference for Track 1**.

It is not a transcript of our discussions and it is not intended to become a generic embedded-systems textbook. It should contain the knowledge worth retaining after we have actually studied, implemented, broken, debugged, measured, and reasoned about a concept.

The handbook has two purposes:

1. **Deep reference while learning** — preserve mental models, internals, experiments, debugging discoveries, failure modes, architecture decisions, and connections between topics.
2. **Senior/Principal interview refresh** — make it possible to revisit Track 1 months or years later without reconstructing everything from tutorials and scattered notes.

The handbook will therefore grow progressively as Track 1 progresses.

---

## 2. North Star

> Give me an unfamiliar Cortex-M system, datasheet, reference manual, schematic, compiler, and debugger, and I'm confident I can understand it, bring it up, write/debug the firmware, diagnose difficult failures, and explain my architectural decisions in an interview.

The STM32H745I-DISCO is our training platform, **not our specialization**.

The real objective is transferable embedded-engineering ability.

---

## 3. Learning Philosophy

### The core loop

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

For every important concept, progression should eventually include:

```text
Fundamentals
    ↓
First principles
    ↓
Internals
    ↓
Simple implementation
    ↓
Lower-level implementation
    ↓
Observe / measure
    ↓
Break deliberately
    ↓
Debug systematically
    ↓
Edge cases / failure modes
    ↓
Performance / optimization
    ↓
Production engineering
    ↓
Architecture / tradeoffs
    ↓
Senior / Principal interview scenarios
    ↓
Explain / teach back
```

### Important rule

**Do not skip fundamentals. Compress fundamentals that are already demonstrated.**

Previous professional exposure does not automatically mean mastery. A topic should be assessed through explanation, implementation, debugging, failure analysis, and design reasoning.

---

## 4. Mastery Scale

We can think about familiarity approximately as:

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

---

## 5. What Principal-Level Mastery Means

For a major embedded subsystem, the goal is eventually to be able to:

```text
Design it
Implement it
Measure it
Break it
Debug it
Test it
Automate it
Explain it
Defend the tradeoffs
```

A Principal engineer should be able to reason **downward** when a system fails and **upward** when designing the architecture.

```text
Application architecture
        ↓
RTOS / concurrency
        ↓
Drivers
        ↓
Interrupts / DMA
        ↓
Memory / cache / MPU
        ↓
CPU / instruction behavior
        ↓
Registers / buses
        ↓
Electrical hardware
```

---

# 6. Track 1 Mastery Stack

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

# 7. Primary Lab Platform — STM32H745I-DISCO

Track 1 uses the **STM32H745I-DISCO** as the primary physical platform.

Important capabilities include:

- STM32H745XI dual-core MCU
- Cortex-M7 up to 480 MHz
- Cortex-M4 up to 240 MHz
- 2 MB internal Flash
- 1 MB internal RAM
- external SDRAM
- external QSPI NOR
- onboard eMMC
- Ethernet
- CAN FD
- USB
- LCD and capacitive touch
- audio / microphone hardware
- onboard STLINK-V3E debugger/programmer
- Arduino Uno V3 expansion
- STMod+ expansion

The board gives us enough complexity to progress from a single GPIO register write all the way to multicore firmware, networking, storage, RTOS, cache/DMA problems, bootloaders, firmware updates, secure boot, diagnostics, and production architecture.

### Board versus MCU

The development board is **not** the MCU.

```text
STM32H745I-DISCO board
│
├── STM32H745 MCU
│   ├── Cortex-M7
│   ├── Cortex-M4
│   ├── Internal Flash
│   ├── Internal SRAM
│   ├── DMA
│   ├── timers
│   ├── GPIO
│   ├── UART / SPI / I2C
│   ├── Ethernet MAC
│   └── many other peripherals
│
├── external SDRAM
├── QSPI Flash
├── eMMC
├── Ethernet PHY
├── LCD / touch
├── audio hardware
├── CAN-related hardware
├── USB hardware
└── STLINK-V3E
```

External components introduce additional latency, bandwidth, initialization, signal, DMA, cache, reliability, and failure considerations.

---

# 8. Track 1 Roadmap

The schedule is deliberately flexible. **Mastery determines progression, not calendar time.**

A rough depth-first journey is approximately 12–15 months at 7–10 hours/week, but taking longer is completely acceptable.

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

Typical weekly balance:

```text
Theory / architecture       2–3 h
Implementation              3–4 h
Debugging / experiments     1–2 h
Documentation / explain     ~1 h
```

Target balance: approximately **60% hands-on / 40% theory**.

---

# 9. Parallel Track — Debugging & Measurement

Debugging is not a chapter that comes after programming. It develops throughout Track 1.

Progression:

```text
printf
  ↓
GDB
  ↓
SWD / ST-LINK
  ↓
register inspection
  ↓
memory / disassembly
  ↓
watchpoints
  ↓
logic analyzer / oscilloscope
  ↓
RTOS tracing
  ↓
performance profiling
  ↓
fault reconstruction
  ↓
production crash diagnostics
```

Examples by topic:

- startup: break inside `Reset_Handler`
- ARM: inspect PC/SP/LR and registers
- interrupts: measure ISR latency and execution time
- DMA: inspect buffers and controller state
- cache: reproduce stale-data bugs
- RTOS: inspect tasks, stacks, CPU utilization, latency, priority inversion
- networking: packet tracing / Wireshark
- multicore: IPC tracing and per-core debugging
- reliability: crash dumps and postmortem reconstruction

---

# 10. Parallel Track — Engineering Practice

The firmware itself is only part of production engineering.

Progression includes:

```text
Git
 ↓
GCC / CMake
 ↓
Warnings / formatting
 ↓
Unit tests
 ↓
Static analysis
 ↓
Mocks / integration tests
 ↓
Python automation
 ↓
CI
 ↓
Hardware-in-the-loop testing
 ↓
Fault injection
 ↓
Automated flashing/testing
 ↓
Artifact/version management
 ↓
OTA / rollback validation
 ↓
Reproducible release engineering
```

At Senior/Principal level this expands into architecture documents, ADRs, design reviews, requirements, traceability, risk analysis, observability, release strategy, reliability strategy, threat models, and manufacturing/service considerations.

---

# 11. Chapter Template

As major topics mature, their handbook chapters should generally contain:

```text
# Topic

## Interview Refresh
## Mental Model
## First Principles
## Internals
## Hardware / Architecture
## Registers / Configuration
## Implementation Progression
## Interactions With Other Subsystems
## Debugging Playbook
## Failure Modes
## Fault Injection
## Performance / Optimization
## Reliability / Recovery
## Security Implications
## Production Design
## Our Lab Findings
## Senior Interview Questions
## Principal Design Scenarios
## Mastery Checklist
```

Not every heading is necessary for every concept. The objective is depth, not template compliance.

---

# 12. Knowledge Map

The handbook will eventually cover this journey:

```text
MCU fundamentals
→ Embedded C/C++
→ ARM Cortex-M7/M4
→ Assembly / ABI
→ Compiler / ELF / linker
→ Startup / vector table
→ Memory architecture
→ Clocks / reset
→ GPIO / UART / SPI / I2C / timers / CAN...
→ Interrupts / exceptions / faults
→ DMA
→ Cache / MPU / barriers
→ GDB / SWD / measurement / debugging
→ FreeRTOS / real-time engineering
→ Ethernet / USB / storage
→ M7 + M4 multicore
→ Bootloader
→ OTA / A-B / rollback
→ Secure boot / firmware security
→ Reliability / watchdog / recovery
→ Zephyr
→ Production firmware architecture
→ Principal-level system design
```

Connections between concepts matter as much as the concepts themselves.

For example:

```text
DMA
├── memory architecture
├── bus/interconnect
├── interrupts
├── cache
├── MPU
├── alignment
├── memory barriers
├── concurrency
├── RTOS synchronization
├── driver architecture
├── buffer ownership
├── zero-copy
└── performance
```

---

# Chapter 1 — MCU Foundations

## Interview Refresh

A microcontroller is much more than a CPU.

A useful first mental model is:

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

The CPU executes instructions, but many important operations are performed by other hardware blocks.

Important ideas:

- An address does not inherently mean RAM.
- The system memory map determines which hardware responds to an address.
- Peripheral registers are exposed through memory-mapped addresses.
- A CPU store instruction can therefore alter physical hardware.
- Peripheral clocks and resets are prerequisites for correct operation.
- DMA can move data without the CPU executing one copy instruction per byte.
- Interrupts allow hardware events to redirect CPU execution.
- Multiple bus masters can compete for memory/interconnect resources.
- The STM32H745 has two CPU cores, making ownership and synchronization first-class concerns.

---

## 1. What Is Actually Inside an MCU?

Conceptually:

```text
                     ┌───────────────┐
                     │ Cortex-M7 CPU │
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

On a real STM32H745 the architecture is considerably more sophisticated, but this simplified model is sufficient to begin reasoning correctly.

Other important participants include:

```text
M4 core
DMA controllers
Ethernet
USB
interrupt controller
cache
clock/reset system
debug infrastructure
```

Some of these can initiate transactions independently of the M7 CPU.

---

## 2. CPU — Fetch, Decode, Execute

At a simplified level, a processor repeatedly performs:

```text
FETCH → DECODE → EXECUTE → repeat
```

The CPU fetches machine instructions from memory, decodes their meaning, and executes them.

Consider:

```c
c = a + b;
```

Conceptually this might become:

```text
load a into a register
load b into a register
add registers
store result into c
```

The actual assembly depends on optimization, variable location, register allocation, architecture capabilities, and compiler decisions.

Later we will compile small C programs and inspect the generated ARM instructions ourselves rather than treating compilation as magic.

---

## 3. Registers — PC, SP, LR

Three registers deserve immediate familiarity.

### Program Counter — PC

The PC identifies the instruction stream being executed.

Branches, function calls, interrupts, exceptions, and returns ultimately alter execution by changing where instructions are fetched from.

### Stack Pointer — SP

The stack pointer identifies the current stack location.

The stack commonly participates in:

- local variables
- saved registers
- function-call state
- interrupt/exception state
- RTOS task context

Cortex-M systems can use more than one stack pointer, which we will study later.

### Link Register — LR

The Link Register commonly contains return information associated with function calls.

During Cortex-M exception handling, LR can contain special `EXC_RETURN` values rather than an ordinary code address. This becomes extremely important when debugging exceptions and reconstructing crashes.

---

## 4. Memory Is More Than RAM

A CPU address is not synonymous with RAM.

An address is an identifier within the processor's address space. Hardware address decoding determines which target responds.

Conceptually:

```text
Address range          Target
--------------------------------
0x0800....             Flash
0x2000....             SRAM
0x4000....             Peripherals
...                    ...
```

These ranges are illustrative. We will learn the exact STM32H745 memory map from the authoritative documentation.

The important mental model is:

```text
CPU issues address
       ↓
interconnect examines address
       ↓
address decoder determines target
       ↓
Flash / SRAM / peripheral / other target responds
```

Therefore the CPU does **not** look at an address such as `0x40020014` and somehow decide, "this looks like RAM."

The system architecture defines what that address means.

---

## 5. Memory-Mapped I/O

Most MCU peripherals expose configuration, control, status, and data registers inside the processor address space.

That allows ordinary CPU load/store instructions to interact with hardware.

Conceptually:

```text
C code
   ↓
compiler
   ↓
ARM STORE instruction
   ↓
CPU puts address + value onto interconnect
   ↓
address decoder selects GPIO peripheral
   ↓
GPIO register receives value
   ↓
GPIO output circuitry changes state
   ↓
physical pin voltage changes
```

That is one of the fundamental bridges between software and electronics.

A high-level call such as:

```c
HAL_GPIO_WritePin(...);
```

ultimately has to cause the appropriate hardware register operation.

We will initially use HAL where useful for fast board bring-up, but then trace what it does and eventually perform important exercises directly through registers.

---

## 6. `volatile` — Early Mental Model

Memory-mapped hardware registers can change independently of ordinary program flow.

The compiler therefore must not assume that repeated accesses can always be optimized away or replaced with a previously known value.

This is one important reason `volatile` appears frequently in embedded programming.

However:

> `volatile` is **not** a concurrency primitive.

It does not automatically provide:

- atomicity
- mutual exclusion
- cache coherency
- inter-core synchronization
- memory ordering guarantees required by every concurrent scenario

We will revisit this topic deeply when studying compiler optimization, interrupts, DMA, multicore communication, atomics, caches, and memory barriers.

---

## 7. Why Peripheral Clocks Matter

Correct register programming is not sufficient if the peripheral itself is not operating.

Many MCU peripherals are clock-gated.

Conceptually:

```text
Oscillator
   ↓
PLL / clock source
   ↓
clock tree
   ↓
bus clock
   ↓
peripheral clock
   ↓
GPIO / UART / SPI / timer / ...
```

Clock gating saves power and allows controlled operation.

A peripheral may fail because:

- its clock is disabled
- it is held in reset
- the wrong clock source is selected
- the clock frequency is incorrect
- a parent bus/domain clock is incorrect

This creates an important debugging hierarchy:

```text
Power
 ↓
Reset
 ↓
Clock
 ↓
Pin mux
 ↓
Peripheral configuration
 ↓
Data path
 ↓
Interrupt / DMA
 ↓
Application logic
```

A strong firmware engineer learns to debug from prerequisites upward instead of immediately blaming application code.

---

## 8. Interrupt Mental Model

Without interrupts, software could continuously poll hardware:

```c
while (1) {
    if (uart_received_data()) {
        process_data();
    }
}
```

Interrupts allow hardware to request CPU attention asynchronously.

Simplified path:

```text
Peripheral event
      ↓
Interrupt request
      ↓
NVIC
      ↓
Cortex-M exception entry
      ↓
automatic context stacking
      ↓
ISR executes
      ↓
exception return
      ↓
interrupted code resumes
```

Later we will inspect the actual automatically stacked Cortex-M exception frame, including registers such as:

```text
R0
R1
R2
R3
R12
LR
PC
xPSR
```

We will also study:

- priorities
- preemption
- nesting
- interrupt masking
- tail chaining
- latency
- jitter
- ISR execution time
- interrupt storms
- ISR/RTOS interaction

And we will **measure** these behaviors rather than only discuss them theoretically.

---

## 9. DMA Mental Model

Consider receiving thousands of bytes from a peripheral.

A CPU could execute instructions to copy each byte. But this consumes CPU execution time.

DMA — Direct Memory Access — allows a hardware engine to perform transfers.

Conceptually:

```text
                       CPU
                        │
                        │ configures DMA
                        ↓
Peripheral ←──── Interconnect ────→ SRAM
                        ↑
                        │
                       DMA
```

The CPU programs the DMA controller with information such as source, destination, size, direction, and transfer configuration.

The DMA controller can then initiate bus transactions itself.

The CPU is therefore not required to execute a load/store pair for every transferred byte.

This immediately creates deeper questions:

- Which hardware owns the buffer?
- Can CPU and DMA access it simultaneously?
- Which memory regions can this DMA controller reach?
- What if CPU data is still dirty inside cache?
- What if DMA updates RAM but CPU reads stale cached data?
- What alignment is required?
- What is a cache line?
- When is the transfer actually complete?
- What if an interrupt races with buffer reuse?
- How can we build zero-copy pipelines?

These will become major Senior-level topics later.

---

## 10. Bus Masters and the Interconnect

The CPU is not necessarily the only component capable of accessing memory.

Potential system agents include:

```text
M7
M4
DMA
Ethernet
USB
other hardware engines
```

This means system performance and correctness can depend on:

- bus contention
- arbitration
- memory accessibility
- memory placement
- latency
- bandwidth
- ownership
- cache behavior

A seemingly simple question such as "where should this buffer live?" can therefore become an architecture decision.

---

## 11. Dual-Core Consequences

STM32H745 contains both Cortex-M7 and Cortex-M4 processors.

This creates powerful architectural possibilities but also additional failure modes.

Imagine both cores can access:

```c
shared_counter++;
```

That expression is not automatically safe simply because the variable is visible to both CPUs.

Eventually we must reason about:

- read-modify-write races
- atomic operations
- synchronization
- hardware semaphores
- shared-memory placement
- memory barriers
- cache behavior
- peripheral ownership
- IPC protocols
- startup coordination
- watchdog ownership
- fault isolation
- firmware version compatibility

A key Principal-level question is not merely **how to share a peripheral**, but whether it should be shared at all.

Often the better architecture establishes clear ownership and communicates through an explicit IPC contract.

---

## 12. ST-LINK and SWD Mental Model

The onboard STLINK-V3E is effectively another processor/debug subsystem used to communicate with the target MCU.

Conceptually:

```text
Development PC
      ↓ USB
STLINK-V3E
      ↓ SWD
STM32 debug infrastructure
      ↓
Cortex-M7 / Cortex-M4
```

This enables capabilities such as:

- programming Flash
- halting a core
- resuming execution
- single stepping
- reading registers
- reading/writing memory
- setting breakpoints
- setting watchpoints

One of our goals is to understand enough of this mechanism that "the debugger stops the CPU" is not treated as magic.

---

## 13. Software-to-Physical-Hardware Chain

One of the most important Track 1 mental models is:

```text
C / C++ statement
       ↓
Compiler
       ↓
ARM machine instruction
       ↓
Cortex-M CPU
       ↓
register operation
       ↓
load / store
       ↓
address + data on interconnect
       ↓
peripheral register
       ↓
hardware state machine / output logic
       ↓
physical pin / signal
```

When something fails, we should eventually be capable of investigating **every layer in this chain**.

---

## 14. First Foundation Check

These questions should be answered from reasoning rather than searching for definitions.

### Question 1

Why doesn't the CPU automatically treat an address such as `0x40020014` as RAM?

### Question 2

How can writing `0x20` to a memory-mapped address eventually change the voltage on a physical MCU pin?

### Question 3

Suppose the register address and value are correct, but the GPIO peripheral clock is disabled. What might happen, and why?

### Question 4 — Harder

DMA can access SRAM without the CPU moving every byte itself. Based on our system mental model, how is that possible?

These questions are intentionally simple-looking. The objective is to establish the reasoning style we will use throughout Track 1.

---

## 15. MCU Foundations Mastery Gate

Before considering the foundations mature, be able to explain naturally:

- what major blocks exist inside an MCU
- CPU fetch/decode/execute
- PC, SP, and LR at a useful conceptual level
- why addresses are not synonymous with RAM
- memory-mapped I/O
- how software ultimately affects physical hardware
- why peripheral clocks and resets matter
- basic interrupt flow
- basic DMA operation
- why DMA can operate without CPU copying each byte
- why multiple bus masters matter
- why dual-core firmware introduces synchronization and ownership concerns
- what ST-LINK/SWD conceptually do

The standard is understanding, not memorized wording.

---

# Chapter 2 — Embedded C

> Status: **Planned / not yet consolidated**

Topics will include:

- integer types and representation
- pointers and arrays
- pointer arithmetic
- structs and unions
- padding and alignment
- bit manipulation
- endianness
- `const`
- `volatile`
- `static`
- `extern`
- function pointers and callbacks
- macros and inline functions
- stack versus heap
- object lifetime
- undefined behavior
- memory-mapped I/O
- compiler optimization implications
- build and link model

The objective is not syntax memorization. The objective is to understand what C causes the machine to do.

---

# Chapter 3 — ARM Cortex-M, Assembly & ABI

> Status: **Planned / not yet consolidated**

We will study enough assembly to confidently read and debug firmware rather than become assembly-language application programmers.

Core areas:

- general-purpose registers
- PC / SP / LR
- MSP / PSP
- load/store architecture
- branches
- function calls
- stack frames
- ARM calling convention / ABI
- compiler-generated assembly
- exception entry and return
- `EXC_RETURN`
- disassembly-driven debugging

---

# Chapter 4 — Compiler, ELF & Linker

> Status: **Planned / not yet consolidated**

Key journey:

```text
source.c
  ↓ compiler
source.o
  ↓ linker
firmware.elf
  ↓ objcopy
firmware.bin / hex
```

Important areas:

- preprocessing
- compilation
- assembly
- object files
- symbols
- relocation
- linking
- ELF structure
- map files
- `objdump`
- `readelf`
- `nm`
- linker scripts

---

# Chapter 5 — Startup, Vector Table & `Reset_Handler`

> Status: **Planned / not yet consolidated**

Eventually we will understand and inspect the entire path:

```text
POWER
  ↓
RESET
  ↓
boot configuration
  ↓
vector table
  ↓
initial MSP
  ↓
Reset_Handler
  ↓
startup assembly
  ↓
copy .data
  ↓
zero .bss
  ↓
system initialization
  ↓
C/C++ runtime initialization
  ↓
main()
```

We will break inside `Reset_Handler`, inspect the vector table and ELF, and eventually modify/write startup and linker configuration ourselves.

---

# Chapter 6 — Memory Architecture

> Status: **Planned / not yet consolidated**

Areas include:

- internal Flash
- SRAM regions
- ITCM / DTCM
- AXI SRAM
- external SDRAM
- QSPI memory
- stack / heap placement
- DMA-accessible memory
- cacheability
- linker placement
- latency / bandwidth
- bus contention
- benchmarking memory placement

---

# Chapter 7 — Clocks & Reset

> Status: **Planned / not yet consolidated**

Progression:

```text
oscillator
→ clock source
→ PLL
→ prescalers
→ CPU clock
→ AHB/APB clocks
→ peripheral clocks
```

We will manually reason about clock configuration, deliberately misconfigure it, and debug resulting failures.

---

# Chapter 8 — Interrupts, Exceptions & Faults

> Status: **Planned / not yet consolidated**

Topics include:

- vector table
- NVIC
- exception entry
- automatic stack frame
- priority
- preemption
- nesting
- tail chaining
- latency
- jitter
- interrupt masking
- ISR design
- interrupt storms
- HardFault
- BusFault
- MemManage
- UsageFault
- fault status registers
- crash-context capture
- postmortem reconstruction

A later exercise will intentionally cause failures and build a fault handler that records enough state to reconstruct the crash.

---

# Chapter 9 — Peripheral Drivers

> Status: **Planned / not yet consolidated**

Representative driver progression for UART:

```text
register polling
      ↓
interrupt TX/RX
      ↓
ring buffers
      ↓
DMA
      ↓
circular DMA
      ↓
thread-safe FreeRTOS driver
      ↓
async API / callbacks
      ↓
zero-copy architecture
      ↓
error recovery / diagnostics
```

Similar depth will be applied to relevant peripherals including:

- GPIO
- UART
- timers / PWM
- SPI
- I2C
- ADC
- watchdog
- CAN FD
- Ethernet
- USB
- eMMC / storage
- QSPI
- SDRAM
- display / touch
- audio / microphone

---

# Chapter 10 — DMA

> Status: **Planned / not yet consolidated**

This will be one of the major Senior-level chapters.

Expected structure:

```text
CPU copy
  ↓
DMA transfer
  ↓
interrupt completion
  ↓
circular DMA
  ↓
double buffering
  ↓
cache coherency
  ↓
buffer ownership
  ↓
zero-copy
  ↓
performance engineering
```

We will study controller/register behavior, bus and memory architecture, interrupts, alignment, races, cache coherency, barriers, ownership, failure modes, and intermittent corruption debugging.

A working CubeMX DMA example is **not** the mastery criterion.

---

# Chapter 11 — Cache, MPU & Memory Barriers

> Status: **Planned / not yet consolidated**

The Cortex-M7 cache plus DMA environment is particularly valuable for learning difficult real-world firmware failures.

Topics include:

- cache lines
- dirty data
- stale data
- clean versus invalidate
- DMA coherency
- alignment
- MPU memory attributes
- barriers
- ordering
- TCM versus SRAM
- shared memory
- zero-copy tradeoffs

We will deliberately create intermittent stale-data/corruption problems and diagnose them.

---

# Chapter 12 — Embedded C++

> Status: **Planned / not yet consolidated**

Topics include:

- references
- constructors/destructors
- RAII
- ownership
- templates
- `constexpr`
- interfaces
- static polymorphism
- dynamic polymorphism
- allocation policy
- placement new
- STL tradeoffs
- exceptions
- RTTI
- zero-cost abstractions
- wrapping C drivers
- inspecting generated assembly

The goal is to understand the cost and machine behavior behind abstractions rather than follow blanket rules such as "C++ is too expensive for embedded."

---

# Chapter 13 — FreeRTOS & Real-Time Engineering

> Status: **Planned / not yet consolidated**

Core areas:

- scheduler
- tasks
- context switching
- priorities
- queues
- mutexes
- semaphores
- event groups
- task notifications
- software timers
- ISR-safe APIs
- stack sizing
- heap strategies
- priority inversion / inheritance
- starvation
- deadlocks
- latency
- jitter
- deadlines
- WCET reasoning

We will measure behavior, intentionally create scheduling/concurrency failures, and debug them.

---

# Chapter 14 — Connectivity & Storage

> Status: **Planned / not yet consolidated**

Major areas:

- Ethernet
- TCP/IP
- packet tracing
- USB
- CAN FD
- eMMC
- QSPI
- persistent data
- filesystem/storage integrity
- error recovery

Networking experiments will include Wireshark/protocol-level observation rather than treating network libraries as black boxes.

---

# Chapter 15 — Multicore M7 ↔ M4

> Status: **Planned / not yet consolidated**

Key questions:

- Which core boots first?
- Who initializes shared resources?
- Who owns each peripheral?
- How is the M4 released?
- How should IPC work?
- Where should shared memory live?
- How is cache handled?
- What happens if one core hangs?
- Which core owns watchdog responsibilities?
- How do firmware versions remain compatible?

Progression includes shared memory, HSEM, explicit IPC protocols, resource ownership, fault isolation, restart strategies, and production partitioning.

---

# Chapter 16 — Bootloader

> Status: **Planned / not yet consolidated**

Progression:

```text
Reset / Boot ROM
      ↓
Our Bootloader
      ↓
Vector table / MSP / VTOR
      ↓
Validate application
      ↓
Jump to application
      ↓
CRC / integrity checking
      ↓
Flash programming
      ↓
Firmware update over UART
      ↓
Power-failure-safe update
      ↓
A/B firmware slots
      ↓
Rollback / recovery
      ↓
Ethernet firmware update
      ↓
Cryptographic signatures
      ↓
Secure Boot / Chain of Trust
      ↓
Anti-rollback
      ↓
Dual-core M7 + M4 update coordination
```

A bootloader/application handoff is **not** simply calling `app_main()`.

We will reason about MSP, VTOR, interrupts, SysTick, NVIC, DMA, peripherals, caches, MPU, clocks, and execution address during handoff.

---

# Chapter 17 — OTA, A/B & Recovery

> Status: **Planned / not yet consolidated**

Target architecture:

```text
Firmware server
      ↓ Ethernet
running firmware
      ↓
download candidate image
      ↓
write inactive slot
      ↓
verify image
      ↓
mark PENDING
      ↓
reboot
      ↓
boot candidate
      ↓
health/self-test
      ↓
CONFIRM or ROLLBACK
```

Failure injection will include:

- network loss at 10%
- network loss at 99%
- power loss during download
- power loss during Flash programming
- power loss during metadata update
- corrupted image
- invalid signature
- wrong hardware version
- signed downgrade attempt
- new firmware crash
- deadlock
- watchdog reset
- storage exhaustion
- repeated network disconnects

Core requirement:

> The device must not become unrecoverably bricked because the update was interrupted at the worst possible moment.

Eventually a Python-driven fault-injection harness should repeat update/power-loss/recovery cycles automatically.

---

# Chapter 18 — Secure Boot & Firmware Security

> Status: **Planned / not yet consolidated**

Basic chain:

```text
Power-on
   ↓
trusted first-stage code
   ↓
verify next stage / application
   ↓
validate policy
   ↓
check anti-rollback state
   ↓
execute only authorized firmware
```

Important progression:

```text
CRC
 ↓
hash
 ↓
digital signature
 ↓
trusted public key
 ↓
root of trust
 ↓
anti-rollback
 ↓
A/B recovery
 ↓
key / bootloader protection
 ↓
production threat model
```

Important distinction:

- **CRC** helps detect accidental corruption but is not authenticity.
- **Hashing** detects modification but does not by itself establish who authorized an image.
- **Digital signatures** can establish authenticity when verification keys and the trust chain are themselves protected.

A cryptographically valid image is not necessarily permitted to boot. For example, a correctly signed but vulnerable old firmware may need to be rejected by anti-rollback policy.

### Secure boot versus TPM/measured boot

These address related but different security questions.

```text
Secure boot
"Is this software authorized to execute?"

Measured boot / TPM-style attestation
"What actually booted, and can I prove that state?"
```

A TPM is not inherently required for secure boot.

---

# Chapter 19 — Reliability, Watchdog & Recovery

> Status: **Planned / not yet consolidated**

A robust watchdog design is more than periodically calling a watchdog-refresh function.

A production architecture may look like:

```text
critical task progress
critical driver progress
M4 health
M7 health
DMA progress
network/update state
        ↓
health monitor
        ↓
only if system is healthy
        ↓
watchdog refresh
```

We will study:

- watchdog architecture
- health monitoring
- reset reason
- persistent crash state
- boot-loop detection
- safe mode
- crash dumps
- fault reconstruction
- recovery policy
- telemetry

Production scenario:

> 20,000 deployed devices exist in the field. Five reboot once every two weeks. You have only a small persistent crash record. How do you design enough diagnostics to find the root cause?

---

# Chapter 20 — Zephyr

> Status: **Planned / support on exact target to be verified when reached**

Zephyr comes **after** deep FreeRTOS/MCU understanding.

The purpose is not to learn another collection of APIs. It is to apply existing embedded principles in another ecosystem and compare:

- driver model
- device model
- configuration
- scheduling
- synchronization
- DeviceTree usage
- build system
- portability
- abstractions
- architecture tradeoffs

Exact STM32H745I-DISCO support should be verified against current Zephyr documentation when this phase begins rather than assumed now.

---

# Chapter 21 — Principal Capstone

The final Track 1 system will combine much of the track into one production-style architecture.

Conceptually:

```text
              Touchscreen / UI
                     │
                     ▼
        ┌─────────────────────────┐
        │ Cortex-M7               │
        │                         │
        │ Networking              │
        │ Storage                 │
        │ UI                      │
        │ Logging                 │
        │ Firmware update         │
        └────────────┬────────────┘
                     │
             shared memory / IPC
                     │
        ┌────────────▼────────────┐
        │ Cortex-M4               │
        │                         │
        │ FreeRTOS                │
        │ real-time control       │
        │ sensors / DMA           │
        │ watchdog / health       │
        └─────────────────────────┘
```

A Linux development PC can provide:

- firmware-update server
- control/management application
- telemetry receiver
- automated test harness
- fault-injection orchestration

Potential failures to inject:

- network loss
- packet corruption
- DMA overrun
- M4 deadlock
- M7 crash
- memory corruption
- storage full
- missed deadline
- power loss during update
- IPC flood
- stack overflow
- invalid firmware

### Final architecture examination

Design a dual-core connected embedded device using STM32H745 with:

- hard real-time requirements
- touchscreen
- Ethernet
- persistent storage
- remote firmware update
- secure boot
- diagnostics
- watchdog/recovery
- long service lifetime

Be prepared to defend:

- M7/M4 partitioning
- peripheral ownership
- IPC design
- DMA architecture
- buffer ownership
- cache strategy
- worst-case latency
- task priorities
- M4 hang recovery
- M7 failure recovery
- OTA power-loss behavior
- firmware compatibility
- network-flood behavior
- stack-corruption diagnosis
- intermittent-failure debugging
- root of trust
- testing strategy
- maintainability

---

# 22. Failure Notebook

Real failures encountered during Track 1 should be preserved because debugging experience is one of the highest-value outputs of the track.

Template:

```text
FAIL-XXX — Short Name

Symptoms:

System Context:

Initial Hypotheses:

Experiments:

Observations:

Root Cause:

Fix:

Why the Fix Works:

Incorrect / Misleading Fixes:

How to Diagnose This on an Unfamiliar MCU:

Prevention / Production Design:

Interview Variation:
```

The goal is not merely to remember the answer. It is to remember the **reasoning path that exposed the answer**.

---

# 23. Interview Preparation Index

This section will eventually aggregate questions and scenarios accumulated during learning. It should primarily reference knowledge already developed in the chapters rather than introduce new material at the end.

Categories will include:

- Embedded C
- Embedded C++
- ARM Cortex-M
- Assembly / ABI
- compiler / ELF / linker
- startup / vector table
- memory architecture
- clocks / reset
- GPIO / UART / SPI / I2C / timers / CAN
- interrupts / exceptions / faults
- DMA
- cache / MPU / barriers
- FreeRTOS / real-time systems
- networking / USB / storage
- multicore
- bootloader
- OTA / rollback / recovery
- secure boot / firmware security
- watchdog / reliability
- GDB / SWD / measurement
- performance
- debugging scenarios
- Senior system design
- Principal architecture / tradeoffs

---

# 24. Current Learning Position

We are at the beginning of **MCU Foundations**.

The immediate sequence before and around board arrival is:

```text
Lesson 0  What is actually inside an MCU?
Lesson 1  How a CPU executes instructions
Lesson 2  Registers, PC/SP/LR, ARM assembly
Lesson 3  MCU memory map + memory-mapped I/O
Lesson 4  C → compiler → assembly → object
Lesson 5  Linking + ELF
Lesson 6  .text / .rodata / .data / .bss / stack / heap
Lesson 7  Linker scripts
Lesson 8  Vector table + Reset_Handler
Lesson 9  What happens before main()
Lesson 10 ST-LINK + SWD + GDB mental model
```

When the physical board arrives, the sequence gains real hardware experiments rather than restarting from a separate tutorial path.

The first physical bring-up will intentionally begin simply — likely with an LED using HAL to establish that board/toolchain/debugging work — and then peel the abstractions away until the same behavior can be explained and controlled from registers and machine-level behavior.

---

# 25. Handbook Maintenance Rule

This handbook should **not** be updated after every conversation message.

The preferred workflow is:

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

This keeps the handbook useful years later instead of turning it into a conversation archive.

---

## Track 1 Status

**Primary board:** STM32H745I-DISCO  
**Current phase:** Foundations / pre-board learning  
**Primary RTOS:** FreeRTOS  
**Secondary RTOS:** Zephyr (later)  
**Primary languages:** C and C++  
**Primary debugging path:** GDB + ST-LINK/SWD + measurement tools  
**End goal:** Senior/Principal-level transferable embedded firmware mastery
