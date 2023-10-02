CC = gcc
CFLAGS = -Os
# on macos use -dead_strip (or man ld and find out)
CSMALLENTRYFLAGS = -eentry -nostartfiles
CSTATICFLAGS = -Wl,--gc-sections -fdata-sections -ffunction-sections -static
BIN = bin
SRC = src
TESTS = tests

all: base base_os base_static small

base:
	$(CC) $(SRC)/base.c -o $(BIN)/base

base_os:
	$(CC) $(CFLAGS) $(SRC)/base.c -o $(BIN)/base_static

base_static:
	$(CC) $(CFLAGS) $(CSTATICFLAGS) $(SRC)/base.c -o $(BIN)/base_os

small:
	$(CC) $(CFLAGS) $(CSMALLFLAGS) $(CSMALLENTRYFLAGS) $(SRC)/small.c -o $(BIN)/small

clean:
	rm -rf $(BIN)/*