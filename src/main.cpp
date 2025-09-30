#include <iostream>
#include "ChessGame.h"


int main() {
    ChessGame game;
    std::string input;

    std::cout<<"Welcome to KnightMare CLI chess \n";
    std::cout<<"Initial Board Setup \n\n\n";
    game.printBoard();
    
    while(true) {
        std::cout<<"\n \n \n";
        std::cout<<"Enter your move (e.g,e2e4) or quit: ";
        std::getline(std::cin,input);

        if(input == "quit" || input == "exit" ) break;
        Move m;
        if(!Move::parseAlgebraic(input,m)) {
            std::cout<<"Invalid move format \n Try something like e2e4 initial file and rank then file and rank you want to go to";
            continue;
        }
        if(!game.makeMove(m)) {
            std::cout<<"Move Invalid! Try Again. \n";
            continue;
        }

        game.printBoard();
    }
    return 0;
}