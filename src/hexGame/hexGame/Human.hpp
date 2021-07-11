
#pragma once

#include "HexGameLib_export.hpp"

#include "Player.hpp"
#include "GameUI.hpp"


/**
 * @brief human player class
 */
class Human final : public Player
{

private:
	/**
	 * @brief user interface of the game
	 */
    GameUI* m_gameUI;

public:

	/**
	 * @brief constructor
	 * @param color player's color
	 * @param gameUI user interface of the game
	 */
	HEXGAMELIB_EXPORT Human(Color color, GameUI* gameUI);

	/**
	 * @brief destructor
	 */
	HEXGAMELIB_EXPORT ~Human();

	/**
	 * @brief choose the move to make
	 * @return Move move made 
	 */
	HEXGAMELIB_EXPORT Move makeMove();

};
