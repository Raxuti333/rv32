#include <emulator.h>
#include <operations.h>

#define rd  ((Emulator*)emulator)->registers[(instruction >> 7) & 0b11111]
#define imm (instruction >> 12)
#define PC ((Emulator*)emulator)->pc


void jal(void* emulator, uint32_t instruction) { rd = PC + 4; PC += imm; }