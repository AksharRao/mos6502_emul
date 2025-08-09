#include "include/instruction.h"

void instr_BRK(cpu_t* cpu, mem_t* mem){
    cpu->breakFlag = true;
    (void)mem;
}

// LDA Instructions

// LDA #oper - immediate
// Loads immediate value into the accumulator
// Ex. LDA #$42 - Loads 42h i.e. 0x42 into accumulator
void instr_LDA_immediate(cpu_t* cpu, mem_t* mem){
    cpu->acc = fetch_byte(cpu, mem);
    printf("\t\tLoaded %d (0x%02X) to Accumulator\n", cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// LDA oper - zero page
// Loads value from zero page address into the accumulator
// Ex. LDA $42 - Loads value from zero page address $42 into accumulator
void instr_LDA_zeropage(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    cpu->acc = read_byte(zp_address, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom zero page address (0x%02X) to Accumulator", 
        cpu->acc, cpu->acc, zp_address);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// LDA oper,X - zero page indexed with X
// Loads value from zero page address + X into the accumulator
// Ex. LDA $42,X - Loads value from zero page address ($42 + X) into accumulator
void instr_LDA_zeropage_x(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    byte zp_address_x = (zp_address + cpu->indX) & 0xFF;
    cpu->acc = read_byte(zp_address_x, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom zero page address (0x%02X),X\n\t\t(0x%02X + 0x%02X = 0x%02X) to Accumulator\n", 
        cpu->acc, cpu->acc, zp_address, zp_address, cpu->indX, zp_address_x);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// LDA oper - absolute
// Loads value from absolute address into the accumulator
// Ex. LDA $1234 - Loads value from absolute address $1234 into accumulator
void instr_LDA_absolute(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    cpu->acc = read_byte(abs_address, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X) to Accumulator\n", 
        cpu->acc, cpu->acc, abs_address);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// LDA oper,X - absolute indexed with X
// Loads value from absolute address + X into the accumulator
// Ex. LDA $1234,X - Loads value from absolute address ($1234 + X) into accumulator
void instr_LDA_absolute_x(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_x = abs_address + cpu->indX;
    cpu->acc = read_byte(abs_address_x, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X), X\n\t\t(0x%04X + 0x%02X = 0x%04X) to Accumulator\n", 
        cpu->acc, cpu->acc, abs_address, abs_address, cpu->indX, abs_address_x);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// LDA oper,Y - absolute indexed with Y
// Loads value from absolute address + Y into the accumulator
// Ex. LDA $1234,Y - Loads value from absolute address ($1234 + Y) into accumulator
void instr_LDA_absolute_y(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_y = abs_address + cpu->indY;
    cpu->acc = read_byte(abs_address_y, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X), Y\n\t\t(0x%04X + 0x%02X = 0x%04X) to Accumulator\n", 
        cpu->acc, cpu->acc, abs_address, abs_address, cpu->indY, abs_address_y);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// LDA (oper,X) - indexed indirect
// Loads value from address pointed to by (zero page address + X) into the accumulator
// Ex. LDA ($42,X) - Loads value from address stored at zero page ($42 + X) into accumulator
void instr_LDA_indirect_x(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    word zp_pointer =  (zp_address + cpu->indX) & 0xFF;
    word final_address = read_word(zp_pointer, mem);
    cpu->acc = read_byte(final_address, mem);
    printf("\t\tLoaded %d (0x%02X) from ($%02X,X)\n\t\t($%02X + $%02X = $%02X) -> $%04X to Accumulator\n", 
        cpu->acc, cpu->acc, zp_address, zp_address, cpu->indX, zp_pointer, final_address);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0);
}

// LDA (oper),Y - indirect indexed
// Loads value from (address pointed to by zero page address) + Y into the accumulator
// Ex. LDA ($42),Y - Loads value from (address at $42) + Y into accumulator
void instr_LDA_indirect_y(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    word base_pointer = read_word(zp_address, mem);
    word final_address = base_pointer + cpu->indY;
    cpu->acc = read_byte(final_address, mem);
    printf("\t\tLoaded %d (0x%02X) from ($%02X),Y\n\t\t($%04X + $%02X = $%04X) to Accumulator\n", 
        cpu->acc, cpu->acc, zp_address, base_pointer, cpu->indY, final_address);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0);
}

// STA Instructions

// STA oper - zero page
// Stores accumulator value to zero page address
// Ex. STA $42 - Stores accumulator value to zero page address $42
void instr_STA_zeropage(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    write_byte(zp_address, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X) to zero page address (0x%02X) from Accumulator\n", 
       cpu->acc, cpu->acc, zp_address);
    print_memory_address(mem, zp_address);
}

// STA oper,X - zero page indexed with X
// Stores accumulator value to zero page address + X
// Ex. STA $42,X - Stores accumulator value to zero page address ($42 + X)
void instr_STA_zeropage_x(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    byte zp_address_x = (zp_address + cpu->indX) & 0xFF;
    write_byte(zp_address_x, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X)\n\t\tfrom zero page address (0x%02X),X\n\t\t(0x%02X + 0x%02X = 0x%02X) from Accumulator\n", 
        cpu->acc, cpu->acc, zp_address, zp_address, cpu->indX, zp_address_x);
}

// STA oper - absolute
// Stores accumulator value to absolute address
// Ex. STA $1234 - Stores accumulator value to absolute address $1234
void instr_STA_absolute(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    write_byte(abs_address, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X)\n\t\tfrom absolute address (0x%04X) from Accumulator\n", 
        cpu->acc, cpu->acc, abs_address);
}

// STA oper,X - absolute indexed with X
// Stores accumulator value to absolute address + X
// Ex. STA $1234,X - Stores accumulator value to absolute address ($1234 + X)
void instr_STA_absolute_x(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_x = abs_address + cpu->indX;
    write_byte(abs_address_x, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X)\n\t\tfrom absolute address (0x%04X), X\n\t\t(0x%04X + 0x%02X = 0x%04X) from Accumulator\n", 
        cpu->acc, cpu->acc, abs_address, abs_address, cpu->indX, abs_address_x);
}

// STA oper,Y - absolute indexed with Y
// Stores accumulator value to absolute address + Y
// Ex. STA $1234,Y - Stores accumulator value to absolute address ($1234 + Y)
void instr_STA_absolute_y(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_y = abs_address + cpu->indY;
    write_byte(abs_address_y, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X)\n\t\tfrom absolute address (0x%04X), Y\n\t\t(0x%04X + 0x%02X = 0x%04X) from Accumulator\n", 
        cpu->acc, cpu->acc, abs_address, abs_address, cpu->indY, abs_address_y);
}

// STA (oper,X) - indexed indirect
// Stores accumulator value to address pointed to by (zero page address + X)
// Ex. STA ($42,X) - Stores accumulator value to address stored at zero page ($42 + X)
void instr_STA_indirect_x(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    word zp_pointer =  (zp_address + cpu->indX) & 0xFF;
    word final_address = read_word(zp_pointer, mem);
    write_byte(final_address, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X) from ($%02X,X)\n\t\t($%02X + $%02X = $%02X) -> $%04X from Accumulator\n", 
        cpu->acc, cpu->acc, zp_address, zp_address, cpu->indX, zp_pointer, final_address);
}

// STA (oper),Y - indirect indexed
// Stores accumulator value to (address pointed to by zero page address) + Y
// Ex. STA ($42),Y - Stores accumulator value to (address at $42) + Y
void instr_STA_indirect_y(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    word base_pointer = read_word(zp_address, mem);
    word final_address = base_pointer + cpu->indY;
    write_byte(final_address, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X) from ($%02X),Y\n\t\t($%02X + $%02X = $%02X) -> $%04X from Accumulator\n", 
        cpu->acc, cpu->acc, zp_address, zp_address, cpu->indY, base_pointer, final_address);
}

// LDX Instructions

// LDX #oper - immediate
// Loads immediate value into the X index register
// Ex. LDX #$42 - Loads 42h i.e. 0x42 into X register
void instr_LDX_immediate(cpu_t* cpu, mem_t* mem){
    cpu->indX = fetch_byte(cpu, mem);
    printf("\t\tLoaded %d (0x%02X) to Index register X\n", cpu->indX, cpu->indX);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// LDX oper - zero page
// Loads value from zero page address into the X index register
// Ex. LDX $42 - Loads value from zero page address $42 into X register
void instr_LDX_zeropage(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    cpu->indX = read_byte(zp_address, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom zero page address (0x%02X) to Index register X", 
        cpu->indX, cpu->indX, zp_address);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// LDX oper,Y - zero page indexed with Y
// Loads value from zero page address + Y into the X index register
// Ex. LDX $42,Y - Loads value from zero page address ($42 + Y) into X register
void instr_LDX_zeropage_y(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    byte zp_address_y = (zp_address + cpu->indY) & 0xFF;
    cpu->indX = read_byte(zp_address_y, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom zero page address (0x%02X),Y\n\t\t(0x%02X + 0x%02X = 0x%02X) to Index register X\n", 
        cpu->indX, cpu->indX, zp_address, zp_address, cpu->indY, zp_address_y);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// LDX oper - absolute 
// Loads from an absolute address to X index register
// Ex. LDX $1234 - Loads value from absolute address $1234 into X register
void instr_LDX_absolute(cpu_t* cpu, mam_t* mem){
    word abs_address = fetch_word(cpu, mem);
    cpu->indX = read_byte(abs_address, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X) to Index register X\n", 
        cpu->indX, cpu->indX, abs_address);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// LDX oper, Y - absolute, Y
// Loads from absolute address + Y into X index register
// Ex. LDX $1234,Y - Laods value from absolute address $1234 + Y into X register
void instr_LDX_absolute_y(cpu_t* cpu, mam_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_y = abs_address + cpu->indY;
    cpu->indX = read_byte(abs_address_y, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X), Y\n\t\t(0x%04X + 0x%02X = 0x%04X) to Index register X\n", 
        cpu->indX, cpu->indX, abs_address, abs_address, cpu->indY, abs_address_y);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}
