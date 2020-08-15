//
//  Board.cpp
//  playground
//
//  Created by Benjarit Hotrabhavananda on 5/9/20.
//  Copyright © 2020 Benjarit Hotrabhavananda. All rights reserved.
//

#include "board.hpp"

Board::Board(char **board) {
    this->board = board;
}

void Board::printBoard() {
    printf("\n\n");
      
    cout << "\t\t\t  " <<  this->board[0][0] << " | " <<  this->board[0][1] << " | " << this->board[0][2] << "  \n";
    cout << "\t\t\t-------------\n";
    cout << "\t\t\t  " <<  this->board[1][0] << " | " <<  this->board[1][1] << " | " << this->board[1][2] << "  \n";
    cout << "\t\t\t-------------\n";
    cout << "\t\t\t  " <<  this->board[2][0] << " | " <<  this->board[2][1] << " | " << this->board[2][2] << "  \n\n";
}

set<pair<short,short>> Board::getOpenningSpots() {
    set<pair<short,short> > openningSpots;
    for (short x = 0; x < 3; x++) {
        for (short y = 0; y < 3; y++) {
            if (!isdigit(this->board[x][y])) {
                openningSpots.insert({x,y});
            }
        }
    }
    return openningSpots;
}

char** Board::getBoard() {
    return this->board;
}
