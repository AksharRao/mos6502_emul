#include "include/instruction.h"

// Index
// LDA Instructions - Line 11
// STA Instructions - Line 115
// LDX Instructions - Line 196
// LDY Instructions - Line 259
// STX Instructions - Line 322
// STY Instructions - Line 356

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
    printf("\t\tStored %d (0x%02X)\n\t\tto zero page address (0x%02X),X\n\t\t(0x%02X + 0x%02X = 0x%02X) from Accumulator\n", 
        cpu->acc, cpu->acc, zp_address, zp_address, cpu->indX, zp_address_x);
}

// STA oper - absolute
// Stores accumulator value to absolute address
// Ex. STA $1234 - Stores accumulator value to absolute address $1234
void instr_STA_absolute(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    write_byte(abs_address, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X)\n\t\tto absolute address (0x%04X) from Accumulator\n", 
        cpu->acc, cpu->acc, abs_address);
}

// STA oper,X - absolute indexed with X
// Stores accumulator value to absolute address + X
// Ex. STA $1234,X - Stores accumulator value to absolute address ($1234 + X)
void instr_STA_absolute_x(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_x = abs_address + cpu->indX;
    write_byte(abs_address_x, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X)\n\t\tto absolute address (0x%04X), X\n\t\t(0x%04X + 0x%02X = 0x%04X) from Accumulator\n", 
        cpu->acc, cpu->acc, abs_address, abs_address, cpu->indX, abs_address_x);
}

// STA oper,Y - absolute indexed with Y
// Stores accumulator value to absolute address + Y
// Ex. STA $1234,Y - Stores accumulator value to absolute address ($1234 + Y)
void instr_STA_absolute_y(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_y = abs_address + cpu->indY;
    write_byte(abs_address_y, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X)\n\t\tto absolute address (0x%04X), Y\n\t\t(0x%04X + 0x%02X = 0x%04X) from Accumulator\n", 
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
    printf("\t\tStored %d (0x%02X) to ($%02X,X)\n\t\t($%02X + $%02X = $%02X) -> $%04X from Accumulator\n", 
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
    printf("\t\tStored %d (0x%02X) to ($%02X),Y\n\t\t($%04X + $%02X = $%04X) from Accumulator\n", 
        cpu->acc, cpu->acc, zp_address, base_pointer, cpu->indY, final_address);
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
void instr_LDX_absolute(cpu_t* cpu, mem_t* mem){
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
void instr_LDX_absolute_y(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_y = abs_address + cpu->indY;
    cpu->indX = read_byte(abs_address_y, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X), Y\n\t\t(0x%04X + 0x%02X = 0x%04X) to Index register X\n", 
        cpu->indX, cpu->indX, abs_address, abs_address, cpu->indY, abs_address_y);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// LDY Instructions

// LDY #oper - immediate
// Loads immediate value into the Y index register
// Ex. LDY #$42 - Loads 42h i.e. 0x42 into Y register
void instr_LDY_immediate(cpu_t* cpu, mem_t* mem){
    cpu->indY = fetch_byte(cpu, mem);
    printf("\t\tLoaded %d (0x%02X) to Index register Y\n", cpu->indY, cpu->indY);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0); 
}

// LDY oper - zero page
// Loads value from zero page address into the Y index register
// Ex. LDY $42 - Loads value from zero page address $42 into Y register
void instr_LDY_zeropage(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    cpu->indY = read_byte(zp_address, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom zero page address (0x%02X) to Index register Y", 
        cpu->indY, cpu->indY, zp_address);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0); 
}

// LDY oper,X - zero page indexed with X
// Loads value from zero page address + X into the Y index register
// Ex. LDY $42,X - Loads value from zero page address ($42 + X) into Y register
void instr_LDY_zeropage_x(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    byte zp_address_x = (zp_address + cpu->indX) & 0xFF;
    cpu->indY = read_byte(zp_address_x, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom zero page address (0x%02X),X\n\t\t(0x%02X + 0x%02X = 0x%02X) to Index register Y\n", 
        cpu->indY, cpu->indY, zp_address, zp_address, cpu->indX, zp_address_x);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0); 
}

// LDY oper - absolute 
// Loads value from absolute address into the Y index register
// Ex. LDY $1234 - Loads value from absolute address $1234 into Y register
void instr_LDY_absolute(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    cpu->indY = read_byte(abs_address, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X) to Index register Y\n", 
        cpu->indY, cpu->indY, abs_address);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0); 
}

// LDY oper,X - absolute indexed with X
// Loads value from absolute address + X into the Y index register
// Ex. LDY $1234,X - Loads value from absolute address ($1234 + X) into Y register
void instr_LDY_absolute_x(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    word abs_address_x = abs_address + cpu->indX;
    cpu->indY = read_byte(abs_address_x, mem);
    printf("\t\tLoaded %d (0x%02X)\n\t\tfrom absolute address (0x%04X), X\n\t\t(0x%04X + 0x%02X = 0x%04X) to Index register Y\n", 
        cpu->indY, cpu->indY, abs_address, abs_address, cpu->indX, abs_address_x);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0); 
}

// STX Instructions

// STX oper - zero page
// Stores x index register value to zero page address
// Ex. STX $42 - Stores x index register value to zero page address $42
void instr_STX_zeropage(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    write_byte(zp_address, mem, cpu->indX);
    printf("\t\tStored %d (0x%02X) to zero page address (0x%02X) from Index register X\n", 
       cpu->indX, cpu->indX, zp_address);
    print_memory_address(mem, zp_address);
}

// STX oper,Y - zero page indexed with Y
// Stores x index register value to zero page address + Y
// Ex. STX $42,Y - Stores x index register value to zero page address ($42 + Y)
void instr_STX_zeropage_y(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    byte zp_address_y = (zp_address + cpu->indY) & 0xFF;
    write_byte(zp_address_y, mem, cpu->indX);
    printf("\t\tStored %d (0x%02X)\n\t\tto zero page address (0x%02X),Y\n\t\t(0x%02X + 0x%02X = 0x%02X) from Index register X\n", 
        cpu->indX, cpu->indX, zp_address, zp_address, cpu->indY, zp_address_y);
}

// STX oper - absolute
// Stores x index register value to absolute address
// Ex. STX $1234 - Stores x index register value to absolute address $1234
void instr_STX_absolute(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    write_byte(abs_address, mem, cpu->indX);
    printf("\t\tStored %d (0x%02X)\n\t\tto absolute address (0x%04X) from Index register X\n", 
        cpu->indX, cpu->indX, abs_address);
}

// STY Instructions

// STY oper - zero page
// Stores Y index register value to zero page address
// Ex. STY $42 - Stores Y index register value to zero page address $42
void instr_STY_zeropage(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    write_byte(zp_address, mem, cpu->indY);
    printf("\t\tStored %d (0x%02X) to zero page address (0x%02X) from Index register Y\n", 
       cpu->indY, cpu->indY, zp_address);
    print_memory_address(mem, zp_address);
}

// STY oper,X - zero page indexed with X
// Stores Y index register value to zero page address + X
// Ex. STY $42,X - Stores Y index register value to zero page address ($42 + X)
void instr_STY_zeropage_x(cpu_t* cpu, mem_t* mem){
    byte zp_address = fetch_byte(cpu, mem);
    byte zp_address_x = (zp_address + cpu->indX) & 0xFF;
    write_byte(zp_address_x, mem, cpu->indY);
    printf("\t\tStored %d (0x%02X)\n\t\tto zero page address (0x%02X),X\n\t\t(0x%02X + 0x%02X = 0x%02X) from Index register Y\n", 
        cpu->indY, cpu->indY, zp_address, zp_address, cpu->indX, zp_address_x);
}

// STY oper - absolute
// Stores Y index register value to absolute address
// Ex. STY $1234 - Stores Y index register value to absolute address $1234
void instr_STY_absolute(cpu_t* cpu, mem_t* mem){
    word abs_address = fetch_word(cpu, mem);
    write_byte(abs_address, mem, cpu->indY);
    printf("\t\tStored %d (0x%02X)\n\t\tto absolute address (0x%04X) from Index register Y\n", 
        cpu->indY, cpu->indY, abs_address);
}

// TAX implied - Transfer Accumulator to index X
void instr_TAX_implied(cpu_t* cpu, mem_t* mem){
    (void)mem; // To get rid of unused variable warning
    cpu->indX = cpu->acc;
    printf("\t\tTransfered %d (0x%02X) from Accumulator to Index register X\n", cpu->indX, cpu->indX);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// TAY implied - Transfer Accumulator to index Y
void instr_TAY_implied(cpu_t* cpu, mem_t* mem){
    (void)mem;
    cpu->indY = cpu->acc;
    printf("\t\tTransfered %d (0x%02X) from Accumulator to Index register Y\n", cpu->indY, cpu->indY);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0); 
}

// TSX implied - Transfer Stack pointer to index X
void instr_TSX_implied(cpu_t* cpu, mem_t* mem){
    (void)mem;
    cpu->indX = cpu->sp;
    printf("\t\tTransfered %d (0x%02X) from Stack pointer to Index register X\n", cpu->indX, cpu->indX);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// TXA implied - Transfer Index X to Accumulator
void instr_TXA_implied(cpu_t* cpu, mem_t* mem){
    (void)mem;
    cpu->acc = cpu->indX;
    printf("\t\tTransfered %d (0x%02X) from Index register X to Accumulator\n", cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// TXS implied - Transfer Index X to Stack Pointer
void instr_TXS_implied(cpu_t* cpu, mem_t* mem){
    (void)mem;
    cpu->sp = cpu->indX;
    printf("\t\tTransfered %d (0x%02X) from Index register X to Stack Pointer\n", cpu->sp, cpu->sp);
    cpu->negative = (cpu->sp & 0x80) != 0;
    cpu->zeroFlag = (cpu->sp == 0); 
}

// TYA implied - Transfer Index Y to accumulator
void instr_TYA_implied(cpu_t* cpu, mem_t* mem){
    (void)mem;
    cpu->acc = cpu->indY;
    printf("\t\tTransfered %d (0x%02X) from Index register Y to Accumulator\n", cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}