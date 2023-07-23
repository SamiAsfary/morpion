

#include "game.hpp"
#include "player.hpp"
#include <iostream>
using namespace std;
int main(int argc, char *argv[])
{
    string name[2];
    char symbol[2];
    for(int i = 0 ; i < 2 ; i++){
        cout << "Enter your name : ";  
        cin >> name[i];
        cout << "Enter the choosen symbol : ";
        cin >> symbol[i];
    }

    Player player0(name[0],symbol[0]);
    Player player1(name[1],symbol[1]);
    Game game(player0,player1);
    cout << "Hello World !" << std::endl;
    game.run();
    return EXIT_SUCCESS; 
}