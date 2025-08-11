// LDX Test Program - Tests all LDX addressing modes

// Test 1: LDX #oper - immediate
write_byte(0xFFFC, &mem, 0xA2); // LDX immediate
write_byte(0xFFFD, &mem, 0x42); // Value 0x42

// Test 2: LDX oper - zero page
write_byte(0xFFFE, &mem, 0xA6); // LDX zero page
write_byte(0xFFFF, &mem, 0x80); // Zero page address 0x80
write_byte(0x0080, &mem, 0x69); // Data at zero page 0x80

// Test 3: LDX oper,Y - zero page indexed with Y (set Y first)
write_byte(0x0000, &mem, 0xA0); // LDY immediate - set up Y register
write_byte(0x0001, &mem, 0x05); // Y = 0x05

write_byte(0x0002, &mem, 0xB6); // LDX zero page,Y
write_byte(0x0003, &mem, 0x40); // Zero page base address 0x40
write_byte(0x0045, &mem, 0x99); // Value at zero page 0x40 + 0x05 = 0x45

// Test 4: LDX oper - absolute
write_byte(0x0004, &mem, 0xAE); // LDX absolute
write_byte(0x0005, &mem, 0x34); // Low byte of address 0x1234
write_byte(0x0006, &mem, 0x12); // High byte of address 0x1234
write_byte(0x1234, &mem, 0x88); // Value at absolute address 0x1234

// Test 5: LDX oper,Y - absolute indexed with Y (Y still = 0x05)
write_byte(0x0007, &mem, 0xBE); // LDX absolute,Y
write_byte(0x0008, &mem, 0x78); // Low byte of base address 0x5678
write_byte(0x0009, &mem, 0x56); // High byte of base address 0x5678
write_byte(0x567D, &mem, 0xAA); // Value at 0x5678 + 0x05 = 0x567D

// Expected Results After Execution:
// cpu->indX = 0x42  (LDX immediate)
// cpu->indX = 0x69  (LDX zero page)
// cpu->indX = 0x99  (LDX zero page,Y with Y=0x05)
// cpu->indX = 0x88  (LDX absolute)
// cpu->indX = 0xAA  (LDX absolute,Y with Y=0x05)