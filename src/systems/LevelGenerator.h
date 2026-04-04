
#include <vector>
#include <stack>
#include <random>
#include <iostream>
#include "../world/Room.h"

class Cor{  
    public:
    int x;
    int y;
};

class IntersectionDirection{
    public:
    bool up;
    bool down;
    bool left;      
    bool right;

    IntersectionDirection(){
        up=false;
        down=false;
        left=false; 
        right=false;
    };
};

class DFS{
    public:
    int Xsize , Ysize;
    std::vector <std::vector<IntersectionDirection>> world;
    DFS(int xSize = 4, int ySize = 4 );
    void Generate();
};

class Level{
    public:
     int Xsize,Ysize;
    //ACTUAL WORLD DATA 
    std::vector<std::vector<Room *>> Map;

    Level(int x=5,int y=5);

    auto GetTilePtr(int RoomX , int RoomY ,int TileX , int TileY);
   
    ~Level();
};