
#pragma once

#include <gameUtils.hpp>
#include <memory>
#include <string>
#include <vector>
#ifdef _WIN32
#include <Windows.h>
#endif

#include "Cursor.hpp"
#include "PositionSaver.hpp"

class GameUI {
private:
    int m_board_size;
    std::vector<Color> m_board;
    PositionSaver m_numTurnSaver;
    PositionSaver m_playerSaver;
    PositionSaver m_getTileSaver;
    PositionSaver m_lastMove;
    std::vector<TileSaver> m_boardSaver;
    std::shared_ptr<Cursor> m_cursor;

public:
    GameUI(std::shared_ptr<Cursor> cursor, int board_size);
    ~GameUI();

    void initDisplay();
    void initNumTurn();
    void initLastMove();
    void initPlayer();
    void initBoard();
    void initGetTile();
    void displayMove(Move move);
    void addMove(Move move);
    std::string displayTile(Color color);
    void displayBoard();
    void displayTurnInfo(int numTurn, Color color);
    void displayLastMove(Move Move);
    void displayWinner(Color color);
    int convertCharToInt(char line);
    std::string getPlayerString(Color color);
    std::string getTileString(Color color);
    Move getPlayerMove();
};
