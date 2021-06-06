
#include "Human.hpp"


Human::Human(Color color, GameUI* gameUI):
    Player::Player(color),
    m_gameUI(gameUI)
{
}


Human::~Human()
{
}


Move Human::makeMove()
{
    Move move(m_color);
    (*m_gameUI).getPlayerMove(move);
    return move;
}
