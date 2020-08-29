#ifndef TIC_TAC_TOE_H_
#define TIC_TAC_TOE_H_

#include <iostream>
#include <vector>
#include <set>

/**
 * @brief class for Tic-Tac-Toe game
 * 
 */
class TicTacToe {
 public:
   /**
    * @brief Construct a new Tic Tac Toe object
    * 
    */
   TicTacToe();
   /**
    * @brief Destroy the Tic Tac Toe object
    * 
    */
   ~TicTacToe();
   
   void initializeGame(const int &grid_size_);

   void displayBoard(const int &grid_size_, const std::vector<std::vector<char>> &grid_disp_);

   bool validMove(int index);

   int playerMove(const int &row,const int &col,const int &player);

   bool gameManager(int index, int &player);
   

 private:
   std::set<int> indexOccupied_;
   std::vector<std::vector<char>> grid_disp_;
   std::vector<int> rows_;
   std::vector<int> cols_;
   int grid_size_;
   int diag_;
   int xdiag_;
};

#endif // TIC_TAC_TOE_H_