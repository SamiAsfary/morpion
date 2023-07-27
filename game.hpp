#ifndef INC_GAME_HPP
#define INC_GAME_HPP 1

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
        void newTurn();
        void display();
        void greeting();
        
        Player playerList[2];
        char playingNow = 0;
        unsigned char round[2];
        char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
};


#endif