write_byte(0xFFFC, &mem, 0xA9); // LDA immediate
write_byte(0xFFFD, &mem, 0x41); // Value 0x42

write_byte(0xFFFE, &mem, 0x85); //STA zeropage
write_byte(0xFFFF, &mem, 0x42); // Zeropage address