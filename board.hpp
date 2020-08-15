//
//  Board.hpp
//  playground
//
//  Created by Benjarit Hotrabhavananda on 5/9/20.
//  Copyright © 2020 Benjarit Hotrabhavananda. All rights reserved.
//

#ifndef Board_hpp
#define Board_hpp
#include "libraries.h"
#endif /* Board_hpp */

using namespace std;

class Board{
    char **board;
public:
    Board(char **board);
    set<pair<short,short>> getOpenningSpots();
    
    char** getBoard();
    void printBoard();
};
