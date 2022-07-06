
#pragma once

#include "HexGameLib_export.hpp"

#include <memory>

#include "Board.hpp"
#include "Player.hpp"
#include "Mediator.hpp"

// Convention : blanc : haut en bas
//				noire : gauche droite

// Without HEXGAMELIB_EXPORT, we get : error LNK2019 or : fatal error LNK1104
// https://docs.microsoft.com/fr-fr/cpp/error-messages/tool-errors/linker-tools-error-lnk2019?view=msvc-160
// https://docs.microsoft.com/fr-fr/cpp/error-messages/compiler-errors-1/fatal-error-c1083?view=msvc-160

class Mediator;

/**
 * @brief class game
 */
class Game final {
  private:
    /**
     * @brief size of the board game
     */
    int m_boardSize;

    /**
     * @brief board of the game
     */
    Board *m_board;

    /**
     * @brief player 1
     */
    std::shared_ptr<Player> m_playerWhite;

    /**
     * @brief player 2
     */
    std::shared_ptr<Player> m_playerBlack;

    /**
     * @brief the number of the current turn
     */
    int m_numTurn;

    /**
     * @brief the player who had to play
     */
     std::shared_ptr<Player> m_player_turn;

    Move m_last_move;

    std::shared_ptr<Mediator> m_mediator;

  public:
    /**
     * @brief constructor
     * @param gameUI user interface use on the game
     * @param player1 player 1
     * @param player2 player 2
     * @param boarSize size of the board
     */
    HEXGAMELIB_EXPORT Game( std::shared_ptr<Player> playerWhite,  std::shared_ptr<Player> playerBlack,
                           int boardSize, const std::shared_ptr<Mediator>& mediator);

    /**
     * @brief destructor
     */
    HEXGAMELIB_EXPORT ~Game();

    /**
     * @brief Get the Board object
     * @return Board * getter of the game's board
     */
    HEXGAMELIB_EXPORT Board *getBoard() const;

    /**
     * @brief Get the Num Turn object
     * @return  int, number of the current turn
     */
    HEXGAMELIB_EXPORT int getNumTurn() const;

    /**
     * @brief Get the Player Turn object
     * @return player who had to play
     */
    HEXGAMELIB_EXPORT  std::shared_ptr<Player> getPlayerTurn() const;

    /**
     * @brief increment the turn number
     */
    HEXGAMELIB_EXPORT void incrementNumTurn();

    /**
     * @brief change the player who had to play
     */
    HEXGAMELIB_EXPORT void changePlayerTurn();

    /**
     * @brief initialize the game
     */
    HEXGAMELIB_EXPORT void initGame();

    /**
     * @brief launch the game
     */
    HEXGAMELIB_EXPORT void launchGame();

    /**
     * @brief Change the turn of the game
     * 
     * @param move VALID move to play
     * @return 
     */
    HEXGAMELIB_EXPORT bool nextTurn(Move move);

    /**
     * @brief is the game is finished
     * @return bool
     */
    HEXGAMELIB_EXPORT bool isGameFinished();

    HEXGAMELIB_EXPORT void WaitingInstruction();
};
