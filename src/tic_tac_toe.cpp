#include "../include/tic_tac_toe.h"

TicTacToe::TicTacToe() {
}

TicTacToe::~TicTacToe() {}

void TicTacToe::initializeGame(const int &grid_size_){
    this->grid_size_ = grid_size_;
    grid_disp_.resize(grid_size_);
    for(int i = 0; i < grid_size_; ++i) grid_disp_[i].resize(grid_size_);
    rows_.resize(grid_size_);
    cols_.resize(grid_size_);
    diag_ = 0;
    xdiag_ = 0;
}

void TicTacToe::displayBoard(const int &grid_size_, const std::vector<std::vector<char>> &grid_disp_) {
    //Display board
    for(int i = 0; i < grid_size_; ++i) {
        printf(" ");
        for(int j = 0; j < grid_size_; ++j) printf(" | %c ", grid_disp_[i][j]);
        printf(" |\n");
    }
    std::cout << "\n" << std::endl;
}

bool TicTacToe::validMove(int index) {
    if (indexOccupied_.find(index) != indexOccupied_.end()) return false;
    return true;
}

int TicTacToe::playerMove(const int &row,const int &col,const int &player) {
    int count  = player == 1 ? 1 : -1;
    
    rows_[row] += count;
    cols_[col] += count;
    
    // Keeping diagonal count
    if (row == col) diag_+=count; 
    if (row + col == grid_size_-1) xdiag_+=count;
    
    if (rows_[row] == grid_size_ || cols_[col] == grid_size_ || 
        diag_ == grid_size_ || xdiag_ == grid_size_) 
            return count > 0 ? 1 : 2;
    return 0;
}

bool TicTacToe::gameManager(int index, int &player) {
    indexOccupied_.insert(index);
    // converting 1d to 2d 
    int move_x = 0, move_y = 0;
    move_x = (index-1) / grid_size_;
    move_y = (index-1) % grid_size_;
    grid_disp_[move_x][move_y] = player == 1 ? 'X':'O';
    std::cout << "  Player " << player << " entered '"<< grid_disp_[move_x][move_y] << "' at index " << index << std::endl;
    displayBoard(grid_size_, grid_disp_);
    int winner =  playerMove(move_x, move_y, player);

    if (winner != 0) {
        std::cout << "\n   Player " << winner << " Won! " << std::endl;
        return true;
    }
    if (indexOccupied_.size() == grid_size_ * grid_size_ && winner == 0) {
        std::cout << "  Game Draw!" << std::endl;
        return true;
    }
    return false;
}

// TODO
// either intialze in the function or use as it is choose one 
// Add grid size greater than zero condition