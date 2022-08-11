#include <iostream>
#include "SlidingPuzzle.hpp"
#include "SPGameManager.hpp"
#include "Board.hpp"

using namespace std;

int main() {

    SPGameManager aMgr; // the main control of the puzzle program; relating to the menu system and handling user input for menu selection
    SlidingPuzzle myPuzzle;   // the puzzle game itself; drawing the board using an internal board object, handling ongoing user inputs to move pieces, and querying the user's choice to continue playing or not
    GameMenuType option;      // a user option chosen by the user

    do {
        aMgr.showGameMenu();
        option = aMgr.processGameMenuOption(myPuzzle);
        // you need to implment NEW_GAME only to get full regular credit
        if (option == NEW_GAME /*|| option == LOAD_GAME || option == CONTINUE_GAME*/) {
            myPuzzle.drawGrid();  //draw the initial shuffled grid  
            myPuzzle.play();      //play until solved or select to quit.
        }
    } while (option != QUIT);
}