# Track 1 documentation register

Use this index to find the primary documents behind Track 1 labs. The [STM32H745I-DISCO documentation page](https://www.st.com/en/evaluation-tools/stm32h745i-disco.html#documentation) is the starting point for current downloads. Record the document revision, the board revision when applicable, and the exact page, figure, table, or section used in each lab. Source links may receive later revisions from ST.

## STM32H745I-DISCO board and STM32H745XI MCU

| Document | What it answers | Track 1 usage |
| --- | --- | --- |
| [Board data brief DB3741](https://www.st.com/resource/en/data_brief/stm32h745i-disco.pdf) | Board features, board identities, and location/format of the board revision marking. | Consulted for Board Lab 00: §2.1 identifies the main-board sticker and revision format. Rev 4 (May 2025) was consulted on 2026-09-27. |
| [Board user manual UM2488](https://www.st.com/resource/en/user_manual/um2488-discovery-kits-with-stm32h745xi-and-stm32h750xb-mcus-stmicroelectronics.pdf) | Board layout, power selection, STLINK-V3E, LEDs, and demo behavior. | Board Lab 00: §3.3 (preloaded demonstration), Figures 4–5 (JP8/CN14), §§6.3–6.4 (ST-LINK power/USB enumeration), LED lookup underway; the learner will choose and identify a user LED independently. Rev 10 (April 2025) was consulted on 2026-09-27. |
| [Main-board schematics: choose MB1381-H745XI revision](https://www.st.com/en/evaluation-tools/stm32h745i-disco.html#documentation) | Actual user LED circuits, component values, signal connections, and LED polarity. | Board Lab 00: revision of the physical main board still to be read. ST currently lists B01, B02, B03, and B04 schematic packs; record the matching schematic and page after checking the board sticker. MB1280 is the separate STMod+ fan-out board. |
| [STM32H745xI/G datasheet DS12923](https://www.st.com/resource/en/datasheet/stm32h745xi.pdf) | MCU pin functions, packages, memory size, electrical characteristics, and limits. | Reference identified; no Board Lab 00 fact taken from it yet. |
| [STM32H745/755 and STM32H747/757 reference manual RM0399](https://www.st.com/resource/en/reference_manual/rm0399-stm32h745755-and-stm32h747757-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) | Clock and GPIO peripheral registers and MCU behavior. | Reference identified; register-level lookup pending. |

The board manual describes **what the board connects**. The board schematic resolves **how a specific board revision wires it**. The MCU datasheet provides **pin and electrical limits**. The MCU reference manual describes **peripheral register behavior**.

## Add a source as labs progress

For each new source, record:

- Official document title, number, link, revision/date, and applicable board/MCU variant.
- Lab number and the specific page/section/table used.
- The fact derived from it and the behavior verified on hardware.
- Any discrepancy between a document, a schematic, and the observed board.

Match the MB1381 schematic to the physical main-board revision before interpreting a selected LED circuit. During an active lookup, use the document link as the prompt; add exact sections and derived facts here after the learner has completed that lookup.
