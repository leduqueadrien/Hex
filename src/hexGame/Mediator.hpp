
#pragma once

#include "HexGameLib_export.hpp"

#include <memory>
#include <list>
#include <thread>
#include <Parameters.hpp>
#include <gameUtils.hpp>
#include <hexGame/Game.hpp>
#include <hexGame/Player.hpp>
#include <iostream>
#include <mutex>


typedef enum MESSAGE {
    NONE,                   // 0
    ASK_FOR_NUM_TURN,       // 1
    SEND_NUM_TURN,          // 2
    ASK_FOR_PLAYER_TURN,    // 3
    SEND_PLAYER_TURN,       // 4
    ASK_FOR_LAST_MOVE,      // 5
    SEND_LAST_MOVE,         // 6
    ASK_FOR_MOVE,           // 7
    SEND_MOVE,              // 8
    ASK_FOR_GAME_INIT,      // 9
    DONE_GAME_INIT,         // 10
    END_GAME,               // 11
    ACK_END_GAME,           // 12
    ASK_NEXT_TURN,          // 13
    DONE_NEXT_TURN          // 14
} MESSAGE;

class Game;

class Mediator {
private:
    std::shared_ptr<Game> m_game;
    std::thread* m_game_thread;
    std::list<MESSAGE> m_list_ui;
    std::list<MESSAGE> m_list_game;
    std::mutex mtx_ui;
    std::mutex mtx_game;
    std::shared_ptr<int> m_num_turn;
    std::shared_ptr<Move> m_move;
    std::shared_ptr<Move> m_last_move;
    std::shared_ptr<bool> m_is_game_finished;
    std::shared_ptr<Color> m_player_turn;

public:
    Mediator() = default;
    ~Mediator() = default;
    std::shared_ptr<Player> Mediator::createPlayer(const Parameters& param, Color color);
    bool createGame(const Parameters& param);
    void sendMessageToUI(MESSAGE message);
    void sendMessageToGame(MESSAGE message);
    MESSAGE getFirstMessageToUI();
    MESSAGE getFirstMessageToGame();
    void removeFirstMessageToUI();
    void removeFirstMessageToGame();
    MESSAGE getRemoveFirstMessageToUI();
    MESSAGE getRemoveFirstMessageToGame();
    MESSAGE getRemoveMessageToGame(MESSAGE message);
    MESSAGE getRemoveMessageToUI(MESSAGE message);
    int getNumTurn();
    void setNumTurn(int numTurn);
    Color getPlayerTurn();
    void setPlayerTurn(Color color);
    Move getLastMove();
    void setLastMove(Move move);
    Move getMove();
    void setMove(Move move);



};

void LOGGER(const std::string& chaine);
void LOGGER(MESSAGE message);
void lunchGameWaiting(std::shared_ptr<Game> game);
