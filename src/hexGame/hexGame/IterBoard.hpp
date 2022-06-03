
#pragma once

#include "HexGameLib_export.hpp"

#include "Board.hpp"
#include "Tile.hpp"

/**
 * @brief iterate on the board
 */
class IterBoard {
  private:
    /**
     * @brief board on which we iterate
     */
    Board *m_board;

    /**
     * @brief line iterator
     */
    int m_i;

    /**
     * @brief column iterator
     */
    int m_j;

  public:
    /**
     * @brief constructor
     * @param board : pointeur on the board
     */
    HEXGAMELIB_EXPORT IterBoard(Board *board);

    /**
     * @brief destructor
     */
    HEXGAMELIB_EXPORT ~IterBoard() = default;

    /**
     * @brief begin the iteration
     * @return Tile * first tile of the board
     */
    HEXGAMELIB_EXPORT Tile *begin();

    /**
     * @brief  Iterator to the element following the last element
     * @return Tile * the element following the last element
     */
    HEXGAMELIB_EXPORT Tile *end();

    /**
     * @brief icremental operator
     * @return Tile * next tile
     */
    HEXGAMELIB_EXPORT Tile *operator++();

    /**
     * @brief return current tile
     * @return Tile * current tile
     */
    HEXGAMELIB_EXPORT Tile *operator*();
};
