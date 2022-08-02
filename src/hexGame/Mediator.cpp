
#include "Mediator.hpp"
#include <AI/MonteCarlo.hpp>
#include <AI/RandomAI.hpp>
#include <algorithm>
#include <cstring>
#include <hexGame/Human.hpp>
#include <iostream>
#include <thread>

void lunchGameWaiting(std::shared_ptr<Game> game) {
    game->gameRunner();
}

bool Mediator::createGame(Parameters &param) {
    std::shared_ptr<Player> playerWhite = createPlayer(param, Color::White);
    std::shared_ptr<Player> playerBlack = createPlayer(param, Color::Black);
    int board_size = std::dynamic_pointer_cast<ParameterBoardSize>(
                         param.getParameter("BoardSize"))
                         ->getBoardSize();

    m_game = std::make_shared<Game>(playerWhite, playerBlack, board_size, this);

    m_game_thread = new std::thread(lunchGameWaiting, m_game);

    return true;
}

std::shared_ptr<Player> Mediator::createPlayer(Parameters &param, Color color) {
    std::shared_ptr<Player> player;
    std::string name_player_type;
    std::string player_type;
    if (color == Color::White)
        name_player_type = "PlayerWhite";
    else
        name_player_type = "PlayerBlack";

    LOGGER(name_player_type);

    player_type = std::dynamic_pointer_cast<ParameterPlayer>(
                      param.getParameter(name_player_type))
                      ->getPlayerType();
    if (!strcmp(player_type.c_str(), "Human")) {
        player =
            std::make_shared<Human>(color, std::shared_ptr<Mediator>(this));
        LOGGER("HUMAN");
    } else if (!strcmp(player_type.c_str(), "Random")) {
        player = std::make_shared<RandomAI>(color);
        LOGGER("RANDOM");
    } else {
        player = std::make_shared<MonteCarlo>(color);
        LOGGER("MONTE CARLO");
    }

    return player;
}

void Mediator::sendMessageToUI(MESSAGE message) {
    LOGGER("SEND : UI");
    LOGGER(message);
    mtx_ui.lock();
    m_list_ui.push_back(message);
    mtx_ui.unlock();
}

void Mediator::sendMessageToGame(MESSAGE message) {
    LOGGER("SEND : GAME");
    LOGGER(message);
    mtx_game.lock();
    m_list_game.push_back(message);
    mtx_game.unlock();
}

MESSAGE Mediator::getFirstMessageToUI() {
    MESSAGE message;
    mtx_ui.lock();
    if (m_list_ui.size() == 0)
        message = MESSAGE::NONE;
    else
        message = m_list_ui.front();
    mtx_ui.unlock();
    return message;
}

MESSAGE Mediator::getFirstMessageToGame() {
    MESSAGE message;
    mtx_game.lock();
    if (m_list_game.size() == 0)
        message = MESSAGE::NONE;
    else
        message = m_list_game.front();
    mtx_game.unlock();
    return message;
}

void Mediator::removeFirstMessageToUI() {
    mtx_ui.lock();
    if (m_list_ui.size() != 0)
        m_list_ui.pop_front();
    mtx_ui.unlock();
}

void Mediator::removeFirstMessageToGame() {
    mtx_game.lock();
    if (m_list_game.size() != 0)
        m_list_game.pop_front();
    mtx_game.unlock();
}

MESSAGE Mediator::getRemoveFirstMessageToUI() {
    MESSAGE message = getFirstMessageToUI();
    removeFirstMessageToUI();
    if (message != MESSAGE::NONE) {
        LOGGER("GET : UI");
        LOGGER(message);
    }
    return message;
}

MESSAGE Mediator::getRemoveFirstMessageToGame() {
    MESSAGE message = getFirstMessageToGame();
    removeFirstMessageToGame();
    if (message != MESSAGE::NONE) {
        LOGGER("GET : GAME");
        LOGGER(message);
    }
    return message;
}

MESSAGE Mediator::getRemoveMessageToUI(MESSAGE message) {
    MESSAGE mes = MESSAGE::NONE;
    mtx_ui.lock();
    std::list<MESSAGE>::iterator it =
        std::find(m_list_ui.begin(), m_list_ui.end(), message);
    if (it != m_list_ui.end()) {
        mes = *it;
        std::remove(m_list_ui.begin(), m_list_ui.end(), message);
    }
    mtx_ui.unlock();
    return mes;
}

MESSAGE Mediator::getRemoveMessageToGame(MESSAGE message) {
    MESSAGE mes = MESSAGE::NONE;
    mtx_game.lock();
    std::list<MESSAGE>::iterator it =
        std::find(m_list_game.begin(), m_list_game.end(), message);
    if (it != m_list_game.end()) {
        mes = *it;
        std::remove(m_list_game.begin(), m_list_game.end(), message);
    }
    mtx_game.unlock();
    return mes;
}

int Mediator::getNumTurn() {
    int turn = *m_num_turn;
    m_num_turn.reset();
    return turn;
}

void Mediator::setNumTurn(int turn) {
    m_num_turn = std::make_shared<int>(turn);
}

Color Mediator::getPlayerTurn() {
    Color color = *m_player_turn;
    m_player_turn.reset();
    return color;
}

void Mediator::setPlayerTurn(Color color) {
    m_player_turn = std::make_shared<Color>(color);
}

Move Mediator::getLastMove() {
    Move move = *m_last_move;
    m_last_move.reset();
    return move;
}

void Mediator::setLastMove(Move move) {
    m_last_move = std::make_shared<Move>(move);
}

Move Mediator::getMove() {
    Move move = *m_move;
    m_move.reset();
    return move;
}

void Mediator::setMove(Move move) {
    m_move = std::make_shared<Move>(move);
}

Color Mediator::getWinnerPlayer() {
    Color color = *m_winner_player;
    m_winner_player.reset();
    return color;
}

void Mediator::setWinnerPlayer(Color color) {
    m_winner_player = std::make_shared<Color>(color);
}

void LOGGER(const std::string &chaine) {
    // std::cout << chaine << std::endl;
}

void LOGGER(MESSAGE message) {
    std::string chaine;
    switch (message) {
    case MESSAGE::ASK_FOR_NUM_TURN:
        chaine = "ASK_FOR_NUM_TURN";
        break;
    case MESSAGE::SEND_NUM_TURN:
        chaine = "SEND_NUM_TURN";
        break;
    case MESSAGE::ASK_FOR_PLAYER_TURN:
        chaine = "ASK_FOR_PLAYER_TURN";
        break;
    case MESSAGE::SEND_PLAYER_TURN:
        chaine = "SEND_PLAYER_TURN";
        break;
    case MESSAGE::ASK_FOR_LAST_MOVE:
        chaine = "ASK_FOR_LAST_MOVE";
        break;
    case MESSAGE::SEND_LAST_MOVE:
        chaine = "SEND_LAST_MOVE";
        break;
    case MESSAGE::ASK_FOR_MOVE:
        chaine = "ASK_FOR_MOVE";
        break;
    case MESSAGE::SEND_MOVE:
        chaine = "SEND_MOVE";
        break;
    case MESSAGE::ASK_FOR_GAME_INIT:
        chaine = "ASK_FOR_GAME_INIT";
        break;
    case MESSAGE::DONE_GAME_INIT:
        chaine = "DONE_GAME_INIT";
        break;
    case MESSAGE::END_GAME:
        chaine = "END_GAME";
        break;
    case MESSAGE::ACK_END_GAME:
        chaine = "ACK_END_GAME";
        break;
    case MESSAGE::ASK_NEXT_TURN:
        chaine = "ASK_NEXT_TURN";
        break;
    case MESSAGE::DONE_NEXT_TURN:
        chaine = "DONE_NEXT_TURN";
        break;
    default:
        chaine = "NONE";
        break;
    }
    // std::cout << "      " << chaine << std::endl;
}
