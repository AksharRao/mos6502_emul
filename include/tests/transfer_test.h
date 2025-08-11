// Transfer Instructions Test Program

// Setup: Load test values into registers
write_byte(0xFFFC, &mem, 0xA9); // LDA immediate
write_byte(0xFFFD, &mem, 0x99); // A = 0x99 (negative value)

write_byte(0xFFFE, &mem, 0xA2); // LDX immediate
write_byte(0xFFFF, &mem, 0x00); // X = 0x00 (zero value)

write_byte(0x0000, &mem, 0xA0); // LDY immediate
write_byte(0x0001, &mem, 0x7F); // Y = 0x7F (positive value)

// Test 1: TAX - Transfer Accumulator to X
write_byte(0x0002, &mem, 0xAA); // TAX
// Should transfer 0x99 from A to X, set negative flag

// Test 2: TAY - Transfer Accumulator to Y  
write_byte(0x0003, &mem, 0xA8); // TAY
// Should transfer 0x99 from A to Y, set negative flag

// Test 3: TXA - Transfer X to Accumulator
write_byte(0x0004, &mem, 0x8A); // TXA
// Should transfer 0x99 from X to A, set negative flag

// Test 4: TYA - Transfer Y to Accumulator
write_byte(0x0005, &mem, 0x98); // TYA
// Should transfer 0x99 from Y to A, set negative flag

// Test 5: TSX - Transfer Stack Pointer to X
write_byte(0x0006, &mem, 0xBA); // TSX
// Should transfer SP (0xFD) to X, set negative flag

// Test 6: TXS - Transfer X to Stack Pointer
write_byte(0x0007, &mem, 0x9A); // TXS
// Should transfer X (0xFD) to SP

// Test zero flag by loading 0 into accumulator, then transferring
write_byte(0x0008, &mem, 0xA9); // LDA immediate
write_byte(0x0009, &mem, 0x00); // A = 0x00

write_byte(0x000A, &mem, 0xAA); // TAX - should set zero flag
write_byte(0x000B, &mem, 0xA8); // TAY - should set zero flag

// End test with BRK
write_byte(0x000C, &mem, 0x00); // BRK

// Expected Results After Execution:
// Final state: A=0x00, X=0x00, Y=0x00, SP=0xFD
// Zero flag should be set, Negative flag should be clear