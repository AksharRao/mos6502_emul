# Detect OS
OS := $(shell uname)
# For Linux
ifeq ($(OS), Linux)
    CC = gcc
endif
# For macOS
ifeq ($(OS), Darwin)
    CC = clang
endif
CFLAGS = -std=c17 -Wall -Wextra -Werror
TARGET = build/m6502
SRC = src/main.c src/cpu.c src/memory.c src/instruction.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -I. -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f ./$(TARGET)

debug: 
	$(CC) $(CFLAGS) -g $(SRC) -I. -o $(TARGET) -DDEBUG_MEMORY
