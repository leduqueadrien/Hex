
#include "Board.hpp"
#include "Tile.hpp"
#include "IterNeighbour.hpp"
#include <stdexcept>
#include <iostream>
#include <stack>


Board::Board(int size):
	m_size(size),
	m_nbFreeTiles(0)
{
	m_board.reserve(m_size);
	for (int i=0; i<m_size; ++i) {
		std::vector<Tile*> tmp;
		tmp.reserve(m_size);
		for (int j=0; j<m_size; ++j) {
			tmp.push_back(new Tile(i, j));
		}
		m_board.push_back(tmp);
	}
}


Board::Board(Board * board):
	m_size((*board).getSize()),
	m_nbFreeTiles((*board).getNbFreeTiles())
{
	m_board.reserve(m_size);
	for (int i=0; i<m_size; ++i) {
		std::vector<Tile*> tmp;
		tmp.reserve(m_size);
		for (int j=0; j<m_size; ++j) {
			tmp.push_back(new Tile(*(*board).getTile(i, j)));
		}
		m_board.push_back(tmp);
	}
}


Board::~Board()
{
	deleteBoard();
}


void Board::initBoard()
{
	m_nbFreeTiles = 0;
	for (int i=0; i<m_size; ++i) {
		for (int j=0; j<m_size; ++j) {
			getTile(i, j)->setColor(Color::Undefined);
			getTile(i, j)->setIsChecked(false);
		}
	}
}


void Board::addMoveToBoard(Move move)
{
	m_board.at(move.i).at(move.j)->setColor(move.color);
	++m_nbFreeTiles;
}


bool Board::isMoveValid(Move move) const
{
	Tile * ptile = getTile(move.i, move.j);
	return ptile != nullptr && (*ptile).getColor() == Color::Undefined;
}


bool Board::hasPlayerWon(Color color)
{
	std::stack<Tile *> stack;
	Tile * currentTile;
	// On ajoute les premiere cases dans la pile
	for (int i=0; i<m_size; ++i) {
		if (color == Color::White) {
			currentTile = getTile(0, i);
		} else {
			currentTile = getTile(i, 0);
		}
		if ((*currentTile).getColor() == color) {
			stack.push(currentTile);
			(*currentTile).setIsChecked(true);
		}
	}
	// On parcour les cases de la couleur du joueur
	while (!stack.empty()) {
		currentTile = stack.top();
		stack.pop();
		IterNeighbour it(this, (*currentTile).getI(), (*currentTile).getJ());

		for (it.begin(); *it!=it.end(); ++it) {
			// On test si la case appartient au joueur
			
			if ((**it).getColor() == color) {
				// On test si le joueur a atteint l'autre cote du board
				if ( (color == Color::White && (**it).getI() == m_size-1) || 
					 (color == Color::Black && (**it).getJ() == m_size-1) ) {
					return true;
				}
				if (!(**it).getIsChecked()) {
					stack.push(*it);
					(**it).setIsChecked(true);
				}
			}
			
		}
	}

	resetCheckup();

	return false;
}


void Board::resetCheckup()
{
	for (int i=0; i<m_size; ++i) {
		for (int j=0; j<m_size; ++j) {
			getTile(i, j)->setIsChecked(false);
		}
	}
}


void Board::deleteBoard() {
	for (int i=0; i<m_size; ++i) {
		for (int j=0; j<m_size; ++j) {
			delete getTile(i, j);
		}
	}
}


Tile * Board::getTile(int i, int j) const
{
	try {
		return m_board.at(i).at(j);
	} catch (std::out_of_range e) {
		return nullptr;
	}
}


int Board::getSize() const
{
	return m_size;
}

int Board::getNbFreeTiles() const
{
	return m_nbFreeTiles;
}

Board& Board::operator=(const Board& board)
{
	if (this != &board) {
		if (board.m_size != m_size) {
			m_size = board.m_size;
			deleteBoard();
			for (int i=0; i<m_size; ++i) {
				std::vector<Tile *> tmp;
				tmp.reserve(m_size);
				for (int j=0; j<m_size; ++j) {
					Tile t = *(board.getTile(i, j));
					tmp.push_back(new Tile(t.getI(), t.getJ(), t.getColor(), t.getIsChecked()));
				}
				m_board.push_back(tmp);
			}
		} else {
			for (int i=0; i<m_size; ++i) {
				for (int j=0; j<m_size; ++j) {
					*(getTile(i, j)) = *(board.getTile(i, j));
				}
			}
		}
	}
	return *this;
}
