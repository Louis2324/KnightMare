#pragma once
#include <string>

struct Move {
    int fromRow,fromCol;
    int toRow, toCol;
    Move(): fromRow(-1) , fromCol(-1) , toRow(-1) , toCol(-1) {};
    Move(int fr , int fc , int tr , int tc) 
     :fromRow(fr), fromCol(fc), toRow(tr), toCol(tc) {};
    static bool parseAlgebraic(const std::string& s, Move& out);
    std::string toString() const;
};