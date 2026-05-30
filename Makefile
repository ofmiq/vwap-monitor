CC     = gcc
CFLAGS = -Wall -Wextra -Wpedantic -Werror -fsanitize=address,leak,undefined

SIM_DIR = simulator
SIM_SRC = $(SIM_DIR)/main.c $(SIM_DIR)/args.c $(SIM_DIR)/generator.c
SIM_OBJ = bin/sim_main.o bin/sim_args.o bin/sim_generator.o

MON_DIR = monitor
MON_SRC = $(MON_DIR)/main.c $(MON_DIR)/args.c
MON_OBJ = bin/mon_main.o bin/mon_args.o

all: bin/simulator bin/monitor

bin/simulator: $(SIM_OBJ) | bin
	$(CC) $(CFLAGS) -o bin/simulator $(SIM_OBJ)

bin/monitor: $(MON_OBJ) | bin
	$(CC) $(CFLAGS) -o bin/monitor $(MON_OBJ)

bin/sim_%.o: $(SIM_DIR)/%.c | bin
	$(CC) $(CFLAGS) -c $< -o $@

bin/mon_%.o: $(MON_DIR)/%.c | bin
	$(CC) $(CFLAGS) -c $< -o $@

bin:
	mkdir -p bin

clean:
	rm -rf bin