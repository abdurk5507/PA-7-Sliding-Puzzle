/*********************************************************
* Summary: This file includes the implementation of "SPGameManager.hpp"
* Author: abdurk5507
* Created: December 4th, 2021
********************************************************/

#include <iostream>
#include <fstream>
#include "SPGameManager.hpp"

void SPGameManager::showGameMenu() const{ //display menu options for game
  std::cout << "\t\t\t\t____ Game Menu ____\n";
  //std::cout << "g - Set the grid size. Do this to change the grid size (default:4)\n";
  std::cout << "n - Play a fresh new puzzle game\n";
  std::cout << "r - Read in from an existing game data file\n";
  std::cout << "s - Save the current game to a file\n";
  //std::cout << "h - Save the game move (h)istory\n";
  //std::cout << "p - Re(p)lay the game from the specified move history\n\n";

  if(gameOption == NOT_SELECTED){
    std::cout << "c - Continue with the current game\n";
  }
  std::cout << "q - Quit the game\n\n";

  std::cout << "What would you like to do? ";
}

GameMenuType SPGameManager::processGameMenuOption(SlidingPuzzle& thePuzzle){ //process user input for menu choice
  char choice;
  std::cout << "Make your choice now: ";
  std::cin >> choice;
  switch(tolower(choice)){
    case 'n' :
      gameOption = NEW_GAME;
      system("clear");
      thePuzzle.shuffle();
      break;

    case 's' :
      gameOption = SAVE_GAME;
      saveSPGame(thePuzzle);
      break;

    case 'q' :
      gameOption = QUIT;
      break;

    case 'r' :
      gameOption = LOAD_GAME;
      system("clear");
      thePuzzle = loadSPGame();
      break;

    default:
      gameOption = NOT_SELECTED;
  }
  return gameOption;
}

std::ostream& operator << (std::ostream &outputStream, SlidingPuzzle aPuzzle){ //operator overloading used to save file
  for(int i = 0; i < SlidingPuzzle::GRID_SIZE; i++){
    for(int j = 0; j < SlidingPuzzle::GRID_SIZE; j++){
      std::string aString = (aPuzzle.current[i][i] == SlidingPuzzle::EMPTY_TILE) ? "?" : std::to_string(aPuzzle.current[i][j]); //convert puzzle array to a string for storage

      if(i == SlidingPuzzle::GRID_SIZE-1 && j == SlidingPuzzle::GRID_SIZE-1){
        outputStream << aString << std::endl; //output converted string
      }
      else{
        outputStream << aString << ",";
      }
    }
  }
}

void SPGameManager::saveSPGame(const SlidingPuzzle& thePuzzle) const{ //creating save file 
  std::string saveFile;
  std::cout << "You are now saving your current game file. What would you like to name it? ";
  std::cin >> saveFile;

  std::ofstream outputFile(saveFile);
  if(outputFile){
    outputFile << thePuzzle;
  }
  outputFile.close();
}

SlidingPuzzle& SPGameManager::loadSPGame()const{ //load save file
  TILE_TYPE gridFromSave[SlidingPuzzle::GRID_SIZE * SlidingPuzzle::GRID_SIZE];
  std::string saveFile, inputLine, numString;
  SlidingPuzzle *aPuzzle;

  std::cout << "Enter the name of the save file: ";
  std::cin >> saveFile;
  std::ifstream inputFile(saveFile);

  if(inputFile){
    std::getline(inputFile, inputLine);
    size_t pos = 0;
    
  }

}

