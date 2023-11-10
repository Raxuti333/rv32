#include <emulator.h>
#include <operations.h>

#define rs1 ((Emulator*)emulator)->registers[(instruction >> 15) & 0b11111]
#define rs2 ((Emulator*)emulator)->registers[(instruction >> 20) & 0b11111]
#define imm (((instruction >> 25) & 0b111111111111) << 5) + ((instruction >> 7) & 0b11111) - 4
#define PC  ((Emulator*)emulator)->pc

void beq(void* emulator, uint32_t instruction) { if(rs1 == rs2) { PC += imm; } }

void bne(void* emulator, uint32_t instruction) { if(rs1 != rs2) { PC += imm; } }

void blt(void* emulator, uint32_t instruction) { if((int32_t)rs1 < (int32_t)rs2) { PC += imm; } }

void bge(void* emulator, uint32_t instruction) { if((int32_t)rs1 >= (int32_t)rs2) { PC += imm; } }

void bltu(void* emulator, uint32_t instruction) { if(rs1 < rs2) { PC += imm; } }

void bgeu(void* emulator, uint32_t instruction) { if(rs1 >= rs2) { PC += imm; } }