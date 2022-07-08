CC=gcc
CFLAGS=-std=gnu17 -ggdb -Wall
LIBS=-lm -lncursesw

SRC=$(wildcard src/*.c)
OBJS=$(addprefix obj/, $(SRC:.c=.o))

all:
	mkdir -p obj/src
	$(MAKE) target

target: $(OBJS)
	$(CC) $(CFLAGS) $^ $(LIBS)

obj/src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(LIBS)

clean:
	-rm -rf obj/src a.out

