# Accumulator Register - 8 bit

* Arithmetic operations, such as `add` and `sub` accumulator.
* Logical operations, such as `and` , `or` , `xor` , and `not` will operate with and store to the accumlator. 
* Can also be used as a general purpose register.

* Possible eventual implementation of `mult` and `div` which operate upon the accumulator.

# General Purpose 

## 8 Bit Registers

* a
    - also used for ALU arithmetic operations
* b
* c

* Planned later support for additional registers.

## 16 Bit Registers

#### Although support is planned for 16 bit operations, no support with be prevelant in early versions

* bc

* Planned later support for additional registers.
* Little endian

# Special

## Flag Register - 8 bit

* f
* Planned to be not be directly accessible.

* Bits 0 to 3 contain flags
* Bit 0 - Carry flag
* Bit 1 - If last operation was a `sub` operation
* Bit 2 - N/A, planned to be used
* Bit 3 - Zero flag, if last operation resulted in zero

* Bits 4 to 7 are always naught or zero.

## Instruction register

* ir
* Contains current opcode to be decoded

# Memory Registers

## Basic Memory Register

* A 8-bit register

* rl - highest nibble - bits 0 to 3 - Address in memory
* Contains the current address to be read or written to in memory.

* Bits 4 - 7 are always naught or zero.

# Stack Registers

* Programmer's Note, the stack grows downward in memory, the first value on the stack having the highest value address.
* Growing down in memory being the address of the n-th byte on the stack can be calculated `sb-n` .

## Stack Pointer - 8 Bit

#### Stack support may not be initially present

* sp

* Contains current location on the stack.
* Increments and deincrements with operations upon the stack.
* When directly accessed, is read-only.

## Stack Bottom - 8 Bit

* sb

* Contains the bottom of the stack, the highest value address.
* Will be default valued and read-only when accessed.

# Clock (Cycle) Register

* cr

* Contains the current amount of clock cycles completed during the running of the program
* Is updated with each operation performed.
