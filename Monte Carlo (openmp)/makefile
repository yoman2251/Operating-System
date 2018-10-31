.PHONY: clean dirs

BIN = bin
SRC = src

all: dirs $(BIN)/openmp

$(BIN)/openmp: $(SRC)/main.c
	gcc $(SRC)/main.c -lpthread -o $(BIN)/openmp

dirs:
	mkdir -p $(SRC) $(BIN)

clean:
	rm -rf $(BIN)