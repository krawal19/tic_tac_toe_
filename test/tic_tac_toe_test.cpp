#include <gtest/gtest.h>
#include "../include/tic_tac_toe.h"

TEST(TicTacToeTest, GameManagerTest) {
    TicTacToe* game = new TicTacToe();
    int grid_size = 3, index = 1, toggle = 1;
    std::vector<int> moves{1, 2, 4, 5, 8, 6, 3, 7, 9};
    int player;

    game->initializeGame(grid_size);

    for(int i = 0; i < moves.size()-1; ++i) {
        player = toggle == 1 ? 1 : 2;
        EXPECT_EQ(false, game->gameManager(moves[i], player));
        toggle ^=1;
    }
    EXPECT_EQ(true, game->gameManager(moves.size(), 1));
}

TEST(TicTacToeTest, InitializeGameTest) {
    TicTacToe* game = new TicTacToe();

    int grid_size = 3, initial_diag = 0;
    game->initializeGame(grid_size);

    EXPECT_EQ(grid_size, game->getGridSize());

    EXPECT_EQ(grid_size, game->getGridDisp().size());
    EXPECT_EQ(grid_size, game->getGridDisp()[0].size());

    EXPECT_EQ(grid_size, game->getRows().size());
    EXPECT_EQ(grid_size, game->getCols().size());

    EXPECT_EQ(initial_diag, game->getDiag());
    EXPECT_EQ(initial_diag, game->getXDiag());
}

TEST(TicTacToeTest, ValidMoveTest) {
    TicTacToe* game = new TicTacToe();
    int index_invalid = 1, index_valid = 5;
    std::set<int> test_set;
    test_set.insert(index_invalid);
    game->setIndexOccupied(test_set);

    EXPECT_EQ(false, game->validMove(index_invalid));
    EXPECT_EQ(true, game->validMove(index_valid));
}

TEST(TicTacToeTest, PlayerMoveTest) {
    TicTacToe* game = new TicTacToe();
    int grid_size = 3, row = 1, col = 1;
    int diag = 0, xdiag = 0, win = 0;
    std::vector<int> rows(grid_size);
    std::vector<int> cols(grid_size);

    game->setGridSize(grid_size);
    game->setRows(rows);
    game->setCols(cols);
    game->setDiag(diag);
    game->setXDiag(xdiag);
    
    EXPECT_EQ(0, game->playerMove(row-1,col-1,1));
    EXPECT_EQ(0, game->playerMove(row,col,1));
    EXPECT_EQ(1, game->playerMove(row+1,col+1,1));
}

TEST(TicTacToeTest, ComputerMoveTest) {
    TicTacToe* game = new TicTacToe();
    int grid_size = 3, index = 1;
    std::set<int> test_set;
    game->setGridSize(grid_size);
    test_set.insert(index);
    game->setIndexOccupied(test_set);
    EXPECT_NE(index, game->computerMove());
}
