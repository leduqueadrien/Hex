
#include "Board.hpp"


Board::Board(int size):
    m_size(size)
{
    std::vector<Tile*> tmp;
    for (int i=0; i<m_size; ++i) {
        for (int j=0; j<m_size; ++j) {
            tmp.push_back(new Tile(i, j));
        }
        m_board.push_back(tmp);
    }
}


Board::~Board()
{
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


Tile* Board::getTile(int i, int j) const
{
    return m_board.at(i).at(j);
}


int Board::getSize() const
{
    return m_size;
}


Board& Board::operator=(const Board& board)
{
	if (this != &board) {
		if (board.m_size == m_size) {
            //copy board.board in this.board
        }
	}
	return *this;
}
