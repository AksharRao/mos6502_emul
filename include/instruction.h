#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include "types.h"
#include "cpu.h"
#include "memory.h"
#include "stdlib.h"
#include "stdio.h"

typedef enum{
    ADDR_IMPLIED, //Implied as in generally Accumulator
    ADDR_IMMEDIATE,
    ADDR_ZEROPAGE, // One cycle less than absolute
    ADDR_ZEROPAGE_X,
    ADDR_ABSOLUTE,
    ADDR_ABSOLUTE_X, // One or two cycles more than absolute
    ADDR_ABSOLUTE_Y,
    ADDR_INDIRECT,
    ADDR_INDIRECT_X,
    ADDR_INDIRECT_Y,
    ADDR_RELATIVE
} addressing_mode_t;

typedef struct {
    const char* name;
    addressing_mode_t addressing_mode;
    byte cycles;
    void (*execute)(cpu_t* cpu, mem_t* mem);
} instruction_t;

void decode_and_execute(cpu_t* cpu, mem_t* mem, byte opcode);

void instr_BRK(cpu_t* cpu, mem_t* mem);
void instr_LDA_immediate(cpu_t* cpu, mem_t* mem);

#endif