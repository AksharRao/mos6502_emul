#include "include/memory.h"
#include <stdio.h>
#include <string.h>

void mem_init(mem_t *mem) {
    for (int i = 0; i < max_mem; i++) {
        mem->data[i] = 0; // Initialize all memory locations to 0
    }
    printf("Memory initialized to 0.\n");
}

#ifdef DEBUG_MEMORY

void print_memory(mem_t *mem) {
    printf("Memory contents:\n");
    for (dword i = 0; i < max_mem; i++) {
        if (i % 16 == 0) {
            printf("\n%04X: ", i); // Print address every 16 bytes
        }
        printf("%02X ", mem->data[i]);
    }
    printf("\n");
}
#endif // DEBUG_MEMORY

void print_memory_address(mem_t *mem, word address){
    printf("\nValue at memory location 0x%04X : %d (0x%02X)\n", address, mem->data[address], mem->data[address]);
}

byte read_byte(dword address, mem_t *mem) {
    if (address < max_mem) {
        return mem->data[address]; // Return the byte at the specified address
    } else {
        printf("Error: Address out of bounds.\n");
        return 0; // Return 0 if address is out of bounds
    }
}

word read_word(dword address, mem_t *mem) {
    if (address < max_mem - 1) {
        byte low_byte = mem->data[address]; // Return the byte at the specified address
        byte high_byte = mem->data[address+1];
        word data = (high_byte<<8) | low_byte;
        return data;
    } else {
        printf("Error: Address out of bounds.\n");
        return 0; // Return 0 if address is out of bounds
    }
}

void write_byte(dword address, mem_t *mem, byte value) {
    if (address < max_mem) {
        mem->data[address] = value; // Write the byte to the specified address
    } else {
        printf("Error: Address out of bounds.\n");
    }
}
