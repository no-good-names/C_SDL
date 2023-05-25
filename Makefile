# File name
OBJS = src/main.c

# Compiler
CC = gcc

# Include path
INCLUDE_PATHS = -IC:\SDL2\include\SDL2

# Lib path
LIBRARY_PATHS = -LC:\SDL2\lib

COMPILER_FLAGS = -w

# Linkers flags
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

# Exectuable name
OBJ_NAME = sdl

all : $(OBJS)
		$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)