/*********************************************************
* Summary: This file includes the implementation of "Board.hpp"
* Author: Abdur Khan
* Created: December 4th, 2021
********************************************************/

#include <iostream>
#include <string>
#include "SlidingPuzzle.hpp"
#include "Board.hpp"

Board::Board(TILE_TYPE aPuzzle[SlidingPuzzle::GRID_SIZE][SlidingPuzzle::GRID_SIZE]){ //constructor 
  for(int i = 0; i < SlidingPuzzle::GRID_SIZE; i++){
    for(int j = 0; j < SlidingPuzzle::GRID_SIZE; j++){
      puzzle[i][j] = aPuzzle[i][j];
    }
  }
}

void Board::drawGrid(){ //used to draw grid, which is composed of lines and numbers
  drawLine();
  for(int i = 0; i < SlidingPuzzle::GRID_SIZE; i++){
    drawNumbers(i);
    drawLine();
  }
}

void Board::drawLine(){ //used to draw the lines around the grid
  for(int i = 0; i < SlidingPuzzle::GRID_SIZE; i++){
    std::cout << "|----";
  }
  std::cout << "|\n";
}

void Board::drawNumbers(int row){
  std::string blueHighlightColor = std::string({0x1b, '[', '7', ';', '9', '4', 'm'});
  std::string redColor = std::string({0x1b, '[', '7', ';', '9', '1', 'm'});
  std::string normalColor = std::string({0x1b, '[', '0', ';', '3', '9', 'm'});
  for(int i = 0; i < SlidingPuzzle::GRID_SIZE; i++){ //display the numbers for the grid and the 'X' tile that will be moved around
    std::cout << "| " << (puzzle[row][i] == SlidingPuzzle::EMPTY_TILE ? blueHighlightColor + "X" + normalColor: std::to_string(puzzle[row][i])) << (puzzle[row][i] >= 10 ? " " : "  ");
  }
  std::cout << "|" << std::endl;
}