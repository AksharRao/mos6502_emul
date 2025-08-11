#include "include/cpu.h"
#include "include/memory.h"
#include "include/instruction.h"
#include<stdio.h>

// Initialize the CPU registers and flags
void cpu_init(cpu_t *cpu){
    cpu->acc = 0;   
    cpu->indX = 0;
    cpu->indY = 0;
    cpu->sp = 0xFD; // Initialize stack pointer to 0xFD
    cpu->pc = 0xFFFC; // Initialize program counter to 0xFFFC

    // Initialize status flags
    cpu->negative = false;  
    cpu->overflow = false;
    cpu->unused = true; //always true
    cpu->breakFlag = false;
    cpu->decimalFlag = false;
    cpu->irqFlag = false;
    cpu->zeroFlag = true; // Set zero flag to true
    cpu->carryFlag = false; // Set carry flag to false
}

// Reset the CPU registers and flags to their initial state
// i.e. initialize cpu again
void cpu_reset(cpu_t *cpu){
    cpu_init(cpu);
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

byte fetch_byte(cpu_t *cpu, mem_t *mem){
    word data = mem->data[cpu->pc]; // Fetch byte from memory
    cpu->pc++;
    return data;
}

word fetch_word(cpu_t *cpu, mem_t *mem){
    byte low_byte = fetch_byte(cpu, mem);
    byte high_byte = fetch_byte(cpu, mem);
    word data = (high_byte<<8) | low_byte;
    return data;
}

void exec_instr(dword *clk_cycle, cpu_t *cpu, mem_t *mem){
    // Placeholder for instruction execution logic
    // This function will execute the instruction at the current program counter (pc)
    // and update the CPU state accordingly.

    //Fetch the instruction from memory at current PC
    while (*clk_cycle > 0 && !cpu->breakFlag) {
        byte instruction = fetch_byte(cpu, mem);
        instruction_t* instr = &instruction_table[instruction];

        if (instr->execute == NULL) {
            printf("Unknown opcode: 0x%02X at PC: 0x%04X\n", instruction, cpu->pc);
            return;
        }
        // Check if we have enough cycles
        if (*clk_cycle < instr->cycles) {
            cpu->pc--;
            break;
        }
        printf("Executing: %s (0x%02X) - %d cycles\n", instr->name, instruction, instr->cycles);
        instr->execute(cpu, mem);
        *clk_cycle -= instr->cycles;
        print_cpu_state(cpu);
        #ifdef DEBUG_MEMORY
        print_memory(mem);
        #endif // DEBUG_MEMORY
    }
}

byte pack_status_register(cpu_t * cpu){
    byte packed_sr = 0;
    packed_sr |= (cpu->negative << 7);
    packed_sr |= (cpu->overflow << 6);
    packed_sr |= (cpu->unused << 5);
    packed_sr |= (cpu->breakFlag << 4);
    packed_sr |= (cpu->decimalFlag << 3);
    packed_sr |= (cpu->irqFlag << 2);
    packed_sr |= (cpu->zeroFlag << 1);
    packed_sr |= (cpu->carryFlag << 0);
    return packed_sr;
}