#include "ChessGame.h"
#include "PieceMoves.h"
#include "Move.h"
#include <iostream>

ChessGame::ChessGame() {
    initBoard();
}

void ChessGame::initBoard () {
    board = {
        {'r','n','b','q','k','b','n','r'},
        {'p','p','p','p','p','p','p','p'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'.','.','.','.','.','.','.','.'},
        {'P','P','P','P','P','P','P','P'},
        {'R','N','B','Q','K','B','N','R'}
    };
}

void ChessGame::printBoard() const {
    for(int i=0 ; i<8 ; i++) {
        std::cout<< 8-i << "  ";
        for(int j=0 ; j<8 ; j++) 
            std::cout << getPiece(i,j) << " ";
        std::cout<<"\n";
    }
    std::cout<<"   a b c d e f g h \n";
}

bool ChessGame::makeMove(const Move& m) {
    if(!inBounds(m.fromRow , m.fromCol) || !inBounds(m.toRow,m.toCol)) return false;
    char piece = getPiece(m.fromRow,m.fromCol);
    if(piece == '.') return false;

    setPiece(m.toRow , m.toCol , piece);
    setPiece(m.fromRow , m.fromCol , '.');
    return true;
}

void ChessGame::setPiece(int r, int c, char piece) {
    if(!inBounds(r, c)) return; 
    board[r][c] = piece;
}

bool ChessGame::isWhite(char piece)const {
    if(piece == '.') return false;
    return std::isupper(static_cast<unsigned char>(piece));
}

bool ChessGame::pathClear(int fr, int fc, int tr, int tc)const {
    int dr = (tr > fr) ? 1 : (tr < fr)? -1 : 0; 
    int dc = (tc > fc) ? 1 : (tc < fc)? -1 : 0; 

    int r = fr + dr;
    int c = fc + dc;

    while(r != tr || c != tc) {
        if(!inBounds(r,c)) return false;
        if(getPiece(r,c) != '.') return false;
        r+=dr;
        c+=dc;
    }

    return true;
}

bool ChessGame::isValidMove(const Move&m , bool whiteTurn )const {
    if(!inBounds(m.toRow , m.toCol)) return false;
    char piece = getPiece(m.fromRow , m.fromCol);
    if(piece == '.') return false;
    if(whiteTurn && !isWhite(piece)) return false;
    if(!whiteTurn && isWhite(piece)) return false;
    char target = getPiece(m.toRow , m.toCol);
    if(target !='.' && isWhite(piece) == isWhite(target)) return false;

    std::vector<Move> possible;
    switch(std::tolower(piece)) {
        case 'p' : possible = PieceMoves::getPawnMoves(m.fromRow,m.fromCol,isWhite(piece)); break;
        case 'r' : possible = PieceMoves::getRookMoves(m.fromRow,m.fromCol); break;
        case 'n' : possible = PieceMoves::getKnightMoves(m.fromRow,m.fromCol); break;
        case 'b' : possible = PieceMoves::getBishopMoves(m.fromRow,m.fromCol); break;
        case 'q' : possible = PieceMoves::getQueenMoves(m.fromRow,m.fromCol); break;
        case 'k' : possible = PieceMoves::getKingMoves(m.fromRow,m.fromCol); break;
    }

    for(auto& move : possible) {
        if(move.toRow == m.toRow && move.toCol == m.toCol) {
            if(std::tolower(piece) == 'r' || std::tolower(piece) == 'b' || std::tolower(piece) == 'q'){
               if(!pathClear(m.fromRow,m.fromCol,m.toRow,m.toCol)) return false;
            }
            return true;
        }
    }
    return false;
  }

std::vector<Move> ChessGame::getAllLegalMoves(bool whiteTurn) const {
    std::vector<Move> allMoves;
    for(int r = 0 ; r<8 ; r++) {
        for (int c = 0 ; c<8 ; c++) {
            char piece = getPiece(r,c);
            if(piece == '.') continue;
            if(whiteTurn != isWhite(piece)) continue;
            std::vector<Move> pieceMoves;
            switch (std::tolower(piece)) {
                case 'p': pieceMoves = PieceMoves::getPawnMoves(r,c,isWhite(piece)); break;
                case 'n': pieceMoves = PieceMoves::getKnightMoves(r,c); break;
                case 'r': pieceMoves = PieceMoves::getRookMoves(r,c); break;
                case 'b': pieceMoves = PieceMoves::getBishopMoves(r,c); break;
                case 'q': pieceMoves = PieceMoves::getQueenMoves(r,c); break;
                case 'k': pieceMoves = PieceMoves::getKingMoves(r,c); break;
            }

            for(auto& m : pieceMoves) {
                if(isValidMove(m , whiteTurn)) allMoves.push_back(m);
            }
        }
    }
    return allMoves;
  }

bool ChessGame::makeRandomMove( bool whiteTurn)  {
    auto moves = getAllLegalMoves(whiteTurn);
    if(moves.empty()) {
        std::cout<<(whiteTurn?"White":"Black")  <<" Has no legal moves";
        return false;
    }

    int idx = std::rand() % moves.size();
    Move chosen = moves[idx];

    
    std::cout << (whiteTurn ? "White" : "Black")
              << " AI plays:" << chosen.toString() <<"\n";
    return makeMove(chosen);
} 