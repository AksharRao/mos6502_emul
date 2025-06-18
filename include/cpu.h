#ifndef CPU_H
#define CPU_H

#include<stdint.h>
#include "memory.h"

typedef uint8_t byte;   // shorthand for 8-bit unsigned integer
typedef uint16_t word;  // shorthand for 16-bit unsigned integer
typedef uint32_t dword; // shorthand for 32-bit unsigned integer

typedef enum { 
    false, 
    true
} bool;

typedef struct cpu {
    byte acc; // Accumulator Register A
    byte indX, indY; // Index (Auxiliary) Registers X and Y
    word sp;   // Stack Pointer (sp)
    word pc; // Program Counter (pc)

    //Status Registers
    bool negative;
    bool overflow;
    bool unused;
    bool breakFlag;
    bool decimalFlag;
    bool irqFlag;
    bool zeroFlag;
    bool carryFlag;

} cpu_t; // Interesting: "_t" is used to tell the said datatype is defined using typedef

//prototypes to be used in cpu.c
void initialize(cpu_t *cpu);
void reset(cpu_t *cpu);
void printCpuState(cpu_t *cpu);

byte fetch_byte(dword *clk_cycle, mem_t *mem, cpu_t *cpu);
void execInstr(dword *clk_cycle, mem_t *mem, cpu_t *cpu);

#endif