
#pragma once

#include "HexGameLib_export.hpp"

#include "Tile.hpp"
#include "Board.hpp"
#include "gameUtils.hpp"
/**
 * @brief iterate on the tile's neighbour 
 * 
 */
class IterNeighbour {
private:

	/**
	 * @brief line of the tile on which we iterate
	 */
	int m_i;

	/**
	 * @brief column of the tile on which we iterate
	 */
	int m_j;

	/**
	 * @brief code number of the current neighbour
	 */
	Neighbour m_numCurrentNeighbour;

	/**
	 * @brief tile's board
	 */
	Board * m_board;

public:

	/**
	 * @brief constructor
	 * @param board : board of the tile on which we iterate
	 * @param i : tile line on which we iterate
	 * @param j : tile columns on which we iterate
	 */
	HEXGAMELIB_EXPORT IterNeighbour(Board * board, int i, int j);

	/**
	 * @brief destructor
	 */
	HEXGAMELIB_EXPORT ~IterNeighbour()=default;

	/**
	 * @brief begin the iteration
	 * @return Tile *, first neighbour of the tile
	 */
	HEXGAMELIB_EXPORT Tile * begin();

	/**
	 * @brief  Iterator to the element following the last element
	 * @return Tile * the element following the last element
	 */
	HEXGAMELIB_EXPORT Tile * end();

	/**
	 * @brief icremental operator
	 * @return Tile *, next neighbour 
	 */
	HEXGAMELIB_EXPORT Tile * operator++();

	/**
	 * @brief return current neighbour
	 * @return Tile * current neighbour
	 */
	HEXGAMELIB_EXPORT Tile * operator*();

};
