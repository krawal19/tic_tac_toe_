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
 *  @file   main.cpp
 *
 *  @author   Kapil Rawal (kapilrawal1995@gmail.com)
 *
 *  @copyright   BSD License
 *
 *  @brief   main file for tic tac toe game
 *
 *  @section   DESCRIPTION
 *
 *  Starts the tic tac toe game and give instructions to the player 
 *  for proceeding with the game
 *
 */

#include "../include/tic_tac_toe.h"

int main(int argc, char** argv) {
    int grid_size = 1;
    int move_number = 1;
    int toggle = 1;
    int win_flag = false;
    int total_players;
    bool computer_flag = false;
    int player;

    TicTacToe startGame;
    startGame.instructions();
    // Input board size check
    while (grid_size <= 1) {
        std::cout << "  Enter the size of the board (Ex: 3) and press 'ENTER': ";
        std::cin >> grid_size;
        if (grid_size <= 1)
            std::cout << "  Board size invalid, Valid board size are 2,3...!" << std::endl;
    }

    const int total_moves = grid_size*grid_size;
    startGame.initializeGame(grid_size);

    // How many players playing the game
    std::cout << "  Enter total players 1 or 2 :";
    std:: cin >> total_players;
    if (total_players == 1) {
        std::cout << "  Player 2 is Computer!\n" << std::endl;
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
        // Sending moves to the game manager
        if (move_number<= total_moves && move_number > 0
            && startGame.validMove(move_number)) {
            player = toggle == 1 ? 1 : 2;
            win_flag = startGame.gameManager(move_number, player);
            toggle ^= 1;
        } else {
            std::cout << "  Not a vaild move, try different availabe value between 1-" << total_moves << "!" << std::endl;
        }
    }
    std::cout << "\n=============GAME ENDED!=============" << std::endl;
    return 0;
}
