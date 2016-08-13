PROGRAMM = hello

SOURCES.c = main.c fib.c
SOURCES.h = fib.h

SOURCES = \
		$(SOURCES.c) \
		$(SOURCES.h)

OBJECTS = \
		$(SOURCES.c:%.c%=%.o)

CC = gcc

CFLAGS = -O3 -Wall
LDLIBS = -lm

all:	$(PROGRAMM)

$(PROGRAMM): $(SOURCES.c) $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $(OBJECTS) $(LDLIBS)

clean:
	rm -rf $(PROGRAMM)

run:
	./hello