#include <iostream>
#include "ChessGame.h"
using namespace std;

int main() {
    ChessGame game;

    cout<<"Welcome to KnightMare CLI chess \n";
    cout<<"Initial Board Setup \n\n\n";

    game.printBoard();
    return 0;
}