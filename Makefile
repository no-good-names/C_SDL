OBJS = main.c

#OBJ_NAME specifies the name of our exectuable
OBJ_NAME = SDL2

#This is the target that compiles our executable
all : $(OBJS)
	g++ $(OBJS) -I${HOME}SDL2\scr\include\SDL2 -L${HOME}\SDL2\scr\lib -w -Wl,-subsystem,windows -lmingw32 -lSDL2main -lSDL2 -o $(OBJ_NAME)
