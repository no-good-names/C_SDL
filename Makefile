all : main

# File name
OBJS = src/main.c

# Compiler
CC = g++

# Compiler flags
CFLAGS = -w

# Linker flags
LFLAGS = -lSDL2

# Executable name
OBJ_NAME = build/SDL

main : $(OBJS)
	mkdir -p build
	$(CC) $(OBJS) $(CFLAGS) $(LFLAGS) -o $(OBJ_NAME)

clean :
	rm -f $(OBJ_NAME)

run :
	./${OBJ_NAME}