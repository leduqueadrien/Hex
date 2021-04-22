
#pragma once

#include "HexGameLib_export.hpp"

#include "gameUtils.hpp"

class Player
{
protected:
    Color color;

public:
	HEXGAMELIB_EXPORT Player(Color color): color(color) {};
	HEXGAMELIB_EXPORT virtual ~Player() = default;

	HEXGAMELIB_EXPORT virtual Move makeMove() = 0;
};