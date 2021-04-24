
#include "IterNeighbour.hpp"
#include "Board.hpp"
#include "gameUtils.hpp"


Neighbour operator++(Neighbour n) {
    return static_cast<Neighbour>(static_cast<int>(n)+1);
}


IterNeighbour::IterNeighbour(Board * board, int i, int j) :
	m_i(i),
	m_j(j),
	m_numCurrentNeighbour(NOT_INIT),
	m_board(board)
{
}


Tile * IterNeighbour::begin() {
	m_numCurrentNeighbour = TOP_LEFT;
	return operator*();
}


Tile * IterNeighbour::end() {
	return nullptr;
}


Tile * IterNeighbour::operator*() {
	switch (m_numCurrentNeighbour) {
		case (TOP_LEFT) :
			return (*m_board).getTile(m_i-1, m_j);
		break;
		case (TOP_RIGHT) :
			return (*m_board).getTile(m_i-1, m_j+1);
		break;
		case (RIGHT) :
			return (*m_board).getTile(m_i, m_j+1);
		break;
		case (BOTTOM_RIGHT) :
			return (*m_board).getTile(m_i+1, m_j);
		break;
		case (BOTTOM_LEFT) :
			return (*m_board).getTile(m_i+1, m_j-1);
		break;
		case (LEFT) :
			return (*m_board).getTile(m_i, m_j-1);
		default :
			return nullptr;

	}
}


Tile * IterNeighbour::operator++() {
	do {
		m_numCurrentNeighbour++;
	} while(operator*() == nullptr && m_numCurrentNeighbour != END);
}	
