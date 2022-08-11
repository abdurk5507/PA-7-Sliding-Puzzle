/*********************************************************
* Summary: This file includes the header file of "SlidingPuzzle.cpp"
* Author: Abdur Khan
* Created: December 4th, 2021
********************************************************/

#ifndef SLIDINGPUZZLE_HPP
#define SLIDINGPUZZLE_HPP

#include <iostream>
#include <string>

typedef int TILE_TYPE;

class SlidingPuzzle{
  public:
    static const int GRID_SIZE = 4;
    static const TILE_TYPE EMPTY_TILE = 0;//represents question mark tile 

  private:
    static const int SHUFFLE_CALL = 2000;
    static const int INVALID_MOVE = -1; //when user makes invalid move
    static const int MOVE_TILE_UP = 0; //valid move
    static const int MOVE_TILE_RIGHT = 1; //valid move 
    static const int MOVE_TILE_DOWN = 2; //valid move
    static const int MOVE_TILE_LEFT = 3; //valid move

    int numMoves;
    int tileMove;
    bool loggingEnabled = true; 
  

  public:

    TILE_TYPE target[GRID_SIZE][GRID_SIZE]; //final goal for grid
    TILE_TYPE initial[GRID_SIZE][GRID_SIZE]; 
    TILE_TYPE current[GRID_SIZE][GRID_SIZE]; //current rendition of grid

    //constructor
    SlidingPuzzle();
    SlidingPuzzle(TILE_TYPE grid[]);

    void shuffle();
    void drawGrid();
    bool isTileEmpty(int r, int c) const;
    void moveTile(TILE_TYPE tileToMove);
    int getTileMove() const {return tileMove;}
    bool isTileUpEmpty(int r, int c) const;
    bool isTileRightEmpty(int r, int c) const;
    bool isTileLeftEmpty(int r, int c) const;
    bool isTileDownEmpty(int r, int c) const;
    bool isSolved() const;
    void play();
  
};

#endif