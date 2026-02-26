#include "raylib.h"

int main() {
    InitWindow(800, 600, "Horror Roguelike");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Setup Working!", 300, 280, 30, GREEN);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}