CC = gcc
CFLAGS = -Os
# on macos use -dead_strip (or man ld and find out)
CSMALLFLAGS = -Wl,--gc-sections -fdata-sections -ffunction-sections -eentry -nostartfiles -static
BIN = bin
SRC = src
TESTS = tests

base:
	$(CC) $(SRC)/base.c -o $(bin)/base

base_os:
	$(CC) $(CFLAGS) $(SRC)/base.c -o $(bin)/base_os

small:
	$(CC) $(CFLAGS) $(CSMALLFLAGS) $(SRC)/small.c -o $(bin)/small

all: base base_os small

clean:
	rm -rf $(BIN)/*