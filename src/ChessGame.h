#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
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
     
     bool isWhite(char piece) const;
     std::vector<Move> getAllLegalMoves(bool whiteTurn) const;
     bool isValidMove(const Move&m , bool whiteTurn ) const;
     bool makeRandomMove( bool whiteTurn);
    private:
     std::vector<std::vector<char>> board;
     bool pathClear(int fr, int fc , int tr , int tc) const;
};