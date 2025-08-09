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
void instr_LDX_absolute(cpu_t* cpu, mam_t* mem);
void instr_LDX_absolute_y(cpu_t* cpu, mam_t* mem);

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
    [0x91] = {"STA (oper), X - indirect, y", 6, instr_STA_indirect_y},
    [0xA2] = {"LDX #oper - immediate", 2, instr_LDX_immediate},
    [0xA6] = {"LDX oper - zeropage", 3, instr_LDX_zeropage},
    [0xB6] = {"LDX oper, Y - zeropage, y", 4, instr_LDX_zeropage_y},
    [0xAE] = {"LDX oper - absolute", 4, instr_LDX_absolute},
    [0xBE] = {"LDX oper, Y - absolute, y", 4, instr_LDX_absolute_y},
};

#endif