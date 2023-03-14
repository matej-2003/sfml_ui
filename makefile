CC=g++
CFLAGS=g++
SFML=SFML
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
SRC=./src
LIB=./lib
BUILD=./build

export LD_LIBRARY_PATH=$(SFML)/lib

run: all
	$(BUILD)/main

all: $(BUILD)/main

$(BUILD)/main: $(LIB)/main.o $(LIB)/Button.o $(LIB)/Component.o
	$(CC) $^ -o $@ -L $(SFML)/lib $(SFML_FLAGS)

$(LIB)/%.o: $(SRC)/%.cpp
	$(CC) -c $< -o $@ -I $(SFML)/include

clean:
	rm -v $(LIB)/* $(BUILD)/*