
#include "Board.hpp"


Board::Board(int size):
    size(size)
{
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            board.at(i).push_back(new Tile(i, j));
        }
    }
}


Board::~Board()
{
}


void Board::initBoard()
{
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            board.at(i).at(j)->setColor(Undefined);
            board.at(i).at(j)->setIsChecked(false);
        }
    }
}


void Board::addMoveToBoard(Move move)
{
    board.at(move.i).at(move.j)->setColor(move.color);
}


bool Board::isMoveValid(Move move)
{
    bool isValid = false;
    if (board.at(move.i).at(move.j)->getColor() == Undefined) {
        isValid = true;
    }
    return isValid;
}


void Board::resetCheckup()
{
    for (int i=0; i<size; i++) {
        for (int j=0; j<size; j++) {
            board.at(i).at(j)->setIsChecked(false);
        }
    }
}


Tile* Board::getTile(int, int)
{
}


Board& Board::operator=(const Board&)
{
}
