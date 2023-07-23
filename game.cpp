#include "game.hpp"
#include <iostream>
using namespace std;

Game::Game(){
    this->playingNow = 0;
    this->round[0] = -1;
    this->round[1] = -1;
}

Game::Game(Player player0, Player player1){
    this->playerList[0] = player0;
    this->playerList[1] = player1;
    this->playingNow = 0;
    this->round[0] = 0;
    this->round[1] = 0;
}

void Game::run(){
    cout << "Player 1 :" << this->playerList[0].playerName << endl;
    cout << "Player 2 :" << this->playerList[1].playerName << endl;

    this->display();
}

void Game::display(){
    cout << "Board State : " << endl;
    cout << "+-+-+-+" << endl;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cout << "|" << this->board[i*3+j];
        }
        cout << "|" << endl;
        cout << "+-+-+-+" << endl;
    }
    cout << "Current player : " << this->playerList[this->playingNow].playerName;
}