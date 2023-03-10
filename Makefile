# File
OBJS = main.cpp

# Compiler location
CC = g++

# Change SDL2 path if not in C:\SDL2
# Include path
INCLUDE_PATHS = -IC:\SDL2\include\SDL2

# Lib path
LIBRARY_PATHS = -LC:\SDL2\lib

COMPILER_FLAGS = -w -Wl,-subsystem,windows

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2

OBJ_NAME = SDL

all : $(OBJS)
		$(CC) $(OBJS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)