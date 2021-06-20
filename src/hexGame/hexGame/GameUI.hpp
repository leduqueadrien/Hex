
#pragma once

#include "HexGameLib_export.hpp"

#include "Board.hpp"


// https://docs.microsoft.com/fr-fr/cpp/cpp/dllexport-dllimport?view=msvc-160
// https://docs.microsoft.com/fr-fr/cpp/cpp/using-dllimport-and-dllexport-in-cpp-classes?view=msvc-160
// https://docs.microsoft.com/fr-fr/cpp/error-messages/tool-errors/linker-tools-error-lnk2001?view=msvc-160#what-is-an-unresolved-external-symbol


/**
 * @brief user interface base class
 */
class GameUI
{
private:

public:

	/**
	 * @brief constructor
	 */
	HEXGAMELIB_EXPORT GameUI() = default;

	/**
	 * @brief destructor
	 */
	HEXGAMELIB_EXPORT virtual ~GameUI() = default;

	/**
	 * @brief display the board
	 */
	HEXGAMELIB_EXPORT virtual void displayBoard(Board*) = 0;

	/**
	 * @brief display information about the turn
	 */
	HEXGAMELIB_EXPORT virtual void displayTurnInfo(int, Color) = 0;

	/**
	 * @brief display a move
	 * 
	 * @param move move who had to be display
	 */
	HEXGAMELIB_EXPORT virtual void displayMove(Move move) = 0;

	/**
	 * @brief Get the player move
	 * @param move move made
	 */
	HEXGAMELIB_EXPORT virtual void getPlayerMove(Move& move) = 0;
};
