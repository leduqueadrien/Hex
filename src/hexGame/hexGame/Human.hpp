
#pragma once

#include "HexGameLib_export.hpp"

#include <memory>

#include "Mediator.hpp"
#include "Player.hpp"

/**
 * @brief human player class
 */
class Human final : public Player {

  private:
    std::shared_ptr<Mediator> m_mediator;

  public:
    /**
     * @brief constructor
     * @param color player's color
     * @param mediator mediator between Game and UI
     */
    HEXGAMELIB_EXPORT Human(Color color, std::shared_ptr<Mediator> mediator);

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
