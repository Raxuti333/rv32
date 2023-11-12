#include <emulator.h>
#include <operations.h>

#include <stdio.h>

#define a0 ((Emulator*)emulator)->registers[10]
#define a1 ((Emulator*)emulator)->registers[11]
#define a7 ((Emulator*)emulator)->registers[17]
#define imm (instruction >> 20) & 0b111111111111
#define M ((Emulator*)emulator)->memory
#define PC ((Emulator*)emulator)->pc

void ecall(void* emulator, uint32_t instruction)
{
    switch(a7)
    {
        case 1: printf("%i", (int32_t)a0); break;
        case 4: printf("%s", (char*)&M[a0]); break;
        case 5: scanf("%i", &a0); break;
        case 8: fgets(&M[a0], a1, stdin); break;
        case 10: PC = UINT32_MAX; break;
        case 11: printf("%c", a0); break;
        case 12: a0 = getchar(); break;

        default: break;
    }
}