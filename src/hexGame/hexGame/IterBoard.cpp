
#include "IterBoard.hpp"

IterBoard::IterBoard(Board * board) :
	m_board(board),
	m_i(-1),
	m_j(-1)
{
}


Tile * IterBoard::begin() {
	m_i = 0;
	m_j = 0;
	return (*m_board).getTile(m_i, m_j);
}


Tile * IterBoard::end() {
	return nullptr;
}


Tile * IterBoard::operator*() {
	return (*m_board).getTile(m_i, m_j);
}


Tile * IterBoard::operator++() {
	++m_j;
	if (m_j == (*m_board).getSize()) {
		m_j = 0;
		++m_i;
	}
	return operator*();
}
