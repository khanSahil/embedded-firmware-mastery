# Track 1 documentation register

Use this index to find the primary documents behind Track 1 labs. The [STM32H745I-DISCO documentation page](https://www.st.com/en/evaluation-tools/stm32h745i-disco.html#documentation) is the starting point for current downloads. Record the document revision, the board revision when applicable, and the exact page, figure, table, or section used in each lab. Source links may receive later revisions from ST.

## STM32H745I-DISCO board and STM32H745XI MCU

| Document | What it answers | Track 1 usage | Added to register (PT) |
| --- | --- | --- | --- |
| [Board data brief DB3741](https://www.st.com/resource/en/data_brief/stm32h745i-disco.pdf) | Board features, board identities, and location/format of the board revision marking. | Consulted for Board Lab 00: §2.1 identifies the main-board sticker and revision format. Rev 4 (May 2025) was consulted on 2026-09-27. | 2026-09-27 |
| [Board user manual UM2488](https://www.st.com/resource/en/user_manual/um2488-discovery-kits-with-stm32h745xi-and-stm32h750xb-mcus-stmicroelectronics.pdf) | Board layout, power selection, STLINK-V3E, LEDs, and demo behavior. | Board Lab 00: §3.3 (preloaded demonstration), Figures 4–5 (JP8/CN14), §§6.3–6.4 (ST-LINK power/USB enumeration), learner selected green user LED LD7 and identified its MCU connection as PJ2. Rev 10 (April 2025) was consulted on 2026-09-27. | 2026-09-27 |
| [MB1381-H745XI-B03 main-board schematic](https://www.st.com/resource/en/schematic_pack/mb1381-h745xi-b03-schematic.pdf) | Actual user LED circuits, component values, signal connections, and LED polarity. | Board Lab 00: the physical main-board sticker reads `MB1381-H745XI-B03`; ST lists the B03 schematic pack as version 3.0 (November 2024). The learner traced the green LD7 circuit: 3V3 feeds LD7 through R233 (510 Ω), then PJ2 sinks current through the LED1 net when driven low. Thus LD7 is active low; the drive-level conclusion was verified against the B03 schematic excerpt on 2026-09-27. MB1280 is a separate STMod+ fan-out board. | 2026-09-27 |
| [STM32CubeProgrammer user manual UM2237](https://www.st.com/resource/en/user_manual/dm00403500-stm32cubeprogrammer-stmicroelectronics.pdf) | Reading, saving, programming, and verifying target memory in the programmer. | Board Lab 00: restoration planning before the factory demo is overwritten; no procedure or backup is completed yet. | 2026-09-27 |
| [STM32H745xI/G datasheet DS12923](https://www.st.com/resource/en/datasheet/stm32h745xi.pdf) | MCU pin functions, packages, memory size, electrical characteristics, and limits. | Reference identified; no Board Lab 00 fact taken from it yet. | 2026-09-27 |
| [STM32H745/755 and STM32H747/757 reference manual RM0399](https://www.st.com/resource/en/reference_manual/rm0399-stm32h745755-and-stm32h747757-advanced-armbased-32bit-mcus-stmicroelectronics.pdf) | Clock and GPIO peripheral registers and MCU behavior. | Reference identified; register-level lookup pending. | 2026-09-27 |

The board manual describes **what the board connects**. The board schematic resolves **how a specific board revision wires it**. The MCU datasheet provides **pin and electrical limits**. The MCU reference manual describes **peripheral register behavior**.

## Add a source as labs progress

For each new source, record:

- Official document title, number, link, revision/date, and applicable board/MCU variant.
- The date the link was added to this register in the learner's local time zone (America/Los_Angeles), distinct from the document's publication or revision date.
- Lab number and the specific page/section/table used.
- The fact derived from it and the behavior verified on hardware.
- Any discrepancy between a document, a schematic, and the observed board.

Match the MB1381 schematic to the physical main-board revision before interpreting a selected LED circuit. During an active lookup, use the document link as the prompt; add exact sections and derived facts here after the learner has completed that lookup.
