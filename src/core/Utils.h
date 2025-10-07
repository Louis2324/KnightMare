#pragma once
#include <cctype>

inline bool isWhite(char piece) {
    return std::isupper(piece);
}
inline bool isBlack(char piece) {
    return std::islower(piece);
}
inline bool isEmpty(char piece) {
    return piece == '.';
}
