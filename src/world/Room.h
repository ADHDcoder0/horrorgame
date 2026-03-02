#pragma once
#include "../GameObject.h"
#include<vector>
#include<string>

enum class TileType {
    Floor,
    Wall,
    Stair,
    Exit,
    HidingSpot,
    //Gas Zone and Fog Zone will be added 
}; 

struct Tile{  // a single tile 
    TileType type =TileType::Floor;
    bool visible = true;
};

struct TaskItem{
    float x,y;
    std::string name;//we need to expand this further 
};

class Room {
    public:
        int id;
        int gridX,gridY;
        int floor;
        int worldOffsetX;
        int worldOffsetY;
        float centerX,CentreY;

        std::vector<std::vector<Tile>> tiles;
        std::vector<TaskItem> items;

        //constructor
        Room(int id, int gridX, int gridY, int w, int h, int floor, int offsetX = 0, int offsetY = 0);

        void Update();
        void Draw(int tileSize);
        void Generate();  //-> for assigning floor and border 
        
        bool isWalkable(int tx,int ty) const; // -> return if you canwalk in the grid or not 

        Rectangle GetBounds(int tileSize) const;

  
        void GenerateItem(const std::string& itemName);  // gives the bound of room in  pixels

    };