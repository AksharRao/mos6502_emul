#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "types.h"
#include "cpu.h"
#include "memory.h"
#include "stdlib.h"
#include "stdio.h"

void instr_BRK(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_LDA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_STA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_LDX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_LDY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_STX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_STY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);

void instr_TAX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_TAY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_TSX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_TXA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_TXS(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_TYA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);

void instr_PHA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_PHP(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_PLA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_PLP(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);

void instr_DEC(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_DEX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_DEY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);

void instr_INC(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_INX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_INY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);

void instr_ADC(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_SBC(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);

void instr_AND(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_EOR(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);
void instr_ORA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode);

static const instruction_t instruction_table[] = {
    [0x00] = {"BRK", 7, instr_BRK, IMPLIED},
    [0xA9] = {"LDA #oper", 2, instr_LDA, IMMEDIATE},
    [0xA5] = {"LDA oper", 3, instr_LDA, ZEROPAGE},
    [0xB5] = {"LDA oper, X", 4, instr_LDA, ZEROPAGE_X},
    [0xAD] = {"LDA oper", 4, instr_LDA, ABSOLUTE},
    [0xBD] = {"LDA oper, X", 4, instr_LDA, ABSOLUTE_X},
    [0xB9] = {"LDA oper, Y", 4, instr_LDA, ABSOLUTE_Y},
    [0xA1] = {"LDA (oper, X)", 6, instr_LDA, INDIRECT_X},
    [0xB1] = {"LDA (oper), Y", 6, instr_LDA, INDIRECT_Y},
    [0x85] = {"STA oper", 3, instr_STA, ZEROPAGE},
    [0x95] = {"STA oper, X", 4, instr_STA, ZEROPAGE_X},
    [0x8D] = {"STA oper", 4, instr_STA, ABSOLUTE},
    [0x9D] = {"STA oper, X", 5, instr_STA, ABSOLUTE_X},
    [0x99] = {"STA oper, Y", 5, instr_STA, ABSOLUTE_Y},
    [0x81] = {"STA (oper, X)", 6, instr_STA, INDIRECT_X},
    [0x91] = {"STA (oper), Y", 6, instr_STA, INDIRECT_Y},
    [0xA2] = {"LDX #oper", 2, instr_LDX, IMMEDIATE},
    [0xA6] = {"LDX oper", 3, instr_LDX, ZEROPAGE},
    [0xB6] = {"LDX oper, Y", 4, instr_LDX, ZEROPAGE_Y},
    [0xAE] = {"LDX oper", 4, instr_LDX, ABSOLUTE},
    [0xBE] = {"LDX oper, Y", 4, instr_LDX, ABSOLUTE_Y},
    [0xA0] = {"LDY #oper", 2, instr_LDY, IMMEDIATE},
    [0xA4] = {"LDY oper", 3, instr_LDY, ZEROPAGE},
    [0xB4] = {"LDY oper, X", 4, instr_LDY, ZEROPAGE_X},
    [0xAC] = {"LDY oper", 4, instr_LDY, ABSOLUTE},
    [0xBC] = {"LDY oper, X", 4, instr_LDY, ABSOLUTE_X},
    [0x86] = {"STX oper", 3, instr_STX, ZEROPAGE},
    [0x96] = {"STX oper, Y", 4, instr_STX, ZEROPAGE_Y},
    [0x8E] = {"STX oper", 4, instr_STX, ABSOLUTE},
    [0x84] = {"STY oper", 3, instr_STY, ZEROPAGE},
    [0x94] = {"STY oper, X", 4, instr_STY, ZEROPAGE_X},
    [0x8C] = {"STY oper", 4, instr_STY, ABSOLUTE},
    [0xAA] = {"TAX", 2, instr_TAX, IMPLIED},
    [0xA8] = {"TAY", 2, instr_TAY, IMPLIED},
    [0xBA] = {"TSX", 2, instr_TSX, IMPLIED},
    [0x8A] = {"TXA", 2, instr_TXA, IMPLIED},
    [0x9A] = {"TXS", 2, instr_TXS, IMPLIED},
    [0x98] = {"TYA", 2, instr_TYA, IMPLIED},
    [0x48] = {"PHA", 3, instr_PHA, IMPLIED},
    [0x08] = {"PHP", 3, instr_PHP, IMPLIED},
    [0x68] = {"PLA", 4, instr_PLA, IMPLIED},
    [0x28] = {"PLP", 4, instr_PLP, IMPLIED},
    [0xC6] = {"DEC oper", 5, instr_DEC, ZEROPAGE},
    [0xD6] = {"DEC oper, X", 6, instr_DEC, ZEROPAGE_X},
    [0xCE] = {"DEC oper", 6, instr_DEC, ABSOLUTE},
    [0xDE] = {"DEC oper, X", 7, instr_DEC, ABSOLUTE_X},
    [0xCA] = {"DEX", 2, instr_DEX, IMPLIED},
    [0x88] = {"DEY", 2, instr_DEY, IMPLIED},
    [0xE6] = {"INC oper", 5, instr_INC, ZEROPAGE},
    [0xF6] = {"INC oper, X", 6, instr_INC, ZEROPAGE_X},
    [0xEE] = {"INC oper", 6, instr_INC, ABSOLUTE},
    [0xFE] = {"INC oper, X", 7, instr_INC, ABSOLUTE_X},
    [0xE8] = {"INX", 2, instr_INX, IMPLIED},
    [0xC8] = {"INY", 2, instr_INY, IMPLIED},
    [0x69] = {"ADC #oper", 2, instr_ADC, IMMEDIATE},
    [0x65] = {"ADC oper", 3, instr_ADC, ZEROPAGE},
    [0x75] = {"ADC oper, X", 4, instr_ADC, ZEROPAGE_X},
    [0x6D] = {"ADC oper", 4, instr_ADC, ABSOLUTE},
    [0x7D] = {"ADC oper, X", 4, instr_ADC, ABSOLUTE_X},
    [0x79] = {"ADC oper, Y", 4, instr_ADC, ABSOLUTE_Y},
    [0x61] = {"ADC (oper, X)", 6, instr_ADC, INDIRECT_X},
    [0x71] = {"ADC (oper), Y", 5, instr_ADC, INDIRECT_Y},
    [0xE9] = {"SBC #oper", 2, instr_SBC, IMMEDIATE},
    [0xE5] = {"SBC oper", 3, instr_SBC, ZEROPAGE},
    [0xF5] = {"SBC oper, X", 4, instr_SBC, ZEROPAGE_X},
    [0xED] = {"SBC oper", 4, instr_SBC, ABSOLUTE},
    [0xFD] = {"SBC oper, X", 4, instr_SBC, ABSOLUTE_X},
    [0xF9] = {"SBC oper, Y", 4, instr_SBC, ABSOLUTE_Y},
    [0xE1] = {"SBC (oper, X)", 6, instr_SBC, INDIRECT_X},
    [0xF1] = {"SBC (oper), Y", 5, instr_SBC, INDIRECT_Y},
    [0x29] = {"AND #oper", 2, instr_AND, IMMEDIATE},
    [0x25] = {"AND oper", 3, instr_AND, ZEROPAGE},
    [0x35] = {"AND oper, X", 4, instr_AND, ZEROPAGE_X},
    [0x2D] = {"AND oper", 4, instr_AND, ABSOLUTE},
    [0x3D] = {"AND oper, X", 4, instr_AND, ABSOLUTE_X},
    [0x39] = {"AND oper, Y", 4, instr_AND, ABSOLUTE_Y},
    [0x21] = {"AND (oper, X)", 6, instr_AND, INDIRECT_X},
    [0x31] = {"AND (oper), Y", 5, instr_AND, INDIRECT_Y},
    [0x49] = {"EOR #oper", 2, instr_EOR, IMMEDIATE},
    [0x45] = {"EOR oper", 3, instr_EOR, ZEROPAGE},
    [0x55] = {"EOR oper, X", 4, instr_EOR, ZEROPAGE_X},
    [0x4D] = {"EOR oper", 4, instr_EOR, ABSOLUTE},
    [0x5D] = {"EOR oper, X", 4, instr_EOR, ABSOLUTE_X},
    [0x59] = {"EOR oper, Y", 4, instr_EOR, ABSOLUTE_Y},
    [0x41] = {"EOR (oper, X)", 6, instr_EOR, INDIRECT_X},
    [0x51] = {"EOR (oper), Y", 5, instr_EOR, INDIRECT_Y},
    [0x09] = {"ORA #oper", 2, instr_ORA, IMMEDIATE},
    [0x05] = {"ORA oper", 3, instr_ORA, ZEROPAGE},
    [0x15] = {"ORA oper, X", 4, instr_ORA, ZEROPAGE_X},
    [0x0D] = {"ORA oper", 4, instr_ORA, ABSOLUTE},
    [0x1D] = {"ORA oper, X", 4, instr_ORA, ABSOLUTE_X},
    [0x19] = {"ORA oper, Y", 4, instr_ORA, ABSOLUTE_Y},
    [0x01] = {"ORA (oper, X)", 6, instr_ORA, INDIRECT_X},
    [0x11] = {"ORA (oper), Y", 5, instr_ORA, INDIRECT_Y}
};

#endif