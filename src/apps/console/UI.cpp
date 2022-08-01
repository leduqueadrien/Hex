
#include "UI.hpp"

#ifdef _WIN32
    #include <Windows.h>
#else
    #include <unistd.h>
#endif

UI::UI() : m_mediator(std::make_shared<Mediator>()), m_cursor(std::make_shared<Cursor>()) {}

void UI::main() {
    mainMenu();
    mainGame();
}

void UI::mainMenu() {
    std::shared_ptr<Menu> current_menu = std::make_shared<MenuHome>(m_cursor);

    navigate(current_menu);
}

void UI::mainGame() {
    int board_size = std::dynamic_pointer_cast<ParameterBoardSize>(m_parameters.getParameter("BoardSize"))->getBoardSize();
    m_gameUI = std::make_shared<GameUI>(m_cursor, board_size);

    m_mediator->createGame(m_parameters);
    gameRunner();
}

void UI::navigate(std::shared_ptr<Menu> current_menu) {
    int choice;
    bool is_succes;
    while (current_menu != nullptr) {
        std::cout << "SELECT" << std::endl;
        current_menu->display();
        choice = current_menu->select();
        is_succes = current_menu->action(choice, m_parameters, current_menu);
        if (!is_succes)
            m_cursor->clearScreen();
    }
}

bool UI::gameRunner() {
    MESSAGE receive_message;
    bool is_game_finished = false;
    m_gameUI->initDisplay();
    while(!is_game_finished) {
        receive_message = m_mediator->getRemoveFirstMessageToUI();
        switch (receive_message) {
            case MESSAGE::ASK_FOR_MOVE:
                m_mediator->setMove(m_gameUI->getPlayerMove());
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
        #ifdef _WIN32
            Sleep(50);
        #else
            sleep(1);
        #endif
    }
    Color color = m_mediator->getWinnerPlayer();
    m_gameUI->displayWinner(color);
    return is_game_finished;
}

void UI::waitingUntil(MESSAGE message) {
    MESSAGE receive_message = MESSAGE::NONE;
    while(receive_message != message) {
        receive_message = m_mediator->getRemoveFirstMessageToUI();
        #ifdef _WIN32
            Sleep(50);
        #else
            sleep(1);
        #endif
    }
}

void UI::display() {

    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_NUM_TURN);
    waitingUntil(MESSAGE::SEND_NUM_TURN);
    int num_turn = m_mediator->getNumTurn();

    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_PLAYER_TURN);
    waitingUntil(MESSAGE::SEND_PLAYER_TURN);
    Color player_turn = m_mediator->getPlayerTurn();

    m_mediator->sendMessageToGame(MESSAGE::ASK_FOR_LAST_MOVE);
    waitingUntil(MESSAGE::SEND_LAST_MOVE);
    Move last_move = m_mediator->getLastMove();

    m_gameUI->displayTurnInfo(num_turn, player_turn);
    m_gameUI->displayMove(last_move);

    m_gameUI->displayLastMove(last_move);

}
