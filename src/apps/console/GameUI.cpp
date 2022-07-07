
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
    gameRunner();
}

Parameters GameUI::menuHandler() {
    HomePage homePage;
    return homePage.navigate();
}


bool GameUI::gameRunner() {
    MESSAGE receive_message;
    bool is_game_finished = false;
    m_gamePrinter->displayBoard();
    while(!is_game_finished) {
        receive_message = m_mediator->getRemoveFirstMessageToUI();
        switch (receive_message) {
            case MESSAGE::ASK_FOR_MOVE:
                m_mediator->setMove(m_gamePrinter->getPlayerMove());
                m_mediator->sendMessageToGame(MESSAGE::SEND_MOVE);
                break;
            case MESSAGE::TURN_MAKE:
                display();
                m_mediator->sendMessageToGame(MESSAGE::END_DISPLAY);
                break;
            case MESSAGE::END_GAME:
                is_game_finished = true;
            default:
                break;
        }
        Sleep(50);
    }
    Color color = m_mediator->getWinnerPlayer();
    m_gamePrinter->displayWinner(color);
    return is_game_finished;
}

void GameUI::waitingUntil(MESSAGE message) {
    MESSAGE receive_message = MESSAGE::NONE;
    while(receive_message != message) {
        receive_message = m_mediator->getRemoveFirstMessageToUI();
        Sleep(50);
    }
}

void GameUI::display() {

    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_NUM_TURN);
    waitingUntil(MESSAGE::SEND_NUM_TURN);
    int num_turn = m_mediator->getNumTurn();

    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_PLAYER_TURN);
    waitingUntil(MESSAGE::SEND_PLAYER_TURN);
    Color player_turn = m_mediator->getPlayerTurn();

    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_LAST_MOVE);
    waitingUntil(MESSAGE::SEND_LAST_MOVE);
    Move last_move = m_mediator->getLastMove();

    m_gamePrinter->displayTurnInfo(num_turn, player_turn);
    m_gamePrinter->displayMove(last_move);
    m_gamePrinter->addMove(last_move);
    m_gamePrinter->displayBoard();

}
