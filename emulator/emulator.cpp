#include <alr88.h>

int main()
{

    alr88 CPU = alr88();
    u_char *file_buffer;
    file_buffer = CPU.load_instruction_file("basic-instruction-file.o");
    printf("File buffer bit size : %i\n", sizeof(file_buffer));
    printf("Memory Location 0 : %i\n", memory[0]);
    printf("Register A : %i\n", *CPU.a_register);

    // Basic Implementation of the machine-code interpretation
    // Code 0x03 is different than currently documented
    while (file_buffer[CPU.pc_register->to_ulong()] != *nullByte)
    {
        CPU.load_instruction(CPU.pc_register->to_ulong(), file_buffer);
        printf("Instruction Register : 0x%X\n", CPU.instruction_register->to_ulong());
        switch (CPU.instruction_register->to_ulong())
        {
        case 0x00:
            CPU.ld_bregister_bregister(CPU.a_register, CPU.a_register);
            break;
        case 0x01:
            CPU.ld_bregister_bregister(CPU.b_register, CPU.a_register);
            break;
        case 0x02:
            CPU.ld_bregister_bregister(CPU.c_register, CPU.a_register);
        case 0x03:
            CPU.load_next_instruction(file_buffer);
            CPU.ld_immediate_bregister(byte(CPU.instruction_register->to_ulong()), CPU.a_register);
            break;
        default:
            break;
        }
    }
    printf("Register A : %i\n", *CPU.a_register);
}