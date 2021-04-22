
#include "Human.hpp"


Human::Human(Color color, GameUI* gameUI):
    Player::Player(color),
    gameUI(gameUI)
{
}


Human::~Human()
{
}


Move Human::makeMove()
{
    Move move(color);
    gameUI->getPlayerMove(move);
    return move;
}
