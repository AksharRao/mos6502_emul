#include "include/memory.h"
#include <stdio.h>
#include <string.h>

void initMemory(mem_t *mem) {
    for (int i = 0; i < max_mem; i++) {
        mem->data[i] = 0; // Initialize all memory locations to 0
    }
    printf("Memory initialized to 0.\n");
}

#ifdef DEBUG_MEMORY

void printMemory(mem_t *mem) {
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

byte read_byte(dword address, mem_t *mem) {
    if (address < max_mem) {
        return mem->data[address]; // Return the byte at the specified address
    } else {
        printf("Error: Address out of bounds.\n");
        return 0; // Return 0 if address is out of bounds
    }
}

void write_byte(dword address, byte value, mem_t *mem) {
    if (address < max_mem) {
        mem->data[address] = value; // Write the byte to the specified address
    } else {
        printf("Error: Address out of bounds.\n");
    }
}
