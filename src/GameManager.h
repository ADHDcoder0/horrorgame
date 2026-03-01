#pragma once
#include <vector>
#include <memory>

enum class GameState {
    Playing,
    FinalEscape,
    GameOver,
    Win
};

class Player;
class Zombie;
class Room;
class RampageController;
class TaskManager;

class GameManager{

    // ! encapsulation is pending evrything public loko into it kushagra 



    public: 
    GameState state = GameState::Playing;
    int currentLevel = 0;

    std::unique_ptr<Player> player;
    std::unique_ptr<Zombie> zombie;
    std::vector<std::unique_ptr<Room>> rooms;


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