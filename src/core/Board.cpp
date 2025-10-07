#include "Board.h"
#include <sstream>

Board::Board() {reset();}

bool Board::inBounds(int row , int col)const {
    return row>=0 && row <SIZE && col >=0 && col <SIZE ;
}

char Board::getPiece(int row , int col) const{
    return inBounds(row ,col) ? grid[row][col] : '.';
}

void Board::setPiece(int row , int col , char piece) {
    if(inBounds(row , col)) grid[row][col] = piece;
}

void Board::reset() {
    std::string startPos[8] = {
        "rnbqkbnr",  
        "pppppppp",  
        "........",  
        "........",
        "........",
        "........",
        "PPPPPPPP",  
        "RNBQKBNR"   
    };
    for (int r = 0; r < SIZE; r++)
        for (int c = 0; c < SIZE; c++)
            grid[r][c] = startPos[r][c];
}

std::string Board::toString() const {
    std::ostringstream out;
    for (int r = 0; r < SIZE; r++) {
        for (int c = 0; c < SIZE; c++) {
            out << grid[r][c] << ' ';
        }
        out << '\n';
    }
    return out.str();
}
