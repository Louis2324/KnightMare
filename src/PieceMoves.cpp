#include "PieceMoves.h"
#include "Move.h"
#include "ChessGame.h"

std::vector<Move> PieceMoves::getPawnMoves(int r, int c, bool white , const ChessGame& game) {
    std::vector <Move> moves;
    int dir = white? -1: 1;

    if(game.inBounds(r + dir,c) && game.getPiece(r+dir,c) == '.') {
        moves.push_back({r,c,r+dir,c});
    }

    if((white && r == 6) || (!white && r == 1)) {
      if (game.getPiece(r + dir, c) == '.' && game.getPiece(r + 2*dir, c) == '.')
        moves.push_back({r,c,r+ 2*dir,c});
    }
   
   if (game.inBounds(r + dir, c - 1) && game.getPiece(r + dir, c - 1) != '.' &&game.isWhite(game.getPiece(r + dir, c - 1)) != white)
        moves.push_back({r, c, r + dir, c - 1});

    if (game.inBounds(r + dir, c + 1) && game.getPiece(r + dir, c + 1) != '.' && game.isWhite(game.getPiece(r + dir, c + 1)) != white)
        moves.push_back({r, c, r + dir, c + 1});

    return moves;
}

std::vector<Move> PieceMoves::getKnightMoves(int r, int c) {
    std::vector<Move> moves;
    int dr[8] = {-2,-2,-1,-1,1,1,2,2};
    int dc[8] = {-1,1,-2,2,-2,2,-1,1};

    for(int i = 0 ; i<8 ; i++) {
        moves.push_back({r,c,r+dr[i],c+dc[i]});
    }
    return moves;
}

std::vector<Move> PieceMoves::getRookMoves(int r, int c) {
    std::vector<Move> moves;
    int dr[4] = {-1,1,0,0};
    int dc[4] = {0,0,-1,1};

    for(int d = 0 ; d < 8 ; d++) {
        for(int step =1 ; step<8 ; step++) {
            moves.push_back({r,c,r+ dr[d] * step, c + dc[d]*step});
        }
    }
    return moves;
}

std::vector<Move> PieceMoves::getBishopMoves(int r , int c) {
    std::vector<Move> moves;
    int dr[4] = {-1,-1,1,1};
    int dc[4] = {-1,1,-1,1};

    for(int d = 0 ; d<4 ; d++) {
        for(int step = 1 ; step < 8 ; step++) {
            moves.push_back({r,c,r+dr[d]*step,c+dc[d]*step});
        }
    }
    return moves;
}

std::vector<Move> PieceMoves::getQueenMoves(int r , int c) {
    std::vector<Move> moves;
    std::vector<Move> rookMoves = PieceMoves::getRookMoves(r,c);
    std::vector<Move> bishopMoves = PieceMoves::getBishopMoves(r,c);

    moves.insert(moves.end(),rookMoves.begin(),rookMoves.end());
    moves.insert(moves.end(),bishopMoves.begin(),bishopMoves.end());
    return moves;
}

std::vector<Move> PieceMoves::getKingMoves(int r , int c) {
    std::vector<Move> moves;
    int dr[8] = {-1,-1,-1,0,0,1,1,1};
    int dc[8] = {-1,0,1,-1,1,-1,0,1};

    for(int i = 0 ; i<8 ; i++) {
        moves.push_back({r,c,r+dr[i],c+dc[i]});
    }
    return moves;
}