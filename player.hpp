#ifndef INC_PLAYER_HPP
#define INC_PLAYER_HPP 1

#include <string>
using namespace std;
class Player{
    public:
        Player();
        Player(string,char);
        char playerSymbol;
        string playerName;
};
#endif