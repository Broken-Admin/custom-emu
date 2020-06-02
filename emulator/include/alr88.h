#include <types.h>
#include <stdlib.h> // malloc
#include <stdio.h>  // file operations

#define MEMORY_SIZE sizeof(byte) * 15

// 4-bit addressed memory
// Allocate memory, 15 bytes of memory which can be addressed by the CPU
static byte *memory = NULL;

typedef class alr88
{
public:
    byte *ROM = (byte *)malloc(byte("11111111").to_ulong() * sizeof(byte));
    byte *RAM = (byte *)malloc(byte("11111111").to_ulong() * sizeof(byte));

    // Define registers and allocate memory for them
    byte *a_register = (byte *)malloc(sizeof(byte));           // General purpose a register / accumulator
    byte *b_register = (byte *)malloc(sizeof(byte));           // General purpose b register
    byte *c_register = (byte *)malloc(sizeof(byte));           // General purpose c register
    byte *flag_register = (byte *)malloc(sizeof(byte));        // Flag register
    byte *instruction_register = (byte *)malloc(sizeof(byte)); // Instruction register
    byte *rl_register = (byte *)malloc(sizeof(byte));          // Ram / memory location register
    byte *pc_register = (byte *)malloc(sizeof(byte));          // Program counter register

    // Constructor to initialize values and allocate memory
    alr88()
    {
        // Future plans for the implementation of RAM and RAM banks
        // and the basic handling of a MBC
        // Intialize values
        *a_register = byte(0x00);
        *b_register = byte(0x00);
        *c_register = byte(0x00);
        *flag_register = byte(0x00);
        *instruction_register = byte(0x00);
        *pc_register = byte(0x00);
        *rl_register = byte(0x00);
    }

    // Open the given file, allocate a pointer space to store the file
    // if the file could not be opened, return an empty pointer
    u_char *load_instruction_file(const char *filename)
    {
        FILE *f = fopen(filename, "rb");

        u_char *buffer;

        // Allocate space for a single byte in the buffer
        buffer = (u_char *)malloc(sizeof(byte));

        // Preload the first byte of the buffer with a null byte
        buffer[0] = *nullByte;

        if (f == NULL)
        // If the file could not be opened
        // return a single null byte
        {
            printf("error: Couldn't open %s\n", filename);
            return (buffer);
        }

        //Get the file size and read it into a memory buffer
        fseek(f, 0L, SEEK_END);
        int fsize = ftell(f);

        if (fsize >= 255)
        // If the file is larger than a byte can address, return an empty byte
        // In-future, load the file into seperate ROM banks which can be swapped
        // by an MBC and then addressed
        {
            printf("error: Couldn't open %s\nFile is incapable of being completely addressed by the CPU\n", filename);
            return (buffer);
        }

        fseek(f, 0L, SEEK_SET);

        // Allocate space to the buffer
        // to store the file's contents
        buffer = (u_char *)malloc((fsize + 1) * sizeof(buffer));

        // Read the file to the buffer
        fread(buffer, fsize, 1, f);
        // Store a null byte behind the file's end
        buffer[fsize + 1] = *nullByte;
        // Close the file
        fclose(f);

        // In-future possibly reset the program counter

        // Return the buffer
        return (buffer);
    }

    // In-future update "instruction" loading titles to specify
    //the loading of a byte instead of only instructions

    // Load an instruction or from the file's buffer to the
    // instruction register
    void load_instruction(byte address, u_char *buffer)
    {
        // A byte type (see types.h) cannot be used to
        // address a location
        ulong addressNum = address.to_ulong();
        *instruction_register = buffer[addressNum];
        *pc_register = byte(pc_register->to_ulong() + 1);
    }

    // Load the next instruction or byte by use of the load_instruction function
    void load_next_instruction(u_char *buffer)
    {

        load_instruction(*pc_register, buffer);
    }

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