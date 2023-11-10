#include <emulator.h>
#include <operations.h>
#include <stdio.h>

#define rd  ((Emulator*)emulator)->registers[(instruction >> 7) & 0b11111]
#define rs1 ((Emulator*)emulator)->registers[(instruction >> 15) & 0b11111]
#define imm (instruction >> 20) & 0b111111111111
#define M ((Emulator*)emulator)->memory
#define PC ((Emulator*)emulator)->pc

void addi(void* emulator, uint32_t instruction) { rd = rs1 + imm; }

void xori(void* emulator, uint32_t instruction) { rd = rs1 ^ imm; }

void ori(void* emulator, uint32_t instruction) { rd = rs1 | imm; }

void andi(void* emulator, uint32_t instruction) { rd = rs1 & imm; }

void slli(void* emulator, uint32_t instruction) { rd = rs1 << (imm & 0b11111); }

void srli(void* emulator, uint32_t instruction) { rd = rs1 << (imm & 0b11111); }

void srai(void* emulator, uint32_t instruction) { rd = (int32_t)rs1 >> (imm & 0b11111); }

void slti(void* emulator, uint32_t instruction) { rd = (int32_t)rs1 < imm; }

void sltiu(void* emulator, uint32_t instruction) { rd = rs1 < imm; }

void lb(void* emulator, uint32_t instruction) { rd = M[rs1 + imm]; }

void lh(void* emulator, uint32_t instruction) { rd = M[rs1 + imm + 1] << 8 + M[rs1 + imm]; }

void lw(void* emulator, uint32_t instruction) { rd = M[rs1 + imm + 3] << 24 + M[rs1 + imm + 2] << 16 + M[rs1 + imm + 1] << 8 + M[rs1 + imm]; }

void lbu(void* emulator, uint32_t instruction) { rd = M[rs1 + imm]; }

void lhu(void* emulator, uint32_t instruction) { rd = M[rs1 + imm + 1] << 8 + M[rs1 + imm]; }

void jalr(void* emulator, uint32_t instruction) { rd = PC + 4; PC = rs1 + imm; }