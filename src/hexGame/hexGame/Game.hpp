
#pragma once

#include "Board.hpp"
#include "GameUI.hpp"
#include "HexGameLib_export.hpp"

// Without HEXGAMELIB_EXPORT, we get : error LNK2019 or : fatal error LNK1104
// https://docs.microsoft.com/fr-fr/cpp/error-messages/tool-errors/linker-tools-error-lnk2019?view=msvc-160
// https://docs.microsoft.com/fr-fr/cpp/error-messages/compiler-errors-1/fatal-error-c1083?view=msvc-160
class Game
{
private:
	int boardSize;
	Board * board = nullptr;
	// Player1
	// Player2
	GameUI * gameUI = nullptr;

public:
	HEXGAMELIB_EXPORT Game(GameUI* gameUI, int boardSize = 11);
	HEXGAMELIB_EXPORT ~Game();

	HEXGAMELIB_EXPORT void displayBoard();
};
