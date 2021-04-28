
#pragma once

#include "HexGameLib_export.hpp"

#include "Tile.hpp"
#include "Board.hpp"
# include "gameUtils.hpp"

class IterNeighbour{
	public:
		int m_i;
		int m_j;
		Neighbour m_numCurrentNeighbour;
		Board * m_board;

	private :
		IterNeighbour(Board *, int, int );
		Tile * begin();
		Tile * end();
		Tile * operator++();
		Tile * operator*();

};

#endif