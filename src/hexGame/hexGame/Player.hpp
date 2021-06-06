
#pragma once

#include "HexGameLib_export.hpp"

#include "gameUtils.hpp"

class Player
{
protected:
    Color m_color;

public:
	HEXGAMELIB_EXPORT Player(Color color): m_color(color) {};
	HEXGAMELIB_EXPORT virtual ~Player() = default;

	HEXGAMELIB_EXPORT inline Color getColor() const {
		return m_color;
	}

	HEXGAMELIB_EXPORT virtual Move makeMove() = 0;
};