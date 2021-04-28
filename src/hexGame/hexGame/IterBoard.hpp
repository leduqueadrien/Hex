
#pragma once

#include "HexGameLib_export.hpp"

#include "Tile.hpp"
#include "Board.hpp"

class IterBoard {
	private:
		Board * m_board;
		int m_i;
		int m_j;

	public:
		HEXGAMELIB_EXPORT IterBoard(Board *);
		HEXGAMELIB_EXPORT ~IterBoard();
		HEXGAMELIB_EXPORT Tile * begin();
		HEXGAMELIB_EXPORT Tile * end();
		HEXGAMELIB_EXPORT Tile * operator++();
		HEXGAMELIB_EXPORT Tile * operator*();
};
