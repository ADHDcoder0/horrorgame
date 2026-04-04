#include "Room.h"

Room::Room(int Xsize , int Ysize , bool LeftGate, bool RightGate , bool TopGate , bool BottomGate){
    
    
    //Fix OutofBounds 
    if( Xsize > 17  ){    Xsize=  17 ;  }
    if( Ysize > 17  ){    Ysize=  17 ;  }
    if( Xsize < 5  ){    Xsize=  5 ;  }
    if( Ysize < 5  ){    Ysize=  5 ;  }

    //Defining Floor 
    Floor.type=TileType::Floor;
    Floor.isMovable=true;
    Floor.visible=true;

    //Defining Walls
    Wall.type=TileType::Wall;
    Wall.isMovable = false;
    Wall.visible=true;

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