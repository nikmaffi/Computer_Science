APP=test.exe

CC=gcc

INCLUDE=-I.
RELEASE=-O2
DEBUG=-ggdb -Wall -Wextra

MAIN=main.c
OBJS=merge_sort.o

all: $(APP)

%.o: %.c %.h
	$(CC) $(RELEASE) $(INCLUDE) -c $<

$(APP): $(MAIN) $(OBJS)
	$(CC) $(RELEASE) $(INCLUDE) -o $@ $^

debug:
	$(CC) $(DEBUG) $(INCLUDE) -o $(APP) *.c

clean:
	rm $(APP) *.o