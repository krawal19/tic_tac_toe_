#include "../include/tic_tac_toe.h"

int main(int argc, char** argv) {
    TicTacToe startGame;
    int grid_size;
    int move_number = 1;
    int player, toggle = 1;
    int win_flag = false;
    int total_players;
    bool computer_flag = false;

    //  Take grid size input from user
    // Add size greater than zero condition
    std::cout << "  Enter the size of the board and press 'ENTER': ";
    std::cin >> grid_size;

    const int total_moves = grid_size*grid_size;
    startGame.initializeGame(grid_size);
    // std::vector<std::vector<char>> test_grid = {{'1', '2', '3'},
    //                                             {'4', '5', '6'},
    //                                             {'7', '8', '9'}};

    std::cout << "  Enter total players 1 or 2 :";
    std:: cin >> total_players;
    if (total_players == 1) {
        std::cout << "  Player 2 is Computer!" << std::endl;
        computer_flag = true;
    }

    // Now take input for Grid
    while (!win_flag) {
        if (computer_flag && toggle == 0) {
            move_number = startGame.computerMove();
        } else {
            std::cout << "  Enter your move number and press 'ENTER': ";
            std::cin >> move_number;
        }

        if (move_number<= total_moves && move_number > 0
            && startGame.validMove(move_number)) {
            player = toggle == 1 ? 1 : 2;
            win_flag = startGame.gameManager(move_number, player);
            toggle ^= 1;
        } else {
            std::cout << "  Not a vaild move, try different availabe value between 1-" << total_moves << "!" << std::endl;
        }
    }
    std::cout << "=============GAME ENDED!=============" << std::endl;
    return 0;
}
