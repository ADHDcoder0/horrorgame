#pragma once
#include <vector>
#include <memory>

#include "systems/LevelGenerator.h"
#include "entities/Player.h"

enum class GameState {
    Playing,
    FinalEscape,
    GameOver,
    Win
};

class Zombie;
class Room;
class RampageController;
class TaskManager;


class GameManager{

   

    public: 
    GameState state = GameState::Playing;
    int currentLevel = 0;

    std::unique_ptr<Player> player;
    std::unique_ptr<Zombie> zombie;
    std::unique_ptr<Level> level;
    std::unique_ptr<RampageController> rampageCtrl;
    std::unique_ptr<TaskManager> taskManager; 




    GameManager();// constructor

    void LoadLevel(int level);

    void Update(float dt);

    void Draw();

    void TriggerFinalRampage();

    void ResetRun();

    void DrawUI();

    void CreateRooms();

    void CheckCollision();



};