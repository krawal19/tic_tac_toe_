/**
 * BSD 3-Clause License
 * Copyright (c) 2020, Kapil Rawal
 * All rights reserved.
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * Redistributions of source code must retain the above copyright notice, this
 * list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 * Neither the name of the copyright holder nor the names of its
 * contributors may be used to endorse or promote products derived from
 * this software without specific prior written permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *  @copyright (c) BSD
 *
 *  @file   tic_tac_toe.h
 *
 *  @author   Kapil Rawal (kapilrawal1995@gmail.com)
 *
 *  @copyright   BSD License
 *
 *  @brief   TicTacToe class header file
 *
 *  @section   DESCRIPTION
 *
 *  File structure containing the definations of TicTacToe class
 *
 */

#ifndef INCLUDE_TIC_TAC_TOE_H_
#define INCLUDE_TIC_TAC_TOE_H_

#include <stdlib.h>
#include <time.h>
#include <thread>
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
    /**
    * @brief initalizing the class variables
    * 
    * @param grid_size_  size of the tic tac toe grid
    */
    void initializeGame(const int &grid_size_);
    /**
    * @brief Displays the current grid status
    * 
    * @param grid_size_ size of the tic tac toe grid
    * @param grid_disp_ grid getting displayed
    */
    void displayBoard(const int &grid_size_,
                      const std::vector<std::vector<char>> &grid_disp_);
    /**
    * @brief checks if the input move is valid
    * 
    * @param index input move from player or computer
    * @return true : if move is valid 
    * @return false : invalid if present in the set i.e already happened move
    */
    bool validMove(int index);
    /**
    * @brief Keeps status of player moves and calculates the winner
    * 
    * @param row input row number played by player or computer
    * @param col input col number played by player or computer
    * @param player player id used to keep count of moves
    * @return int : returns the player who won the game, 0 if draw
    */
    int playerMove(const int &row, const int &col, const int &player);
    /**
    * @brief randomly calculates a valid move for the computer
    * 
    * @return int : valid move generated between range of input moves
    */
    int computerMove();
    /**
    * @brief manages the logic of the game by first converting move number 
    *        to move index in x and y, then calls displayboard and personmove 
    *        for further calculating and displaying the game. Also displayes 
    *        the winner
    * 
    * @param index input move index
    * @param player player id
    * @return true : if someone won the game and stop the loop in main
    * @return false : if the game is a draw and all moves are used by players
    */
    bool gameManager(int index, const int &player);

 private:
    std::vector<std::vector<char>> grid_disp_;
    std::vector<int> rows_;
    std::vector<int> cols_;
    std::set<int> indexOccupied_;
    int grid_size_;
    int diag_;
    int xdiag_;
};

#endif  // INCLUDE_TIC_TAC_TOE_H_
