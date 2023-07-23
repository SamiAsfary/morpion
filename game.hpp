#ifndef HPP_GAME_INC
#define HPP_GAME_INC 1

#include <string>
#include "player.hpp"
using namespace std;

class Game{
    public:
        Game();
        Game(Player, Player);
        void run();
        
    private:
        bool winCheck();
        void display();
        
        Player playerList[2];
        bool playingNow = 0;
        unsigned char round[2];
        char board[9] = {'1','2','3','4','5','6','X',' ','O'};
};


#endif