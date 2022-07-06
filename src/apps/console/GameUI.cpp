
#include "GameUI.hpp"
#include "HomePage.hpp"
#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

GameUI::GameUI() : m_mediator(std::make_shared<Mediator>()) {}

void GameUI::main() {
    Parameters param = menuHandler();
    int board_size = atoi(param.getValue("BoardSize").c_str());
    m_gamePrinter = std::make_shared<GamePrinter>(board_size);

    m_mediator->createGame(param);
    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_GAME_INIT);
    waitingUntil(MESSAGE::DONE_GAME_INIT);
    gameProcessing();
}

Parameters GameUI::menuHandler() {
    HomePage homePage;
    return homePage.navigate();
}

void GameUI::gameProcessing() {
    bool is_end_game = false;

    display();
    while (!is_end_game) {
        m_mediator->sendMessageToGame(MESSAGE::ASK_NEXT_TURN);
        is_end_game = waitingUntil(MESSAGE::DONE_NEXT_TURN);
        display();
    }
    m_mediator->sendMessageToGame(MESSAGE::ACK_END_GAME);

}

bool GameUI::waitingUntil(MESSAGE message) {
    MESSAGE receive_message = MESSAGE::NONE;
    bool is_game_finished = false;
    while(receive_message != message && !is_game_finished) {
        receive_message = m_mediator->getRemoveFirstMessageToUI();
        switch (receive_message)
        {
        case MESSAGE::ASK_FOR_MOVE:
            m_mediator->setMove(m_gamePrinter->getPlayerMove());
            m_mediator->sendMessageToGame(MESSAGE::SEND_MOVE);
            break;
        case MESSAGE::END_GAME:
            is_game_finished = true;
        default:
            break;
        }
        Sleep(10);
    }
    return is_game_finished;
}

void GameUI::display() {

    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_NUM_TURN);
    waitingUntil(MESSAGE::SEND_NUM_TURN);
    int num_turn = m_mediator->getNumTurn();
    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_PLAYER_TURN);
    waitingUntil(MESSAGE::SEND_PLAYER_TURN);
    Color player_turn = m_mediator->getPlayerTurn();
    m_gamePrinter->displayTurnInfo(num_turn, player_turn);

    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_LAST_MOVE);
    waitingUntil(MESSAGE::SEND_LAST_MOVE);
    Move last_move = m_mediator->getLastMove();
    m_gamePrinter->displayMove(last_move);

    m_gamePrinter->addMove(last_move);
    m_gamePrinter->displayBoard();

}
