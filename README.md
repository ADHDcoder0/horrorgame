# Horror Roguelike - Top Down Survival

## First Time Setup

### 1. Install Raylib
Download and install raylib from https://github.com/raysan5/raylib/releases
Install it at `C:/raylib/` 

### 2. Create your config.mk
In the root of the project, create a file called `config.mk`:
```
RAYLIB_INCLUDE = C:/raylib/raylib/include
RAYLIB_LIB     = C:/raylib/raylib/lib
GXX            = C:/raylib/w64devkit/bin/g++.exe
```
If your raylib is installed somewhere else, update these paths accordingly or move you raylib.

### 3. Create build folder
```
mkdir build
```

### 4. Open in VS Code
Open the `horrorGame` folder in VS Code.

### 5. Build
Press `Ctrl+Shift+B` to build.
Output will be at `build/game.exe`.

### 6. Run / Debug
Press `F5` to build and debug.

---

## If your raylib is NOT at C:/raylib/
Update these two files with your own paths:
- `.vscode/tasks.json` → change `executable` path
- `.vscode/launch.json` → change `miDebuggerPath`

---

## Project Structure
```
src/
  main.cpp              ← Entry point
  GameObject.h          ← Base class
  GameManager.h/.cpp    ← Core game loop

  entities/
    Player.h/.cpp
    Zombie.h/.cpp

  systems/
    RampageController.h/.cpp
    TaskManager.h/.cpp

  world/
    Room.h/.cpp

build/                  ← Compiled output (gitignored)
config.mk               ← Your local raylib paths (gitignored)
Makefile                ← Build system
```

## Controls
- `WASD` — Move
- `E` — Interact / Pick up
- `H` — Hide
- `Tab` — Inventory