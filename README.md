<h1 align=center> TIC-TAC-TOE </h1>

[![License](https://img.shields.io/badge/License-BSD%203--Clause-blue.svg)](https://opensource.org/licenses/BSD-3-Clause)

## Project Overview
This project is the tic-tac-toe game which can be played with 1 or 2 players.

License
This project is under the [BSD License](https://gitlab.com/krawal19/tic_tac_toe/-/tree/master/LICENSE).

## Dependencies
The project requires following dependenices:
- gcc 7.5.0
- Googletest
- cmake 3.10.2
- Ubuntu 18.04

## Program installation
```
git clone https://gitlab.com/krawal19/tic_tac_toe.git
cd tic_tac_toe
mkdir lib
cd lib 
git clone https://github.com/google/googletest/
cd ..
mkdir build
cd build
cmake ..
make

Run program: ./ticTacToe
```
## Running tests via command line
To check the tests you can run the following command.
```
Run program: ./test/ticTacToeTest
```
## Instructions to play the game
After running the ./ticTacToe program you will get the instructions on the screen as follows:

>Note: Please try to input values within constriants. 

- Here the numbers in the grid represents the actual grid position which player should enter to play his move.

```
  Welcome to TIC-TAC-TOE game
  This game can be played with 1 or 2 players!
  The instructions are as follows: 

  The following shows the numbering on the grid
  | 1 | 2 | 3 |
  | 4 | 5 | 6 |
  | 7 | 8 | 9 |


  Use this numbers when asked for player input
  Enjoy the Game!

```
- Now you'll have to enter total players playing this game, ideal inputs are 1 or 2
```
  
  Enter total players 1 or 2 :1
  Player 2 is Computer!
```
- If one is entered as the total players then your opponent will be a computer
- After selecting players procced with your first move by entering a number between 1 to 9 both included.
```
Enter your move number and press 'ENTER': 
```
- Once you enter the move number the screen will show following output
- Below example is of playing with computer, which will always be player 2
```
 Player 1 entered 'X' at index 2
  |   | X |   |
  |   |   |   |
  |   |   |   |

 Player 2 entered 'O' at index 1
  | O | X |   |
  |   |   |   |
  |   |   |   |

  Enter your move number and press 'ENTER': 
```
- Here it will again ask you to enter your valid move, enter another move in empty space
- Now the game will proceed as follows:
```
Enter your move number and press 'ENTER': 3
  Player 1 entered 'X' at index 3
  | O | X | X |
  |   |   |   |
  |   |   |   |


  Player 2 entered 'O' at index 4
  | O | X | X |
  | O |   |   |
  |   |   |   |

  Enter your move number and press 'ENTER': 7
  Player 1 entered 'X' at index 7
  | O | X | X |
  | O |   |   |
  | X |   |   |


  Player 2 entered 'O' at index 6
  | O | X | X |
  | O |   | O |
  | X |   |   |

  Enter your move number and press 'ENTER': 5
  Player 1 entered 'X' at index 5
  | O | X | X |
  | O | X | O |
  | X |   |   |


  Player 1 Won! 

=============GAME ENDED!=============
```
- It will show who won once the game is completed
- The game will be completed if any player wins or the game is a draw.
- The output of draw game will look as follow:
```
  Player 1 entered 'X' at index 9
  | X | O | X |
  | X | O | O |
  | O | X | X |


  Game Draw!
```
- Press ctrl+c to kill the game! 

The game will also show messgaes such as:
- This will happend when same move is used again and the borad slot is not empty.
```
Not a vaild move, try different availabe value between 1-9!
```
- When valid board size is not entered!
```
Board size invalid, Valid board size are 2,3...!
```
## Extend Functionality and further enhancements
- This game API can further be used for multiple size boards 5, 10 etc with changing the base API code.
- The computer player can be made smarter
- Input typo detection can be moved to API

## Author
- Kapil Rawal
- Email Id: Kapilrawal1995@gmail.com