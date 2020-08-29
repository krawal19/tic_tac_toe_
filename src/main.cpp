#include "../include/tic_tac_toe.h"

int main(int argc, char** argv) {
    TicTacToe startGame;
    int grid_size; 
    //  Take grid size input from user 
    // TODO: Add size greater than zero condition
    std::cout << "  Enter the size of the board and press 'ENTER': ";
    std::cin >> grid_size;

    startGame.initializeGame(grid_size);
    std::vector<std::vector<char>> test_grid = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
    
    const int total_moves = grid_size*grid_size;
    int move_number = 1;
    int player, toggle = 1;
    int win_flag = false;

    // Now take input for Grid
    while(!win_flag) { // change the condition later
        std::cout << "  Enter your move number and press 'ENTER': ";
        std::cin >> move_number;
        if (move_number<= total_moves && move_number > 0
            && startGame.validMove(move_number)) {
            player = toggle == 1 ? 1 : 2;
            win_flag = startGame.gameManager(move_number,player);
            toggle ^= 1;
        } else
            std::cout << "  Not a vaild move, try different availabe value between 1-" << total_moves << "!" << std::endl;
    }
    std::cout << "=============GAME ENDED!=============" << std::endl;
    return 0;
}
