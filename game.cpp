#include "game.hpp"
#include <iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
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
}

void Game::run(){
    cout << "Player 1 :" << this->playerList[0].playerName << endl;
    cout << "Player 2 :" << this->playerList[1].playerName << endl;
    this->greeting();
    for(;;){
        this->display();
        this->newTurn();
        if(this->winCheck() || boardFullness >= 9){
            this->display();
            if(boardFullness < 9){
                cout << "The winner is " << this->playerList[this->playingNow].playerName << "." << endl;
                this->round[this->playingNow]++;
            }else{
                cout << "There is no winner this round" << endl;
                this->round[2]++;
            }
            if(!this->newRound()){
                break;
            }
            this->resetBoard();
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
    int index;
    cout << "It's " << this->playerList[this->playingNow].playerName << "'s turn." << endl;
    cout << "Type the index of were you want to place your symbol : ";
    cin >> index;
    while(this->board[index] != ' ' || index < 0 || index > 8 || cin.fail()){
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cout << "You cannot choose to replace the other player symbol nor the index can be >8." << endl;
        cout << "Type the index of were you want to place your symbol : ";
        cin >> index;
    }
    this->board[index] = this->playerList[this->playingNow].playerSymbol;
    this->boardFullness++;
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

bool Game::newRound(){
    char askContinue = 0;
    cout << "Current Score :" << endl;
    cout << this->playerList[0].playerName << " : " << this->round[0] << endl;
    cout << this->playerList[1].playerName << " : " << this->round[1] << endl;
    cout << "Draw : " << this->round[2] << endl;
    do{
    cout << "Continue playing (y/n) : ";
    cin >> askContinue;
    }while(askContinue != 'y' && askContinue != 'n');
    return askContinue == 'y' ? true : false;

}

void Game::resetBoard(){
    for(int i = 0; i < 9; i++){
        this->board[i] = ' ';
    }
    boardFullness = 0;
}
