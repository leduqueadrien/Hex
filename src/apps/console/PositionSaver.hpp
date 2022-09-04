
#pragma once

#include <gameUtils.hpp>

#include <iostream>

#ifdef _WIN32
#include <Windows.h>
#else
#endif

#define SAVE "\033[s"
#define LOAD "\033[u"
#define ESC "\033"
#define CSI "\033["
#define MOVE(l, c) "\033[" << (l) << ";" << (c) << "H"

// ############################################################################
// ############################# POSITION SAVER ###############################
// ############################################################################
/**
 * @brief Class for retaining a position
 */
class PositionSaver {
protected:
    /**
     * @brief Line of the saved position 
     */
    int m_line;

    /**
     * @brief Column of the saved position
     */
    int m_column;

public:
    /**
     * @brief Construct a new Position Saver object
     * @param line Line of the position
     * @param column Column of the position
     */
    PositionSaver(int line, int column);

    /**
     * @brief Construct a new Position Saver object
     */
    PositionSaver();

    /**
     * @brief Destroy the Position Saver object
     */
    ~PositionSaver() = default;

    /**
     * @brief Get the Line object
     * @return Line of the position
     */
    int getLine() const;

    /**
     * @brief Set the Line object
     * @param line New line
     */
    void setLine(int line);

    /**
     * @brief Get the Column object
     * @return Column of the position
     */
    int getColumn() const;

    /**
     * @brief Set the Column object
     * @param column New column
     */
    void setColumn(int column);
};

// ############################################################################
// ############################# TILE SAVER ###################################
// ############################################################################
/**
 * @brief class for retaining a tile position
 * Inheritate from PositionSaver class
 */
class TileSaver : public PositionSaver {
private:
    /**
     * @brief Color of the tile
     */
    Color m_color;

public:
    
    /**
     * @brief Construct a new Tile Saver object
     * @param line Line of the position
     * @param column Column of the position
     */
    TileSaver(int line, int column);
    
    /**
     * @brief Construct a new Tile Saver object
     */
    TileSaver();
    
    /**
     * @brief Get the Color object
     * @return The tile's color
     */
    Color getColor() const;
    
    /**
     * @brief Set the Color object
     * @param color New color
     */
    void setColor(Color color);
};
