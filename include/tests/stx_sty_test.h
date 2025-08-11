// STX/STY Test Program - Tests all STX and STY addressing modes

// Setup: Load test values into X and Y registers first
write_byte(0xFFFC, &mem, 0xA2); // LDX immediate
write_byte(0xFFFD, &mem, 0x42); // X = 0x42

write_byte(0xFFFE, &mem, 0xA0); // LDY immediate  
write_byte(0xFFFF, &mem, 0x88); // Y = 0x88

// Test 1: STX oper - zero page
write_byte(0x0000, &mem, 0x86); // STX zero page
write_byte(0x0001, &mem, 0x20); // Store X to zero page address 0x20

// Test 2: STX oper,Y - zero page indexed with Y
write_byte(0x0002, &mem, 0x96); // STX zero page,Y
write_byte(0x0003, &mem, 0x30); // Base address 0x30 (0x30 + 0x88 = 0xB8, wraps to 0xB8)

// Test 3: STX oper - absolute
write_byte(0x0004, &mem, 0x8E); // STX absolute
write_byte(0x0005, &mem, 0x00); // Low byte of address 0x4000
write_byte(0x0006, &mem, 0x40); // High byte of address 0x4000

// Test 4: STY oper - zero page
write_byte(0x0007, &mem, 0x84); // STY zero page
write_byte(0x0008, &mem, 0x25); // Store Y to zero page address 0x25

// Test 5: STY oper,X - zero page indexed with X
write_byte(0x0009, &mem, 0x94); // STY zero page,X
write_byte(0x000A, &mem, 0x35); // Base address 0x35 (0x35 + 0x42 = 0x77)

// Test 6: STY oper - absolute
write_byte(0x000B, &mem, 0x8C); // STY absolute
write_byte(0x000C, &mem, 0x00); // Low byte of address 0x5000
write_byte(0x000D, &mem, 0x50); // High byte of address 0x5000

// End test with BRK
write_byte(0x000E, &mem, 0x00); // BRK

// Expected Results After Execution:
// mem[0x20] = 0x42    (STX zero page)
// mem[0xB8] = 0x42    (STX zero page,Y with Y=0x88, wraps in zero page)
// mem[0x4000] = 0x42  (STX absolute)
// mem[0x25] = 0x88    (STY zero page)
// mem[0x77] = 0x88    (STY zero page,X with X=0x42)
// mem[0x5000] = 0x88  (STY absolute)