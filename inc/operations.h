#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <emulator.h>

void add(void* emulator, uint32_t instruction);

void sub(void* emulator, uint32_t instruction);

void xor(void* emulator, uint32_t instruction);

void or(void* emulator, uint32_t instruction);

void and(void* emulator, uint32_t instruction);

void sll(void* emulator, uint32_t instruction);

void srl(void* emulator, uint32_t instruction);

void sra(void* emulator, uint32_t instruction);

void slt(void* emulator, uint32_t instruction);

void sltu(void* emulator, uint32_t instruction);

void addi(void* emulator, uint32_t instruction);

void xori(void* emulator, uint32_t instruction);

void ori(void* emulator, uint32_t instruction);

void andi(void* emulator, uint32_t instruction);

void slli(void* emulator, uint32_t instruction);

void srli(void* emulator, uint32_t instruction);

void srai(void* emulator, uint32_t instruction);

void slti(void* emulator, uint32_t instruction);

void sltiu(void* emulator, uint32_t instruction);

void lb(void* emulator, uint32_t instruction);

void lh(void* emulator, uint32_t instruction);

void lw(void* emulator, uint32_t instruction);

void lbu(void* emulator, uint32_t instruction);

void lhu(void* emulator, uint32_t instruction);

void jalr(void* emulator, uint32_t instruction);

void beq(void* emulator, uint32_t instruction);

void bne(void* emulator, uint32_t instruction);

void blt(void* emulator, uint32_t instruction);

void bge(void* emulator, uint32_t instruction);

void bltu(void* emulator, uint32_t instruction);

void bgeu(void* emulator, uint32_t instruction);

void lui(void* emulator, uint32_t instruction);

void auipc(void* emulator, uint32_t instruction);

void jal(void* emulator, uint32_t instruction);

void sb(void* emulator, uint32_t instruction);

void sh(void* emulator, uint32_t instruction);

void sw(void* emulator, uint32_t instruction);

void ecall(void* emulator, uint32_t instruction);

#endif