
#include "Human.hpp"


Human::Human(Color color, GameUI* gameUI):
    Player::Player(color, true),
    m_gameUI(gameUI)
{
}


Human::~Human()
{
}


Move Human::makeMove(Board* current_board)
{
    Move move(m_color);
    (*m_gameUI).getPlayerMove(move);
    return move;
}
