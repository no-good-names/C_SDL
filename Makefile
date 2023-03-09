# Compiler
CC = g++

# file
OBJS = main.c

# Executable name
EX_NAME = SDL2

all : $(OBJS)
	CC $(OBJS) -I${HOME}SDL2\scr\include\SDL2 -L${HOME}\SDL2\scr\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o $(EX_NAME)
