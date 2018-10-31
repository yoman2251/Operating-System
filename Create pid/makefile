.PHONY: clean dirs

BIN = bin
SRC = src

all: dirs $(BIN)/hw1_2.o

$(BIN)/hw1_2.o: $(SRC)/main.c
	gcc $(SRC)/main.c -o $(BIN)/hw1_2.o

dirs:
	mkdir -p $(SRC) $(BIN)

clean:
	rm -rf $(BIN)
