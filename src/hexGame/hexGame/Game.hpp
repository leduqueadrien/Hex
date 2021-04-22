
#pragma once

#include "Board.hpp"
#include "GameUI.hpp"
#include "Player.hpp"
#include "HexGameLib_export.hpp"

// Without HEXGAMELIB_EXPORT, we get : error LNK2019 or : fatal error LNK1104
// https://docs.microsoft.com/fr-fr/cpp/error-messages/tool-errors/linker-tools-error-lnk2019?view=msvc-160
// https://docs.microsoft.com/fr-fr/cpp/error-messages/compiler-errors-1/fatal-error-c1083?view=msvc-160
class Game final
{
private:
	int m_boardSize;
	Board* m_board = nullptr;
	GameUI* m_gameUI = nullptr;
	Player* m_player1 = nullptr;
	Player* m_player2 = nullptr;

	Player* m_turn = nullptr;

public:
	HEXGAMELIB_EXPORT Game(GameUI* gameUI, Player* player1, Player* player2, int boardSize = 11);
	HEXGAMELIB_EXPORT ~Game();

	HEXGAMELIB_EXPORT void displayBoard() const;

	HEXGAMELIB_EXPORT void initGame();
	HEXGAMELIB_EXPORT void launchGame();
	HEXGAMELIB_EXPORT bool isGameFinished() const;
};
