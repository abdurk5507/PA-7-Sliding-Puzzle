****
- **Name      :**
- **Student ID #:**
- **Class     :  CSCI 2312**   
- **PA#       :  7 -  Sliding Puzzle**  
- **Due Date  :  12/12/2021**  
****

# Read Me 

## Description of Program
This program allows the user to play a sliding puzzle game. The goal of the game is to arrange the numerical tiles in sequential order from lowest to greatest. During the game, the user can choose to complete the game in one run or, alternatively, they can save their progress. I attempted to implement the load save file function, but this is incomplete. While it is an option, running the 'r' option will cause the program to crash.

## Circumstance of Program
The main components of the program are working, that is to say that options 'n' and 'q' fully function. The save function also works (option 's'). However, once this option has been run and the file has been saved (by creating a text file stored outside of the program), the core is dumped and the program ceases working. I was not able to resolve this error. It, however, does not impair the save function. The 'r' function does not entirely work, so running this option will cause the core to be dumped and terminate the program.

The function prototypes are defined in "Board.hpp," "SlidingPuzzle.hpp," and "SPGameManager.hpp." The functions are are located in "Board.cpp," "SlidingPuzzle.cpp," and "SPGameManager.cpp." The driver is placed in "main.cpp."

This program was developed, run, and tested using REPL.it.

## How to Run the Program
1. Open program in REPL.it using shareable link.
2. Open *main.cpp*.
3. Press "run."
4. Follow prompts given by the program and input the requested information.

# Algorithm
1. Provide a list of options for the user to select from.
2. Once the user selects the option to play a new game, generate a randomly shuffled board.
3. The user will then need to move around the 'X' until all numbers have been arranged sequentially from lowest to greatest.
    1. If the user wishes, the game can be quit and saved.
    2. User must name save file.
4. Game will be played until the tiles have been arranged properly.


