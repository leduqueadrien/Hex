
#pragma once

#include "HexGameLib_export.hpp"

#include "gameUtils.hpp"

class Player
{
protected:
    Color m_color;

public:
	HEXGAMELIB_EXPORT Player(Color color);
	HEXGAMELIB_EXPORT virtual ~Player() = default;

	HEXGAMELIB_EXPORT Color getColor() const;

	HEXGAMELIB_EXPORT virtual Move makeMove() = 0;
	
};
