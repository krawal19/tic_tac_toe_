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
    /**
     * @brief instructions for the tic tac toe game
     * 
     */
    void instructions();
    /**
     * @brief Get the Grid Disp object
     * 
     * @return std::vector<std::vector<char>> return the display vector
     */
    std::vector<std::vector<char>> getGridDisp();
    /**
     * @brief Get the Rows object
     * 
     * @return std::vector<int> rows_ vector
     */
    std::vector<int> getRows();
    /**
     * @brief Set the Rows object
     * 
     * @param rows_vec sets rows_ vector
     */
    void setRows(std::vector<int> &rows_vec);
    /**
     * @brief Get the Cols object
     * 
     * @return std::vector<int> cols_ vector
     */
    std::vector<int> getCols();
    /**
     * @brief Set the Cols object
     * 
     * @param cols_vec sets cols_ vector
     */
    void setCols(std::vector<int> &cols_vec);
    /**
     * @brief Get the Index Occupied object
     * 
     * @return std::set<int>  index_occupied_ set
     */
    std::set<int> getIndexOccupied();
    /**
     * @brief Set the Index Occupied object
     * 
     * @param index_set  sets inde_occupied_ set
     */
    void setIndexOccupied(std::set<int> &index_set);
    /**
     * @brief Get the Grid Size object
     * 
     * @return int grid_size_ value
     */
    int getGridSize();
    /**
     * @brief Set the Grid Size object
     * 
     * @param grid_size_value input grid size
     */
    void setGridSize(int grid_size_value);
    /**
     * @brief Get the Diag object
     * 
     * @return int disg_ value
     */
    int getDiag();
    /**
     * @brief Set the Diag object
     * 
     * @param diag_value  
     */
    void setDiag(int diag_value);
    /**
     * @brief Get the xDiag object
     * 
     * @return int xdiag_ value
     */
    int getXDiag();
    /**
     * @brief sets the xDiag object
     * 
     * @param xdiag_value 
     */
    void setXDiag(int xdiag_value);

 private:
    std::vector<std::vector<char>> grid_disp_;
    std::vector<int> rows_;
    std::vector<int> cols_;
    std::set<int> index_occupied_;
    int grid_size_;
    int diag_;
    int xdiag_;
};

#endif  // INCLUDE_TIC_TAC_TOE_H_
