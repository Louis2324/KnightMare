#pragma once
#include <array>
#include <string>
#include "Utils.h"

class Board {
 public: 
    static const int SIZE = 8;
    Board();
     std::string toString() const;
    bool inBounds (int row , int col)const;
    char getPiece (int row , int col)const;
    void setPiece (int row , int col , char piece);
    void reset();
 private:
    std::array<std::array<char,SIZE>,SIZE> grid;
};