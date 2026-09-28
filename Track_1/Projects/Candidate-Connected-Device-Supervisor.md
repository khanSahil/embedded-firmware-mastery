# Candidate – Connected Device Supervisor and Recovery Platform

Status: **proposal for discussion; no project has been selected**

This is one possible first production-style Track 1 project. Evaluate it alongside alternatives before committing to a roadmap or creating implementation branches. The agreed [engineering workflow](Engineering-Workflow.md) applies whichever project is chosen.

## Problem it would address

A field-deployed controller or appliance can stop responding, lose connectivity, corrupt persistent state, or fail during an update. An STM32H745I-DISCO-based supervisor could observe a managed device, record diagnostic evidence, make bounded recovery decisions, and expose status to an operator.

A program on the development computer could simulate the managed device initially. This would let labs test heartbeat loss, reset requests, intermittent communication, and recovery without additional hardware. Later stages could include a Linux-side client.

## Why it might be a good learning project

It can connect portable C modules, board bring-up, timers, interrupts, protocols, persistence, watchdogs, fault injection, update/recovery design, resource budgets, and cross-system interfaces. Its engineering questions include false failure detection, escalation, loss of power during writes, diagnostic retention, safe defaults, and compatibility across firmware versions.

Potential scope is broad. The Discovery board would serve as a learning platform for production engineering methods; any claim of deployment readiness would require separate product hardware, validation, and qualification.

## Questions to settle before selecting it

- What concrete device or process is supervised, and what observable failure signals exist?
- What actions are safe for the supervisor to take, and who authorizes them?
- What minimum reliable version is useful before adding storage or networking?
- Which acceptance criteria and failure cases make this a stronger learning vehicle than other candidate projects?
- How should the work map to the current curriculum without pulling later concepts forward?

No implementation milestones or lab numbers are committed until the project is mutually selected.
