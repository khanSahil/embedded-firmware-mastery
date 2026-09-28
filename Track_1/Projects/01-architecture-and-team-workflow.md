# Project 1 – Source layout and team workflow

Status: **proposed architecture for implementation labs**

This document defines how the connected device supervisor and recovery platform will grow as a maintainable C project. Create the directories and files incrementally in labs; each addition should have a real responsibility and a working check. The exact build tool and generated STM32 code layout will be chosen during board bring-up.

## Repository layout

```text
Track_1/Projects/
  01-device-health-and-recovery.md
  01-architecture-and-team-workflow.md
  device-supervisor/
    README.md
    docs/
      requirements/
      decisions/
      interfaces/
    firmware/
      app/
      core/
      services/
      platform/
        stm32h745/
      include/
        supervisor/
    host/
      simulator/
      client/
    tests/
      unit/
      integration/
      hardware/
    tools/
```

- `firmware/core/`: portable C logic such as health state machine, bounded event queue, deadline logic, and recovery policy. This code should not include STM32 HAL headers.
- `firmware/services/`: event journal, command protocol, diagnostics, and orchestration that depend on explicit interfaces.
- `firmware/platform/stm32h745/`: board-specific startup integration, clocks, GPIO, timers, UART, storage, reset-cause reading, and adapters to chosen vendor libraries. Keep generated code clearly separated from handwritten code.
- `firmware/app/`: composition, initialization order, main loop or task wiring; little policy logic.
- `firmware/include/supervisor/`: stable headers shared across modules. Put private headers beside their implementation files; use ownership and dependency direction to decide when a header becomes public.
- `host/`: a simulated managed device and later a Linux client. Reuse portable core code where appropriate.
- `tests/`: unit checks for portable logic, integration checks for module contracts, and hardware procedures/automation where practical.
- `docs/` and `tools/`: reviewed requirements, design decisions, protocol schemas, reproducible build/debug commands, and helper scripts.

Illustrative files will appear only when needed: `health_monitor.c/.h`, `event_ring.c/.h`, `recovery_policy.c/.h`, `uart_transport.c/.h`, `host/simulator/main.c`. A new module must state its API, ownership of buffers/state, error behavior, and test seam.

## Simulating a multi-engineer team

Use separate feature branches, optionally separate Git worktrees, to model concurrent contributors without fabricating human identities.

Example integration exercise:

1. **Contract proposal:** agree on a small versioned heartbeat/event API and its error and timing semantics in a design PR.
2. **Engineer A role:** implement the portable health state machine on `feature/P1-Lxx-health-core` with host-side tests.
3. **Engineer B role:** implement the STM32 transport adapter on `feature/P1-Lyy-uart-transport` against the agreed header, with fakes until the board is ready.
4. **Engineer C role:** implement the host simulator and protocol checks on `feature/P1-Lzz-host-simulator`.
5. Open small PRs to `main`. For each, review contract compatibility, failure cases, tests, memory/timing impact, and documentation. Revise the PR in response.
6. Merge one PR at a time after checks pass. Update later branches to current `main`, resolve any conflict, rerun checks, and verify the integrated behavior.
7. Record the integration issue and the reason for the final resolution. A later lab can deliberately create a safe merge-conflict scenario on exercise branches.

Rotate through author, integrator, and reviewer roles. Use truthful Git attribution. A simulated review is a learning exercise; an enforced independent GitHub approval requires another real collaborator. Do not merge intentionally broken exercises to `main`.

## Mainline expectations

- `main` remains buildable and retains established behavior. Each lab has a reproducible commit or tag.
- A PR states the requirement, changed modules, relevant ST documentation, verification evidence, failure modes, and compatibility impact.
- Portable unit and integration checks run before merge; board checks run when hardware is required. Add CI checks as the build becomes available.
- API or log-format changes are discussed before dependent branches implement them. Use versioning or explicit migration when compatibility matters.
- Prefer one clear owner per module at a time, but require cross-module review for shared headers and behavior.

GitHub branch protection and required checks can be enabled after working CI exists. Avoid claiming that a single account's role-play provides an independent reviewer.
