
#pragma once

#include <string>
#include <vector>
#include <gameUtils.hpp>

class Printer {
  private:
    int m_board_size;
    std::vector<Color> m_board;

  public:
    Printer(int board_size);
    ~Printer();

    void addMove(Move move);
    std::string displayTile(Color color);
    void displayBoard();
    void displayTurnInfo(int numTurn, Color color);
    void displayMove(Move Move);
    void displayWinner(Color color);
    Move getPlayerMove();
};
