#include <stdio.h>
#include <vector>
#include <stack>
#include <random>
#include "RoomTester.cpp"
#include <iostream>
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
    DFS(int xSize = 4, int ySize = 4 ) {
        Xsize=xSize , Ysize=ySize;

        world.resize(Xsize);
        for(int i=0;i<Xsize;i++){
        world[i].resize(Ysize);
        }
    }
    void Generate();
};


 void DFS::Generate(){
    int loop=2;
    std::random_device rd;
    std::mt19937 gen(rd());

    std::vector<std::vector<bool>> visited(Xsize, std::vector<bool>(Ysize, false));
    std::stack<Cor> Temp;

    // Start at 0,0
    Cor current = {0, 0};
    visited[0][0] = true;
    Temp.push(current);

    while (!Temp.empty()) {
        current = Temp.top();
        std::vector<int> neighbors;

        // Check Up, Down, Left, Right for bounds and visited status
        if (current.x > 0 && !visited[current.x - 1][current.y])         neighbors.push_back(1); // Up
        if (current.x < Xsize - 1 && !visited[current.x + 1][current.y]) neighbors.push_back(2); // Down
        if (current.y > 0 && !visited[current.x][current.y - 1])         neighbors.push_back(3); // Left
        if (current.y < Ysize - 1 && !visited[current.x][current.y + 1]) neighbors.push_back(4); // Right
        
        if (!neighbors.empty()) {
            std::uniform_int_distribution<> dist(0, neighbors.size() - 1);
            int dir = neighbors[dist(gen)];

            Cor next = current;
            if (dir == 1) { // Move Up
                world[current.x][current.y].up = true;
                world[current.x - 1][current.y].down = true;
                next.x--;
            } else if (dir == 2) { // Move Down
                world[current.x][current.y].down = true;
                world[current.x + 1][current.y].up = true;
                next.x++;
            } else if (dir == 3) { // Move Left
                world[current.x][current.y].left = true;
                world[current.x][current.y - 1].right = true;
                next.y--;
            } else if (dir == 4) { // Move Right
                world[current.x][current.y].right = true;
                world[current.x][current.y + 1].left = true;
                next.y++;
            }

            visited[next.x][next.y] = true;
            Temp.push(next);
        } else {
            std::uniform_int_distribution<> dist(0, 4);
            if(loop!=0){
                int dir=dist(gen);

                if (dir == 1 && current.x!=0) { 
                    world[current.x][current.y].up = true;
                    world[current.x - 1][current.y].down = true;
                    loop--;
                } else if (dir ==  2 && current.x!= Xsize-1) { 
                    world[current.x][current.y].down = true;
                    world[current.x + 1][current.y].up = true;
                    loop--;
                } else if (dir == 3 && current.y!=0) { 
                    world[current.x][current.y].left = true;
                    world[current.x][current.y - 1].right = true;
                    loop--;
                } else if (dir == 4 && current.y!=Ysize-1) { 
                    world[current.x][current.y].right = true;
                    world[current.x][current.y + 1].left = true;
                    loop--;
                }

            }
            Temp.pop(); // Backtrack
        }
    }
    }
    



class Level{
    public:
    std::vector<std::vector<Room *>> Map;
    int Xsize,Ysize;
    Level(int x=5,int y=5){
        Xsize=x,Ysize=y;
        DFS dfs(x,y);
        dfs.Generate();

        Map.resize(Xsize);
        for(int i=0;i<Xsize;i++){
            Map[i].resize(Ysize);
        }

        for(int i=0;i<Xsize;i++){
            for(int j=0;j<Ysize;j++){
                std::random_device rd;
                std::mt19937 gen(rd());
                std::uniform_int_distribution<> dist(7,18);
                int M=dist(gen); if(M==18){M=5;}
                Map[i][j]=new Room(M,M,dfs.world[i][j].left,dfs.world[i][j].right,dfs.world[i][j].up,dfs.world[i][j].down);
            }
        }
    }
    ~Level(){
        for(int i=0;i<Xsize;i++){
            for(int j=0;j<Ysize;j++){
               delete Map[i][j];
            }
        }
    }
};


int main(){
    int x=3,y=3;
    Level world(x,y);
    printf("\033[2J");
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            int temp1=1,temp2=1;
            if(i!=0){temp1=(i*17)+1;}
            if(j!=0){temp2=(j*2*17)+1;}

            printf("\033[%d;%dH",temp1,temp2);
            //Room
            for(int k=0;k<17;k++){
                for(int l=0;l<17;l++){
                    if(world.Map[i][j]->tiles[k][l]==&Floor){
                        printf("\033[48;2;0;255;255m  ");
                    }
                    if(world.Map[i][j]->tiles[k][l]==&Empty){
                        printf("\033[48;2;50;50;50m  ");
                    }
                    if(world.Map[i][j]->tiles[k][l]==&Wall){
                        printf("\033[48;2;100;255;0m  ");
                    }
                }
                    printf("\033[B\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D\033[D");
            }
            //===============================
        }
        
    }
    

    return 0;
}