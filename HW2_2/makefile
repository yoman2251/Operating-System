.PHONY: clean dirs

BIN = bin
SRC = src

all: dirs $(BIN)/hw2_2

$(BIN)/hw2_2: $(SRC)/main.c
	gcc $(SRC)/main.c -lpthread -o $(BIN)/hw2_2

dirs:
	mkdir -p $(SRC) $(BIN)

clean:
	rm -rf $(BIN)