//
//  player.hpp
//  playground
//
//  Created by Benjarit Hotrabhavananda on 5/9/20.
//  Copyright © 2020 Benjarit Hotrabhavananda. All rights reserved.
//

#ifndef player_hpp
#define player_hpp
#include "libraries.h"
#endif /* player_hpp */

using namespace std;

class Player{
    int playerId;
    int score;
    string name;
public:
    Player(int playerID, string name);
    
    void setScore(int score);
    int getPlayerId();
    int getScore();
    string getName();
};
