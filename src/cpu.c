#include "include/cpu.h"
#include<stdio.h>

// Initialize the CPU registers and flags
void initialize(cpu_t *cpu){
    cpu->accumulator = 0;   
    cpu->indexX = 0;
    cpu->indexY = 0;
    cpu->stackPointer = 0x0100; // Initialize stack pointer to 0x0100
    cpu->programCounter = 0xFFFC; // Initialize program counter to 0xFFFC

    // Initialize status flags
    cpu->negative = false;  
    cpu->overflow = false;
    cpu->unused = false;
    cpu->breakFlag = false;
    cpu->decimalFlag = false;
    cpu->irqFlag = false;
    cpu->zeroFlag = true; // Set zero flag to true
    cpu->carryFlag = false; // Set carry flag to false
}

// Reset the CPU registers and flags to their initial state
void reset(cpu_t *cpu){
    cpu->accumulator = 0;   
    cpu->indexX = 0;
    cpu->indexY = 0;
    cpu->stackPointer = 0x0100; // Initialize stack pointer to 0x0100
    cpu->programCounter = 0xFFFC; // Initialize program counter to 0xFFFC

    // Initialize status flags
    cpu->negative = false;  
    cpu->overflow = false;
    cpu->unused = false;
    cpu->breakFlag = false;
    cpu->decimalFlag = false;
    cpu->irqFlag = false;
    cpu->zeroFlag = true; // Set zero flag to true
    cpu->carryFlag = false; // Set carry flag to false
}

// Print the current state of the CPU registers and flags
void printCpuState(cpu_t *cpu){
    printf("CPU State:\n\n"); 
    printf("Accumulator: %d\n", cpu->accumulator);
    printf("Index X: %d\tIndex Y: %d\n", cpu->indexX, cpu->indexY);
    printf("Stack Pointer: %04X\n", cpu->stackPointer);
    printf("Program Counter: %04X\n\n", cpu->programCounter);
    printf("Status Flags:\n");
    printf("Negative Flag: %d\n", cpu->negative);
    printf("Overflow Flag: %d\n", cpu->overflow);           
    printf("Unused Flag: %d\n", cpu->unused);
    printf("Break Flag: %d\n", cpu->breakFlag);
    printf("Decimal Flag: %d\n", cpu->decimalFlag);
    printf("IRQ Flag: %d\n", cpu->irqFlag);
    printf("Zero Flag: %d\n", cpu->zeroFlag);
    printf("Carry Flag: %d\n", cpu->carryFlag);
    printf("\n");
}