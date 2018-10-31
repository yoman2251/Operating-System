.PHONY: clean dirs

BIN = bin
SRC = src

all: dirs $(BIN)/hw2_1.o

$(BIN)/hw2_1.o: $(SRC)/main.c
	gcc $(SRC)/main.c -lpthread -o $(BIN)/hw2_1

dirs:
	mkdir -p $(SRC) $(BIN)

clean:
	rm -rf $(BIN)
