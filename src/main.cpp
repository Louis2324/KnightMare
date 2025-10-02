#include <iostream>
#include "ChessGame.h"

int main() {
    ChessGame game;
    std::string input;
    bool whiteTurn = true , gameOver = false;

    std::cout << "Welcome to KnightMare CLI Chess\n";
    std::cout << "Initial Board Setup\n\n";
    game.printBoard();

    while (!gameOver) {
        std::cout << "\n";

        if (whiteTurn) {
            std::cout << "Enter your move (e.g., e2e4) or 'quit': ";
            std::getline(std::cin, input);

            if (input == "quit" || input == "exit")
                break;

            Move m;
            if (!Move::parseAlgebraic(input, m)) {
                std::cout << "Invalid move format! Use something like e2e4.\n";
                continue;
            }

            if (!game.makeMove(m,whiteTurn)) {
                std::cout << "Illegal move! Try again.\n";
                continue;
            }

            std::cout << "You played: " << input << "\n";
            game.printBoard();
        } else {
            std::cout << "Black is thinking...\n";
            if (!game.makeRandomMove(false)) {
                std::cout << "Black has no legal moves! Game over.\n";
                break;
            }
            game.printBoard();
        }

        whiteTurn = !whiteTurn; 
        if(game.isCheckMate(whiteTurn)) {
            std::cout<< (whiteTurn?"White" : "Black") << "is checkmated! \n";
            std::cout<< (whiteTurn?"Black":"White") << " loses \n";
            gameOver = true;
        }

        if(game.isStaleMate(whiteTurn)) {
            std::cout<< "Stalemate it's a draw \n";
            gameOver = true;
        }
    }

    std::cout << "Thanks for playing against KnightMare!\n";
    return 0;
}
