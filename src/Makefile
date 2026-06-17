
# code details

EXE_DIR = .
EXE = game

SRC= main.c GameOfLife.c Show.c Check.c GameUi.c

# generic build details

CC =     gcc
CFLAGS = -Wall -O
CFLAGS += -fcommon
LIBS =   -lSDL3
# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< 

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) -o $(EXE) $(LIBS)

# clean up compilation

ifeq ($(OS),Windows_NT)
CLEANUP = del /F /Q
else
CLEANUP = rm -f
endif

clean:
	-$(CLEANUP) $(OBJ) $(EXE)

# dependencies

main.o:  main.c DataStructure.h NextGenre.h GameWindow.h
GameOfLife.o:  GameOfLife.c DataStructure.h NextGenre.h GameWindow.h
Shwo.o: Show.c DataStructure.h GameWindow.h
Check.o: Check.c Check.h DataStructure.h