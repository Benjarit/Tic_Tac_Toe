#ifndef Game_hpp
#define Game_hpp

#define SIDE 3

#include "board.hpp"
#include "player.hpp"

#endif /* Game_hpp */

enum PlayerType { O = 'O', X = 'X' };
enum PlayerTurn { HUMAN, COMPUTER };

class Game{
    Board *board;
    Player* winner = nullptr;
    PlayerTurn currentPlayer;
    PlayerTurn previousPlayerTurn;
    vector<Player*> players;
    
    bool hasWinner;
    int convertPlayerTurn(PlayerTurn);
public:
    Game(Board *board, vector<Player*> players);
    PlayerTurn getPlayerTurn();
    Board* getBoard();
    Player* getWinner();

    void setWinner(Player* winner);
    void setPlayerTurn(PlayerTurn currentPlayer);
    void printMenus();
    void gameStatus();
    void getUserInput(int spot);
    bool gameOver();
    bool rowCrossed();
    bool columnCrossed();
    bool diagonalCrossed();
};
