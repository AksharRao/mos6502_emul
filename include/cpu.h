#ifndef CPU_H
#define CPU_H

#include "types.h"
#include "memory.h"

//prototypes to be used in cpu.c
void cpu_init(cpu_t *cpu);
void cpu_reset(cpu_t *cpu);
void print_cpu_state(cpu_t *cpu);

byte fetch_byte(cpu_t *cpu, mem_t *mem);
word fetch_word(cpu_t *cpu, mem_t *mem);
void exec_instr(dword *clk_cycle, cpu_t *cpu, mem_t *mem);

byte pack_status_register(cpu_t * cpu);

#endif