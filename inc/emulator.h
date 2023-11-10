#ifndef EMULATOR_H
#define EMULATOR_H

#include <stdint.h>

#include <operations.h>

#define MEMORY 4096

typedef struct Emulator 
{
    uint32_t pc;
    uint32_t registers[32];

    uint8_t memory[];
} Emulator;

void emulate(Emulator* emulator);

typedef void (*Operation)(Emulator*, uint32_t);

typedef enum FMT { R, I, S, B, U, J } FMT;

typedef struct Instruction { uint32_t base; FMT type; Operation operation; } Instruction;

#define R_TYPE(INST, OP, FUNCT3, FUNCT7)    (Instruction){.base = (OP & 0b1111111) + ((FUNCT3 & 0b111) << 12) + ((FUNCT7 & 0b1111111) << 25), .type = R, .operation = INST}
#define I_TYPE(INST, OP, FUNCT3)            (Instruction){.base = (OP & 0b1111111) + ((FUNCT3 & 0b111) << 12), .type = I, .operation = INST}
#define SI_TYPE(INST, OP, FUNCT3, FUNCT7)   (Instruction){.base = (OP & 0b1111111) + ((FUNCT3 & 0b111) << 12) + ((FUNCT7 & 0b1111111) << 25), .type = I, .operation = INST}
#define S_TYPE(INST, OP, FUNCT3)            (Instruction){.base = (OP & 0b1111111) + ((FUNCT3 & 0b111) << 12), .type = S, .operation = INST}
#define B_TYPE(INST, OP, FUNCT3)            (Instruction){.base = (OP & 0b1111111) + ((FUNCT3 & 0b111) << 12), .type = B, .operation = INST}
#define U_TYPE(INST, OP)                    (Instruction){.base = (OP & 0b1111111), .type = U, .operation = INST}
#define J_TYPE(INST, OP)                    (Instruction){.base = (OP & 0b1111111), .type = J, .operation = INST}

static const Instruction instructions[] = 
{
    R_TYPE(add,   0b0110011,  0x0,    0x00),
    R_TYPE(sub,   0b0110011,  0x0,    0x20),
    R_TYPE(xor,   0b0110011,  0x4,    0x00),
    R_TYPE(or,    0b0110011,  0x6,    0x00),
    R_TYPE(and,   0b0110011,  0x7,    0x00),
    R_TYPE(sll,   0b0110011,  0x1,    0x00),
    R_TYPE(srl,   0b0110011,  0x5,    0x00),
    R_TYPE(sra,   0b0110011,  0x5,    0x20),
    R_TYPE(slt,   0b0110011,  0x2,    0x00),
    R_TYPE(sltu,  0b0110011,  0x3,    0x00),

    /* Immediate type instructions */

    I_TYPE(addi,  0b0010011,  0x0),
    I_TYPE(xori,  0b0010011,  0x4),
    I_TYPE(ori,   0b0010011,  0x6),
    I_TYPE(andi,  0b0010011,  0x7),
    I_TYPE(slti,  0b0010011,  0x2),
    I_TYPE(sltiu, 0b0010011,  0x3),
    I_TYPE(lb,    0b0000011,  0x0),
    I_TYPE(lh,    0b0000011,  0x1),
    I_TYPE(lw,    0b0000011,  0x2),
    I_TYPE(lbu,   0b0000011,  0x4),
    I_TYPE(lhu,   0b0000011,  0x5),
    I_TYPE(jalr,  0b1100111,  0x0),
    I_TYPE(ecall, 0b1110011,  0x0),

    /* special immediate type instructions with funct7 */

    SI_TYPE(slli, 0b0010011,  0x1,    0x00),
    SI_TYPE(srli, 0b0010011,  0x5,    0x00),
    SI_TYPE(srai, 0b0010011,  0x5,    0x20),

    /* Store type instructions */

    S_TYPE(sb,    0b0100011,  0x0),
    S_TYPE(sh,    0b0100011,  0x1),
    S_TYPE(sw,    0b0100011,  0x2),

    /* Branch type instructions */

    B_TYPE(beq,   0b1100011,  0x0),
    B_TYPE(bne,   0b1100011,  0x1),
    B_TYPE(blt,   0b1100011,  0x4),
    B_TYPE(bge,   0b1100011,  0x5),
    B_TYPE(bltu,  0b1100011,  0x6),
    B_TYPE(bgeu,  0b1100011,  0x7),

    /* Upper immediate type instructions */

    U_TYPE(lui,   0b0110111),
    U_TYPE(auipc, 0b0010111),

    /* Jump type instructions */

    J_TYPE(jal,   0b1101111),
};

#endif