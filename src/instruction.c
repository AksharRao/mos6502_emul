#include "include/instruction.h"

static instruction_t instruction_table[] = {
    [0x00] = {"BRK", ADDR_IMPLIED, 7, instr_BRK},
    [0xA9] = {"LDA", ADDR_IMMEDIATE, 2, instr_LDA_immediate}
};

void decode_and_execute(cpu_t* cpu, mem_t* mem, byte opcode){
    instruction_t* instr = &instruction_table[opcode];

    if(instr->execute == NULL){
        printf("Unknown opcode: 0x%02X at PC: 0x%04X\n", opcode, cpu->pc);
        return;
    }

    printf("Executing: %s (0x%02X)\n", instr->name, opcode);
    instr->execute(cpu, mem);
}

void instr_BRK(cpu_t* cpu, mem_t* mem){
    cpu->breakFlag = true;
    (void)mem;
}

void instr_LDA_immediate(cpu_t* cpu, mem_t* mem){
    dword dummy_cycle = 1;
    cpu->acc = fetch_byte(&dummy_cycle, cpu, mem);
    printf("\t\tLoaded %d (0x%02X)\n", cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}



