# Project 1 – Connected Device Supervisor and Recovery Platform

Status: **selected project; implementation has not started**

Source modules, header ownership, repository layout, and the simulated team integration workflow are described in [Project 1 – Source layout and team workflow](01-architecture-and-team-workflow.md).

## Real-world problem

A deployed controller or appliance can hang, lose connectivity, exhaust resources, corrupt its persistent state, or fail during an update. Build an STM32H745I-DISCO-based supervisor that observes a managed device, records evidence, makes bounded recovery decisions, and exposes enough diagnostics for an operator to understand what happened.

Initially, a program on the development computer can act as the managed device and send heartbeats or fault reports. Recovery outputs can be simulated and verified before connecting external equipment. Later, a Linux-side management component can exercise the cross-system contract. This is a learning platform for production firmware engineering, not a claim that a Discovery board is a certified product or a complete server BMC.

Track 1 may include multiple substantial projects. This is Project 1 because it spans system bring-up, firmware architecture, protocols, reliability, storage, concurrency, debugging, updates, and host integration. Additional projects can target other production domains.

## End-state behavior

- Detect healthy, degraded, and unresponsive states from explicit signals and timeouts.
- Keep a bounded event history with timestamps, reset causes, and diagnostic context.
- Make recovery decisions through a documented state machine with rate limits, escalation, and a safe fallback.
- Serve local diagnostics and later expose a versioned host/network interface.
- Preserve critical evidence through reset and tolerate interrupted writes where feasible.
- Support an update and recovery path with authenticity and rollback considerations at the appropriate curriculum stage.
- Explain and measure timing, memory, power, reliability, and security tradeoffs.

## Engineering requirements for each stage

Each feature gets a clear contract and failure behavior. We will use primary ST documentation to derive register, pin, electrical, and timing facts. Keep modules testable on the host where possible and confirm board-dependent behavior on hardware.

Review resource budgets, bounds, concurrency ownership, timeout behavior, reset behavior, storage integrity, and observability as they become relevant. Add fault injection and regression checks for real failure paths. Use design notes to record alternatives, assumptions, evidence, and consequences. Choose numerical acceptance thresholds from requirements and measurements rather than inventing impressive targets.

## Provisional progression

These are milestone groups, not a rigid lab count or permission to skip prerequisites. Every regular lab contributes a usable feature, module, project-relevant test, tool, or implementation document. Independent labs can be integrated after verification; related labs may build directly on earlier work.

| Milestone | Contributions and evidence |
| --- | --- |
| Portable core | Host build, event schema, bounded buffer, state machine, parser, unit tests, design notes |
| Board bring-up | Reproducible build/flash/debug procedure, status indication, input capture, register and debugger observations |
| Supervision | Heartbeat protocol, deadlines, health transitions, hysteresis, bounded recovery policy, timing measurements |
| Diagnostics | Reset-cause capture, fault record, local command interface, useful error classification |
| Persistence | Storage abstraction, integrity checks, interrupted-write recovery, retention and wear tradeoffs |
| Connectivity | Versioned host interface, Linux-side test client, disconnect/retry behavior, load and backpressure tests |
| Reliability and updates | Watchdog, fault injection, long-run checks, update/rollback design and implementation when prerequisite concepts are ready |

Do not schedule board-heavy implementation before the curriculum's planned board acclimation in Phase 1 Sections 14–15. Earlier C labs can provide portable project components or tests. Later subsystems such as RTOS, DMA/cache, dual-core coordination, secure update, and Linux management are introduced only after their foundations are learned.

## Lab integration rule

- Begin from a known working revision; an independent module may be developed on its own branch.
- For each lab, record the requirement, source documentation, predicted result, observed evidence, design choice, code/tests, and remaining risk in `Track_1/Labs.md`.
- Verify the new behavior and affected earlier capabilities; keep completed stages reproducible with Git history.
- Keep intentional-bug exercises isolated from the working project. Integrate a discovered real fix only with evidence and an appropriate regression check.

The next concrete step is a scoped Project 1 requirements and architecture exercise at the learner's current readiness level, followed by the first lab specification when its prerequisites are met.
