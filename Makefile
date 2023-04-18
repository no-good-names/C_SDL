all : main

# File name
OBJS = main.cpp

# Compiler
CC = g++

# Compiler flags
CFLAGS = -w

# Linker flags
LFLAGS = -lSDL2

OBJ_NAME = build/SDL

main : $(OBJS)
	mkdir -p build
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJ_NAME)

clean :
	rm -f $(OBJ_NAME)

run :
	./build/SDL
