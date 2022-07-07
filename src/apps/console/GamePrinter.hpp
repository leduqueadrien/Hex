
#pragma once

#include <string>
#include <vector>
#include <gameUtils.hpp>

class GamePrinter {
  private:
    int m_board_size;
    std::vector<Color> m_board;

  public:
    GamePrinter(int board_size);
    ~GamePrinter();

    void GamePrinter::addMove(Move move);
    std::string displayTile(Color color);
    void displayBoard();
    void displayTurnInfo(int numTurn, Color color);
    void displayMove(Move Move);
    void displayWinner(Color color);
    Move getPlayerMove();
};
