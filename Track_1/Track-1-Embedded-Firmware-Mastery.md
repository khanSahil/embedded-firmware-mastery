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

For every important concept, progression should eventually include fundamentals, first principles, internals, implementation, observation, deliberate failure, debugging, edge cases, performance, production engineering, architecture/tradeoffs, interview scenarios, and teach-back.

### Important rule

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

---

## 5. What Principal-Level Mastery Means

For a major embedded subsystem, the goal is eventually to be able to design it, implement it, measure it, break it, debug it, test it, automate it, explain it, and defend the tradeoffs.

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

Important capabilities include STM32H745XI dual-core MCU, Cortex-M7 up to 480 MHz, Cortex-M4 up to 240 MHz, 2 MB internal Flash, 1 MB internal RAM, external SDRAM, external QSPI NOR, onboard eMMC, Ethernet, CAN FD, USB, LCD/touch, audio/microphone hardware, onboard STLINK-V3E, Arduino Uno V3 expansion, and STMod+ expansion.

The development board is **not** the MCU. External components introduce additional latency, bandwidth, initialization, signal, DMA, cache, reliability, and failure considerations.

---

# 8. Track 1 Roadmap

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

# 9. Parallel Track — Debugging & Measurement

Debugging is not a chapter that comes after programming. It develops throughout Track 1: printf → GDB → SWD/ST-LINK → register inspection → memory/disassembly → watchpoints → logic analyzer/oscilloscope → RTOS tracing → performance profiling → fault reconstruction → production crash diagnostics.

---

# 10. Parallel Track — Engineering Practice

Production engineering includes Git, GCC/CMake, warnings/formatting, tests, static analysis, mocks/integration tests, Python automation, CI, hardware-in-the-loop testing, fault injection, automated flashing/testing, artifact/version management, OTA/rollback validation, and reproducible release engineering.

---

# 11. Chapter Template

As topics mature, chapters should preserve interview refresh, mental models, first principles, internals, hardware/architecture, registers/configuration, implementation progression, interactions, debugging playbooks, failure modes, fault injection, performance, reliability, security, production design, lab findings, interview scenarios, and mastery checks where relevant.

---

# 12. Knowledge Map

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

---

# Chapter 1 — MCU Foundations

## Interview Refresh

A microcontroller is much more than a CPU. A useful first mental model is CPU(s) + memories + peripherals + interconnect/buses + clocks/reset + interrupt system + DMA + caches + debug infrastructure + power management.

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

Other important participants include the M4 core, DMA controllers, Ethernet, USB, interrupt controller, cache, clock/reset system, and debug infrastructure. Some can initiate transactions independently of the M7 CPU.

---

## 2. CPU — Fetch, Decode, Execute

At a simplified level a processor repeatedly performs `FETCH → DECODE → EXECUTE`. The actual machine behavior behind a C expression depends on optimization, variable location, register allocation, architecture capabilities, and compiler decisions. Later we will compile small programs and inspect generated ARM instructions ourselves.

---

## 3. Registers — PC, SP, LR

- **PC** identifies the instruction stream being executed.
- **SP** identifies the current stack location and participates in local variables, saved registers, call state, exception state, and RTOS task context.
- **LR** commonly contains function-return information. During Cortex-M exceptions it can contain special `EXC_RETURN` values.

---

## 4. Memory Is More Than RAM

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

The system architecture defines what an address means.

---

## 5. Memory-Mapped I/O

Most MCU peripherals expose configuration, control, status, and data registers inside the processor address space. Ordinary CPU load/store instructions can therefore interact with hardware.

```text
C code
   ↓
compiler
   ↓
ARM STORE instruction
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

---

## 6. `volatile` — Early Mental Model

Memory-mapped hardware registers can change independently of ordinary program flow, which is one reason `volatile` appears frequently in embedded programming. But `volatile` is **not** a concurrency primitive: it does not automatically provide atomicity, mutual exclusion, cache coherency, inter-core synchronization, or all required memory-ordering guarantees.

---

## 7. Why Peripheral Clocks and Reset Matter

Many MCU peripherals are clock-gated. Clock gating saves power and controls operation. A peripheral may fail because its clock is disabled, it is held in reset, the wrong source is selected, the frequency is wrong, or a parent clock/domain is wrong.

Important nuance: do not assume universally that a bus write to a clock-gated peripheral must fail. The bus-facing register interface and functional peripheral logic may have different clocking behavior. The reference manual defines the exact behavior for a given MCU/peripheral.

Clock gating and reset are different:

```text
Clock gated
→ clock-dependent state stops progressing
→ retained state may remain intact

Reset asserted
→ peripheral state/registers are driven to defined reset conditions
```

A useful debugging hierarchy is `Power → Reset → Clock → Pin mux → Peripheral configuration → Data path → Interrupt/DMA → Application logic`.

---

## 8. GPIO Electrical Foundations

### 8.1 MCU boundary: the GPIO pin is physical hardware

A GPIO pin is a physical connection on the MCU package. Behind it is internal circuitry that can sense the pin voltage and, when configured for output, drive the pin.

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

The software/electrical chain is therefore:

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

When configured as output, the direction is conceptually reversed: register state controls output circuitry, which drives a physical voltage on the pin.

### 8.2 Input mode is high impedance

A digital GPIO input is designed to sense voltage while drawing very little current. A simple DC mental model is a very large input resistance, but real semiconductor inputs are more accurately characterized by leakage current, parasitic capacitance, protection structures, and input thresholds rather than one literal fixed resistor.

High input impedance matters because a sensing input should not significantly load the external circuit.

### 8.3 Floating inputs

If an input has no meaningful path to VDD or ground, nothing establishes a definite electrical potential:

```text
VDD   no connection

        ● GPIO input

GND   no connection
```

The input is **floating**. Its voltage can be influenced by stored charge, leakage, electrical noise, nearby signals, or touch. Firmware may therefore observe unstable or unpredictable digital values.

A crucial principle is:

> Zero current does not imply zero voltage, and it does not imply VDD either. Voltage is established by circuit conditions and electrical connections.

A node directly connected to ground is at approximately 0 V. A node directly connected to 3.3 V is at approximately 3.3 V. A floating node has no such defined state.

### 8.4 Pull-ups and pull-downs

A pull-up creates a weak resistive path toward VDD:

```text
3.3 V
  │
 [R]
  │
  ● GPIO
```

With a high-impedance input, almost no current flows, so the voltage drop across the pull-up is tiny and the pin sits near VDD.

A pull-down is the mirror image:

```text
  ● GPIO
  │
 [R]
  │
 GND
```

It establishes a default LOW.

The resistor makes the bias **weak**: it establishes a default state when nothing stronger controls the node, but a low-resistance external path can override it safely.

For a 3.3 V supply and 10 kΩ pull-up, a switch to ground draws approximately:

```text
I = V / R = 3.3 / 10000 = 0.33 mA
```

Without the resistor, closing a switch between VDD and ground would create a near short circuit rather than a safe logic transition.

### 8.5 Internal pull resistors

Many MCUs can enable weak pull-ups or pull-downs internally. Enabling an internal pull-up does **not** mean the GPIO input sensing circuitry stops being high impedance. Instead, the MCU enables an additional weak resistive path between the pin and VDD.

```text
                 INSIDE MCU
        ┌─────────────────────────┐
        │ VDD                     │
        │  │                      │
        │ [internal pull-up]      │
        │  │                      │
        │  ├────● GPIO PIN        │
        │  │                      │
        │ input sensing           │
        │ (high impedance)        │
        └─────────────────────────┘
```

### 8.6 Active-low signals

A common button arrangement uses a pull-up and a switch to ground:

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

This is an **active-low** signal: the logical function is asserted when the signal is LOW. Common naming conventions include `RESET_N`, `ENABLE_N`, `CS_N`, `IRQ_N`, `/RESET`, `nRESET`, and `RESET#`.

"Active" describes the logical meaning of the signal, not merely whether current is flowing or a switch is physically closed.

### 8.7 Digital input thresholds: VIL(max) and VIH(min)

Digital inputs do not simply treat every voltage below 1.65 V as 0 and every voltage above it as 1. Datasheets specify guaranteed regions.

For a hypothetical device:

```text
VIL(max) = 0.8 V
VIH(min) = 2.0 V

0 V ─────── 0.8 V ───────────── 2.0 V ─────── 3.3 V
   guaranteed LOW   not guaranteed   guaranteed HIGH
```

- `VIL(max)` = **Voltage Input Low, maximum**: the highest input voltage still guaranteed to be interpreted as LOW.
- `VIH(min)` = **Voltage Input High, minimum**: the lowest input voltage guaranteed to be interpreted as HIGH.

A voltage between those limits does not represent a third digital value. The input register still produces a digital result, but which result occurs is not guaranteed by the specification.

### 8.8 Output guarantees: VOL(max) and VOH(min)

A real GPIO output is not an ideal voltage source. Datasheets therefore specify what an output guarantees under stated operating/loading conditions:

- `VOL(max)` = **Voltage Output Low, maximum**: when driving LOW, the sender guarantees the output will be no higher than this limit.
- `VOH(min)` = **Voltage Output High, minimum**: when driving HIGH, the sender guarantees the output will be at least this voltage.

A useful way to reconstruct all four names instead of memorizing them:

```text
V = Voltage
I = Input / receiver
O = Output / sender
H = High
L = Low

HIGH → minimum matters
LOW  → maximum matters
```

Therefore:

```text
INPUT / receiver       OUTPUT / sender
VIH(min)               VOH(min)
VIL(max)               VOL(max)
```

### 8.9 Logic-level compatibility

When Chip A drives Chip B:

```text
             CHIP A                         CHIP B
             SENDER                        RECEIVER

HIGH:       VOH(min) ─────────────────────► VIH(min)
LOW:        VOL(max) ─────────────────────► VIL(max)
```

For guaranteed compatibility:

```text
HIGH: VOH(min) ≥ VIH(min)
LOW:  VOL(max) ≤ VIL(max)
```

Reason physically rather than memorizing inequalities:

- For HIGH, the sender's worst guaranteed HIGH must still be high enough for the receiver.
- For LOW, the sender's worst guaranteed LOW must still be low enough for the receiver.

Example:

```text
Sender:   VOH(min)=2.7 V, VOL(max)=0.4 V
Receiver: VIH(min)=2.0 V, VIL(max)=0.8 V

HIGH: 2.7 ≥ 2.0  ✓
LOW:  0.4 ≤ 0.8  ✓
```

Testing a few boards successfully is not a substitute for satisfying guaranteed datasheet limits across the specified operating conditions.

### 8.10 Noise margin

The gap between the sender's guaranteed output and the receiver's required input is an electrical safety cushion.

```text
HIGH noise margin = VOH(min) - VIH(min)
LOW  noise margin = VIL(max) - VOL(max)
```

Using the previous example:

```text
HIGH margin = 2.7 - 2.0 = 0.7 V
LOW margin  = 0.8 - 0.4 = 0.4 V
```

Larger noise margin generally means more tolerance to electrical degradation/disturbance. Whether a particular margin is sufficient depends on the actual system: loading, PCB layout, trace length, interface speed, switching noise, temperature, supply variation, and other electrical conditions.

### 8.11 Why GPIO HIGH is not exactly VDD

The GPIO output driver uses real transistors with nonzero effective resistance. When the pin sources current, the driver can develop an internal voltage drop:

```text
VDD ──[effective output resistance]──● GPIO ── load
```

A simplified model gives:

```text
Vdrop = I × Rinternal
```

For example, 10 mA through an effective 20 Ω produces about 0.2 V of drop, so a 3.3 V source could result in roughly 3.1 V at the pin in that simplified model.

Likewise, a heavily loaded LOW output may sit somewhat above 0 V. This is why `VOH(min)` and `VOL(max)` are meaningful and why datasheet limits are tied to specified output-current conditions.

### 8.12 GPIO electrical mental model to retain

```text
Firmware configuration
        ↓
GPIO registers
        ↓
internal input/output circuitry
        ↓
physical MCU pin
        ↓
external electrical network
        ↓
voltage/current behavior
        ↓
receiving device thresholds
        ↓
logical 0 / 1
```

Do not collapse these layers into "software writes a 1, therefore the wire is exactly 3.3 V." A robust embedded engineer reasons across the entire chain.

### 8.13 GPIO electrical mastery check

Be able to explain from first principles:

- where the physical GPIO pin sits relative to internal MCU circuitry
- why an input is high impedance
- why a floating input is undefined
- why zero current does not imply zero voltage
- how pull-ups and pull-downs establish deterministic default states
- why pull resistors are intentionally weak
- why a resistor prevents a button-to-ground circuit from shorting VDD
- internal versus external pulls
- active-low signaling
- `VIL(max)`, `VIH(min)`, `VOL(max)`, and `VOH(min)` without rote memorization
- how to verify logic-level compatibility between two devices
- what noise margin means physically
- why GPIO output voltage changes with load
- why datasheet guarantees matter more than behavior observed on one board

---

## 9. Interrupt Mental Model

Without interrupts, software can poll hardware continuously. Interrupts allow hardware to request CPU attention asynchronously.

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

Later we will study priorities, preemption, nesting, masking, tail chaining, latency, jitter, ISR execution time, interrupt storms, and RTOS interaction.

---

## 10. DMA Mental Model

DMA allows a hardware engine to perform transfers after CPU configuration, rather than requiring the CPU to execute a load/store pair for every byte.

This creates deeper questions around buffer ownership, memory accessibility, cache coherency, alignment, completion, races, and zero-copy design.

---

## 11. Bus Masters and the Interconnect

Potential bus masters include M7, M4, DMA, Ethernet, USB, and other hardware engines. Performance and correctness can therefore depend on contention, arbitration, memory accessibility/placement, latency, bandwidth, ownership, and cache behavior.

---

## 12. Dual-Core Consequences

STM32H745 contains Cortex-M7 and Cortex-M4 processors. Shared state is not automatically safe. We will study read-modify-write races, atomics, synchronization, hardware semaphores, shared-memory placement, barriers, cache behavior, peripheral ownership, IPC, startup coordination, watchdog ownership, fault isolation, and firmware compatibility.

---

## 13. ST-LINK and SWD Mental Model

```text
Development PC
      ↓ USB
STLINK-V3E
      ↓ SWD
STM32 debug infrastructure
      ↓
Cortex-M7 / Cortex-M4
```

This enables programming Flash, halting/resuming, stepping, reading registers/memory, and setting breakpoints/watchpoints. We will later understand the mechanism deeply enough that debugging is not treated as magic.

---

## 14. Software-to-Physical-Hardware Chain

```text
C / C++ statement
       ↓
Compiler
       ↓
ARM machine instruction
       ↓
Cortex-M CPU
       ↓
load / store
       ↓
address + data on interconnect
       ↓
peripheral register
       ↓
hardware state machine / I/O circuitry
       ↓
physical pin / signal
```

When something fails, we should eventually be capable of investigating every layer in this chain.

---

## 15. MCU Foundations Mastery Gate

Before considering the foundations mature, be able to explain naturally: major MCU blocks; fetch/decode/execute; PC/SP/LR; address decoding; memory-mapped I/O; software-to-physical hardware; clocks/reset; GPIO electrical behavior; interrupts; DMA; bus masters; dual-core ownership/synchronization; and ST-LINK/SWD.

The standard is understanding, not memorized wording.

---

# Chapter 2 — Embedded C

> Status: **Planned / not yet consolidated**

Topics include integer representation, pointers/arrays, structs/unions, padding/alignment, bit manipulation, endianness, `const`, `volatile`, `static`, `extern`, function pointers, macros/inline functions, stack/heap, lifetime, undefined behavior, MMIO, optimization, and build/link behavior.

---

# Chapter 3 — ARM Cortex-M, Assembly & ABI

> Status: **Planned / not yet consolidated**

Core areas include general-purpose registers, PC/SP/LR, MSP/PSP, load/store architecture, branches, function calls, stack frames, ABI, compiler-generated assembly, exception entry/return, `EXC_RETURN`, and disassembly-driven debugging.

---

# Chapter 4 — Compiler, ELF & Linker

> Status: **Planned / not yet consolidated**

```text
source.c → compiler → source.o → linker → firmware.elf → objcopy → firmware.bin / hex
```

We will study preprocessing, compilation, assembly, object files, symbols, relocation, linking, ELF, map files, `objdump`, `readelf`, `nm`, and linker scripts.

---

# Chapter 5 — Startup, Vector Table & `Reset_Handler`

> Status: **Planned / not yet consolidated**

```text
POWER → RESET → boot configuration → vector table → initial MSP → Reset_Handler
→ startup assembly → copy .data → zero .bss → system/runtime initialization → main()
```

---

# Chapter 6 — Memory Architecture

> Status: **Planned / not yet consolidated**

Areas include internal Flash, SRAM regions, ITCM/DTCM, AXI SRAM, external SDRAM, QSPI, stack/heap placement, DMA-accessible memory, cacheability, linker placement, latency/bandwidth, contention, and benchmarking.

---

# Chapter 7 — Clocks & Reset

> Status: **Planned / not yet consolidated**

We will study oscillator/source/PLL/prescalers, CPU and bus clocks, peripheral clocks, clock domains, reset types, deliberate misconfiguration, measurement, and debugging.

---

# Chapter 8 — Interrupts, Exceptions & Faults

> Status: **Planned / not yet consolidated**

Topics include vector table, NVIC, exception entry/frame, priority, preemption, nesting, tail chaining, latency, jitter, masking, ISR design, interrupt storms, HardFault, BusFault, MemManage, UsageFault, status registers, crash-context capture, and postmortem reconstruction.

---

# Chapter 9 — Peripheral Drivers

> Status: **Planned / not yet consolidated**

Representative progression: register polling → interrupts → buffering → DMA → circular DMA → RTOS-safe driver → async API → zero-copy → error recovery/diagnostics. Relevant peripherals include GPIO, UART, timers/PWM, SPI, I2C, ADC, watchdog, CAN FD, Ethernet, USB, eMMC, QSPI, SDRAM, display/touch, and audio/microphone.

---

# Chapter 10 — DMA

> Status: **Planned / not yet consolidated**

CPU copy → DMA transfer → interrupt completion → circular DMA → double buffering → cache coherency → buffer ownership → zero-copy → performance engineering. A working CubeMX example is **not** the mastery criterion.

---

# Chapter 11 — Cache, MPU & Memory Barriers

> Status: **Planned / not yet consolidated**

Topics include cache lines, dirty/stale data, clean/invalidate, DMA coherency, alignment, MPU attributes, barriers, ordering, TCM versus SRAM, shared memory, and zero-copy tradeoffs. We will deliberately create stale-data/corruption failures and diagnose them.

---

# Chapter 12 — Embedded C++

> Status: **Planned / not yet consolidated**

Topics include references, constructors/destructors, RAII, ownership, templates, `constexpr`, interfaces, polymorphism, allocation policy, placement new, STL tradeoffs, exceptions, RTTI, zero-cost abstractions, wrapping C drivers, and generated assembly.

---

# Chapter 13 — FreeRTOS & Real-Time Engineering

> Status: **Planned / not yet consolidated**

Core areas include scheduler/tasks, context switching, priorities, queues, mutexes, semaphores, event groups, task notifications, timers, ISR-safe APIs, stack sizing, heap strategies, priority inversion/inheritance, starvation, deadlocks, latency, jitter, deadlines, and WCET reasoning.

---

# Chapter 14 — Connectivity & Storage

> Status: **Planned / not yet consolidated**

Major areas include Ethernet/TCP-IP, packet tracing, USB, CAN FD, eMMC, QSPI, persistent data, filesystem/storage integrity, and error recovery. Networking experiments will include Wireshark/protocol-level observation.

---

# Chapter 15 — Multicore M7 ↔ M4

> Status: **Planned / not yet consolidated**

We will study boot order, shared-resource initialization, peripheral ownership, M4 release, IPC, shared-memory placement, cache, hang recovery, watchdog ownership, firmware compatibility, HSEM, resource ownership, fault isolation, restart strategies, and production partitioning.

---

# Chapter 16 — Bootloader

> Status: **Planned / not yet consolidated**

Progression includes reset/Boot ROM, custom bootloader, vector table/MSP/VTOR, application validation and jump, CRC/integrity, Flash programming, update transport, power-failure safety, A/B slots, rollback/recovery, signatures, secure boot, anti-rollback, and dual-core update coordination.

A bootloader/application handoff is **not** simply calling `app_main()`.

---

# Chapter 17 — OTA, A/B & Recovery

> Status: **Planned / not yet consolidated**

Target architecture: download candidate → write inactive slot → verify → mark pending → reboot → health/self-test → confirm or rollback. Failure injection will cover network/power loss, corruption, invalid signatures, incompatible images, downgrade attempts, crashes, deadlocks, watchdog resets, and storage exhaustion.

Core requirement: the device must not become unrecoverably bricked because the update was interrupted at the worst possible moment.

---

# Chapter 18 — Secure Boot & Firmware Security

> Status: **Planned / not yet consolidated**

Progression: CRC → hash → digital signature → trusted public key → root of trust → anti-rollback → A/B recovery → key/bootloader protection → production threat model.

CRC detects accidental corruption but is not authenticity. Hashing detects modification but alone does not establish authorization. Digital signatures can establish authenticity when the verification keys and trust chain are protected.

---

# Chapter 19 — Reliability, Watchdog & Recovery

> Status: **Planned / not yet consolidated**

We will study watchdog architecture, health monitoring, reset reason, persistent crash state, boot-loop detection, safe mode, crash dumps, fault reconstruction, recovery policy, and telemetry. A robust watchdog design validates system progress rather than blindly refreshing a timer.

---

# Chapter 20 — Zephyr

> Status: **Planned / support on exact target to be verified when reached**

Zephyr comes after deep FreeRTOS/MCU understanding. The goal is to apply existing principles in another ecosystem and compare driver/device models, configuration, scheduling, synchronization, DeviceTree, build system, portability, abstractions, and architecture tradeoffs.

---

# Chapter 21 — Principal Capstone

The final Track 1 system will combine dual-core partitioning, real-time control, networking, storage, UI, firmware update, security, diagnostics, watchdog/recovery, automated testing, and deliberate fault injection. The final architecture examination will require defending M7/M4 partitioning, peripheral ownership, IPC, DMA/buffer ownership, cache strategy, worst-case latency, priorities, failure recovery, OTA behavior, compatibility, security, testing, and maintainability.

---

# 22. Failure Notebook

Real failures encountered during Track 1 should be preserved because debugging experience is one of the highest-value outputs of the track. Each entry should preserve symptoms, context, hypotheses, experiments, observations, root cause, fix, why it works, misleading fixes, unfamiliar-MCU diagnostic approach, prevention/production design, and interview variations.

---

# 23. Interview Preparation Index

This section will eventually aggregate questions and scenarios accumulated during learning across C/C++, Cortex-M, assembly/ABI, compiler/linker/startup, memory, clocks/reset, peripherals, interrupts/faults, DMA, cache/MPU/barriers, RTOS, networking/storage, multicore, bootloader, OTA/security, reliability, debugging, performance, and Senior/Principal architecture.

---

# 24. Current Learning Position

We are at the beginning of **MCU Foundations**. We have now consolidated the first electrical GPIO foundation block: MCU/pin boundary, high-impedance inputs, floating nodes, pull-ups/pull-downs, active-low signals, digital thresholds, sender/receiver logic-level compatibility, noise margins, and output loading.

The broader immediate sequence remains CPU execution, registers/assembly, memory map/MMIO, compiler/object/ELF/linking, memory sections/linker scripts, vector table/startup, and ST-LINK/SWD/GDB. When the physical board arrives, real hardware experiments will be integrated into this same path rather than treated as a separate tutorial.

---

# 25. Handbook Maintenance Rule

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
