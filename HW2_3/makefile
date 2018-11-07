.PHONY: clean dirs

BIN = bin
SRC = src

all: dirs $(BIN)/mutex

$(BIN)/mutex: $(SRC)/main.c
	gcc $(SRC)/main.c -lpthread -o $(BIN)/mutex

dirs:
	mkdir -p $(SRC) $(BIN)

clean:
	rm -rf $(BIN)