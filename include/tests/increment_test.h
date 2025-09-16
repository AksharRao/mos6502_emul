// Increment Instructions Test Program

// Test 1: INX - Increment Index X
write_byte(0xFFFC, &mem, 0xA2); // LDX immediate
write_byte(0xFFFD, &mem, 0x7E); // X = 0x7E

write_byte(0xFFFE, &mem, 0xE8); // INX
// Should increment X to 0x7F, positive value, clear negative and zero flags

// Test 2: INX with zero result
write_byte(0xFFFF, &mem, 0xA2); // LDX immediate
write_byte(0x0000, &mem, 0xFF); // X = 0xFF

write_byte(0x0001, &mem, 0xE8); // INX
// Should increment X to 0x00, set zero flag, clear negative flag

// Test 3: INY - Increment Index Y
write_byte(0x0002, &mem, 0xA0); // LDY immediate
write_byte(0x0003, &mem, 0x7F); // Y = 0x7F

write_byte(0x0004, &mem, 0xC8); // INY
// Should increment Y to 0x80, set negative flag, clear zero flag

// Test 4: INY with zero result
write_byte(0x0005, &mem, 0xA0); // LDY immediate
write_byte(0x0006, &mem, 0xFF); // Y = 0xFF

write_byte(0x0007, &mem, 0xC8); // INY
// Should increment Y to 0x00, set zero flag, clear negative flag

// Set up memory values for INC memory tests
write_byte(0x0080, &mem, 0x7F); // Value at zero page 0x80
write_byte(0x0085, &mem, 0xFE); // Value at zero page 0x85
write_byte(0x0090, &mem, 0xFF); // Value at zero page 0x90
write_byte(0x3000, &mem, 0x00); // Value at absolute 0x3000
write_byte(0x4005, &mem, 0x7F); // Value at absolute 0x4005

// Test 5: INC zero page
write_byte(0x0008, &mem, 0xE6); // INC zero page
write_byte(0x0009, &mem, 0x80); // Address 0x80
// Should increment 0x7F to 0x80, set negative flag

// Test 6: INC zero page,X
write_byte(0x000A, &mem, 0xA2); // LDX immediate - set up X register
write_byte(0x000B, &mem, 0x05); // X = 0x05

write_byte(0x000C, &mem, 0xF6); // INC zero page,X
write_byte(0x000D, &mem, 0x80); // Base address 0x80 (0x80 + 0x05 = 0x85)
// Should increment 0xFE to 0xFF at address 0x85, set negative flag

// Test 7: INC zero page,X with zero result
write_byte(0x000E, &mem, 0xF6); // INC zero page,X
write_byte(0x000F, &mem, 0x8B); // Base address 0x8B (0x8B + 0x05 = 0x90)
// Should increment 0xFF to 0x00 at address 0x90, set zero flag

// Test 8: INC absolute
write_byte(0x0010, &mem, 0xEE); // INC absolute
write_byte(0x0011, &mem, 0x00); // Low byte of address 0x3000
write_byte(0x0012, &mem, 0x30); // High byte of address 0x3000
// Should increment 0x00 to 0x01, clear all flags

// Test 9: INC absolute,X (X still = 0x05)
write_byte(0x0013, &mem, 0xFE); // INC absolute,X
write_byte(0x0014, &mem, 0x00); // Low byte of base address 0x4000
write_byte(0x0015, &mem, 0x40); // High byte (0x4000 + 0x05 = 0x4005)
// Should increment 0x7F to 0x80 at address 0x4005, set negative flag

// End test with BRK
write_byte(0x0016, &mem, 0x00); // BRK

// Expected Results After Execution:
// X Register: 0x00 (from INX with 0xFF)
// Y Register: 0x00 (from INY with 0xFF)  
// mem[0x80] = 0x80 (INC zero page)
// mem[0x85] = 0xFF (INC zero page,X)
// mem[0x90] = 0x00 (INC zero page,X with zero result)
// mem[0x3000] = 0x01 (INC absolute)
// mem[0x4005] = 0x80 (INC absolute,X)
// Final flags: Zero=1, Negative=0 (from last register operations)