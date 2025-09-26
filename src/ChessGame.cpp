#include "ChessGame.h"
#include <iostream>

ChessGame::ChessGame() {
    initBoard();
}

void ChessGame::initBoard () {
    board = {
        {'r','n','b','q','k','b','n','r'},
        {'p','p','p','p','p','p','p','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'P','P','P','P','P','P','P','P'},
        {'R','N','B','Q','K','B','N','R'}
    };
}

void ChessGame::printBoard() const {
    for(int i=0 ; i<8 ; i++) {
        std::cout<< 8-i << " ";
        for(int j=0 ; j<8 ; j++) 
            std::cout << board[i][j] << " ";
        std::cout<<"\n";
    }
    std::cout<<"  a b c d e f g h \n";
}