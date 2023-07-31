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
        bool newRound();
        bool fullBoard();
        void resetBoard();
        
        Player playerList[2];
        unsigned char playingNow = 0;
        unsigned char boardFullness = 0;
        unsigned int round[3] = {0,0,0};
        char board[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};
};


#endif
