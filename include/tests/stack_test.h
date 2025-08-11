// Stack Instructions Test Program

// Setup: Load test values
write_byte(0xFFFC, &mem, 0xA9); // LDA immediate
write_byte(0xFFFD, &mem, 0x42); // A = 0x42

write_byte(0xFFFE, &mem, 0xA2); // LDX immediate
write_byte(0xFFFF, &mem, 0x88); // X = 0x88

// Test 1: PHA - Push Accumulator
write_byte(0x0000, &mem, 0x48); // PHA
// Should push 0x42 to stack at 0x01FD, SP becomes 0xFC

// Test 2: PHP - Push Processor Status
write_byte(0x0001, &mem, 0x08); // PHP
// Should push status register to stack at 0x01FC, SP becomes 0xFB

// Test 3: Change accumulator, then PLA
write_byte(0x0002, &mem, 0xA9); // LDA immediate
write_byte(0x0003, &mem, 0x99); // A = 0x99

write_byte(0x0004, &mem, 0x68); // PLA - Pull Accumulator
// Should pull status register (not 0x42) from 0x01FC, SP becomes 0xFC

// Test 4: PLA again to get original accumulator value
write_byte(0x0005, &mem, 0x68); // PLA
// Should pull 0x42 from 0x01FD, SP becomes 0xFD

// Test 5: Push status, modify flags, then PLP
write_byte(0x0006, &mem, 0x08); // PHP - push current status

write_byte(0x0007, &mem, 0xA9); // LDA immediate
write_byte(0x0008, &mem, 0x00); // A = 0x00 (sets zero flag)

write_byte(0x0009, &mem, 0x28); // PLP - Pull Processor Status
// Should restore previous status flags

// End test with BRK
write_byte(0x000A, &mem, 0x00); // BRK