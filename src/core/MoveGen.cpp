#include "MoveGen.h"
#include "Utils.h"

void MoveGen::addPawnMoves(const Board& board, int r, int c, bool white, std::vector<Move>& moves) {
    int dir = white ? -1 : 1;
    int startRow = white ? 6 : 1;
    if (board.inBounds(r + dir, c) && board.getPiece(r + dir, c) == '.')
        moves.emplace_back(r, c, r + dir, c);

    if (r == startRow && board.getPiece(r + dir, c) == '.' && board.getPiece(r + 2 * dir, c) == '.')
        moves.emplace_back(r, c, r + 2 * dir, c);

    for (int dc = -1; dc <= 1; dc += 2) {
        int nr = r + dir, nc = c + dc;
        if (!board.inBounds(nr, nc)) continue;
        char target = board.getPiece(nr, nc);
        if (target != '.' && isWhite(target) != white)
            moves.emplace_back(r, c, nr, nc);
    }
}

void MoveGen::addKnightMoves(const Board& board, int r, int c, bool white, std::vector<Move>& moves) {
    const int dr[8] = {-2,-2,-1,-1,1,1,2,2};
    const int dc[8] = {-1,1,-2,2,-2,2,-1,1};
    for (int i = 0; i < 8; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (!board.inBounds(nr, nc)) continue;
        char target = board.getPiece(nr, nc);
        if (target == '.' || isWhite(target) != white)
            moves.emplace_back(r, c, nr, nc);
    }
}

void MoveGen::addSlidingMoves(const Board& board, int r, int c, bool white,const int dr[], const int dc[], int count, std::vector<Move>& moves) {
    for (int d = 0; d < count; d++) {
        for (int step = 1; step < 8; step++) {
            int nr = r + dr[d] * step, nc = c + dc[d] * step;
            if (!board.inBounds(nr, nc)) break;
            char target = board.getPiece(nr, nc);
            if (target == '.') {
                moves.emplace_back(r, c, nr, nc);
            } else {
                if (isWhite(target) != white)
                    moves.emplace_back(r, c, nr, nc);
                break;
            }
        }
    }
}
