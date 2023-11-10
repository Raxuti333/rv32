#include <emulator.h>
#include <operations.h>

#define rs1 ((Emulator*)emulator)->registers[(instruction >> 15) & 0b11111]
#define rs2 ((Emulator*)emulator)->registers[(instruction >> 20) & 0b11111]
#define imm ((instruction >> 7) & 0b11111) + (instruction >> 25)
#define M ((Emulator*)emulator)->memory

void sb(void* emulator, uint32_t instruction) { M[rs1 + imm] = rs2 & 0b11111111; }

void sh(void* emulator, uint32_t instruction) { M[rs1 + imm] = rs2 & 0b11111111; M[rs1 + imm + 1] = rs2 >> 8; }

void sw(void* emulator, uint32_t instruction) { M[rs1 + imm] = rs2 & 0b11111111; M[rs1 + imm + 1] = (rs2 >> 8) & 0b11111111; M[rs1 + imm + 2] = (rs2 >> 16) & 0b11111111; M[rs1 + imm + 3] = (rs2 >> 24) & 0b11111111; }