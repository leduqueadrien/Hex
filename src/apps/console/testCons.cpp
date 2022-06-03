
#include "ConsoleUI.hpp"
#include <hexGame/Board.hpp>
#include <hexGame/IterBoard.hpp>
#include <hexGame/IterNeighbour.hpp>
#include <hexGame/gameUtils.hpp>
#include <iostream>

int main() {
    Board board(3);

    ConsoleUI console;

    console.displayBoard(&board);

    board.addMoveToBoard(Move(Color::White, 0, 0));
    board.addMoveToBoard(Move(Color::Black, 0, 1));
    board.addMoveToBoard(Move(Color::Black, 1, 0));

    console.displayBoard(&board);

    IterNeighbour itN(&board, 0, 0);

    for (itN.begin(); *itN != itN.end(); ++itN) {
        std::cout << "i:" << (**itN).getI() << " j:" << (**itN).getJ()
                  << " color:" << (**itN).getColor() << std::endl;
    }
}