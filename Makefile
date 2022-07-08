CC=gcc
CFLAGS=-std=gnu17 -ggdb -Wall

SRC=$(wildcard src/*.c)
OBJS=$(addprefix obj/, $(SRC:.c=.o))

all:
	mkdir -p obj/src
	$(MAKE) target

target: $(OBJS)
	$(CC) $(CFLAGS) $^

obj/src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	-rm -rf obj/src a.out

