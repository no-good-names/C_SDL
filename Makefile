# File name
OBJS = main.c

# Compiler
CC = g++

# Include path
INCLUDE_PATHS = -I/workspaces/C_SDL/scr/include/SDL2

# Lib path
LIBRARY_PATHS = -L/workspaces/C_SDL/scr/lib

COMPILER_FLAGS = -w

# Linkers flags
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

# Exectuable name
OBJ_NAME = SDL

all : $(OBJS)
		$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)