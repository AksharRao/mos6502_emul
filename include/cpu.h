#ifndef CPU_H
#define CPU_H

#include<stdint.h>

typedef uint8_t byte;   // shorthand for 8-bit unsigned integer
typedef uint16_t word;  // shorthand for 16-bit unsigned integer
typedef uint32_t dword; // shorthand for 32-bit unsigned integer

typedef enum { 
    false, 
    true
} bool;

typedef struct cpu {
    byte accumulator; // Accumulator Register
    byte indexX, indexY; // Index (Auxiliary) Registers
    word stackPointer;   // Stack Pointer
    word programCounter; // Program Counter

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

void initialize(cpu_t *cpu);
void reset(cpu_t *cpu);
void printCpuState(cpu_t *cpu);

#endif