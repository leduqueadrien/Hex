
#include "Player.hpp"
#include "Human.hpp"
#include "Game.hpp"

Player::Player(Color color): Player(color, true) {}

Player::Player(Color color, bool isHuman) : m_color(color), m_isHuman(isHuman) {}

Color Player::getColor() const {
	return m_color;
}

bool Player::getIsHuman() const {
	return m_isHuman;
}

void Player::initPlayer() {}
