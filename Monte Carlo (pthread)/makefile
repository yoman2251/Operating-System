.PHONY: clean dirs

BIN = bin
SRC = src

all: dirs $(BIN)/pthread

$(BIN)/pthread: $(SRC)/main.c
	gcc $(SRC)/main.c -lpthread -o $(BIN)/pthread

dirs:
	mkdir -p $(SRC) $(BIN)

clean:
	rm -rf $(BIN)
