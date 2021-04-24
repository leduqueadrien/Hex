
#include "Board.hpp"
#include "Tile.hpp"
#include <stdexcept>


Board::Board(int size):
    m_size(size)
{
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
