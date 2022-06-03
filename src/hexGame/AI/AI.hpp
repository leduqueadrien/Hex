
#pragma once

#include "HexGameLib_export.hpp"

#include <hexGame/Board.hpp>
#include <hexGame/Player.hpp>

class AI : public Player {
  public:
    HEXGAMELIB_EXPORT
    AI(Color color) : Player::Player(color, false) {}
    HEXGAMELIB_EXPORT ~AI() = default;
};
