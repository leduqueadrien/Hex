
#pragma once

#include "HexGameLib_export.hpp"

#include <hexGame/Board.hpp>
#include <hexGame/Player.hpp>

/**
 * @brief AI based class
 */
class AI : public Player {

public:
    /**
     * @brief constructor
     * @param color player's color
     */
    HEXGAMELIB_EXPORT AI(Color color) : Player::Player(color, false) {
    }

    /**
     * @brief destructor
     */
    HEXGAMELIB_EXPORT ~AI() = default;
};
