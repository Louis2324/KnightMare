#pragma once
#include <vector>
#include "Move.h"
#include "Board.h"

class MoveGen {
public:
    static std::vector<Move> generatePieceMoves(const Board& board, int row, int col);
    static std::vector<Move> generateAllMoves(const Board& board, bool whiteToMove);

private:
    static void addPawnMoves(const Board& board, int r, int c, bool white, std::vector<Move>& moves);
    static void addKnightMoves(const Board& board, int r, int c, bool white, std::vector<Move>& moves);
    static void addSlidingMoves
    (const Board& board, int r, int c, bool white, const int dr[], const int dc[], int count, std::vector<Move>& moves);
};
