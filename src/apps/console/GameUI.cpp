
#include "GameUI.hpp"
#include <cmath>
#include <sstream>
#include <string>

GameUI::GameUI(std::shared_ptr<Cursor> cursor, int board_size)
    : m_board_size(board_size), m_cursor(cursor) {
    m_cursor->clearScreen();
}

GameUI::~GameUI() {
    m_cursor->quitAlternateBuffer();
}

void GameUI::initDisplay() {
    m_cursor->setPositionToOrigine();
    initNumTurn();
    initPlayer();
    initBoard();
    initLastMove();
    initGetTile();
    displayTurnInfo(1, Color::White);
}

void GameUI::initNumTurn() {
    m_cursor->newLine();
    m_cursor->print("Trun : ");
    m_cursor->saveCursorPosition(m_numTurnSaver);
    m_cursor->newLine();
}

void GameUI::initPlayer() {
    m_cursor->newLine();
    m_cursor->print("Player : ");
    m_cursor->saveCursorPosition(m_playerSaver);
    m_cursor->newLine();
}

void GameUI::initLastMove() {
    m_cursor->newLine();
    m_cursor->saveCursorPosition(m_lastMove);
    m_cursor->newLine();
}

void GameUI::initBoard() {
    m_boardSaver.reserve(m_board_size * m_board_size);
    for (int i = 0; i < m_board_size * m_board_size; ++i)
        m_boardSaver.push_back(TileSaver());

    // On affiche les indicateurs de colonnes
    m_cursor->newLine();
    m_cursor->print("  ");
    int A_hex = 65;
    for (int i = A_hex; i < A_hex + m_board_size; ++i) {
        m_cursor->print(" ");
        m_cursor->print(char(i));
    }

    m_cursor->newLine();

    // On affiche le plateau
    // On affiche la première ligne
    m_cursor->print("  ");
    for (int j = 0; j < m_board_size; ++j) {
        m_cursor->printDrawMode(j == 0 ? 'l' : 'w');
        m_cursor->printDrawMode('q');
    }
    m_cursor->printlnDrawMode('k');

    // On affiche toutes les autres lignes
    for (int i = 0; i < m_board_size; ++i) {
        bool is_last = i == m_board_size - 1;

        // On affiche le numero de la ligne
        if ((i + 1) < 10)
            m_cursor->print(" ");
        m_cursor->print(std::to_string(i + 1));
        // On affiche les espaces pour le décalage entre chaque ligne
        for (int k = i; k > 0; --k)
            m_cursor->print(" ");
        // On affiche la ligne du milieu de la ligne i
        for (int j = 0; j < m_board_size; ++j) {
            m_cursor->printDrawMode('x');
            m_cursor->saveCursorPosition(m_boardSaver.at(i * m_board_size + j));
            m_cursor->print(" ");
        }
        m_cursor->printlnDrawMode('x');

        // On affiche la ligne entre la case i et i+1
        // On affiche les espaces pour le décalage entre chaque ligne
        m_cursor->print("  ");
        for (int k = i; k > 0; --k)
            m_cursor->print(" ");

        for (int j = 0; j < m_board_size; ++j) {
            if (j == 0)
                m_cursor->printDrawMode('m');
            else
                m_cursor->printDrawMode('v');
            m_cursor->printDrawMode(is_last ? 'q' : 'w');
        }
        if (is_last) {
            m_cursor->printlnDrawMode('j');
        } else {
            m_cursor->printDrawMode('v');
            m_cursor->printlnDrawMode('k');
        }
    }
}

void GameUI::initGetTile() {
    m_cursor->newLine();
    m_cursor->saveCursorPosition(m_getTileSaver);
}

std::string GameUI::getTileString(Color color) {
    if (color == Color::White) {
        return "B";
    } else if (color == Color::Black) {
        return "N";
    } else {
        return " ";
    }
}

void GameUI::displayMove(Move move) {
    TileSaver *tile = &(m_boardSaver.at(move.i * m_board_size + move.j));
    tile->setColor(move.color);
    m_cursor->print(getTileString(move.color), *tile);
}

std::string GameUI::getPlayerString(Color color) {
    if (color == Color::White) {
        return "White";
    } else if (color == Color::Black) {
        return "Black";
    } else {
        return "None ";
    }
}

void GameUI::displayTurnInfo(int numTurn, Color color) {
    m_cursor->print(std::to_string(numTurn), m_numTurnSaver);
    m_cursor->print(getPlayerString(color), m_playerSaver);
}

void GameUI::displayLastMove(Move move) {
    std::stringstream ss;
    ss << "player's move : (" << (move.i + 1) << "," << (move.j + 1) << ")";
    m_cursor->println(ss.str(), m_lastMove);
}

void GameUI::displayWinner(Color color) {
    std::string winner;
    if (color == Color::White)
        winner = "White";
    else
        winner = "Black";
    m_cursor->print("Winner : ");
    m_cursor->println(winner);
    m_cursor->waitEnter();
}

int GameUI::convertCharToInt(char line) {
    return (int)(line)-97;
}

Move GameUI::getPlayerMove() {
    Move move;
    std::string message = "Tile coordonate : ";
    std::string output;
    int column;
    output = m_cursor->getString(message, m_getTileSaver);

    column = (int)message.size() + (int)output.size();
    m_cursor->deleteLine(column, m_getTileSaver);

    move.j = convertCharToInt(output.c_str()[0]);
    if (move.j < 0 || move.j > m_board_size)
        move.j = -1;

    try {
        move.i = std::stoi(&(output.c_str()[1])) - 1;
    } catch (const std::invalid_argument &) {
        move.i = -1;
    }

    if (move.i < 0 || move.i > m_board_size)
        move.i = -1;

    return move;
}
