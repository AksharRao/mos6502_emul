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

static instruction_t instruction_table[] = {
    [0x00] = {"BRK", ADDR_IMPLIED, 7, instr_BRK},
    [0xA9] = {"LDA #oper - immediate", ADDR_IMMEDIATE, 2, instr_LDA_immediate},
    [0xA5] = {"LDA oper - zeropage", ADDR_ZEROPAGE, 3, instr_LDA_zeropage},
    [0xB5] = {"LDA oper, X - zeropage, x", ADDR_ZEROPAGE_X, 4, instr_LDA_zeropage_x},
    [0xAD] = {"LDA oper - absolute", ADDR_ABSOLUTE, 4, instr_LDA_absolute},
    [0xBD] = {"LDA oper, X - absolute, x", ADDR_ABSOLUTE_X, 4, instr_LDA_absolute_x},
    [0xB9] = {"LDA oper, Y - apsolute, y", ADDR_ABSOLUTE_Y, 4, instr_LDA_absolute_y},
    [0xA1] = {"LDA (oper, X) - indirect, x", ADDR_INDIRECT_X, 6, instr_LDA_indirect_x},
    [0xB1] = {"LDA (oper), Y - indirect, y", ADDR_INDIRECT_X, 6, instr_LDA_indirect_y},
    [0x85] = {"STA oper - zeropage", ADDR_ZEROPAGE, 3, instr_STA_zeropage},
    [0x95] = {"STA oper, X - zeropage, x", ADDR_ZEROPAGE_X, 4, instr_STA_zeropage_x},
    [0x8D] = {"STA oper - absolute", ADDR_ABSOLUTE, 4, instr_STA_absolute},
    [0x9D] = {"STA oper, X - absolute, x", ADDR_ABSOLUTE_X, 5, instr_STA_absolute_x},
    [0x99] = {"STA oper, Y - absolute, y", ADDR_ABSOLUTE_Y, 5, instr_STA_absolute_y},
    [0x81] = {"STA (oper, X) - indirect, x", ADDR_INDIRECT_X, 6, instr_STA_indirect_x},
    [0x91] = {"STA (oper), X - indirect, y", ADDR_INDIRECT_Y, 6, instr_STA_indirect_y}
};

#endif