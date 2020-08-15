//
//  main.cpp
//  playground
//
//  Created by Benjarit Hotrabhavananda on 1/21/20.
//  Copyright © 2020 Benjarit Hotrabhavananda. All rights reserved.
//

#include "game.hpp"

# define SIDE 3

pair<int,int> findIndexofNumbersThatSum(int* numbers, int sum);
int findDifferenceOfMaxAndMinInTheArray(int* number);
Game* initializeGame(vector<Player*>, Board*);
char** createBoard(void);
void getUserInput(unsigned short *spot);
void displayPlayerTurn(PlayerTurn playerTurn);

int main(int argc, const char * argv[]) {
    /*
        int test[] = {5, 9, 10, 20, 30};
        cout << findIndexofNumbersThatSum(test, 40).first << endl;
        cout << findIndexofNumbersThatSum(test, 40).second << endl;
     */
    
    /* int* x = new int[6];
        x[0] = 5;
        x = x+1;
        x[0] = 30;
        x[1] = 20;
        x[2] = 40;
        x[3] = 70;
        x[4] = 45;
        int result = findDifferenceOfMaxAndMinInTheArray(x);
        cout << result << endl;
        x = x-1;
        delete[] x;
        x = nullptr;
     */
    
    /* ******** TikTacToe Game ********** */
    srand(static_cast<unsigned int>(time(nullptr)));
    Player *player1 = new Player(PlayerTurn::HUMAN, "Ben");
    Player *player2 = new Player(PlayerTurn::COMPUTER, "Kevin");
    vector<Player*> players = {player1, player2};
    Board *board = new Board(createBoard());
    Game *game = initializeGame(players, board);
    
    /* Game loop */
    unsigned short spot = 0, moveCount = 0;
    while (!game->gameOver() && moveCount != SIDE * SIDE) {
        displayPlayerTurn(game->getPlayerTurn());
        getUserInput(&spot);
        game->getUserInput(spot);
        game->getBoard()->printBoard();
        moveCount++;
    }
    cout << "Congratuations, " << game->getWinner()->getName() << "!!" << endl;
    cout << "You the winnter!" << endl;
    
    return 0;
}

pair<int,int> findIndexofNumbersThatSum(int* numbers, int sum) {
    unordered_map<int, int> temp;
    for (int x = 0; x < 5; ++x){
        int diff = sum - numbers[x];
        if (temp.find(diff) != temp.end()) {
            return make_pair(x,temp[diff]);
        }
        temp.insert({numbers[x], x});
    }
    return {-1,-1};
}

int findDifferenceOfMaxAndMinInTheArray(int* numbers) {
    int count = numbers[-1];
    int max = numbers[0], min = numbers[0];
    for (int x = 1; x < count; x++) {
        if (max < numbers[x]) {
            max = numbers[x];
        }
        if (min > numbers[x]) {
            min = numbers[x];
        }
    }
    return max - min;
}

Game* initializeGame(vector<Player*> players, Board* board) {
    Game* game = new Game(board,players);
    return game;
}

char** createBoard(void) {
    char **board = new char* [3];
    for (int i=0; i<3; i++) {
        board[i] = new char[3];
    }
    
    board[0][0] = '1';
    board[0][1] = '2';
    board[0][2] = '3';
    board[1][0] = '4';
    board[1][1] = '5';
    board[1][2] = '6';
    board[2][0] = '7';
    board[2][1] = '8';
    board[2][2] = '9';
    
    return board;
}

void getUserInput(unsigned short *spot) {
    cout << "Enter spot: ";
    cin >> *spot;
}

void displayPlayerTurn(PlayerTurn playerTurn) {
    bool playerType = playerTurn == PlayerTurn::HUMAN;
    cout << (playerType ? "HUMAN" : "COPUTER") << endl;
}
