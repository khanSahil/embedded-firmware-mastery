# Track 1 – Project engineering workflow

Status: **future project workflow; project selection and implementation are paused during foundational labs**

Apply this structure to the chosen project, adjusting module names to its actual problem. Create source files incrementally during labs so each file has a reason to exist.

## Modular C layout

```text
Track_1/Projects/<chosen-project>/
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
  host/
  tests/
    unit/
    integration/
    hardware/
  tools/
```

- `firmware/core/` holds portable decision logic and bounded data structures; keep STM32 headers out of it.
- `firmware/services/` coordinates protocols, diagnostics, persistence, and other domain services through explicit interfaces.
- `firmware/platform/stm32h745/` contains board-specific adapters, startup integration, and chosen vendor libraries. Separate generated from handwritten code.
- `firmware/app/` wires components and owns initialization order.
- `firmware/include/` holds stable shared APIs. Put private headers beside their `.c` files.
- `host/` provides simulators or clients where useful; `tests/` and `tools/` support reproducible verification.
- `docs/` records requirements, module contracts, decisions, failure modes, and measurement evidence.

Each new module must explain its purpose, public API, state/buffer ownership, error behavior, and test seam. Folder and build-tool details can change through reviewed design decisions.

## Simulated multi-engineer integration

Use distinct feature branches, optionally checked out in separate Git worktrees. Rotate the learner through author, reviewer, and integrator roles without fabricating contributor identities.

1. Agree on a small shared interface and behavior contract.
2. Develop an independent core module, a hardware adapter, and a host/test component on separate branches when the project needs them.
3. Open small PRs against `main`; describe requirements, documentation evidence, test results, resource impact, compatibility, and failure handling.
4. Review the diff and revise it. Merge one verified PR, then update remaining branches to current `main`, resolve conflicts, rerun checks, and verify integration.
5. Include a deliberate merge-conflict or interface-change exercise on safe branches after the basic workflow is understood.

`main` remains buildable and retains established behavior. Keep reproducible checkpoints. Add CI and branch protection when the build and checks exist. An actual independent GitHub approval requires another real collaborator; role-play review is a learning exercise.

Intentional-bug exercises remain isolated from the working project. Only a verified fix with regression evidence is integrated.
