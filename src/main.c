#include "include/cpu.h"
#include "include/memory.h"
#include<stdio.h>

int main(){
    cpu_t cpu;
    mem_t mem;
    
    cpu_init(&cpu);
    print_cpu_state(&cpu);
    cpu_reset(&cpu);

    mem_init(&mem);
    #ifdef DEBUG_MEMORY
    print_memory(&mem);
    #endif // DEBUG_MEMORY

    write_byte(0xFFFC, &mem, 0xA9); // LDA immediate
    write_byte(0xFFFD, &mem, 0x42); // Value 0x42

    dword clk_cycle = 2;
    exec_instr(&clk_cycle, &cpu, &mem);

    print_cpu_state(&cpu);
    
    return 0;
}