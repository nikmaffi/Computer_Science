CC=gcc
DB=gdb
CFLAGS=-Wall -Wextra -ggdb -Iinclude

APP=bin/list.out
OBJS=obj/main.o obj/list.o

all: build run

release: CFLAGS=-O2 -Wall -Iinclude
release: clean
release: all

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -o $@ -c $^

build: $(OBJS)
	$(CC) $(CFLAGS) -o $(APP) $^

run:
	./$(APP)

clean:
	rm $(APP) $(OBJS)
