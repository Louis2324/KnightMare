#include "Move.h"
#include <cctype>

Move::Move() :fromRow(-1),fromCol(-1),toRow(-1),toCol(-1),flag(NORMAL),promotionPiece('0'){};
Move::Move(int fr,int fc,int tr , int tc , int f , char promo) 
    :fromRow(fr) , fromCol(fc) , toRow(tr) , toCol(tc) , flag(f) , promotionPiece(promo) {}

bool Move::parseAlgebraic(const std::string& s, Move& out) {
    if (s.size() < 4) return false;
    char fFile = std::tolower(s[0]);
    char fRank = s[1];
    char tFile = std::tolower(s[2]);
    char tRank = s[3];

    if (fFile < 'a' || fFile > 'h' || tFile < 'a' || tFile > 'h') return false;
    if (fRank < '1' || fRank > '8' || tRank < '1' || tRank > '8') return false;

    out.fromCol = fFile - 'a';
    out.toCol = tFile - 'a';
    out.fromRow = 8 - (fRank - '0');
    out.toRow = 8 - (tRank - '0');
    out.flag = NORMAL;

    if (s.size() == 5) {
        out.promotionPiece = std::toupper(s[4]);
        out.flag = PROMOTION;
    }
    return true;
}

std::string Move::toString() const {
    auto colToFile = [](int c) { return char('a' + c); };
    auto rowToRank = [](int r) { return char('0' + (8 - r)); };
    std::string s;
    s += colToFile(fromCol);
    s += rowToRank(fromRow);
    s += colToFile(toCol);
    s += rowToRank(toRow);
    if (flag == PROMOTION) s += std::tolower(promotionPiece);
    return s;
}