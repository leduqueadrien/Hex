
#pragma once

#include "HexGameLib_export.hpp"

#include "Board.hpp"


// https://docs.microsoft.com/fr-fr/cpp/cpp/dllexport-dllimport?view=msvc-160
// https://docs.microsoft.com/fr-fr/cpp/cpp/using-dllimport-and-dllexport-in-cpp-classes?view=msvc-160
// https://docs.microsoft.com/fr-fr/cpp/error-messages/tool-errors/linker-tools-error-lnk2001?view=msvc-160#what-is-an-unresolved-external-symbol

class GameUI
{
private:
	/* data */
public:
	HEXGAMELIB_EXPORT GameUI() = default;
	HEXGAMELIB_EXPORT virtual ~GameUI() = default;

	HEXGAMELIB_EXPORT virtual void displayBoard(Board*) = 0;
	HEXGAMELIB_EXPORT virtual void getMove() = 0;
	//
};
