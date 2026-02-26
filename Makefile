include config.mk

TARGET = build/game.exe
SRC  = $(shell find src -name "*.cpp")

FLAGS   = -std=c++17 -g -fdiagnostics-color=always
INCLUDE = -I$(RAYLIB_INCLUDE) -Isrc
LIBS    = -L$(RAYLIB_LIB) -lraylib -lopengl32 -lgdi32 -lwinmm

all: $(TARGET)

$(TARGET): $(SRC)
	$(GXX) $(FLAGS) $(SRC) -o $(TARGET) $(INCLUDE) $(LIBS)

clean:
	del build\game.exe