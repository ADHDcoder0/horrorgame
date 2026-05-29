// int main() {
//     InitWindow(800, 600, "Horror Roguelike");
//     SetTargetFPS(60);

//     while (!WindowShouldClose()) {
//         BeginDrawing();
//             ClearBackground(BLACK);
//             DrawText("Setup Working!", 300, 280, 30, GREEN);
//         EndDrawing();
//     }

//     CloseWindow();
//     return 0;
// }


#include "raylib.h"
#include "raymath.h"
#include "systems/LevelGenerator.h"



int main(){
  
    InitWindow(1920,1080,"Movement");
    SetExitKey(KEY_ESCAPE);
    
    Vector2 ShipPos;
    ShipPos.x = 0 ;
    ShipPos.y = 0 ; 
    Vector2 ShipDirection;
    ShipDirection.x=1;
    ShipDirection.y=1;
    int ShipSpeed = 600;
    Level level;


    Camera2D camera = Camera2D();
    camera.zoom = 1;
    camera.target = ShipPos;
    camera.offset = Vector2{1920/2,1080/2};
    
    while(!WindowShouldClose()){
        //updates

        ShipDirection.x = (int)(IsKeyDown(KEY_RIGHT)) - (int)(IsKeyDown(KEY_LEFT));
        ShipDirection.y = (int)(IsKeyDown(KEY_DOWN)) - (int)(IsKeyDown(KEY_UP));
        float dt=GetFrameTime();
        ShipDirection = Vector2Normalize(ShipDirection);
        ShipPos.x += ShipSpeed*ShipDirection.x*dt;
        ShipPos.y += ShipSpeed*ShipDirection.y*dt;
        camera.target = ShipPos;
        
        BeginDrawing();
        BeginMode2D(camera);
        ClearBackground(BLACK);
        level.RenderLevel(ShipPos,3);
        DrawCircleV(ShipPos,20,WHITE);
        EndMode2D();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}