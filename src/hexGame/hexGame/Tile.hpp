
#pragma once

#include "HexGameLib_export.hpp"

#include "gameUtils.hpp"

/**
 * @brief Content of the game board
 *
 */
class Tile final {
  private:
    /**
     * @brief line of the tile in the board
     */
    int m_i;
    /**
     * @brief column of the tile in the board
     */
    int m_j;
    /**
     * @brief color of the tile
     */
    Color m_color;
    /**
     * @brief boolean use when a process on the board is running
     * True : the tile had already been checked
     */
    bool m_isChecked;

  public:
    
    /**
     * @brief Default constructor
     */
    HEXGAMELIB_EXPORT Tile();

    /**
     * @brief Constructor
     * @param i line of the tile
     * @param j column of the tile
     */
    HEXGAMELIB_EXPORT Tile(int i, int j);

    /**
     * @brief constructor
     * @param i line of the tile
     * @param j column of the tile
     * @param color color of the tile
     * @param isChecked is the tile check
     */
    HEXGAMELIB_EXPORT Tile(int i, int j, Color color, bool isChecked);

    /**
     * @brief Copy constructor
     * @param Tile Tile to copy
     */
    HEXGAMELIB_EXPORT Tile(const Tile &tile);

    /**
     * @brief destructor
     */
    HEXGAMELIB_EXPORT ~Tile() = default;

    /**
     * @brief Get the m_i property
     * @return int
     */
    HEXGAMELIB_EXPORT int getI() const;

    /**
     * @brief Get the m_j property
     * @return int
     */
    HEXGAMELIB_EXPORT int getJ() const;

    /**
     * @brief Set the line and column property
     * @param i new line
     * @param j new colunm
     * @return void
     */
    HEXGAMELIB_EXPORT void setIndexes(int i, int j);

    /**
     * @brief Get the Color property
     * @return Color
     */
    HEXGAMELIB_EXPORT Color getColor() const;

    /**
     * @brief Set the Color property
     * @param color new color
     * @return void
     */
    HEXGAMELIB_EXPORT void setColor(Color color);

    /**
     * @brief Get the Is Checked property
     * @return bool
     */
    HEXGAMELIB_EXPORT bool getIsChecked() const;

    /**
     * @brief Set the Is Checked property
     * @param isChecked
     * @return void
     */
    HEXGAMELIB_EXPORT void setIsChecked(bool isChecked);

    HEXGAMELIB_EXPORT void initTile();

    /**
     * @brief operator= affectation oprator
     * @param tile tile to be copy
     * @return Tile &
     */
    HEXGAMELIB_EXPORT Tile &operator=(const Tile &tile);
};

/**
 * @brief operator== equality operator for the tile class
 * @param tile1 first tile
 * @param tile2 second tile
 * @return bool
 */
HEXGAMELIB_EXPORT bool operator==(const Tile &tile1, const Tile &tile2);

/**
 * @brief operator!= difference operator for the tile class
 * @param tile1 first tile
 * @param tile2 second tile
 * @return bool
 */
HEXGAMELIB_EXPORT bool operator!=(const Tile &tile1, const Tile &tile2);
