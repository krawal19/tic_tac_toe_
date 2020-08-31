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
 *  @file   tic_tac_toe.cpp
 *
 *  @author   Kapil Rawal (kapilrawal1995@gmail.com)
 *
 *  @copyright   BSD License
 *
 *  @brief   TicTacToe class implementation file
 *
 *  @section   DESCRIPTION
 *
 * This file contains the implementations of the methods of TicTacToe Class
 *
 */

#include "tic_tac_toe.h"

TicTacToe::TicTacToe(int grid_size) {
    grid_size_ = grid_size;
    std::vector<std::vector<char>> grid_disp_vector(grid_size_,std::vector<char>(grid_size_, ' '));
    grid_disp_ = grid_disp_vector;
    rows_.resize(grid_size_);
    cols_.resize(grid_size_);
    diag_ = 0;
    xdiag_ = 0;
}

TicTacToe::~TicTacToe() {}

void TicTacToe::instructions(){
    std::vector<std::vector<char>> ins_grid = {{'1', '2', '3'},
                                                {'4', '5', '6'},
                                                {'7', '8', '9'}};
    std::cout << "\n\tWelcome to TIC-TAC-TOE game" << std::endl;
    std::cout << "  This game can be played with 1 or 2 players!" << std::endl;
    std::cout << "  The instructions are as follows: \n" << std::endl;
    std::cout << "  The following shows the numbering on the grid" << std::endl;
    displayBoard(ins_grid);
    std::cout << "  Use this numbers when asked for player input" << std::endl;
    std::cout << "  Enjoy the Game!\n" << std::endl;
}

void TicTacToe::displayBoard(const std::vector<std::vector<char>> &grid_disp_) {
    for (int i = 0; i < grid_size_; ++i) {
        std::cout << " ";
        for (int j = 0; j < grid_size_; ++j) std::cout << " | " << grid_disp_[i][j];
        std::cout << " |" << std::endl;
    }
    std::cout << "\n" << std::endl;
}

bool TicTacToe::validMove(int index) {
    if (index_occupied_.find(index) != index_occupied_.end()) return false;
    return true;
}

int TicTacToe::playerMove(const int &row, const int &col, const int &player) {
    int count  = player == 1 ? 1 : -1;

    rows_[row] += count;
    cols_[col] += count;

    // Keeping diagonal count
    if (row == col) diag_+=count;
    if (row + col == grid_size_-1) xdiag_+=count;

    if (abs(rows_[row]) == grid_size_ || abs(cols_[col]) == grid_size_ ||
        abs(diag_) == grid_size_ || abs(xdiag_) == grid_size_)
        return count > 0 ? 1 : 2;

    return 0;
}

int TicTacToe::computerMove() {
    int random_index = 1, total_range = grid_size_* grid_size_;
    thread_local unsigned int seed = time(NULL);
    while (!validMove(random_index) && index_occupied_.size() <= total_range)
        random_index  = 1 + (rand_r(&seed) % total_range);
    return random_index;
}

bool TicTacToe::gameManager(int index, const int &player) {
    index_occupied_.insert(index);
    // converting 1d index to 2d index values
    int move_x = 0, move_y = 0;
    move_x = (index-1) / grid_size_;
    move_y = (index-1) % grid_size_;
    grid_disp_[move_x][move_y] = player == 1 ? 'X':'O';

    std::cout << "  Player " << player << " entered '"<<
        grid_disp_[move_x][move_y] << "' at index " << index << std::endl;

    displayBoard(grid_disp_);

    int winner =  playerMove(move_x, move_y, player);
    if (winner != 0) {
        std::cout << "\n   Player " << winner << " Won! " << std::endl;
        return true;
    }
    if (index_occupied_.size() == grid_size_ * grid_size_ && winner == 0) {
        std::cout << "  Game Draw!" << std::endl;
        return true;
    }
    return false;
}

void TicTacToe::setIndexOccupied(std::set<int> &index_set) { index_occupied_  = index_set; }
