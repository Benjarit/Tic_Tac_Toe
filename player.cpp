//
//  player.cpp
//  playground
//
//  Created by Benjarit Hotrabhavananda on 5/9/20.
//  Copyright © 2020 Benjarit Hotrabhavananda. All rights reserved.
//

#include "player.hpp"

Player::Player(int playerId, string name) {
    this->playerId = playerId;
    this->name = name;
}

int Player::getPlayerId() {
    return this->playerId;
}

int Player::getScore() {
    return this->score;
}

string Player::getName() {
    return this->name;
}
