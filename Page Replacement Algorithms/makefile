.PHONY: clean dirs

BIN = bin
SRC = src

all: dirs $(BIN)/paging.o

$(BIN)/paging.o: $(SRC)/main.c
	gcc $(SRC)/main.c -o $(BIN)/paging.o

dirs:
	mkdir -p $(SRC) $(BIN)

clean:
	rm -rf $(BIN)
