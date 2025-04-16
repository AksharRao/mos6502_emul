#include "include/cpu.h"
#include<stdio.h>

int main(){
    cpu_t cpu;
    initialize(&cpu);
    printCpuState(&cpu);
    return 0;
}