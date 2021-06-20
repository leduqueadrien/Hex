
#pragma once

#include "Board.hpp"
#include "GameUI.hpp"
#include "Player.hpp"
#include "HexGameLib_export.hpp"

// Convention : blanc : haut en bas
//				noire : gauche droite

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
	int m_numTurn;

	Player* m_player_turn = nullptr;

public:
	HEXGAMELIB_EXPORT Game(GameUI* gameUI, int player1Code, int player2Code, int boardSize = 11);
	HEXGAMELIB_EXPORT ~Game();

	HEXGAMELIB_EXPORT Board* getBoard() const;
	HEXGAMELIB_EXPORT int getNumTurn() const;
	HEXGAMELIB_EXPORT Player* getPlayerTurn() const;

	HEXGAMELIB_EXPORT void displayBoard() const;
	HEXGAMELIB_EXPORT void incrementNumTurn();
	HEXGAMELIB_EXPORT void changePlayerTurn();

	HEXGAMELIB_EXPORT void initGame();
	HEXGAMELIB_EXPORT void launchGame();
	HEXGAMELIB_EXPORT bool isGameFinished();
	HEXGAMELIB_EXPORT bool hasPlayerWon(Color);
	HEXGAMELIB_EXPORT Player* ConvertCodeToPlayer(int code, Color color);
};
