
#pragma once

#include "HexGameLib_export.hpp"

#include <hexGame/Player.hpp>
#include <hexGame/Board.hpp>

class AI: public Player {
	public:
		HEXGAMELIB_EXPORT AI(Color color) : Player::Player(color, false) {}
		HEXGAMELIB_EXPORT ~AI() = default;
};
