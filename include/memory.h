#ifndef MEMORY_H
#define MEMORY_H

#include<stdint.h>

#define max_mem 1024 * 64 //64KB of addressable memory
typedef uint8_t byte;   // shorthand for 8-bit unsigned integer
typedef uint16_t word;  // shorthand for 16-bit unsigned integer
typedef uint32_t dword; // shorthand for 32-bit unsigned integer

typedef struct{
    byte data[max_mem]; // Memory array of 64KB}
} mem_t;

void initMemory(mem_t *mem); //initialising memory

#ifdef DEBUG_MEMORY
void printMemory(mem_t *mem); //printing memory contents
#endif // DEBUG_MEMORY

byte read_byte(dword address, mem_t *mem);              //reading a byte from memory
void write_byte(dword address, byte value, mem_t *mem); //writing a byte to memory

#endif // MEMORY_H
