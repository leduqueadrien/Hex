
#include "Board.hpp"


Board::Board(int size):
    size(size)
{
    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            board.at(i).push_back(new Tile(i, j));
        }
    }
}


Board::~Board()
{
}


void Board::initBoard()
{
    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            board.at(i).at(j)->setColor(Color::Undefined);
            board.at(i).at(j)->setIsChecked(false);
        }
    }
}


void Board::addMoveToBoard(Move move)
{
    board.at(move.i).at(move.j)->setColor(move.color);
}


bool Board::isMoveValid(Move move) const
{
    return board.at(move.i).at(move.j)->getColor() == Color::Undefined;
}


void Board::resetCheckup()
{
    for (int i=0; i<size; ++i) {
        for (int j=0; j<size; ++j) {
            board.at(i).at(j)->setIsChecked(false);
        }
    }
}


Tile* Board::getTile(int i, int j) const
{
    return board.at(i).at(j);
}


Board& Board::operator=(const Board& board)
{
	if (this != &board) {
		if (board.size == size) {
            //copy board.board in this.board
        }
	}
	return *this;
}
