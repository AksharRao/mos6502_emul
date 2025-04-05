CFLAGS = -std=c17 -Wall -Wextra -Werror
CC = clang
TARGET = m6502
SRC = m6502.c

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
