#include "include/instruction.h"

void instr_BRK(cpu_t* cpu, mem_t* mem){
    cpu->breakFlag = true;
    (void)mem;
}

void instr_LDA_immediate(cpu_t* cpu, mem_t* mem){
    cpu->acc = fetch_byte(cpu, mem);
    printf("\t\tLoaded %d (0x%02X) to accumulator\n", cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

void instr_LDA_zeropage(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    cpu->acc = read_byte(zp_address, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom zero page address (0x%02X)", 
        cpu->acc, cpu->acc, zp_address);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

void instr_LDA_zeropage_x(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    byte zp_address_x = (zp_address + cpu->indX) & 0xFF;
    cpu->acc = read_byte(zp_address_x, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom zero page address (0x%02X),X\n\t\t(0x%02X + 0x%02X = 0x%02X)\n", 
        cpu->acc, cpu->acc, zp_address, zp_address, cpu->indX, zp_address_x);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

void instr_LDA_absolute(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    cpu->acc = read_byte(abs_address, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X)\n", 
        cpu->acc, cpu->acc, abs_address);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

void instr_LDA_absolute_x(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_x = abs_address + cpu->indX;
    cpu->acc = read_byte(abs_address_x, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X), X\n\t\t(0x%04X + 0x%02X = 0x%04X)\n", 
        cpu->acc, cpu->acc, abs_address, abs_address, cpu->indX, abs_address_x);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

void instr_LDA_absolute_y(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_y = abs_address + cpu->indY;
    cpu->acc = read_byte(abs_address_y, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X), Y\n\t\t(0x%04X + 0x%02X = 0x%04X)\n", 
        cpu->acc, cpu->acc, abs_address, abs_address, cpu->indY, abs_address_y);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

void instr_LDA_indirect_x(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    word zp_pointer =  (zp_address + cpu->indX) & 0xFF;
    word final_address = read_word(zp_pointer, mem);
    cpu->acc = read_byte(final_address, mem);
    printf("\t\tLoaded %d (0x%02X) from ($%02X,X)\n\t\t($%02X + $%02X = $%02X) -> $%04X\n", 
        cpu->acc, cpu->acc, zp_address, zp_address, cpu->indX, zp_pointer, final_address);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0);
}

void instr_LDA_indirect_y(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    word base_pointer =  read_word(zp_address, mem);
    word final_address = base_pointer + cpu->indY;
    cpu->acc = read_byte(final_address, mem);
    printf("\t\tLoaded %d (0x%02X) from ($%02X),Y\n\t\t($%04X + $%02X = $%04X)\n", 
        cpu->acc, cpu->acc, zp_address, base_pointer, cpu->indY, final_address);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0);
}



