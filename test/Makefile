#We try to detect the OS we are running on, and adjust commands as needed
ifeq ($(OS),Windows_NT)
	CLEANUP = del /F /Q
	MKDIR = mkdir
	TARGET_EXTENSION=.exe
else
	CLEANUP = rm -f
	MKDIR = mkdir -p
	TARGET_EXTENSION=.out
endif

C_COMPILER=gcc
ifneq ($(OS),Windows_NT)
ifeq ($(shell uname -s),Darwin)
C_COMPILER=clang
endif
endif

UNITY_ROOT=../unity
SRCs=../

CFLAGS = -Wall -O
CFLAGS += -fcommon

# Conditional SDL3 support
ifndef NO_SDL3
LIBS = -lSDL3
CFLAGS += -DSDL3_AVAILABLE
else
LIBS =
CFLAGS += -DNO_SDL3
endif

#CFLAGS += -Wno-misleading-indentation

all: default

default: $(SRC_FILES1) $(SRC_FILES2)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES1) -o $(TARGET1) $(LIBS)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES2) -o $(TARGET2) $(LIBS)
	$(C_COMPILER) $(CFLAGS) $(INC_DIRS) $(SYMBOLS) $(SRC_FILES3) -o $(TARGET3) $(LIBS)

run: default
	- ./$(TARGET1)
	- ./$(TARGET2)
	- ./$(TARGET3)

clean:
	-$(CLEANUP) $(TARGET1) $(TARGET2) $(TARGET3)


ci: default run
