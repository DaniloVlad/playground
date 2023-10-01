CC = gcc
CFLAGS =
OBJ = obj
BIN = bin
SRC = src
TESTS = tests

SOURCES = $(wildcard $(SRC)/*.c)
OBJECTS = $(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SOURCES))
BINARIES = $(patsubst $(SRC)/%.c, $(BIN)/%, $(SOURCES))

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN)/%: $(SRC)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(OBJECTS) $(BINARIES)

clean:
	rm -rf $(OBJ)/* $(BIN)/*