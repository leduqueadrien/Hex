
#pragma once

#include "HexGameLib_export.hpp"

#include "GameUI.hpp"
#include "Player.hpp"

/**
 * @brief human player class
 */
class Human final : public Player {

  private:
    /**
     * @brief user interface of the game
     */
    GameUI *m_gameUI;

  public:
    /**
     * @brief constructor
     * @param color player's color
     * @param gameUI user interface of the game
     */
    HEXGAMELIB_EXPORT Human(Color color, GameUI *gameUI);

    /**
     * @brief destructor
     */
    HEXGAMELIB_EXPORT ~Human();

    /**
     * @brief Initialise the player
     *
     * @param board the board on which the player will play
     * @return void
     */
    HEXGAMELIB_EXPORT virtual void initPlayer(Board *board) override;

    /**
     * @brief choose the move to make
     * @param current_board unused parameter
     * @return Move move made
     */
    HEXGAMELIB_EXPORT Move makeMove(Board *current_board) override;
};
