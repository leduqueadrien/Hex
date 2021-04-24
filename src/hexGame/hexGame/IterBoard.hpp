
#ifndef ITERBOARD_HPP
#define ITERBOARD_HPP

#include "Tile.hpp"
#include "Board.hpp"

class IterBoard {
	private:
		Board * m_board;
		int m_i;
		int m_j;

	public :
		IterBoard(Board *);
		~IterBoard();
		Tile * begin();
		Tile * end();
		Tile * operator++();
		Tile * operator*();
};

#endif