
#pragma once

#include "HexGameLib_export.hpp"
#include "Message.hpp"

#include <memory>
#include <list>
#include <thread>
#include <Parameters.hpp>
#include <gameUtils.hpp>
#include <hexGame/Game.hpp>
#include <hexGame/Player.hpp>
#include <iostream>
#include <mutex>


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
    std::shared_ptr<Color> m_winner_player;

public:
    Mediator() = default;
    ~Mediator() = default;
    std::shared_ptr<Player> createPlayer(Parameters& param, Color color);
    bool createGame(Parameters& param);
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
    Color getWinnerPlayer();
    void setWinnerPlayer(Color color);

};

void LOGGER(const std::string& chaine);
void LOGGER(MESSAGE message);
void lunchGameWaiting(std::shared_ptr<Game> game);
