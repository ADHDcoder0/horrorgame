
#include "LevelGenerator.h"


DFS::DFS(int xSize = 4, int ySize = 4 ){
        Xsize=xSize , Ysize=ySize;

        world.resize(Xsize);
        for(int i=0;i<Xsize;i++){
        world[i].resize(Ysize);
        }
}



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
    



Level::Level(int x=5,int y=5){           
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

auto Level::GetTilePtr(int RoomX , int RoomY ,int TileX , int TileY){
        // Range: [0,max]
        if(RoomX>=Xsize){RoomX=Xsize-1;}
        if(RoomY>=Ysize){RoomY=Ysize-1;}
        if(RoomX<0){RoomX=0;}
        if(RoomY<0){RoomY=0;}

        if(TileX<0){TileX=0;}
        if(TileY<0){TileY=0;}
        if(TileX>=17){TileX=16;}
        if(TileY>=17){TileY=16;}

        return Map[RoomX][RoomY]->tiles[TileX][TileY];
    }
   

Level::~Level(){
    for(int i=0;i<Xsize;i++){
        for(int j=0;j<Ysize;j++){
           delete Map[i][j];
        }
    }
}

