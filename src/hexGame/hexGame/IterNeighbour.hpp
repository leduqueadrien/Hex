
#pragma once

#include "HexGameLib_export.hpp"

#include "Tile.hpp"
#include "Board.hpp"
# include "gameUtils.hpp"

class IterNeighbour {
	private:
		int m_i;
		int m_j;
		Neighbour m_numCurrentNeighbour;
		Board * m_board;

	public:
		HEXGAMELIB_EXPORT IterNeighbour(Board *, int, int );
		HEXGAMELIB_EXPORT Tile * begin();
		HEXGAMELIB_EXPORT Tile * end();
		HEXGAMELIB_EXPORT Tile * operator++();
		HEXGAMELIB_EXPORT Tile * operator*();

};
