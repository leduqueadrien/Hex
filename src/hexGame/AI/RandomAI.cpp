
#include "RandomAI.hpp"
#include <cstdlib>
#include <ctime>

RandomAI::RandomAI(Color color, Game* game):
    AI::AI(color, game)
{
	std::srand((int)std::time(nullptr));
}

RandomAI::RandomAI(Color color):
    AI::AI(color, nullptr)
{
}


RandomAI::~RandomAI()
{
}


Move RandomAI::makeMove()
{
	int n = (*(*m_game).getBoard()).getSize();
    Move move(m_color);
    
	move.i = -1;
	move.j = -1;

	while(!(*(*m_game).getBoard()).isMoveValid(move)) {
		move.i = std::rand() % n;
		move.j = std::rand() % n;
	}

    return move;
}
