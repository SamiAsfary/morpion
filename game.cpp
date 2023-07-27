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
    this->greeting();
    for(;;){
        this->display();
        this->newTurn();
        if(this->winCheck()){
            this->display();
            cout << "The winner is " << this->playerList[this->playingNow].playerName << "." << endl;
            break;
        }
        this->playingNow = (this->playingNow+1)%2;
    }
    
}

void Game::greeting(){
    cout << "Greeting to you " << this->playerList[0].playerName << " and to you too " << this->playerList[1].playerName << endl;
    cout << "Each round you will select the index where you want to put your symbol on the board. The index are as follow :" << endl;
    cout << "+-+-+-+" << endl;
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < 3;j++){
            cout << "|" << i*3+j;
        }
        cout << "|" << endl;
        cout << "+-+-+-+" << endl;
    }
    cout << endl;
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
}

void Game::newTurn(){
    unsigned int index;
    cout << "It's " << this->playerList[this->playingNow].playerName << "'s turn." << endl;
    cout << "Type the index of were you want to place your symbol : ";
    cin >> index;
    while(this->board[index] != ' ' || index > 8){
        cout << "You cannot choose to replace the other player symbol nor the index can be >8." << endl;
        cout << "Type the index of were you want to place your symbol : ";
        cin >> index;
    }
    this->board[index] = this->playerList[this->playingNow].playerSymbol;

}

bool Game::winCheck(){
    int i;
    for(i = 0; i<9;i+=3){
        if(this->board[i] != ' '){
            if(this->board[i] == this->board[i+1] && this->board[i] == this->board[i+2]){
                return true;
            }
        }
    }

    for(i = 0; i<3;i+=1){
        if(this->board[i] != ' '){
            if(this->board[i] == this->board[i+3] && this->board[i] == this->board[i+6]){
                return true;
            }
        }
    }

    if(this->board[4] != ' '){
        if((this->board[4] == this->board[0] && this->board[4] == this->board[8]) || (this->board[4] == this->board[2] && this->board[4] == this->board[6])){
            return true;
        }
    }

    return false;
}