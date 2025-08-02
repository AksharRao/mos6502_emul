# MOS 6502 CPU Emulator

A C implementation of the MOS 6502 microprocessor emulator, featuring instruction execution, memory management, and CPU state tracking.

## Overview

This project emulates the classic MOS 6502 8-bit microprocessor that was used in many famous computers including the Apple II, Commodore 64, and Nintendo Entertainment System (NES). The emulator implements the core CPU functionality including registers, memory addressing modes, and instruction execution.

## Project Structure

```
mos6502_emul/
├── include/
│   ├── cpu.h           # CPU structure and function declarations
│   ├── instruction.h   # Instruction table and execution functions
│   ├── memory.h        # Memory management functions
│   └── types.h         # Type definitions
├── src/
│   ├── main.c          # Main program and test setup
│   ├── cpu.c           # CPU implementation
│   ├── instruction.c   # Instruction implementations
│   └── memory.c        # Memory operations
├── output_log/
│   └── lda_instructions.txt  # execution output
└── Makefile           # Build configuration
```

## Features

### CPU Implementation
- **Registers**: Accumulator (A), Index registers (X, Y), Stack Pointer (SP), Program Counter (PC)
- **Status Flags**: Negative, Zero, Carry, Overflow, Break, Decimal, IRQ, Unused
- **Memory**: 64KB addressable memory space
- **Cycle-accurate execution**: Instructions consume appropriate CPU cycles
- Currently implementations for LDA instructions of all addressing modes are available.

## Building and Running

### Prerequisites
- GCC (Linux) or Clang (macOS)
- Make

### Build Commands

```bash
# Standard build
make

# Run the emulator
make run

# Debug build with memory visualization
make debug

# Clean build artifacts
make clean
```

## CPU State Output

The emulator provides detailed output showing:
- CPU register values (A, X, Y, SP, PC)
- Status flag states
- Instruction execution details
- Memory access information

## Future Enhancements

The emulator can be extended to include:
- Additional instruction sets (STA, LDX, LDY, arithmetic operations)
- Interrupt handling
- Assembler integration

## Verilog

Hardware implementation of the same can be found [here](https://github.com/AksharRao/mos6502-verilog).