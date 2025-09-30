#pragma once
#include <vector>
#include "Move.h"

class ChessGame {
    public:
     ChessGame();
     void printBoard() const;
     void initBoard();
     bool makeMove(const Move& m);
     bool inBounds(int r , int c) const {return r>=0 && r<8 && c>= 0 && c<8 ; }
     char getPiece(int r , int c) const {return board[r][c]; }
     void setPiece(int r , int c , char piece);
    private:
     std::vector<std::vector<char>> board;
};