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

#include <tuple>
#include <gtest/gtest.h>
#include "tic_tac_toe.h"

/**
 * @brief TestFixture class
 * 
 */
class TicTacToeTestFixture : public testing::Test {
    protected:
        TicTacToe *game;
        int grid_size = 3;
    void SetUp() { game = new TicTacToe(grid_size); }
    void TearDown() { delete game;}
};

/**
 * @brief Game Manager Parameterized Test class inherited from test Fixture class
 * 
 */
class TicTacToeTestParamGameManager: 
public TicTacToeTestFixture, 
public ::testing::WithParamInterface<std::tuple<int,int>> {
};

/**
 * @brief Player move Parameterized Test class inherited from test Fixture class
 * 
 */
class TicTacToeTestParamPlayerMove:
public TicTacToeTestFixture, 
public ::testing::WithParamInterface<int> {
};

/**
 * @brief check if validMove method works properly
 * 
 * @param TicTacToeTest name of the test suite
 * 
 * @param ValidMoveTest of the test
 * 
 */
TEST_F(TicTacToeTestFixture, ValidMoveTest) {
    int index_invalid = 1, index_valid = 5;
    std::set<int> test_set;
    test_set.insert(index_invalid);
    game->setIndexOccupied(test_set);

    EXPECT_EQ(false, game->validMove(index_invalid));
    EXPECT_EQ(true, game->validMove(index_valid));
}

/**
 * @brief check if computerMove method works properly
 * 
 * @param TicTacToeTest name of the test suite
 * 
 * @param ComputerMoveTest name of the test
 * 
 */
TEST_F(TicTacToeTestFixture, ComputerMoveTest) {
    int grid_size = 3, index = 1;
    std::set<int> test_set;
    test_set.insert(index);
    game->setIndexOccupied(test_set);

    EXPECT_NE(index, game->computerMove());
}

/**
 * @brief check if playerMove method works properly for diagoal
 * 
 * @param TicTacToeTestFixture name of the test suite
 * 
 * @param PlayerMoveDigonalTest of the test
 * 
 */
TEST_F(TicTacToeTestFixture, PlayerMoveDigonalTest) {
    int row = 1, col = 1;

    EXPECT_EQ(0, game->playerMove(row-1, col-1, 1));
    EXPECT_EQ(0, game->playerMove(row, col, 1));
    EXPECT_EQ(1, game->playerMove(row+1, col+1, 1));
}
    
/**
 * @brief check if playerMove method works properly for X diagonal
 * 
 * @param TicTacToeTestFixture name of the test suite
 * 
 * @param PlayerMoveXDigonalTest of the test
 * 
 */
TEST_F(TicTacToeTestFixture, PlayerMoveXDigonalTest) {
    int row = 1, col = 1;

    EXPECT_EQ(0, game->playerMove(row-1 , col+1, 2));
    EXPECT_EQ(0, game->playerMove(row, col, 2));
    EXPECT_EQ(2, game->playerMove(row+1, col-1, 2));
}

/**
 * @brief check if playerMove method works properly for Rows
 * 
 * @param TicTacToeTestParamPlayerMove name of the test suite
 * 
 * @param PlayerMoveRowTest of the test
 * 
 */
TEST_P(TicTacToeTestParamPlayerMove, PlayerMoveRowTest) {
    int col = 0;
    int row = GetParam();
    EXPECT_EQ(0, game->playerMove(row, col, 1));
    EXPECT_EQ(0, game->playerMove(row, col+1, 1));
    EXPECT_EQ(1, game->playerMove(row, col+2, 1));
}

/**
 * @brief check if playerMove method works properly for Columns
 * 
 * @param TicTacToeTestParamPlayerMove name of the test suite
 * 
 * @param PlayerMoveColTest of the test
 * 
 */
TEST_P(TicTacToeTestParamPlayerMove, PlayerMoveColTest) {
    int row = 0;
    int col = GetParam();

    EXPECT_EQ(0, game->playerMove(row , col, 2));
    EXPECT_EQ(0, game->playerMove(row + 1, col, 2));
    EXPECT_EQ(2, game->playerMove(row + 2, col, 2));
}

INSTANTIATE_TEST_CASE_P(
    TicTacToePlayerMoveParams,
    TicTacToeTestParamPlayerMove,
    ::testing::Values(0,1,2)
    );

/**
 * @brief check if gameManager method works properly
 * 
 * @param TicTacToeTest name of the test suite
 * 
 * @param GameManagerTest name of the test
 * 
 */
TEST_P(TicTacToeTestParamGameManager, GameManagerSigleInputTest) {
    int player = std::get<0>(GetParam());
    int moves = std::get<1>(GetParam());
    ASSERT_FALSE(game->gameManager(moves, player));
}

INSTANTIATE_TEST_CASE_P(
    TicTacToeGameManagerParams,
    TicTacToeTestParamGameManager,
    testing::Combine(
        ::testing::Values(1,2),
        ::testing::Range(1,10))
    );
