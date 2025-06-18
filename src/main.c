#include "include/cpu.h"
#include "include/memory.h"
#include<stdio.h>

int main(){
    cpu_t cpu;
    mem_t mem;
    
    initialize(&cpu);
    printCpuState(&cpu);
    reset(&cpu);

    initMemory(&mem);
    #ifdef DEBUG_MEMORY
    printMemory(&mem);
    #endif // DEBUG_MEMORY

    dword clk_cycle = 2;
    execInstr(&clk_cycle, &mem, &cpu);
    printCpuState(&cpu);
    
    return 0;
}