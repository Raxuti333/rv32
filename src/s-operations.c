#include <emulator.h>
#include <operations.h>
#include <string.h>

#define rs1 ((Emulator*)emulator)->registers[(instruction >> 15) & 0b11111]
#define rs2 ((Emulator*)emulator)->registers[(instruction >> 20) & 0b11111]
#define imm ((instruction >> 7) & 0b11111) + (instruction >> 25)
#define M ((Emulator*)emulator)->memory

void sb(void* emulator, uint32_t instruction) { M[rs1 + imm] = rs2 & 0b11111111; }

void sh(void* emulator, uint32_t instruction) { memcpy(&M[rs1 + imm], &rs2, sizeof(uint16_t)); }

void sw(void* emulator, uint32_t instruction) { memcpy(&M[rs1 + imm], &rs2, sizeof(uint32_t)); }