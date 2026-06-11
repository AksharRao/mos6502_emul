#include "include/instruction.h"

word get_operand_address(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    if (mode == IMMEDIATE) {
        return (word)cpu->pc++;
    } else if (mode == ABSOLUTE) {
        word abs_address = fetch_word(cpu, mem);
        return abs_address;
    } else if (mode == ZEROPAGE) {
        byte zp_address = fetch_byte(cpu, mem);
        return (word)zp_address;
    } else if (mode == ABSOLUTE_X) {
        word abs_address = fetch_word(cpu, mem);
        word abs_address_x = abs_address + cpu->indX;
        return abs_address_x;
    } else if (mode == ABSOLUTE_Y) {
        word abs_address = fetch_word(cpu, mem);
        word abs_address_y = abs_address + cpu->indY;
        return abs_address_y;
    } else if (mode == ZEROPAGE_X) {
        byte zp_address = fetch_byte(cpu, mem);
        byte zp_address_x = (zp_address + cpu->indX) & 0xFF;
        return (word)zp_address_x;
    } else if (mode == ZEROPAGE_Y) {
        byte zp_address = fetch_byte(cpu, mem);
        byte zp_address_y = (zp_address + cpu->indY) & 0xFF;
        return (word)zp_address_y;
    } else if (mode == INDIRECT) {
        return 0;
    } else if (mode == INDIRECT_X) {
        byte zp_address = fetch_byte(cpu, mem);
        word zp_pointer =  (zp_address + cpu->indX) & 0xFF;
        word final_address = read_word(zp_pointer, mem);
        return final_address;
    } else if (mode == INDIRECT_Y) {
        byte zp_address = fetch_byte(cpu, mem);
        word base_pointer = read_word(zp_address, mem);
        word final_address = base_pointer + cpu->indY;
        return final_address;
    } else if (mode == RELATIVE) {
        return 0;
    }
    return 0;
}

void instr_BRK(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    cpu->breakFlag = true;
    (void)mem;
    (void)mode;
}

void instr_LDA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    cpu->acc = read_byte(address, mem);
    printf("\t\tLoaded %d (0x%02X) to Accumulator\n",
        cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

void instr_STA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    write_byte(address, mem, cpu->acc);
    printf("\t\tStored %d (0x%02X) to address (0x%02X) from Accumulator\n", 
       cpu->acc, cpu->acc, address);
    print_memory_address(mem, address);
}

void instr_LDX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    cpu->indX = read_byte(address, mem);
    printf("\t\tLoaded %d (0x%02X) to Index register X\n", cpu->indX, cpu->indX);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

void instr_LDY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    cpu->indY = read_byte(address, mem);
    printf("\t\tLoaded %d (0x%02X) to Index register Y\n", cpu->indY, cpu->indY);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0); 
}

void instr_STX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    write_byte(address, mem, cpu->indX);
    printf("\t\tStored %d (0x%02X) to address (0x%02X) from Index register X\n", 
       cpu->indX, cpu->indX, address);
    print_memory_address(mem, address);
}

void instr_STY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    write_byte(address, mem, cpu->indY);
    printf("\t\tStored %d (0x%02X) to address (0x%02X) from Index register Y\n", 
       cpu->indY, cpu->indY, address);
    print_memory_address(mem, address);
}

// Transfer Instructions
// TAX implied - Transfer Accumulator to index X
void instr_TAX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem; // To get rid of unused variable warning
    (void)mode;
    cpu->indX = cpu->acc;
    printf("\t\tTransfered %d (0x%02X) from Accumulator to Index register X\n",
        cpu->indX, cpu->indX);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// TAY implied - Transfer Accumulator to index Y
void instr_TAY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->indY = cpu->acc;
    printf("\t\tTransfered %d (0x%02X) from Accumulator to Index register Y\n",
        cpu->indY, cpu->indY);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0); 
}

// TSX implied - Transfer Stack pointer to index X
void instr_TSX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->indX = cpu->sp;
    printf("\t\tTransfered %d (0x%02X) from Stack pointer to Index register X\n",
        cpu->indX, cpu->indX);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0); 
}

// TXA implied - Transfer Index X to Accumulator
void instr_TXA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->acc = cpu->indX;
    printf("\t\tTransfered %d (0x%02X) from Index register X to Accumulator\n",
        cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// TXS implied - Transfer Index X to Stack Pointer
void instr_TXS(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->sp = cpu->indX;
    printf("\t\tTransfered %d (0x%02X) from Index register X to Stack Pointer\n",
        cpu->sp, cpu->sp);
    cpu->negative = (cpu->sp & 0x80) != 0;
    cpu->zeroFlag = (cpu->sp == 0); 
}

// TYA implied - Transfer Index Y to accumulator
void instr_TYA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->acc = cpu->indY;
    printf("\t\tTransfered %d (0x%02X) from Index register Y to Accumulator\n",
        cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

// PHA implied - Push accumulator onto stack
void instr_PHA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mode;
    push_stack(cpu, mem, cpu->acc);
    printf("\t\tPushed %d (0x%02X) from Accumulator on to the Stack\n",
        cpu->acc, cpu->acc);
}

// PHP implied - Push Status Register onto stack
void instr_PHP(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mode;
    byte packed_sr = pack_status_register(cpu);
    packed_sr |= (1 << 4); // Set break flag
    push_stack(cpu, mem, packed_sr);
    printf("\t\tPushed %d (0x%02X) from Status Register on to the Stack\n",
        packed_sr, packed_sr);
}

// PLA implied - Pull accumulator from stack
void instr_PLA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mode;
    cpu->acc = pop_stack(cpu, mem);
    printf("\t\tPopped %d (0x%02X) from Stack to Accumulator\n",
        cpu->acc, cpu->acc);
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->zeroFlag = (cpu->acc == 0); 
}

void instr_PLP(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mode;
    byte packed_sr = pop_stack(cpu, mem);
    // Unused and Break flag are to be ignored
    cpu->negative = (packed_sr >> 7) & 1;   
    cpu->overflow = (packed_sr >> 6) & 1;   
    cpu->decimalFlag = (packed_sr >> 3) & 1;
    cpu->irqFlag = (packed_sr >> 2) & 1;    
    cpu->zeroFlag = (packed_sr >> 1) & 1;   
    cpu->carryFlag = packed_sr & 1;
    
    printf("\t\tPopped %d (0x%02X) from Stack to Status Register\n",
        packed_sr, packed_sr);
}

void instr_DEC(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    byte value = read_byte(address, mem);
    value -= 1;
    write_byte(address, mem, value);
    printf("\t\tDecremented 1 at address (0x%02X)\n",
        value);
    cpu->negative = (value & 0x80) != 0;
    cpu->zeroFlag = (value == 0);
}

// DEX - Decrement index X by 1
void instr_DEX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->indX -= 1;
    printf("\t\tDecremented Index X by 1, Index X = (0x%02X)\n",
        cpu->indX);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0);
}

// DEY - Decrement index Y by 1
void instr_DEY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->indY -= 1;
    printf("\t\tDecremented Index Y by 1, Index Y = (0x%02X)\n",
        cpu->indY);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0);
}

void instr_INC(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    byte value = read_byte(address, mem);
    value += 1;
    write_byte(address, mem, value);
    printf("\t\tIncremented 1 at address (0x%02X)\n",
        address);
    cpu->negative = (value & 0x80) != 0;
    cpu->zeroFlag = (value == 0);
}

// INX - Increment index X by 1
void instr_INX(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->indX += 1;
    printf("\t\tIncremented Index X by 1, Index X = (0x%02X)\n",
        cpu->indX);
    cpu->negative = (cpu->indX & 0x80) != 0;
    cpu->zeroFlag = (cpu->indX == 0);
}

// INY - Increment index Y by 1
void instr_INY(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    (void)mem;
    (void)mode;
    cpu->indY += 1;
    printf("\t\tIncremented Index Y by 1, Index Y = (0x%02X)\n",
        cpu->indY);
    cpu->negative = (cpu->indY & 0x80) != 0;
    cpu->zeroFlag = (cpu->indY == 0);
}

// Arithemetic Instructions

// ADC - Add with carry
void instr_ADC(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    byte operand = read_byte(address, mem);
    byte old_acc = cpu->acc;
    word result = cpu->acc + operand + cpu->carryFlag;
    cpu->acc = result & 0xFF;
    printf("\t\tAdded %d (0x%02X) + %d (carry) to Accumulator\n\t\tResult: %d (0x%02X)\n",
        operand, operand, cpu->carryFlag, cpu->acc, cpu->acc);
    cpu->carryFlag = (result > 0xFF) ? 1 : 0;
    cpu->zeroFlag = (cpu->acc == 0) ? 1 : 0;
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->overflow = ((old_acc ^ cpu->acc) & (operand ^ cpu->acc) & 0x80) != 0;
}

// SBC - Subtract with carry
void instr_SBC(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    byte operand = read_byte(address, mem);
    byte old_acc = cpu->acc;
    word result = cpu->acc - operand - (1 - cpu->carryFlag);
    cpu->acc = result & 0xFF;
    printf("\t\tSubtracted %d (0x%02X) - %d (borrow) from Accumulator\n\t\tResult: %d (0x%02X)\n",
        operand, operand, (1 - cpu->carryFlag), cpu->acc, cpu->acc);
    cpu->carryFlag = (result <= 0xFF) ? 1 : 0;
    cpu->zeroFlag = (cpu->acc == 0) ? 1 : 0;
    cpu->negative = (cpu->acc & 0x80) != 0;
    cpu->overflow = ((old_acc ^ operand) & (old_acc ^ cpu->acc) & 0x80) != 0;
}

// Logical instructions

void instr_AND(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    byte operand = read_byte(address, mem);
    cpu->acc &= operand;
    printf("\t\tPerformed bitwise AND with %d (0x%02X) and Accumulator\n\t\tResult: %d (0x%02X)\n",
        operand, operand, cpu->acc, cpu->acc);
    cpu->zeroFlag = (cpu->acc == 0) ? 1 : 0;
    cpu->negative = (cpu->acc & 0x80) != 0;
}

void instr_EOR(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    byte operand = read_byte(address, mem);
    cpu->acc ^= operand;
    printf("\t\tPerformed bitwise EOR with %d (0x%02X) and Accumulator\n\t\tResult: %d (0x%02X)\n",
        operand, operand, cpu->acc, cpu->acc);
    cpu->zeroFlag = (cpu->acc == 0) ? 1 : 0;
    cpu->negative = (cpu->acc & 0x80) != 0;
}

void instr_ORA(cpu_t* cpu, mem_t* mem, addressing_mode_t mode){
    word address = get_operand_address(cpu, mem, mode);
    byte operand = read_byte(address, mem);
    cpu->acc |= operand;
    printf("\t\tPerformed bitwise ORA with %d (0x%02X) and Accumulator\n\t\tResult: %d (0x%02X)\n",
        operand, operand, cpu->acc, cpu->acc);
    cpu->zeroFlag = (cpu->acc == 0) ? 1 : 0;
    cpu->negative = (cpu->acc & 0x80) != 0;
}