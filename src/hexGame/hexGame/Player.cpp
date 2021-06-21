
#include "Player.hpp"
#include "Human.hpp"
#include "Game.hpp"

Player::Player(Color color): m_color(color) {}

Color Player::getColor() const {
	return m_color;
}
