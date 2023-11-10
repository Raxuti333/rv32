#include <emulator.h>
#include <operations.h>

#include <stdio.h>

#define rd  ((Emulator*)emulator)->registers[(instruction >> 7) & 0b11111]
#define rs1 ((Emulator*)emulator)->registers[(instruction >> 15) & 0b11111]
#define rs2 ((Emulator*)emulator)->registers[(instruction >> 20) & 0b11111]

void add(void* emulator, uint32_t instruction) { rd = rs1 + rs2; }

void sub(void* emulator, uint32_t instruction) { rd = rs1 - rs2; }

void xor(void* emulator, uint32_t instruction) { rd = rs1 ^ rs2; }

void or(void* emulator, uint32_t instruction) { rd = rs1 | rs2; }

void and(void* emulator, uint32_t instruction) { rd = rs1 & rs2; }

void sll(void* emulator, uint32_t instruction) { rd = rs1 << rs2; }

void srl(void* emulator, uint32_t instruction) { rd = rs1 >> rs2; }

void sra(void* emulator, uint32_t instruction) { rd = (int32_t)rs1 >> rs2; }

void slt(void* emulator, uint32_t instruction) { rd = (int32_t)rs1 < (int32_t)rs2; }

void sltu(void* emulator, uint32_t instruction) { rd = rs1 < rs2; }