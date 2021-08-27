
#include "Board.hpp"
#include "Tile.hpp"
#include "IterNeighbour.hpp"
#include <stdexcept>
#include <iostream>
#include <stack>


Board::Board(int size):
    m_size(size)
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
    m_size((*board).getSize())
{
    m_board.reserve(m_size);
    for (int i=0; i<m_size; ++i) {
        std::vector<Tile*> tmp;
        tmp.reserve(m_size);
        for (int j=0; j<m_size; ++j) {
            tmp.push_back(new Tile((*board).getTile(i, j)));
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
    for (int i=0; i<m_size; ++i) {
        for (int j=0; j<m_size; ++j) {
            m_board.at(i).at(j)->setColor(Color::Undefined);
            m_board.at(i).at(j)->setIsChecked(false);
        }
    }
}


void Board::addMoveToBoard(Move move)
{
    m_board.at(move.i).at(move.j)->setColor(move.color);
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
            m_board.at(i).at(j)->setIsChecked(false);
        }
    }
}


void Board::deleteBoard() {
    for (int i=0; i<m_size; ++i) {
        for (int j=0; j<m_size; ++j) {
            delete m_board.at(i).at(j);
        }
    }
}


Tile* Board::getTile(int i, int j) const
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
                    Tile t = *(board.m_board.at(i).at(j));
                    tmp.push_back(new Tile(t.getI(), t.getJ(), t.getColor(), t.getIsChecked()));
                }
                m_board.push_back(tmp);
            }
        } else {
            for (int i=0; i<m_size; ++i) {
                for (int j=0; j<m_size; ++j) {
                    *(m_board.at(i).at(j)) = *(board.m_board.at(i).at(j));
                }
            }
        }
	}
	return *this;
}
