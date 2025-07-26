#ifndef MEMORY_H
#define MEMORY_H

#include "types.h"

void mem_init(mem_t *mem); //initialising memory

#ifdef DEBUG_MEMORY
void print_memory(mem_t *mem); //printing memory contents
#endif // DEBUG_MEMORY

byte read_byte(dword address, mem_t *mem); //reading a byte from memory
word read_word(dword address, mem_t *mem); //reading a word from memory
void write_byte(dword address, mem_t *mem, byte value); //writing a byte to memory


#endif // MEMORY_H
