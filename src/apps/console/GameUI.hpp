
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

/**
 * @brief Class for print the game
 */
class GameUI {
private:
    
    /**
     * @brief Board size of the game
     */
    int m_board_size;
    
    /**
     * @brief Board to store the color of each Tile
     */
    std::vector<Color> m_board;
    
    /**
     * @brief Position where to print the turn number
     */
    PositionSaver m_numTurnSaver;
    
    /**
     * @brief Position where to print the player turn
     */
    PositionSaver m_playerSaver;
    
    /**
     * @brief Position where to get the user input
     */
    PositionSaver m_getTileSaver;
    
    /**
     * @brief Position where to print the last move played
     */
    PositionSaver m_lastMove;
    
    /**
     * @brief Position where to print eache Tile
     */
    std::vector<TileSaver> m_boardSaver;
    
    /**
     * @brief Cursor to print on the screen
     */
    std::shared_ptr<Cursor> m_cursor;

public:
    
    /**
     * @brief Construct a new Game UI object
     * @param cursor Cursor of the screen
     * @param board_size Board size
     */
    GameUI(std::shared_ptr<Cursor> cursor, int board_size);
    
    /**
     * @brief Destroy the Game U I object
     */
    ~GameUI();
    
    /**
     * @brief Initialize the screen
     */
    void initDisplay();
    
    /**
     * @brief Initialize the turn number display
     */
    void initNumTurn();
    
    /**
     * @brief Initialize the last move display
     */
    void initLastMove();
    
    /**
     * @brief Initialize the player display
     */
    void initPlayer();
    
    /**
     * @brief Initialize the board display
     */
    void initBoard();
    
    /**
     * @brief Iinitialize the input user
     */
    void initGetTile();
    
    /**
     * @brief Display the moved made
     * @param move Move made
     */
    void displayMove(Move move);
    
    /**
     * @brief Display the turn information
     * @param numTurn Turn number
     * @param color Color of the player turn
     */
    void displayTurnInfo(int numTurn, Color color);
    
    /**
     * @brief Display the last move made
     * @param Move Last move
     */
    void displayLastMove(Move Move);
    
    /**
     * @brief Display the winner
     * @param color Winner Color
     */
    void displayWinner(Color color);
    
    /**
     * @brief Convert a charactere to a integer
     * a->0, b->1, ...
     * @param line Line charactere
     * @return Line integer
     */
    int convertCharToInt(char line);
    
    /**
     * @brief Convert a Color to a string
     *  Undefined->None, White->White and Black->Black
     * @param color Color to convert
     * @return string associated with the color
     */
    std::string getPlayerString(Color color);
    
    /**
     * @brief Convert a Color to a charactere
     * Undefined->" ", White->"B" and Black->"N"
     * @param color Color to convert
     * @return Charactere associated with the color
     */
    std::string getTileString(Color color);
    
    /**
     * @brief Get the player move by reading the user input
     * @return Move choose by the user
     */
    Move getPlayerMove();
};
