# Track 1 – Embedded Firmware Mastery Curriculum

This is the long-term curriculum map. It is intentionally broad and can evolve as the learner progresses.

This file is **Track 1 only**. The overall three-track roadmap is preserved in `Tracks-Overview.md`; Track 2 and Track 3 should not be folded into Track 1 progress.

## Phase 1 – Embedded C and Bare-Metal Foundations

Goal: build a precise model of how C maps to CPU execution, memory, compiler behavior, and hardware.

### Section 1 – MCU / Hardware Foundations

- MCU mental model
- memory map
- MMIO
- Flash / RAM / peripheral regions
- clocks and reset
- GPIO electrical foundations
- how software interacts with hardware registers

### Section 2 – Generic CPU Execution

- instructions
- CPU registers
- Program Counter
- LOAD / STORE
- arithmetic and branch instructions
- fetch-decode-execute cycle
- stack
- Stack Pointer
- Link Register
- function calls
- stack frames
- recursion

### Section 3 – Binary & Bit Manipulation

- binary representation
- hexadecimal representation
- AND / OR / XOR / NOT
- left and right shifts
- masks
- setting bits
- clearing bits
- toggling bits
- testing bits
- register-field manipulation

### Section 4 – Integer Representation / Arithmetic

- signed vs unsigned integers
- two's complement
- integer ranges
- overflow
- unsigned wraparound
- signed-overflow concerns
- CPU arithmetic flags at a conceptual level

### Section 5 – Memory Representation

- byte-addressed memory
- multi-byte objects
- endianness
- alignment
- object representation
- how integer values appear as bytes in memory

### Section 6 – C Memory & Pointer Foundations

- pointer declaration and types
- address-of operator
- dereference operator
- typed pointer semantics
- pointer size vs pointed-to type
- pointer arithmetic
- scaling by element size
- pointer subtraction
- pointer comparison
- one-past-the-end rule
- arrays and pointer decay
- `&arr` vs `arr`
- multidimensional arrays
- pointer-to-pointer
- const with pointers
- structures
- padding and alignment
- void pointers
- null pointers
- dangling pointers
- wild / uninitialized pointers
- object lifetime
- strict aliasing
- pointer casts
- integer / pointer conversion
- function pointers
- MMIO pointers
- volatile pointer patterns
- pointer-related undefined behavior
- debugger inspection
- firmware failure scenarios
- Senior / Principal interview questions

### Section 7 – Embedded-C Semantics

- `volatile`
- `const`
- `const volatile`
- fixed-width integer types
- safe bit manipulation
- implementation-defined behavior
- undefined behavior
- compiler assumptions relevant to firmware

### Section 8 – Concurrency Foundations

- atomicity
- read-modify-write operations
- race conditions
- shared state
- interrupts and concurrent modification
- why `volatile` does not imply atomicity or thread safety

### Section 9 – Compiler & Build Pipeline

- preprocessing
- compilation
- assembly
- object files
- linking
- symbols
- relocation basics
- translation units
- optimization implications

### Section 10 – Program Memory Layout

- `.text`
- `.rodata`
- `.data`
- `.bss`
- stack
- heap
- where each region lives conceptually and why

### Section 11 – ELF Fundamentals

- ELF sections
- symbols
- map files
- `objdump` basics
- `readelf` basics
- inspecting compiled firmware artifacts

### Section 12 – Linker Script Fundamentals

- Flash / RAM placement
- `MEMORY`
- `SECTIONS`
- VMA vs LMA
- linker-defined symbols
- mapping program sections into physical memory

### Section 13 – Startup / Boot Fundamentals

- reset
- initial stack pointer concept
- startup code
- copying `.data`
- zeroing `.bss`
- transition into `main()`

### Section 14 – Bare-Metal Firmware Structure

- initialization
- superloop architecture
- polling
- state-machine thinking
- driver / application separation

### Section 15 – Debugging Foundations

- debugger mental model
- breakpoints
- watchpoints
- CPU register inspection
- memory inspection
- disassembly
- stepping
- debugging optimized code

Current progress:

- Sections 1–5: covered previously. Exact mastery should be revalidated where needed rather than assumed.
- Section 6: in progress.
- Latest checkpoint: pointer comparison and one-past-the-end basics covered; arrays and pointer decay next.

## Phase 2 – MCU Architecture and Hardware Fundamentals

- CPU core model
- privilege levels / execution modes where applicable
- memory map
- SRAM / Flash / ROM
- buses
- peripheral register model
- clock tree
- reset sources
- GPIO
- timers
- watchdog
- interrupt controller
- low-power modes
- boot sequence

## Phase 3 – Interrupts, Concurrency, and Timing

- interrupt entry/exit
- vector tables
- priority
- nesting
- latency
- critical sections
- atomicity
- race conditions
- lock-free considerations
- ISR design
- deferred work
- timer-driven systems
- jitter
- deterministic timing

## Phase 4 – Peripheral Protocols

### UART
- framing
- baud generation
- FIFOs
- interrupts
- DMA
- error handling
- debugging

### SPI
- modes
- chip select
- timing
- full duplex
- controller/target behavior
- DMA
- failure cases

### I2C / SMBus
- electrical model
- open drain
- pull-ups
- START/STOP
- ACK/NACK
- arbitration
- clock stretching
- bus recovery
- SMBus differences
- SSIF relevance

### Additional interfaces
- CAN where useful
- USB fundamentals where useful
- PCIe conceptual foundation where useful

## Phase 5 – DMA, Caches, and Memory Ordering

- DMA architecture
- descriptors
- scatter/gather
- cache coherency
- cache maintenance
- barriers
- ordering
- ownership transfer
- zero-copy
- common corruption bugs
- debugging

## Phase 6 – Linkers, Startup, Boot, and Firmware Images

- ELF
- sections
- symbols
- relocation
- linker scripts
- startup assembly
- vector table
- `.data` copy
- `.bss` zeroing
- stack initialization
- boot ROM
- first-stage bootloader
- second-stage bootloader
- firmware image layout
- secure boot concepts
- OTA/update architecture
- rollback/recovery

## Phase 7 – RTOS Mastery

- scheduler
- tasks/threads
- context switch
- priorities
- mutexes
- semaphores
- queues
- event groups
- timers
- priority inversion
- deadlock
- stack sizing
- heap strategies
- ISR/RTOS interaction
- real-time analysis
- debugging

## Phase 8 – Embedded Linux Foundations

- boot chain
- kernel architecture
- process/thread model
- virtual memory
- syscalls
- device model
- sysfs
- procfs
- udev
- systemd
- memory management
- networking basics
- tracing and debugging

## Phase 9 – Linux Device Drivers

- kernel modules
- character drivers
- platform drivers
- device tree
- regmap
- interrupts
- GPIO
- I2C
- SPI
- DMA
- workqueues
- threaded IRQs
- locking
- memory mapping
- user/kernel interfaces
- debugging and tracing

## Phase 10 – BMC / OpenBMC Deep Dive

- BMC architecture
- AST2600 / AST2500 concepts
- OpenBMC Yocto architecture
- D-Bus
- sdbusplus
- phosphor services
- IPMI
- KCS
- SSIF
- PLDM
- MCTP
- SEL
- host/BMC interaction
- sensors
- power control
- firmware update
- Redfish
- networking
- service debugging
- boot and failure analysis

## Phase 11 – Production Firmware Engineering

- observability
- logging
- crash analysis
- watchdog strategy
- fault injection
- brownout/reset analysis
- memory corruption
- stack overflow
- performance profiling
- long-duration testing
- reliability
- secure coding
- CI
- HIL testing
- manufacturing considerations
- field recovery

## Phase 12 – Senior / Principal-Level Integration

- architecture tradeoffs
- subsystem boundaries
- performance and reliability tradeoffs
- debugging unfamiliar systems
- incident analysis
- design reviews
- hardware/software co-debugging
- mentoring
- interview preparation
- end-to-end capstone systems

---

# Current detailed section

## Phase 1 – Section 6: C Memory & Pointer Foundations

Planned coverage:

- pointer declaration and types
- address-of operator
- dereference operator
- typed pointer semantics
- pointer size vs pointed-to type
- pointer arithmetic
- scaling by element size
- pointer subtraction
- pointer comparison
- one-past-the-end rule
- arrays and pointer decay
- `&arr` vs `arr`
- multidimensional arrays
- pointer-to-pointer
- const with pointers
- void pointers
- null pointers
- dangling pointers
- wild/uninitialized pointers
- lifetime
- strict aliasing
- alignment
- pointer casts
- integer/pointer conversion
- function pointers
- MMIO pointers
- volatile pointer patterns
- pointer-related undefined behavior
- debugger inspection
- firmware failure scenarios
- interview questions