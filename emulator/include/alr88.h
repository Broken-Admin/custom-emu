#include <types.h>
#include <stdlib.h> // malloc

#define MEMORY_SIZE 8 * 15

// 4-bit addressed memory
// Allocate memory, 15 bytes of memory which can be addressed by the CPU
static byte *memory = NULL;

typedef class alr88
{
public:
    // Define registers and allocate memory for them
    byte *a_register = (byte *)malloc(sizeof(byte));
    byte *b_register = (byte *)malloc(sizeof(byte));
    byte *c_register = (byte *)malloc(sizeof(byte));
    byte *flag_register = (byte *)malloc(sizeof(byte));
    byte *instruction_register = (byte *)malloc(sizeof(byte));
    byte *rl_register = (byte *)malloc(sizeof(byte));
    byte *pc_register = (byte *)malloc(sizeof(byte));

    // Constructor to initialize values and allocate memory
    alr88()
    {
        // Allocate memory
        memory = (byte *)malloc(MEMORY_SIZE);
        // Intialize values
        *a_register = byte(0x00);
        *b_register = byte(0x00);
        *c_register = byte(0x00);
        *flag_register = byte(0x00);
        *instruction_register = byte(0x00);
        *rl_register = byte(0x00);
    }

    // Future plans for the implementation of RAM and RAM banks
    // and the basic handling of a MBC

    // Read byte from address to destination register
    void read_byte(nibble address, byte *destination)
    {
        // A nibble type (see types.h) cannot be used to
        // address a location
        uint8_t addressNum = uint8_t(address.to_ullong());
        *destination = memory[addressNum];
    }
    // Write byte to address from origin register
    void write_byte(nibble address, byte *origin)
    {
        // A nibble or byte type (see types.h) cannot be used to
        // address a location
        uint8_t originNum = uint8_t(origin->to_ullong());
        uint8_t addressNum = uint8_t(address.to_ullong());
        memory[addressNum] = originNum;
    }

    // Load a byte register to another byte register
    void ld_bregister_bregister(byte *origin, byte *destination)
    {
        *destination = *origin;
    }
    // Load an immediate byte value to a byte register
    void ld_immediate_bregister(byte immediate, byte *destination)
    {
        *destination = immediate;
    }
} alr88;