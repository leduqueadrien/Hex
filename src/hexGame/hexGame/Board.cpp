
#include "Board.hpp"
<<<<<<< HEAD
#include "Tile.hpp"
=======
#include <stdexcept>
>>>>>>> a070196adac219250807e2336f47b050b7d70ec5


Board::Board(int size):
    m_size(size)
{
    std::vector<Tile*> tmp;
    for (int i=0; i<m_size; ++i) {
        std::vector<Tile*> tmp;
        for (int j=0; j<m_size; ++j) {
            tmp.push_back(new Tile(i, j));
        }
        m_board.push_back(tmp);
    }
}


Board::~Board()
{
<<<<<<< HEAD

=======
    deleteBoard();
>>>>>>> a070196adac219250807e2336f47b050b7d70ec5
}


void Board::initBoard()
{
    deleteBoard();
}


void Board::addMoveToBoard(Move move)
{
    m_board.at(move.i).at(move.j)->setColor(move.color);
}


bool Board::isMoveValid(Move move) const
{
    return m_board.at(move.i).at(move.j)->getColor() == Color::Undefined;
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
        for (int j=0; j<m_size; j++) {
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


void Board::deleteBoard() {
    for (int i=0; i<m_size; ++i) {
        for (int j=0; j<m_size; ++j) {
            delete m_board.at(i).at(j);
        }
    }
}


Board& Board::operator=(const Board& board)
{
	if (this != &board) {
		if (board.m_size != m_size) {
            m_size = board.m_size;
            deleteBoard();
            for (int i=0; i<m_size; ++i) {
                std::vector<Tile *> tmp;
                for (int j=0; j<m_size; ++j) {
                    Tile t = *(board.m_board.at(i).at(j));
                    tmp.push_back(new Tile(t.getI(), t.getJ(), t.getColor(), t.getIsChecked()));
                }
                m_board.push_back(tmp);
            }
        } else {
            for (int i=0; i<m_size; ++i) {
                for (int j=0; j<m_size; ++j) {
                    m_board.at(i).at(j) = board.m_board.at(i).at(j);
                }
            }
        }
	}
	return *this;
}
