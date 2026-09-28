# Board Lab 00 — factory flash backup

Added: 2026-09-28 (America/Los_Angeles).

`STM32_Disco_Board_Original_Shipped_Firmware.bin` is the learner's STM32CubeProgrammer **Read All → Save As** dump of the STM32H745I-DISCO internal flash, made before writing new board firmware.

| Field | Value |
| --- | --- |
| Board label | STM32H745I-DISCO; MB1381-H745XI-B03 |
| Reported read start | `0x08000000` |
| File size | 2,097,152 bytes (2 MiB) |
| SHA-256 | `961d7faa8833fb785141d3e9af8d6dee751661c4c3f67a3680e709d6a91d562c` |
| Git blob SHA-1 | `8a618054a226bdf5599fcbc40285dd6f7c079e04` |
| Verification | Local file size, checksum, and initial vector words checked; a file-to-device comparison remains pending |

This captures internal flash only. A complete restoration of the factory demonstration may also require resources stored outside internal flash. Verify the image against the device in STM32CubeProgrammer before relying on it for restoration.
