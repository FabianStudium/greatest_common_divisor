# Makefile for gcd

# Compiler to use
CC = gcc

# Flags to pass compiler
CFLAGS = -Wall -std=c11

# Name for executable
EXE = gcd

# Space-separated list of source files
SOURCES = main.c ../../factor/factor/factor.c

# gcc -o gcd_program gcd.c factor.c -lm

# Automatically generated list of object files
OBJS = $(SOURCES:.c=.o)

# Default target
$(EXE): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXE) $(OBJS)

# Dependencies
main.o: main.c main.h
../../factor/factor/factor.o: ../../factor/factor/factor.c ../../factor/factor/factor.h

# Housekeeping
clean:
	rm -f core $(EXE) $(OBJS)
