/*********************************************************
* Summary: This file includes the header file of "SPGameManager.cpp"
* Author: Abdur Khan
* Created: December 4th, 2021
********************************************************/

#ifndef SPGAMEMANAGER_HPP
#define SPGAMEMANAGER_HPP

#include <iostream>
#include <fstream>
#include "SlidingPuzzle.hpp"

enum GameMenuType{ //enum type for game choices
  NOT_SELECTED = -1,
  NEW_GAME = 1,
  LOAD_GAME = 2,
  SAVE_GAME = 3,
  SAVE_MOVE_HISTORY = 4,
  CONTINUE_GAME = 5,
  REPLAY_GAME = 6,
  SET_GRID_SIZE = 7,
  QUIT = 10
};

class SPGameManager{
  private:
    GameMenuType gameOption;

  public:
    SPGameManager(){
      gameOption = NOT_SELECTED;
    }

    void showGameMenu() const;
    GameMenuType processGameMenuOption(SlidingPuzzle& thePuzzle);
    GameMenuType getGameOption(){return gameOption;}

    //extra credit functions
    void saveSPGame(const SlidingPuzzle& thePuzzle) const;
    friend std::ostream& operator << (std::ostream &outputStream, SlidingPuzzle aPuzzle);
    SlidingPuzzle& loadSPGame() const;

};

#endif