#include "Move.h"
#include <cctype>

bool Move::parseAlgebraic(const std::string& s , Move& out) {
    if(s.size()!=4) return false;
    char fFile = std::tolower(s[0]);
    char fRank = s[1];
    char tFile = std::tolower(s[2]);
    char tRank = s[3];

    if(fFile<'a' || fFile> 'h') return false;
    if(tFile<'a' || tFile> 'h') return false;
    if(fRank<'1' || fRank >'8') return false;
    if(tRank<'1' || tRank>'8') return false;

    out.fromCol = fFile - 'a';
    out.toCol = fFile - 'a';
    out.fromRow = 8 - (fRank - '0');
    out.toRow = 8 - (tRank - '0');
    return true;
}

std::string Move::toString() const {
    auto colToFile = [](int c) {return char ('a' + c) ;};
    auto rowToRank = [](int r) {return char ('0' + (8-r)) ;};
    std:: string s;
    s+=colToFile(fromCol);
    s+=rowToRank(fromRow);
    s+=colToFile(toCol);
    s+=rowToRank(toRow);
    return s;
}