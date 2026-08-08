# Project settings
TARGET = build/game.exe
SRC    = $(shell find src -name "*.cpp")

# Compiler settings
GXX    = C:/raylib/w64devkit/bin/g++
FLAGS  = -std=c++17 -g -fdiagnostics-color=always
INCLUDE= -I C:/raylib/raylib/src -Isrc
LIBS = -lraylib -lopengl32 -lgdi32 -lwinmm

# Default build
all: $(TARGET)

$(TARGET): $(SRC)
	$(GXX) $(FLAGS) $(SRC) -o $(TARGET) $(INCLUDE) $(LIBS)

# Clean build output
clean:
	del build\game.exe
