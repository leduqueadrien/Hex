
// #pragma ones


#ifndef AI_HPP
#define AI_HPP




#include "HexGameLib_export.hpp"

#include <hexGame/Player.hpp>
#include <hexGame/Game.hpp>

class AI: public Player {
	protected:
		Game * m_game;

	public:
		HEXGAMELIB_EXPORT AI(Color color, Game* game) : Player::Player(color), m_game(game) {}
		HEXGAMELIB_EXPORT AI(Color color) : Player::Player(color){}
		HEXGAMELIB_EXPORT ~AI() = default;
		HEXGAMELIB_EXPORT void setGame(Game * game) {m_game = game;}
};

#endif
