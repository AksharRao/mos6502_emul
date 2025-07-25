#include "include/cpu.h"
#include "include/memory.h"
#include "include/instruction.h"
#include<stdio.h>

// Initialize the CPU registers and flags
void cpu_init(cpu_t *cpu){
    cpu->acc = 0;   
    cpu->indX = 0;
    cpu->indY = 0;
    cpu->sp = 0x0100; // Initialize stack pointer to 0x0100
    cpu->pc = 0xFFFC; // Initialize program counter to 0xFFFC

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
void cpu_reset(cpu_t *cpu){
    cpu->acc = 0;   
    cpu->indX = 0;
    cpu->indY = 0;
    cpu->sp = 0x0100; // Initialize stack pointer to 0x0100
    cpu->pc = 0xFFFC; // Initialize program counter to 0xFFFC

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
void print_cpu_state(cpu_t *cpu){
    printf("\nCPU State:\n"); 
    printf("Accumulator: %d\n", cpu->acc);
    printf("Index X: %d\tIndex Y: %d\n", cpu->indX, cpu->indY);
    printf("Stack Pointer: %04X\n", cpu->sp);
    printf("Program Counter: %04X\n\n", cpu->pc);
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

byte fetch_byte(dword *clk_cycle, cpu_t *cpu, mem_t *mem) {
    // Fetch a byte from memory at the current program counter (pc)
    // and increment the program counter by 1.
    if (*clk_cycle == 0) {
        return 0; // No clock cycle, return 0
    }
    
    byte data = mem->data[cpu->pc]; // Fetch byte from memory
    cpu->pc++;
    (*clk_cycle)--; // Decrement the clock cycle
    return data;
}

void exec_instr(dword *clk_cycle, cpu_t *cpu, mem_t *mem) {
    // Placeholder for instruction execution logic
    // This function will execute the instruction at the current program counter (pc)
    // and update the CPU state accordingly.
    
    while (*clk_cycle > 0 && !cpu->breakFlag) {
        //Fetch the instruction from memory at current PC
        byte instruction = fetch_byte(clk_cycle, cpu, mem);
        decode_and_execute(cpu, mem, instruction);
    }
}