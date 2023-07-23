#include "player.hpp"

Player::Player(){
    this->playerName = "n/a";
    this->playerSymbol = 'E';
}

Player::Player(string Name, char Symbol){
    this->playerName = Name;
    this->playerSymbol = Symbol;
}