### Sample Output 1: Showing Save Function

                ____ Game Menu ____  
n - Play a fresh new puzzle game <br>
r - Read in from an existing game data file<br>
s - Save the current game to a file<br>
c - Continue with the current game<br>
q - Quit the game<br>

What would you like to do? Make your choice now: n<br>

|----|----|----|----|<br>
| 10 | 7  | 15 | 3  |<br>
|----|----|----|----|<br>
| 9  | 14 | 11 | 12 |<br>
|----|----|----|----|<br>
| 1  | X  | 13 | 2  |<br>
|----|----|----|----|<br>
| 4  | 8  | 5  | 6  |<br>
|----|----|----|----|<br>

Please enter the number to move (1..15) or '0' to exit: 1<br>
|----|----|----|----|<br>
| 10 | 7  | 15 | 3  |<br>
|----|----|----|----|<br>
| 9  | 14 | 11 | 12 |<br>
|----|----|----|----|<br>
| X  | 1  | 13 | 2  |<br>
|----|----|----|----|<br>
| 4  | 8  | 5  | 6  |<br>
|----|----|----|----|<br>

Please enter the number to move (1..15) or '0' to exit: 4<br>
|----|----|----|----|<br>
| 10 | 7  | 15 | 3  |<br>
|----|----|----|----|<br>
| 9  | 14 | 11 | 12 |<br>
|----|----|----|----|<br>
| 4  | 1  | 13 | 2  |<br>
|----|----|----|----|<br>
| X  | 8  | 5  | 6  |<br>
|----|----|----|----|<br>

Please enter the number to move (1..15) or '0' to exit: 0<br>
                ____ Game Menu ____<br>
n - Play a fresh new puzzle game<br>
r - Read in from an existing game data file<br>
s - Save the current game to a file<br>
q - Quit the game<br>

What would you like to do? Make your choice now: s<br>
You are now saving your current game file. What would you like to name it? testFile.txt<br>
signal: illegal instruction (core dumped)<br>

### Sample Output 2: Showing quit function

                ____ Game Menu ____
n - Play a fresh new puzzle game<br>
r - Read in from an existing game data file<br>
s - Save the current game to a file<br>
c - Continue with the current game<br>
q - Quit the game<br>

What would you like to do? Make your choice now: n<br>

|----|----|----|----|<br>
| 5  | 13 | 11 | 9  |<br>
|----|----|----|----|<br>
| 7  | 6  | 4  | 2  |<br>
|----|----|----|----|<br>
| X  | 1  | 8  | 3  |<br>
|----|----|----|----|<br>
| 14 | 10 | 12 | 15 |<br>
|----|----|----|----|<br>

Please enter the number to move (1..15) or '0' to exit: 0<br>
                ____ Game Menu ____<br>
n - Play a fresh new puzzle game<br>
r - Read in from an existing game data file<br>
s - Save the current game to a file<br>
q - Quit the game<br>

What would you like to do? Make your choice now: q<br>

### Sample Output 3: Showcasing invalid input

               ____ Game Menu ____
n - Play a fresh new puzzle game <br>
r - Read in from an existing game data file<br>
s - Save the current game to a file<br>
c - Continue with the current game<br>
q - Quit the game<br>

What would you like to do? Make your choice now: n<br>

|----|----|----|----|<br>
| 1  | 3  | 2  | 4  |<br>
|----|----|----|----|<br>
| 11 | X  | 14 | 15 |<br>
|----|----|----|----|<br>
| 7  | 9  | 5  | 8  |<br>
|----|----|----|----|<br>
| 6  | 10 | 13 | 12 |<br>
|----|----|----|----|<br>

Please enter the number to move (1..15) or '0' to exit: 10<br>

!!! Invalid Move !!!<br>
    Try Again<br>
|----|----|----|----|<br>
| 1  | 3  | 2  | 4  |<br>
|----|----|----|----|<br>
| 11 | X  | 14 | 15 |<br>
|----|----|----|----|<br>
| 7  | 9  | 5  | 8  |<br>
|----|----|----|----|<br>
| 6  | 10 | 13 | 12 |<br>
|----|----|----|----|<br>