#ifndef HPP_PLAYER_INC
#define HPP_PLAYER_INC 1

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