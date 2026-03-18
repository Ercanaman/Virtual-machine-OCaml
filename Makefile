CC = gcc -Wall -std=c99 

HEADERS = headers
SRC = src
OBJ = obj
BIN = bin
TESTS = tests

all: $(BIN)/vm_ocaml

$(OBJ)/%.o: $(SRC)/%.c $(HEADERS)/%.h $(SRC)/stack.c $(HEADERS)/stack.h
	$(CC) -c $< -o $@

$(BIN)/vm_ocaml: $(OBJ)/stack.o $(OBJ)/base.o $(OBJ)/branchs.o $(OBJ)/ints.o $(OBJ)/prims.o $(OBJ)/mem.o $(OBJ)/blocks.o $(OBJ)/atoms.o $(SRC)/main.c
	$(CC) -o $@ $^

test_base: $(BIN)/vm_ocaml
	$< $(TESTS)/base.sobf --print-end-machine
	$< $(TESTS)/branchs.sobf --print-end-machine
	$< $(TESTS)/ints.sobf --print-end-machine
	$< $(TESTS)/blocks.sobf --print-end-machine

prims: $(BIN)/vm_ocaml $(TESTS)/prims.sobf
	$^

fact: $(BIN)/vm_ocaml $(TESTS)/fact.sobf
	$^

pinetree: $(BIN)/vm_ocaml $(TESTS)/pinetree.sobf
	$^

wumpus: $(BIN)/vm_ocaml $(TESTS)/wumpus.sobf
	$^

clean:
	rm $(OBJ)/*.o
	rm $(BIN)/vm_ocaml
