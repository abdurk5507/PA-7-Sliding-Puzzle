/*********************************************************
* Summary: This file includes the implementation of "SlidingPuzzle.hpp"
* Author: Abdur Khan
* Created: December 4th, 2021
********************************************************/

#include <iostream>

#include "SlidingPuzzle.hpp"
#include "Board.hpp"

SlidingPuzzle::SlidingPuzzle()/*:numMoves(0)*/{ //constructor
  for(int i = 0; i < GRID_SIZE; i++){
    for(int j = 0; j < GRID_SIZE; j++){
      current[i][j] = target[i][j] = i*GRID_SIZE+j+1;
    }
  }
  current[GRID_SIZE-1][GRID_SIZE-1] = target[GRID_SIZE-1][GRID_SIZE-1] = EMPTY_TILE;//assigns bottom rightmost tile as question mark
}

SlidingPuzzle::SlidingPuzzle(TILE_TYPE grid[]){//copy constructor for if someone gives a board as input
  for(int i = 0; i < GRID_SIZE; i++){
    for(int j = 0; j < GRID_SIZE; j++){
      target[i][j] = i*GRID_SIZE + j + 1;
      initial[i][j] = current[i][j] = grid[i * GRID_SIZE + j];
    }
  }
  target[GRID_SIZE - 1][GRID_SIZE - 1] = EMPTY_TILE;
}

void SlidingPuzzle::drawGrid(){ //draw grid using board.cpp (following MVC)
  Board newGrid(current);
  newGrid.drawGrid();
}

void SlidingPuzzle::shuffle(){
  srand(time(NULL)); //generate random shuffles each call

  for(int i = 0; i < SHUFFLE_CALL; i++){
    moveTile(rand() % (GRID_SIZE * GRID_SIZE -1)+1); //move each tile randomly
  }

  for(int i = 0; i < GRID_SIZE; i++){
    for(int j = 0; j < GRID_SIZE; j++){
      initial[i][j] = current[i][j];
    }
  }
}

void SlidingPuzzle::moveTile(TILE_TYPE tileToMove){
  int r, c;
  char moveCharacter;
  for(int i = 0; i < GRID_SIZE; i++){
    for(int j = 0; j < GRID_SIZE; j++){
      if(current[i][j] == tileToMove){
        r = i;
        c = j;
      }
    }
  }

  tileMove = INVALID_MOVE;
  
  if(isTileUpEmpty(r, c)){ //check if upper tile is empty before moving
    current[r-1][c] = current[r][c];
    current[r][c] = EMPTY_TILE;
    moveCharacter = 'U';
    tileMove = MOVE_TILE_UP;
    
  }
  else if(isTileDownEmpty(r, c)){ //check is lower tile is empty before moving
    current[r+1][c] = current[r][c];
    current[r][c] = EMPTY_TILE;
    moveCharacter = 'D';
    tileMove = MOVE_TILE_DOWN;
    
  }
  else if(isTileRightEmpty(r, c)){ //check if right tile is empty before moving
    current[r][c+1] = current[r][c];
    current[r][c] = EMPTY_TILE;
    moveCharacter = 'R';
    tileMove = MOVE_TILE_RIGHT;
    
  }
  else if(isTileLeftEmpty(r, c)){ //check is left tile is empty before moving
    current[r][c-1] = current[r][c];
    current[r][c] = EMPTY_TILE;
    moveCharacter = 'L';
    tileMove = MOVE_TILE_LEFT;
    
  }
  else{
    tileMove = INVALID_MOVE;
  }
  /*
  if(tileMove != INVALID_MOVE && loggingEnabled == true){
    moveHistoryLog.push_back("(" + std::to_string(r) + "," std::to_string(c) + "," + moveChar + ")");
  }
  */
}

bool SlidingPuzzle::isTileEmpty(int r, int c) const{ //checks if tile is empty
  return current[r][c] == EMPTY_TILE;
}

bool SlidingPuzzle::isTileUpEmpty(int r, int c) const{ //checks if upper tile is empty
  if (r == 0){
    return false;
  }
  return current[r-1][c] == EMPTY_TILE;
}

bool SlidingPuzzle::isTileRightEmpty(int r, int c) const{ //check if right tile is empty
  if(c == GRID_SIZE-1){
    return false;
  } 
  return current[r][c+1] == EMPTY_TILE;
}

bool SlidingPuzzle::isTileDownEmpty(int r, int c) const{ //check is lower tile is empty
  if(r == GRID_SIZE - 1){
    return false;
  }
  return current[r + 1][c] == EMPTY_TILE;
}

bool SlidingPuzzle::isTileLeftEmpty(int r, int c) const{ //check is left tile is empty
  if(c == 0){
    return false;
  }
  return current[r][c - 1] == EMPTY_TILE;
}

bool SlidingPuzzle::isSolved() const{ //check is puzzle is solved by comparing current with target
  for(int i = 0; i < GRID_SIZE; i++){
    for(int j = 0; j < GRID_SIZE; j++){
      if(target[i][j] != current[i][j]){
        return false;
      }
    }
  }
  return true;
}

void SlidingPuzzle::play(){ //play sliding puzzle game
  int r, c, choiceToMove;

  while(!isSolved()){
    bool isOkay = false;
    while(!isOkay){
      std::cout << "\nPlease enter the number to move (1.." << GRID_SIZE*GRID_SIZE - 1 << ") or '0' to exit: ";
      std::cin >> choiceToMove;
      if(! std::cin.fail() && choiceToMove >= 0 && choiceToMove < GRID_SIZE*GRID_SIZE /*- 1*/){//removing the -1 solves the issue of getting the invalid input when entering 15 as a valid move
      //checks if input is valid and within the parametrs of the board
        isOkay = true;
      }
      else{
        std::cout << "\nInvalid Input!!!\n";
        std::cin.clear();
        //std::cin.ignore(INT_MAX, '\n');
      }

      if(choiceToMove == EMPTY_TILE){
        return; //leave game
      }

      moveTile(choiceToMove);

      if(getTileMove() == INVALID_MOVE){
        std::string brownTextItalics = std::string({0x1b, '[', '9', '3', ';', '3', 'm'});
        std::string testColor = std::string({0x1b, '[', '6', ';', '9', '1', 'm'});
        std::string redColor = std::string({0x1b, '[', '7', ';', '9', '1', 'm'});
        std::string normalColor = std::string({0x1b, '[', '0', ';', '3', '9', 'm'});
        std::string blueUnderlineColor = std::string({0x1b, '[', '4', ';', '9', '6', 'm'});
        std::string greenUnderlineColor = std::string({0x1b, '[', '4', ';', '9', '2', 'm'});
        std::string magentaTextColor = std::string({0x1b, '[', '6', ';', '9', '5', 'm'});
        std::string yellowHighlightColor = std::string({0x1b, '[', '7', ';', '9', '3', 'm'});

        for(int i = 0; i < 2000; i++){ //creating beep sound when invalid input is received
          std::cout << '\a';
        }

        std::cout <<  blueUnderlineColor + "\n!!! Invalid " << greenUnderlineColor <<  "Move !!!\n" << normalColor << yellowHighlightColor << " \tTry Again\n" + normalColor;
      }
      else{
        numMoves++;
      }
      drawGrid();
    }
  }
  std::cout << "The puzzle has been solved! Total moves: " << numMoves << std::endl;
}

