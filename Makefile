# File name
OBJS = main.c

# Compiler
CC = g++

### Dirs for codespace ###

# Include path
INCLUDE_PATHS = -IC:\SDL2\include\SDL2

# Lib path
LIBRARY_PATHS = -LC:\SDL2\lib

# C:\SDL2\include\SDL2
# C:\SDL2\lib

COMPILER_FLAGS = -w

# Windows:
# -Wl,-subsystem,windows: for no terminal
# using terminal for tests
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2_image -lSDL2

# linux:
# LINKER_FLAGS = -lSDL2

# Mac: Idk

# Exectuable name
OBJ_NAME = SDL

all : $(OBJS)
		$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
