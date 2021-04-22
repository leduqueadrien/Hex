
#pragma once

#include "HexGameLib_export.hpp"

#include <vector>
#include "gameUtils.hpp"
#include "Tile.hpp"

class Board final
{
private:
	int m_size;
	std::vector<std::vector<Tile*>> m_board;

public:
	HEXGAMELIB_EXPORT Board(int size);
	HEXGAMELIB_EXPORT ~Board();

	HEXGAMELIB_EXPORT void initBoard();
	HEXGAMELIB_EXPORT void addMoveToBoard(Move move);
	HEXGAMELIB_EXPORT bool isMoveValid(Move move) const;
	HEXGAMELIB_EXPORT void resetCheckup();
	HEXGAMELIB_EXPORT void deleteBoard();

	// Getters - Setters
	HEXGAMELIB_EXPORT Tile* getTile(int i, int j) const;

	// Operators
	HEXGAMELIB_EXPORT Board& operator=(const Board& board);
};
