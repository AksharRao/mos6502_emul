// LDA $42h
write_byte(0xFFFC, &mem, 0xA9); // LDA immediate
write_byte(0xFFFD, &mem, 0x42); // Value 0x42

write_byte(0xFFFE, &mem, 0xA5); // LDA zeropage
write_byte(0xFFFF, &mem, 0x42); // Zeropage address
write_byte(0x0042, &mem, 0x69); // Data at zero page 0x42

write_byte(0x0000, &mem, 0xB5); // LDA zeropage, x
write_byte(0x0001, &mem, 0x40); // zero page address
write_byte(0x05, &mem, 0x99); // value at zeropage + indX

write_byte(0x0002, &mem, 0xAD); // LDA absolute 
write_byte(0x0003, &mem, 0x34); // low byte
write_byte(0x0004, &mem, 0x12); // high byte
write_byte(0x1234, &mem, 0x88); // value at 0x1234

write_byte(0x0005, &mem, 0xBD); // LDA absolute, X 
write_byte(0x0006, &mem, 0x78); // low byte
write_byte(0x0007, &mem, 0x56); // high byte
write_byte(0x567D, &mem, 0x89); // value at absolute + indX

write_byte(0x0008, &mem, 0xA1); // LDA (indirect, X)
write_byte(0x0009, &mem, 0x20); // zero page base address
write_byte(0x0025, &mem, 0x00); // low byte zero page + indX
write_byte(0x0026, &mem, 0x80); // high byte
write_byte(0x8000, &mem, 0xAA); // value at 0x8000

write_byte(0x000A, &mem, 0xB1); // LDA (indirect), Y
write_byte(0x000B, &mem, 0x30); // zero page address
write_byte(0x0030, &mem, 0x00); // low byte of zero page address
write_byte(0x0031, &mem, 0x20); // high byte of zero page address
write_byte(0x2003, &mem, 0xBB); // value at 0x2003, value at zero page + indY