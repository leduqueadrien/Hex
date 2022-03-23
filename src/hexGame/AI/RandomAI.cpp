
#include "RandomAI.hpp"
#include <cstdlib>
#include <ctime>

RandomAI::RandomAI(Color color):
	AI::AI(color)
{
	std::srand((int)std::time(nullptr));
}


RandomAI::~RandomAI()
{
}


void RandomAI::initPlayer(Board* board) {}


Move RandomAI::makeMove(Board* current_board)
{
	int n = (*current_board).getSize();
	Move move(m_color);
	
	move.i = -1;
	move.j = -1;

	while(!(*current_board).isMoveValid(move)) {
		move.i = std::rand() % n;
		move.j = std::rand() % n;
	}

	return move;
}
