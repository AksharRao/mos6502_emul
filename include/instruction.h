#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "types.h"
#include "cpu.h"
#include "memory.h"
#include "stdlib.h"
#include "stdio.h"

void instr_BRK(cpu_t* cpu, mem_t* mem);

// LDA Instructions
void instr_LDA_immediate(cpu_t* cpu, mem_t* mem);
void instr_LDA_zeropage(cpu_t* cpu, mem_t* mem);
void instr_LDA_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_LDA_absolute(cpu_t* cpu, mem_t* mem);
void instr_LDA_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_LDA_absolute_y(cpu_t* cpu, mem_t* mem);
void instr_LDA_indirect_x(cpu_t* cpu, mem_t* mem);
void instr_LDA_indirect_y(cpu_t* cpu, mem_t* mem);

// STA Instructions
void instr_STA_zeropage(cpu_t* cpu, mem_t* mem);
void instr_STA_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_STA_absolute(cpu_t* cpu, mem_t* mem);
void instr_STA_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_STA_absolute_y(cpu_t* cpu, mem_t* mem);
void instr_STA_indirect_x(cpu_t* cpu, mem_t* mem);
void instr_STA_indirect_y(cpu_t* cpu, mem_t* mem);

// LDX Instructions
void instr_LDX_immediate(cpu_t* cpu, mem_t* mem);
void instr_LDX_zeropage(cpu_t* cpu, mem_t* mem);
void instr_LDX_zeropage_y(cpu_t* cpu, mem_t* mem);
void instr_LDX_absolute(cpu_t* cpu, mem_t* mem);
void instr_LDX_absolute_y(cpu_t* cpu, mem_t* mem);

// LDY Instructions
void instr_LDY_immediate(cpu_t* cpu, mem_t* mem);
void instr_LDY_zeropage(cpu_t* cpu, mem_t* mem);
void instr_LDY_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_LDY_absolute(cpu_t* cpu, mem_t* mem);
void instr_LDY_absolute_x(cpu_t* cpu, mem_t* mem);

// STX Instructions
void instr_STX_zeropage(cpu_t* cpu, mem_t* mem);
void instr_STX_zeropage_y(cpu_t* cpu, mem_t* mem);
void instr_STX_absolute(cpu_t* cpu, mem_t* mem);

// STY Instructions
void instr_STY_zeropage(cpu_t* cpu, mem_t* mem);
void instr_STY_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_STY_absolute(cpu_t* cpu, mem_t* mem);

// Transfer instructions
void instr_TAX_implied(cpu_t* cpu, mem_t* mem);
void instr_TAY_implied(cpu_t* cpu, mem_t* mem);
void instr_TSX_implied(cpu_t* cpu, mem_t* mem);
void instr_TXA_implied(cpu_t* cpu, mem_t* mem);
void instr_TXS_implied(cpu_t* cpu, mem_t* mem);
void instr_TYA_implied(cpu_t* cpu, mem_t* mem);

// Stack Instructions
void instr_PHA_implied(cpu_t* cpu, mem_t* mem);
void instr_PHP_implied(cpu_t* cpu, mem_t* mem);
void instr_PLA_implied(cpu_t* cpu, mem_t* mem);
void instr_PLP_implied(cpu_t* cpu, mem_t* mem);

// Decrement instructions
void instr_DEC_zeropage(cpu_t* cpu, mem_t* mem);
void instr_DEC_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_DEC_absolute(cpu_t* cpu, mem_t* mem);
void instr_DEC_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_DEX_implied(cpu_t* cpu, mem_t* mem);
void instr_DEY_implied(cpu_t* cpu, mem_t* mem);

// Increment instructions
void instr_INC_zeropage(cpu_t* cpu, mem_t* mem);
void instr_INC_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_INC_absolute(cpu_t* cpu, mem_t* mem);
void instr_INC_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_INX_implied(cpu_t* cpu, mem_t* mem);
void instr_INY_implied(cpu_t* cpu, mem_t* mem);

// Arithemetic instructions
void instr_ADC_immediate(cpu_t* cpu, mem_t* mem);
void instr_ADC_zeropage(cpu_t* cpu, mem_t* mem);
void instr_ADC_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_ADC_absolute(cpu_t* cpu, mem_t* mem);
void instr_ADC_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_ADC_absolute_y(cpu_t* cpu, mem_t* mem);
void instr_ADC_indirect_x(cpu_t* cpu, mem_t* mem);
void instr_ADC_indirect_y(cpu_t* cpu, mem_t* mem);

void instr_SBC_immediate(cpu_t* cpu, mem_t* mem);
void instr_SBC_zeropage(cpu_t* cpu, mem_t* mem);
void instr_SBC_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_SBC_absolute(cpu_t* cpu, mem_t* mem);
void instr_SBC_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_SBC_absolute_y(cpu_t* cpu, mem_t* mem);
void instr_SBC_indirect_x(cpu_t* cpu, mem_t* mem);
void instr_SBC_indirect_y(cpu_t* cpu, mem_t* mem);

// Logical instructions
void instr_AND_immediate(cpu_t* cpu, mem_t* mem);
void instr_AND_zeropage(cpu_t* cpu, mem_t* mem);
void instr_AND_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_AND_absolute(cpu_t* cpu, mem_t* mem);
void instr_AND_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_AND_absolute_y(cpu_t* cpu, mem_t* mem);
void instr_AND_indirect_x(cpu_t* cpu, mem_t* mem);
void instr_AND_indirect_y(cpu_t* cpu, mem_t* mem);

void instr_EOR_immediate(cpu_t* cpu, mem_t* mem);
void instr_EOR_zeropage(cpu_t* cpu, mem_t* mem);
void instr_EOR_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_EOR_absolute(cpu_t* cpu, mem_t* mem);
void instr_EOR_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_EOR_absolute_y(cpu_t* cpu, mem_t* mem);
void instr_EOR_indirect_x(cpu_t* cpu, mem_t* mem);
void instr_EOR_indirect_y(cpu_t* cpu, mem_t* mem);

void instr_ORA_immediate(cpu_t* cpu, mem_t* mem);
void instr_ORA_zeropage(cpu_t* cpu, mem_t* mem);
void instr_ORA_zeropage_x(cpu_t* cpu, mem_t* mem);
void instr_ORA_absolute(cpu_t* cpu, mem_t* mem);
void instr_ORA_absolute_x(cpu_t* cpu, mem_t* mem);
void instr_ORA_absolute_y(cpu_t* cpu, mem_t* mem);
void instr_ORA_indirect_x(cpu_t* cpu, mem_t* mem);
void instr_ORA_indirect_y(cpu_t* cpu, mem_t* mem);

static instruction_t instruction_table[] = {
    // [opcode] = {"Instruction info", no_of_clock_cycles, function_pointer}
    [0x00] = {"BRK", 7, instr_BRK},
    [0xA9] = {"LDA #oper - immediate", 2, instr_LDA_immediate},
    [0xA5] = {"LDA oper - zeropage", 3, instr_LDA_zeropage},
    [0xB5] = {"LDA oper, X - zeropage, x", 4, instr_LDA_zeropage_x},
    [0xAD] = {"LDA oper - absolute", 4, instr_LDA_absolute},
    [0xBD] = {"LDA oper, X - absolute, x", 4, instr_LDA_absolute_x},
    [0xB9] = {"LDA oper, Y - apsolute, y", 4, instr_LDA_absolute_y},
    [0xA1] = {"LDA (oper, X) - indirect, x", 6, instr_LDA_indirect_x},
    [0xB1] = {"LDA (oper), Y - indirect, y", 6, instr_LDA_indirect_y},
    [0x85] = {"STA oper - zeropage", 3, instr_STA_zeropage},
    [0x95] = {"STA oper, X - zeropage, x", 4, instr_STA_zeropage_x},
    [0x8D] = {"STA oper - absolute", 4, instr_STA_absolute},
    [0x9D] = {"STA oper, X - absolute, x", 5, instr_STA_absolute_x},
    [0x99] = {"STA oper, Y - absolute, y", 5, instr_STA_absolute_y},
    [0x81] = {"STA (oper, X) - indirect, x", 6, instr_STA_indirect_x},
    [0x91] = {"STA (oper), Y - indirect, y", 6, instr_STA_indirect_y},
    [0xA2] = {"LDX #oper - immediate", 2, instr_LDX_immediate},
    [0xA6] = {"LDX oper - zeropage", 3, instr_LDX_zeropage},
    [0xB6] = {"LDX oper, Y - zeropage, y", 4, instr_LDX_zeropage_y},
    [0xAE] = {"LDX oper - absolute", 4, instr_LDX_absolute},
    [0xBE] = {"LDX oper, Y - absolute, y", 4, instr_LDX_absolute_y},
    [0xA0] = {"LDY #oper - immediate", 2, instr_LDY_immediate},
    [0xA4] = {"LDY oper - zeropage", 3, instr_LDY_zeropage},
    [0xB4] = {"LDY oper, Y - zeropage, y", 4, instr_LDY_zeropage_x},
    [0xAC] = {"LDY oper - absolute", 4, instr_LDY_absolute},
    [0xBC] = {"LDY oper, Y - absolute, y", 4, instr_LDY_absolute_x},
    [0x86] = {"STX oper - zeropage", 3, instr_STX_zeropage},
    [0x96] = {"STX oper, Y - zeropage, y", 4, instr_STX_zeropage_y},
    [0x8E] = {"STX oper - absolute", 4, instr_STX_absolute},
    [0x84] = {"STY oper - zeropage", 3, instr_STY_zeropage},
    [0x94] = {"STY oper, X - zeropage, x", 4, instr_STY_zeropage_x},
    [0x8C] = {"STY oper - absolute", 4, instr_STY_absolute},
    [0xAA] = {"TAX - implied", 2, instr_TAX_implied},
    [0xA8] = {"TAY - implied", 2, instr_TAY_implied},
    [0xBA] = {"TSX - implied", 2, instr_TSX_implied},
    [0x8A] = {"TXA - implied", 2, instr_TXA_implied},
    [0x9A] = {"TXS - implied", 2, instr_TXS_implied},
    [0x98] = {"TYA - implied", 2, instr_TYA_implied},
    [0x48] = {"PHA - implied", 3, instr_PHA_implied},
    [0x08] = {"PHP - implied", 3, instr_PHP_implied},
    [0x68] = {"PLA - implied", 4, instr_PLA_implied},
    [0x28] = {"PLP - implied", 4, instr_PLP_implied},
    [0xC6] = {"DEC oper - zeropage", 5, instr_DEC_zeropage},
    [0xD6] = {"DEC oper, X - zeropage, x", 6, instr_DEC_zeropage_x},
    [0xCE] = {"DEC oper - absolute", 6, instr_DEC_absolute},
    [0xDE] = {"DEC oper, X - absolute, x", 7, instr_DEC_absolute_x},
    [0xCA] = {"DEX - implied", 2, instr_DEX_implied},
    [0x88] = {"DEY - implied", 2, instr_DEY_implied},
    [0xE6] = {"INC oper - zeropage", 5, instr_INC_zeropage},
    [0xF6] = {"INC oper, X - zeropage, x", 6, instr_INC_zeropage_x},
    [0xEE] = {"INC oper - absolute", 6, instr_INC_absolute},
    [0xFE] = {"INC oper, X - absolute, x", 7, instr_INC_absolute_x},
    [0xE8] = {"INX - implied", 2, instr_INX_implied},
    [0xC8] = {"INY - implied", 2, instr_INY_implied},
    [0x69] = {"ADC #oper - immediate", 2, instr_ADC_immediate},
    [0x65] = {"ADC oper - zeropage", 3, instr_ADC_zeropage},
    [0x75] = {"ADC oper, X - zeropage, x", 4, instr_ADC_zeropage_x},
    [0x6D] = {"ADC oper - absolute", 4, instr_ADC_absolute},
    [0x7D] = {"ADC oper, X - absolute, x", 4, instr_ADC_absolute_x},
    [0x79] = {"ADC oper, Y - apsolute, y", 4, instr_ADC_absolute_y},
    [0x61] = {"ADC (oper, X) - indirect, x", 6, instr_ADC_indirect_x},
    [0x71] = {"ADC (oper), Y - indirect, y", 5, instr_ADC_indirect_y},
    [0xE9] = {"SBC #oper - immediate", 2, instr_SBC_immediate},
    [0xE5] = {"SBC oper - zeropage", 3, instr_SBC_zeropage},
    [0xF5] = {"SBC oper, X - zeropage, x", 4, instr_SBC_zeropage_x},
    [0xED] = {"SBC oper - absolute", 4, instr_SBC_absolute},
    [0xFD] = {"SBC oper, X - absolute, x", 4, instr_SBC_absolute_x},
    [0xF9] = {"SBC oper, Y - absolute, y", 4, instr_SBC_absolute_y},
    [0xE1] = {"SBC (oper, X) - indirect, x", 6, instr_SBC_indirect_x},
    [0xF1] = {"SBC (oper), Y - indirect, y", 5, instr_SBC_indirect_y},
    [0x29] = {"AND #oper - immediate", 2, instr_AND_immediate},
    [0x25] = {"AND oper - zeropage", 3, instr_AND_zeropage},
    [0x35] = {"AND oper, X - zeropage, x", 4, instr_AND_zeropage_x},
    [0x2D] = {"AND oper - absolute", 4, instr_AND_absolute},
    [0x3D] = {"AND oper, X - absolute, x", 4, instr_AND_absolute_x},
    [0x39] = {"AND oper, Y - absolute, y", 4, instr_AND_absolute_y},
    [0x21] = {"AND (oper, X) - indirect, x", 6, instr_AND_indirect_x},
    [0x31] = {"AND (oper), Y - indirect, y", 5, instr_AND_indirect_y},
    [0x49] = {"EOR #oper - immediate", 2, instr_EOR_immediate},
    [0x45] = {"EOR oper - zeropage", 3, instr_EOR_zeropage},
    [0x55] = {"EOR oper, X - zeropage, x", 4, instr_EOR_zeropage_x},
    [0x4D] = {"EOR oper - absolute", 4, instr_EOR_absolute},
    [0x5D] = {"EOR oper, X - absolute, x", 4, instr_EOR_absolute_x},
    [0x59] = {"EOR oper, Y - absolute, y", 4, instr_EOR_absolute_y},
    [0x41] = {"EOR (oper, X) - indirect, x", 6, instr_EOR_indirect_x},
    [0x51] = {"EOR (oper), Y - indirect, y", 5, instr_EOR_indirect_y},
    [0x09] = {"ORA #oper - immediate", 2, instr_ORA_immediate},
    [0x05] = {"ORA oper - zeropage", 3, instr_ORA_zeropage},
    [0x15] = {"ORA oper, X - zeropage, x", 4, instr_ORA_zeropage_x},
    [0x0D] = {"ORA oper - absolute", 4, instr_ORA_absolute},
    [0x1D] = {"ORA oper, X - absolute, x", 4, instr_ORA_absolute_x},
    [0x19] = {"ORA oper, Y - absolute, y", 4, instr_ORA_absolute_y},
    [0x01] = {"ORA (oper, X) - indirect, x", 6, instr_ORA_indirect_x},
    [0x11] = {"ORA (oper), Y - indirect, y", 5, instr_ORA_indirect_y}
};

#endif