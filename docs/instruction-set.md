# Instruction Set

* Each instruction takes at least 1 byte, or 8 bits

* Placeholders
    - `r` - Any general-purpose register
    - `n` - Any 8-bit immediate number value

* Formatting
    - Immediate hex code value should be formatted with a leading `$` | E.g. `$0A` , `$FF` 
    - Immediate binary values should be formatted with a leading `%` | E.g. `%10101100` , `%00001111` 

## Loads - 8-bit

* `ldx r` operations
    - Basic load operations
    - Does not update flags

    - `lda r` 
        - load `r` into the accumulator or the general-purpose `a` register

    - `ldb r` 
        - load `r` into the general-purpose `b` register

    - `ldc r` 
        - load `r` into the general-purpose `c` register

* `ldr n` operations
    - load immediate value `n` into register given register
    - Does not update flags

    - `lda n` 

        - load immediate `n` into the accumulator or the general-purpose `a` register

    - `ldb n` 
        - load immediate `n` into the general-purpose `b` register

    - `ldc n` 
        - load immediate `n` into the general-purpose `c` register

## Logical Operations - 8-bit

#### Logical operations store to the accumulator, or the " `a` register"

#### If no `r` register is specified, defaults to perform the logical operation upon the `a` register

#### Updates the zero flag

* `and r/n` 
    - perform a logical `and` with the `a` register and register `'r'` or immediate value `n` 

* `or r/n` 
    - perform a logical `or` with the `a` register and register `'r'` or immediate value `n` 

* `xor r/n` 
    - perform a logical `xor` with the `a` register and register `'r'` or immediate value `n` 

* `not r/n` 
    - perform a logical `not` with the `'r'` register or immediate value `n` 

# OpCodes

|    | x0     | x1    | x2    | x3    | x4      | x5    | x6    | x7    | x8      | x9    | xA    | xB    | xC      | xD   | xE   | xF   |
|----|--------|-------|-------|-------|---------|-------|-------|-------|---------|-------|-------|-------|---------|------|------|------|
| 0x | LDA A  | LDA B | LDA C | LDB A | LDB B   | LDB C | LDC A | LDC B | LDC C   | AND A | AND B | AND C | AND `n` | OR A | OR B | OR C |
| 1x | OR `n` | XOR A | XOR B | XOR C | XOR `n` | NOT A | NOT B | NOT C | NOT `n` |       |       |       |         |      |      |      |
| 2x |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| 3x |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| 4x |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| 5x |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| 6x |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| 7x |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| 8x |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| 9x |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| Ax |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| Bx |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| Cx |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| Dx |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| Ex |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |
| Fx |        |       |       |       |         |       |       |       |         |       |       |       |         |      |      |      |

[Update the table](https://www.tablesgenerator.com/markdown_tables)
