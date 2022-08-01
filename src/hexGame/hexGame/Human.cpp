
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

#include "Human.hpp"

Human::Human(Color color,std::shared_ptr<Mediator> mediator)
    : Player::Player(color, true), m_mediator(mediator) {}

Human::~Human() {}

Move Human::makeMove(Board *current_board) {
    m_mediator->sendMessageToUI(MESSAGE::ASK_FOR_MOVE);
    MESSAGE message = MESSAGE::NONE;
    while (message != MESSAGE::SEND_MOVE) {
        message = m_mediator->getRemoveFirstMessageToGame();
        #ifdef _WIN32
            Sleep(50);
        #else
            sleep(1);
        #endif
    }
    Move move = m_mediator->getMove();
    move.color = m_color;
    return move;
}

void Human::initPlayer(Board *board) {}
