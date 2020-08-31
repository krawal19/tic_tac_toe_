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
 *  @file   tic_tac_toe_test.cpp
 *
 *  @author   Kapil Rawal (kapilrawal1995@gmail.com)
 *
 *  @copyright   BSD License
 *
 *  @brief   TicTacToe class test implementation file
 *
 *  @section   DESCRIPTION
 *
 * This file contains the implementations of the test for TicTacToe Class methods
 *
 */

#include <gtest/gtest.h>
#include "../include/tic_tac_toe.h"

/**
 * @brief check if gameManager method works properly
 * 
 * @param TicTacToeTest name of the test suite
 * 
 * @param GameManagerTest name of the test
 * 
 */
TEST(TicTacToeTest, GameManagerTest) {
    int grid_size = 3, index = 1, toggle = 1;
    TicTacToe* game = new TicTacToe(grid_size);
    std::vector<int> moves{1, 2, 4, 5, 8, 6, 3, 7, 9};
    int player;

    for (int i = 0; i < moves.size()-1; ++i) {
        player = toggle == 1 ? 1 : 2;
        EXPECT_EQ(false, game->gameManager(moves[i], player));
        toggle ^=1;
    }
    EXPECT_EQ(true, game->gameManager(moves.size(), 1));
}

/**
 * @brief check if Initialization of variables if proper
 * 
 * @param TicTacToeTest name of the test suite
 * 
 * @param InitializationTest name of the test
 * 
 */
TEST(TicTacToeTest, InitializationTest) {
    int grid_size = 3, initial_diag = 0;
    TicTacToe* game = new TicTacToe(grid_size);

    EXPECT_EQ(grid_size, game->getGridSize());

    EXPECT_EQ(grid_size, game->getGridDisp().size());
    EXPECT_EQ(grid_size, game->getGridDisp()[0].size());

    EXPECT_EQ(grid_size, game->getRows().size());
    EXPECT_EQ(grid_size, game->getCols().size());

    EXPECT_EQ(initial_diag, game->getDiag());
    EXPECT_EQ(initial_diag, game->getXDiag());
}

/**
 * @brief check if validMove method works properly
 * 
 * @param TicTacToeTest name of the test suite
 * 
 * @param ValidMoveTest of the test
 * 
 */
TEST(TicTacToeTest, ValidMoveTest) {
    int index_invalid = 1, index_valid = 5, grid_size = 3;
    TicTacToe* game = new TicTacToe(grid_size);
    std::set<int> test_set;
    test_set.insert(index_invalid);
    game->setIndexOccupied(test_set);

    EXPECT_EQ(false, game->validMove(index_invalid));
    EXPECT_EQ(true, game->validMove(index_valid));
}

/**
 * @brief check if playerMove method works properly
 * 
 * @param TicTacToeTest name of the test suite
 * 
 * @param PlayerMoveTest of the test
 * 
 */
TEST(TicTacToeTest, PlayerMoveTest) {
    int grid_size = 3, row = 1, col = 1;
    int diag = 0, xdiag = 0, win = 0;
    TicTacToe* game = new TicTacToe(grid_size);

    EXPECT_EQ(0, game->playerMove(row-1, col-1, 1));
    EXPECT_EQ(0, game->playerMove(row, col, 1));
    EXPECT_EQ(1, game->playerMove(row+1, col+1, 1));
}

/**
 * @brief check if computerMove method works properly
 * 
 * @param TicTacToeTest name of the test suite
 * 
 * @param ComputerMoveTest name of the test
 * 
 */
TEST(TicTacToeTest, ComputerMoveTest) {
    int grid_size = 3, index = 1;
    TicTacToe* game = new TicTacToe(grid_size);
    std::set<int> test_set;
    test_set.insert(index);
    game->setIndexOccupied(test_set);
    EXPECT_NE(index, game->computerMove());
}
