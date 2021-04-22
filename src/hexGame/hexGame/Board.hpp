
#pragma once

#include "HexGameLib_export.hpp"

#include <vector>
#include "gameUtils.hpp"
#include "Tile.hpp"

class Board
{
private:
	int size;
	std::vector<std::vector<Tile*>> board;

public:
	HEXGAMELIB_EXPORT Board(int size);
	HEXGAMELIB_EXPORT ~Board();

	HEXGAMELIB_EXPORT void initBoard();
	HEXGAMELIB_EXPORT void resetCheckup();
	HEXGAMELIB_EXPORT Tile* getTile(int, int);
	HEXGAMELIB_EXPORT void addMoveToBoard(Move);
	HEXGAMELIB_EXPORT bool isMoveValid(Move);

	// Operators

	HEXGAMELIB_EXPORT Board& operator=(const Board&);
};
