/*********************************************************
* Summary: This file includes the function headers for "Board.cpp"
* Author: Abdur Khan
* Created: December 4th, 2021
********************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include "SlidingPuzzle.hpp"

class Board{
  public:
    Board(TILE_TYPE aPuzzle[SlidingPuzzle::GRID_SIZE][SlidingPuzzle::GRID_SIZE]);
    void drawGrid();

  private:
    void drawLine();
    void drawNumbers(int row);
    TILE_TYPE puzzle[SlidingPuzzle::GRID_SIZE][SlidingPuzzle::GRID_SIZE];
};

#endif