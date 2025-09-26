#pragma once;
#include <vector>
#include "Move.h"

class ChessGame {
    public:
     ChessGame();
     void printBoard() const;
     void initBoard();
    private:
     std::vector<std::vector<char>> board;
};