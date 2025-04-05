#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define MAX_SIZE (1024 * 64) // Maximum size of memory 64 KB

typedef uint8_t byte;   // shorthand for 8-bit unsigned integer
typedef uint16_t word;  // shorthand for 16-bit unsigned integer
typedef uint32_t dword; // shorthand for 32-bit unsigned integer

typedef struct mem {
    byte data[MAX_SIZE]; // Memory array
    void (*Initialise)(struct mem *memory); // Function pointer for initialization
} memory_t;
//mem is struct name, memory_t is type name

void Initialise(struct mem *memory) {
    // Initialize memory with zeros
    for (dword i = 0; i < MAX_SIZE; i++) {
        memory->data[i] = 0; // Initialize memory to zero
    }
}

typedef struct mcpu {
    byte a; // Accumulator Register
    byte x, y; // Index (Auxiliary) Registers
    word sp;   // Stack Pointer
    word pc;   // Program Counter

    // Status Register
    byte N : 1;
    byte V : 1;
    byte unused : 1;
    byte B : 1;
    byte D : 1;
    byte I : 1;
    byte Z : 1;
    byte C : 1;

    void (*reset)(struct mcpu *cpu, struct mem *memory); // Function pointer
    void (*execute)(struct mcpu *cpu, struct mem *memory); // Function pointer
} cpu_t;

void reset(cpu_t *cpu, struct mem *memory) {
    cpu->a = cpu->x = cpu->y = 0;
    cpu->sp = 0x0100;
    cpu->pc = 0xFFFC;

    cpu->N = 0;
    cpu->V = 0;
    cpu->B = 0;
    cpu->D = 0;
    cpu->I = 0;
    cpu->Z = 1;
    cpu->C = 0;

    memory->Initialise(memory); // Initialize memory
}

void execute (dword clockCycle, cpu_t *cpu, struct mem *memory) {
   
}

int main(void) {
    memory_t memory; // Create a memory instance
   memory.Initialise = Initialise; // Assign the initialization function to the memory instance


    cpu_t cpu; // Create a CPU instance
    cpu.reset = reset; // Assign the reset function to the CPU instance
    cpu.reset(&cpu, &memory); // Call the reset function

    printf("CPU Reset:\nA = %d, X = %d, Y = %d\nPC = 0x%04X, SP = 0x%04X\nZ = %d\n",
           cpu.a, cpu.x, cpu.y, cpu.pc, cpu.sp, cpu.Z); 
        
    cpu.execute(2, &cpu, &memory); // Call the execute function 

    return 0;
}
