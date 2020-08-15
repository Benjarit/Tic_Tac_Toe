#include "game.hpp"

Game::Game(Board *board, vector<Player*> players){
    this->currentPlayer = PlayerTurn::HUMAN;
    this->board = board;
    this->players = players;
    this->board->printBoard();
}

Board* Game::getBoard() {
    return this->board;
}

Player* Game::getWinner() {
    return this->winner;
}

void Game::setWinner(Player* winner) {
    this->winner = winner;
}

void Game::setPlayerTurn(PlayerTurn currentPlayer){
    this->currentPlayer = currentPlayer;
}

void Game::getUserInput(int spot) {
    short x = 0;
    short y = 0;
    
    switch (spot) {
        case 1:
        case 2:
        case 3:
            x = 0;
            y = (spot-1);
            break;
        case 4:
            x = 1;
            y = 0;
            break;
        case 5:
            x = 1;
            y = 1;
            break;
        case 6:
            x = 1;
            y = 2;
            break;
        case 7:
            x = 2;
            y = 0;
            break;
       case 8:
            x = 2;
            y = 1;
            break;
       case 9:
            x = 2;
            y = 2;
            break;
    }
    bool duplicateFlag = false;
    for (auto elem : this->board->getOpenningSpots())
    {
        if (make_pair(x,y) == elem) {
            duplicateFlag = true;
        }
    }
    if (duplicateFlag == false) {
        this->board->getBoard()[x][y] = this->currentPlayer == PlayerTurn::HUMAN ? PlayerType::O : PlayerType::X;
        this->previousPlayerTurn = this->currentPlayer;
        this->currentPlayer = this->currentPlayer == PlayerTurn::HUMAN ? PlayerTurn::COMPUTER : PlayerTurn::HUMAN;
    } else {
        cout << "This spot is already taken." << endl;
    }
}

bool Game::gameOver() {
    if (this->rowCrossed() || this->columnCrossed() || this->diagonalCrossed()) {
        this->setWinner(this->players[this->convertPlayerTurn(this->previousPlayerTurn)]);
        return true;
    }
    return false;
}

// A function that returns true if any of the row
// is crossed with the same player's move
bool Game::rowCrossed() {
    for (int i = 0 ; i < SIDE; i++)
    {
        if (this->board->getBoard()[i][0] == this->board->getBoard()[i][1] &&
            this->board->getBoard()[i][1] == this->board->getBoard()[i][2] &&
            !isdigit(this->board->getBoard()[i][0])) {
            return true;
        }
    }
    
    return false;
}
  
// A function that returns true if any of the column
// is crossed with the same player's move
bool Game::columnCrossed() {
    for (int i = 0; i < SIDE; i++)
    {
        if (this->board->getBoard()[0][i] == this->board->getBoard()[1][i] &&
            this->board->getBoard()[1][i] == this->board->getBoard()[2][i] &&
            !isdigit(this->board->getBoard()[0][i])) {
            return true;
        }
    }
    
    return false;
}
  
// A function that returns true if any of the diagonal
// is crossed with the same player's move
bool Game::diagonalCrossed() {
    if (this->board->getBoard()[0][0] == this->board->getBoard()[1][1] &&
        this->board->getBoard()[1][1] == this->board->getBoard()[2][2] &&
        !isdigit(this->board->getBoard()[0][0])) {
        return true;
    }
          
    if (this->board->getBoard()[0][2] == this->board->getBoard()[1][1] &&
        this->board->getBoard()[1][1] == this->board->getBoard()[2][0] &&
        !isdigit(this->board->getBoard()[0][2])) {
        return true;
    }
  
    return false;
}

PlayerTurn Game::getPlayerTurn() {
    return this->currentPlayer;
}

int Game::convertPlayerTurn(PlayerTurn playerTurn) {
    if (playerTurn == PlayerTurn::HUMAN) {
        return 0;
    } else {
        return 1;
    }
}
