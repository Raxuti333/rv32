#include <emulator.h>
#include <operations.h>

#define rd  ((Emulator*)emulator)->registers[(instruction >> 7) & 0b11111]
#define imm (instruction >> 12)
#define PC ((Emulator*)emulator)->pc


void lui(void* emulator, uint32_t instruction) { rd = imm << 12; }

void auipc(void* emulator, uint32_t instruction) { rd = PC + (imm << 12); }