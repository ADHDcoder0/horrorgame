#include <stdio.h>
#include <unistd.h>
#include<vector>
#include<string>

bool Top[4]={true,true,true,true};

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
    bool isMovable = false;
};

struct TaskItem{
    float x,y;
    std::string name;//we need to expand this further 
};

Tile Floor;
Tile Wall;
Tile Empty;

class Room {
    public:
        int id;
        int Xsize,Ysize;
        
        std::vector<std::vector<Tile*>> tiles{17, std::vector<Tile*>(17, nullptr)};
        std::vector<TaskItem> items;

        //constructor
        Room(int Xsize , int Ysize , bool LeftGate, bool RightGate , bool TopGate , bool BottomGate);//Xsize and Ysize <= 17 blocks 
};


Room::Room(int Xsize , int Ysize , bool LeftGate, bool RightGate , bool TopGate , bool BottomGate){

    //Defining Floor 
    
    Floor.type=TileType::Floor;
    Floor.isMovable=true;

    //Defining Walls
    
    Wall.type=TileType::Wall;
    Wall.isMovable = false;

    //Defining Empty
    Empty.type=TileType::Wall;
    Empty.isMovable=false;
    Empty.visible=false;
    
    //Filling Room with empty
    for(int i=0;i<17;i++){
        for(int j=0;j<17;j++){
            tiles[i][j] = &Empty;
        }
    }
    
    int startRow = (17 - Ysize) / 2;
    int startCol = (17 - Xsize) / 2;
    int endRow = startRow + Ysize - 1;
    int endCol = startCol + Xsize - 1;
    int mid=8;

    //Adding Gates
    if(LeftGate){
        for(int i=0;i<mid;i++){
            tiles[7 ][i]= &Floor;
            tiles[8 ][i]= &Floor;
            tiles[9 ][i]= &Floor;
            tiles[6 ][i]= &Wall ;
            tiles[10][i]= &Wall ;
        }   
    }
    if(RightGate){
        for(int i=mid;i<17;i++){
            tiles[7 ][i]= &Floor;
            tiles[8 ][i]= &Floor;
            tiles[9 ][i]= &Floor;
            tiles[6 ][i]= &Wall ;
            tiles[10][i]= &Wall ;
        }
    }
    if(BottomGate){
        for(int i=mid;i<17;i++){
            tiles[i][7 ]= &Floor;
            tiles[i][8 ]= &Floor;
            tiles[i][9 ]= &Floor;
            tiles[i][6 ]= &Wall ;
            tiles[i][10]= &Wall ;
        }
    }
    if(TopGate){
        for(int i=0;i<mid;i++){
            tiles[i][7 ]= &Floor;
            tiles[i][8 ]= &Floor;
            tiles[i][9 ]= &Floor;
            tiles[i][6 ]= &Wall ;
            tiles[i][10]= &Wall ;
        }
    }

    //Room Generator
    for(int i = startRow; i <= endRow; i++) {
        for(int j = startCol; j <= endCol; j++) {
            if(i == startRow || i == endRow || j == startCol || j == endCol) {
                tiles[i][j] = &Wall;
            } else {
                tiles[i][j] = &Floor;
            }
        }
    }

    if(LeftGate){
        tiles[7 ][startCol]= &Floor;
        tiles[8 ][startCol]= &Floor;
        tiles[9 ][startCol]= &Floor;
    }
    if(RightGate){
        tiles[7 ][endCol]= &Floor;
        tiles[8 ][endCol]= &Floor;
        tiles[9 ][endCol]= &Floor;
    }
    if(BottomGate){
        tiles[endRow][7 ]= &Floor;
        tiles[endRow][8 ]= &Floor;
        tiles[endRow][9 ]= &Floor;
    }
    if(TopGate){
        tiles[startRow][7 ]= &Floor;
        tiles[startRow][8 ]= &Floor;
        tiles[startRow][9 ]= &Floor;
    }
}

// int main(){
//     for(int m=10;m<16;m++){
//         for(int i=13;i<18;i++){
//             for(int j=13;j<18;j++){
//                 Room room(i,j,m&1,m&2,m&4,m&8);
//                 for(int I=0;I<17;I++){
//                     for(int J=0;J<17;J++){
//                        if(room.tiles[I][J]== (&room.Wall)){
//                             printf("\033[48;2;100;255;0m  ");
//                        }
//                        if(room.tiles[I][J]== (&room.Floor)){
//                             printf("\033[48;2;0;255;255m  ");
//                        } 
//                        if(room.tiles[I][J]== (&room.Empty)){
//                             printf("\033[48;2;50;50;50m  ");
//                        }
//                     }
//                     printf("\033[48;2;0;0;0m\n");
//                 }
//                 usleep(10000);
//                 printf("\033[2J\033[H");
//             }
//         }
//     }

    
//     return 0;
// }
