#pragma once
#include <string>

enum MoveFlag {
    NORMAL = 0,
    PROMOTION = 1,
    CASTLING = 2,
    EN_PASSANT = 3
};

struct Move {
    int fromRow , fromCol ;
    int toRow , toCol;
    char promotionPiece;
    int flag;

    Move();
    Move(int fr , int fc , int tr , int tc , int f = NORMAL , char promotionPiece = '\0');
    
    static bool parseAlgebraic (const std::string& s , Move& out);
    std::string toString() const;
};
