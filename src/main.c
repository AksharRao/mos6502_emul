#include "include/cpu.h"
#include "include/memory.h"
#include<stdio.h>

int main(){
    cpu_t cpu;
    mem_t mem;
    dword clk_cycle = 100;
    
    cpu_init(&cpu);
    print_cpu_state(&cpu);
    cpu_reset(&cpu);

    mem_init(&mem);
    #ifdef DEBUG_MEMORY
    print_memory(&mem);
    #endif // DEBUG_MEMORY
    
    cpu.indX = 0x05; // value at x index register
    cpu.indY = 0x03; // value at y index register

    #include "include/code/sta_code.h"

    exec_instr(&clk_cycle, &cpu, &mem);
    print_cpu_state(&cpu);
    
    return 0;
}