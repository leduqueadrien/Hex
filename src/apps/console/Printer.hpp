
#pragma once

#include <string>
#include <vector>
#include <gameUtils.hpp>
#include <windows.h>

#include "PositionSaver.hpp"

#define ESC "\x1b"
#define CSI "\x1b["

class Printer {
  private:
    int m_board_size;
    std::vector<Color> m_board;
    NumTurnSaver m_numTurnSaver;
    PlayerSaver m_playerSaver;
    GetTileSaver m_getTileSaver;
    std::vector<TileSaver> m_boardSaver;
    CONSOLE_SCREEN_BUFFER_INFO m_screenBufferInfo;
    HANDLE m_hOut;

  public:
    Printer(int board_size);
    ~Printer();

    bool setVirtualTerminal();
    void setAlternateBuffer();
    void quitAlternateBuffer();
    void initDisplay();
    void initNumTurn();
    void initPlayer();
    void initBoard();
    void initGetTile();
    COORD getCoord();
    void displayMove(Move move);
    void addMove(Move move);
    std::string displayTile(Color color);
    void displayBoard();
    void displayTurnInfo(int numTurn, Color color);
    void displayLastMove(Move Move);
    void displayWinner(Color color);
    int convertCharToInt(char line);
    Move getPlayerMove();
};
