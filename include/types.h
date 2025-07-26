#ifndef TYPES_H
#define TYPES_H

#include<stdint.h>

#define max_mem 1024 * 64 //64KB of addressable memory

typedef enum { 
    false, 
    true
} bool;

typedef uint8_t byte;   // shorthand for 8-bit unsigned integer
typedef uint16_t word;  // shorthand for 16-bit unsigned integer
typedef uint32_t dword; // shorthand for 32-bit unsigned integer

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

typedef struct{
    byte data[max_mem]; // Memory array of 64KB
} mem_t;

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

#endif