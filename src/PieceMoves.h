#pragma once
#include <vector>
#include "Move.h"

class PieceMoves {
    public: 
    static std::vector<Move> getPawnMoves(int r, int c, bool white);
    static std::vector<Move> getRookMoves(int r, int c);
    static std::vector<Move> getKnightMoves(int r, int c);
    static std::vector<Move> getBishopMoves(int r, int c);
    static std::vector<Move> getQueenMoves(int r, int c);
    static std::vector<Move> getKingMoves(int r, int c);
};