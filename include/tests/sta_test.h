write_byte(0xFFFC, &mem, 0xA9); // LDA immediate - load test value
write_byte(0xFFFD, &mem, 0x42); // Load 0x42 into accumulator

write_byte(0xFFFE, &mem, 0x85); // STA zero page
write_byte(0xFFFF, &mem, 0x80); // Store to zero page address 0x80

// Test 2: STA Zero Page,X (with X = 0x05)
write_byte(0x0000, &mem, 0xA2); // LDX immediate - set up X register
write_byte(0x0001, &mem, 0x05); // X = 0x05

write_byte(0x0002, &mem, 0xA9); // LDA immediate - load test value
write_byte(0x0003, &mem, 0x88); // Load 0x88 into accumulator

write_byte(0x0004, &mem, 0x95); // STA zero page,X
write_byte(0x0005, &mem, 0x40); // Base address 0x40 (0x40 + 0x05 = 0x45)

// Test 3: STA Absolute
write_byte(0x0006, &mem, 0xA9); // LDA immediate - load test value
write_byte(0x0007, &mem, 0x99); // Load 0x99 into accumulator

write_byte(0x0008, &mem, 0x8D); // STA absolute
write_byte(0x0009, &mem, 0x00); // Low byte of address 0x3000
write_byte(0x000A, &mem, 0x30); // High byte of address 0x3000

// Test 4: STA Absolute,X (with X still = 0x05)
write_byte(0x000B, &mem, 0xA9); // LDA immediate - load test value
write_byte(0x000C, &mem, 0xAA); // Load 0xAA into accumulator

write_byte(0x000D, &mem, 0x9D); // STA absolute,X
write_byte(0x000E, &mem, 0x00); // Low byte of base address 0x4000
write_byte(0x000F, &mem, 0x40); // High byte (0x4000 + 0x05 = 0x4005)

// Test 5: STA Absolute,Y (set up Y register first)
write_byte(0x0010, &mem, 0xA0); // LDY immediate - set up Y register
write_byte(0x0011, &mem, 0x08); // Y = 0x08

write_byte(0x0012, &mem, 0xA9); // LDA immediate - load test value
write_byte(0x0013, &mem, 0xBB); // Load 0xBB into accumulator

write_byte(0x0014, &mem, 0x99); // STA absolute,Y
write_byte(0x0015, &mem, 0x00); // Low byte of base address 0x5000
write_byte(0x0016, &mem, 0x50); // High byte (0x5000 + 0x08 = 0x5008)

// Test 6: STA (Indirect,X) - Set up pointer at zero page
// First set up the pointer at zero page 0x20 + X (0x05) = 0x25
write_byte(0x0025, &mem, 0x00); // Low byte of target address 0x6000
write_byte(0x0026, &mem, 0x60); // High byte of target address 0x6000

write_byte(0x0017, &mem, 0xA9); // LDA immediate - load test value
write_byte(0x0018, &mem, 0xCC); // Load 0xCC into accumulator

write_byte(0x0019, &mem, 0x81); // STA (indirect,X)
write_byte(0x001A, &mem, 0x20); // Zero page base address 0x20 (0x20 + 0x05 = 0x25)

// Test 7: STA (Indirect),Y - Set up pointer at zero page
// Set up pointer at zero page 0x30
write_byte(0x0030, &mem, 0x00); // Low byte of base address 0x7000
write_byte(0x0031, &mem, 0x70); // High byte of base address 0x7000

write_byte(0x001B, &mem, 0xA9); // LDA immediate - load test value
write_byte(0x001C, &mem, 0xDD); // Load 0xDD into accumulator

write_byte(0x001D, &mem, 0x91); // STA (indirect),Y
write_byte(0x001E, &mem, 0x30); // Zero page pointer address 0x30 (0x7000 + 0x08 = 0x7008)

// Expected Results After Execution:
// mem[0x80] = 0x42    (STA zero page)
// mem[0x45] = 0x88    (STA zero page,X with X=0x05)
// mem[0x3000] = 0x99  (STA absolute)
// mem[0x4005] = 0xAA  (STA absolute,X with X=0x05)
// mem[0x5008] = 0xBB  (STA absolute,Y with Y=0x08)
// mem[0x6000] = 0xCC  (STA (indirect,X))
// mem[0x7008] = 0xDD  (STA (indirect),Y with Y=0x08)