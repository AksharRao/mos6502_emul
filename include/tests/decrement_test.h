// Decrement Instructions Test Program

// Test 1: DEX - Decrement Index X
write_byte(0xFFFC, &mem, 0xA2); // LDX immediate
write_byte(0xFFFD, &mem, 0x01); // X = 0x01

write_byte(0xFFFE, &mem, 0xCA); // DEX
// Should decrement X to 0x00, set zero flag, clear negative flag

// Test 2: DEX with underflow
write_byte(0xFFFF, &mem, 0xA2); // LDX immediate
write_byte(0x0000, &mem, 0x00); // X = 0x00

write_byte(0x0001, &mem, 0xCA); // DEX
// Should decrement X to 0xFF, set negative flag, clear zero flag

// Test 3: DEY - Decrement Index Y
write_byte(0x0002, &mem, 0xA0); // LDY immediate
write_byte(0x0003, &mem, 0x81); // Y = 0x81

write_byte(0x0004, &mem, 0x88); // DEY
// Should decrement Y to 0x80, set negative flag, clear zero flag

// Test 4: DEY with zero result
write_byte(0x0005, &mem, 0xA0); // LDY immediate
write_byte(0x0006, &mem, 0x01); // Y = 0x01

write_byte(0x0007, &mem, 0x88); // DEY
// Should decrement Y to 0x00, set zero flag, clear negative flag

// Set up memory values for DEC memory tests
write_byte(0x0020, &mem, 0x01); // Value at zero page 0x20
write_byte(0x0025, &mem, 0x00); // Value at zero page 0x25
write_byte(0x0030, &mem, 0x80); // Value at zero page 0x30
write_byte(0x2000, &mem, 0x42); // Value at absolute 0x2000
write_byte(0x3008, &mem, 0xFF); // Value at absolute 0x3008

// Test 5: DEC zero page
write_byte(0x0008, &mem, 0xC6); // DEC zero page
write_byte(0x0009, &mem, 0x20); // Address 0x20
// Should decrement 0x01 to 0x00, set zero flag

// Test 6: DEC zero page,X
write_byte(0x000A, &mem, 0xA2); // LDX immediate - set up X register
write_byte(0x000B, &mem, 0x05); // X = 0x05

write_byte(0x000C, &mem, 0xD6); // DEC zero page,X
write_byte(0x000D, &mem, 0x20); // Base address 0x20 (0x20 + 0x05 = 0x25)
// Should decrement 0x00 to 0xFF at address 0x25, set negative flag

// Test 7: DEC zero page,X with normal decrement
write_byte(0x000E, &mem, 0xD6); // DEC zero page,X
write_byte(0x000F, &mem, 0x2B); // Base address 0x2B (0x2B + 0x05 = 0x30)
// Should decrement 0x80 to 0x7F at address 0x30, clear negative flag

// Test 8: DEC absolute
write_byte(0x0010, &mem, 0xCE); // DEC absolute
write_byte(0x0011, &mem, 0x00); // Low byte of address 0x2000
write_byte(0x0012, &mem, 0x20); // High byte of address 0x2000
// Should decrement 0x42 to 0x41, clear all flags

// Test 9: DEC absolute,X (X still = 0x05)
write_byte(0x0013, &mem, 0xDE); // DEC absolute,X
write_byte(0x0014, &mem, 0x03); // Low byte of base address 0x3003
write_byte(0x0015, &mem, 0x30); // High byte (0x3003 + 0x05 = 0x3008)
// Should decrement 0xFF to 0xFE at address 0x3008, set negative flag

// End test with BRK
write_byte(0x0016, &mem, 0x00); // BRK

// Expected Results After Execution:
// X Register: 0x05 (set by LDX for indexing)
// Y Register: 0x00 (from DEY with 0x01)  
// mem[0x20] = 0x00 (DEC zero page)
// mem[0x25] = 0xFF (DEC zero page,X with underflow)
// mem[0x30] = 0x7F (DEC zero page,X normal)
// mem[0x2000] = 0x41 (DEC absolute)
// mem[0x3008] = 0xFE (DEC absolute,X)
// Final flags: Zero=1, Negative=0 (from Y register operations)