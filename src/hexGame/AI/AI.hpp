
#pragma ones

#include "HexGameLib_export.hpp"

#include <hexGame/Player.hpp>
#include <hexGame/Game.hpp>

class AI: public Player {
	protected:
		Game * m_game;

	public:
		HEXGAMELIB_EXPORT AI(Color color, Game* game) : Player::Player(color), m_game(game) {}
		HEXGAMELIB_EXPORT ~AI() = default;
};
