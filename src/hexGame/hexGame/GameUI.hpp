
#pragma once

#include "HexGameLib_export.hpp"

#include "Board.hpp"

// https://docs.microsoft.com/fr-fr/cpp/error-messages/tool-errors/linker-tools-error-lnk2001?view=msvc-160#what-is-an-unresolved-external-symbol
class HEXGAMELIB_EXPORT GameUI
{
private:
	/* data */
public:
	GameUI(/* args */)=default;
	virtual ~GameUI()=default;

	virtual void displayBoard(Board*) = 0;
	virtual void getMove() = 0;
	//
};
