# Instruction Set

* Each instruction takes at least 1 byte, or 8 bits

## Loads - 8-bit

* `ldx r` operations
    - Basic load operations
    - Does not update flags
    - `r` being any 8-bit general purpose register

* `lda r` 
    - load `r` into the accumulator or the `a` register

* `ldb r` 
    - load `r` into the general-purpose `b` register

* `ldc r` 
    - load `r` into the general-purpose `c` register

# OpCodes

|     | x0    | x1    | x2    | x3    | x4    | x5    | x6    | x7    | x8    | x9 | xA | xB | xC | xD | xE | xF |
|-----|-------|-------|-------|-------|-------|-------|-------|-------|-------|----|----|----|----|----|----|----|
| 0x  | LDA A | LDA B | LDA C | LDB A | LDB B | LDB C | LDC A | LDC B | LDC C |    |    |    |    |    |    |    |
| 1x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| 2x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| 3x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| 4x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| 5x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| 6x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| 7x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| 8x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| 9x  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
|  Ax |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| Bx  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| Cx  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| Dx  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
| Ex  |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |
|  Fx |       |       |       |       |       |       |       |       |       |    |    |    |    |    |    |    |

[Update the table (https://www.tablesgenerator.com/markdown_tables)
