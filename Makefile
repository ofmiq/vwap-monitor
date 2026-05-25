CC     = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -fsanitize=address,leak,undefined

SIM_DIR = simulator
SIM_SRC = $(SIM_DIR)/main.c $(SIM_DIR)/args.c $(SIM_DIR)/generator.c
SIM_OBJ = bin/main.o bin/args.o bin/generator.o

all: bin/simulator

bin/simulator: $(SIM_OBJ) | bin
	$(CC) $(CFLAGS) -o bin/simulator $(SIM_OBJ)

bin/%.o: $(SIM_DIR)/%.c | bin
	$(CC) $(CFLAGS) -c $< -o $@

bin:
	mkdir -p bin

clean:
	rm -rf bin