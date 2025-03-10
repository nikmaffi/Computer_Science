CC=gcc
DB=gdb

CFLAGS=-Wall -Wextra -Iinclude
DEBUG_FLAGS=-g$(DB) -DDEBUG -fsanitize=address
RELEASE_FLAGS=-O2 -s -DNDEBUG

SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin
INCLUDE_DIR=include

SRCS=$(wildcard $(SRC_DIR)/*.c)
OBJS=$(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

BIN=$(BIN_DIR)/quick_sort

all: debug

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

debug: CFLAGS+=$(DEBUG_FLAGS)
debug: $(BIN)

release: CFLAGS+=$(RELEASE_FLAGS)
release: clean
release: $(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJ_DIR)/* $(BIN_DIR)/*
