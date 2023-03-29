all : main

# File name
SCR = main.c

# Compiler
CC = g++

# Compiler flags
CFLAGS = -w

# Linker flags
LFLAGS = -lSDL2

# Executable name
SCR_NAME = SDL

main : $(OBJS)
		$(CC) $(SCR) $(CFLAGS) $(LFLAGS) -o $(SCR_NAME)
clean :
		rm -f $(EXE)
