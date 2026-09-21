# Embedded Systems Mastery – Three-Track Roadmap

This file preserves the overall multi-year learning roadmap across the three distinct tracks discussed previously.

## Separation rule

Keep Track 1, Track 2, and Track 3 as separate learning programs. Do not merge their progress ledgers or treat them as one continuous curriculum.

Sequence rule:

1. Complete Track 1 first.
2. After Track 1, choose either Track 2 or Track 3 as the next major track.
3. The other track can be taken later.

The learning priority is mastery, retention, debugging depth, and interview confidence rather than finishing by a fixed calendar date.

A topic is not complete merely because it works once. The preferred mastery progression is:

understand → implement → remove abstractions → break → debug → measure → optimize → explain → defend

---

## Track 1 – Embedded Firmware Mastery

### Purpose

Build deep firmware/MCU mastery from C and bare metal through RTOS, boot/update/security, and production-grade embedded engineering.

### Primary platform

STM32H745 / STM32H745I-DISCO family as the main hands-on MCU platform where appropriate.

### Major progression

- embedded C and bare-metal foundations
- MCU / ARM architecture
- drivers and peripheral programming
- interrupts and DMA
- C++ for embedded systems
- FreeRTOS / RTOS internals
- cache, MPU, memory ordering, and performance
- connectivity and storage
- dual-core architecture and synchronization
- bootloader, OTA/update, security, rollback/recovery
- Zephyr
- production debugging and reliability
- Senior / Principal-level capstone work

The current Project curriculum contains a broader detailed Track 1 map and should remain the authoritative source for actual Track 1 progress.

### Earlier planning estimate

Approximately 12–15 months at roughly 7–10 hours/week was discussed as a planning estimate, with up to ~18 months considered acceptable. The learning plan is mastery-driven, not deadline-driven.

Earlier allocation discussed: roughly 60% hands-on / 40% theory.

---

## Track 2 – Embedded Linux / Linux Device Drivers

### Purpose

Build deep Embedded Linux and Linux Device Driver capability, including system programming, kernel internals, BSP/bring-up, drivers, boot flow, Yocto, debugging, production behavior, and update/security concerns.

### Platforms

- Linux PC / VM and QEMU can be used early for concepts and experiments.
- i.MX 8M Plus EVK was identified as the main hardware platform when real board/BSP/driver work is needed.

### Major progression

- Linux system programming
- Linux kernel architecture and internals
- Boot ROM → SPL → U-Boot boot chain
- Device Tree
- kernel modules
- character/platform and related driver models
- interrupts
- concurrency and synchronization
- memory management
- DMA and cache/coherency considerations
- BSP and board bring-up
- kernel debugging and tracing
- Yocto / Buildroot concepts and BSP construction
- userspace integration and systemd
- networking
- secure boot / security concepts
- OTA / field update architecture
- production failure analysis and recovery
- capstone integrating boot, kernel, driver, userspace, and build system layers

### Earlier planning estimate

Approximately 8–10 months, roughly 35–45 weeks at 7–10 hours/week, was discussed as a planning estimate. Track 2 comes after Track 1 if selected next.

---

## Track 3 – Jetson / CUDA / Edge AI / Computer Vision / Robotics

### Purpose

Build GPU-accelerated edge AI, vision, and robotics capability on NVIDIA Jetson, progressing from GPU/CUDA fundamentals to optimized real-time perception and robotics integration.

### Primary platform

NVIDIA Jetson platform.

### Major progression

- Jetson architecture
- GPU architecture and execution model
- CUDA programming
- CUDA memory hierarchy and performance optimization
- profiling and performance analysis
- OpenCV
- camera pipelines
- CSI cameras
- V4L2
- GStreamer
- PyTorch inference concepts
- ONNX
- TensorRT
- FP16 optimization
- INT8 quantization / calibration concepts
- real-time computer vision pipelines
- ROS 2
- Isaac ROS
- perception pipelines
- SLAM concepts
- robotics integration
- end-to-end Jetson/vision/robotics capstone

### Earlier planning estimate

Approximately 9–12 months was discussed as a planning estimate. Track 3 comes after Track 1 if selected next.

---

## Teaching and mastery policy across all three tracks

The same depth-first standard applies to Track 1, Track 2, and Track 3.

For important topics, go beyond definitions and basic demos into, where relevant:

- architecture and first principles
- hardware/software internals
- registers and datasheet-level behavior
- implementation
- adjacent subsystem interactions
- edge cases and failure modes
- concurrency and timing
- performance
- debugging and measurement
- deliberate fault injection
- recovery behavior
- security implications
- production design
- Senior / Principal interview reasoning
- cross-layer integration

Do not assume mastery because the learner has used a technology professionally. Verify understanding from fundamentals, then accelerate only after the learner demonstrates strong depth.