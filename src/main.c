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

    #include "include/tests/stack_test.h"

    exec_instr(&clk_cycle, &cpu, &mem);
    print_cpu_state(&cpu);
    
    return 0;
}