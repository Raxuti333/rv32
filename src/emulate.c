#include <stdlib.h>
#include <emulator.h>

#include <stdio.h>

static uint32_t mask[] = 
{
    [R]0b1111111 + (0b111 << 12) + ((0b1111111) << 25),
    [I]0b1111111 + (0b111 << 12),
    [S]0b1111111 + (0b111 << 12),
    [B]0b1111111 + (0b111 << 12),
    [U]0b1111111,
    [J]0b1111111,
};

void emulate(Emulator* emulator)
{
    for(emulator->pc; emulator->pc < 60; emulator->pc += 4)
    {
        uint32_t instruction = *(uint32_t*)(emulator->memory + emulator->pc);

        for(size_t i = 0; i < (sizeof(instructions) / sizeof(*instructions)); ++i)
        {
            if(instructions[i].base == (instruction & mask[instructions[i].type]))
            {
                instructions[i].operation(emulator, instruction);

                break;
            }
        }
        emulator->registers[0] = 0;
    }
}