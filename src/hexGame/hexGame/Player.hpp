
#pragma once

#include "HexGameLib_export.hpp"

#include "gameUtils.hpp"


/**
 * @brief player base class
 */
class Player
{
protected:
	/**
	 * @brief color of the player
	 */
    Color m_color;

public:

	/**
	 * @brief constructor
	 * @param color player's color
	 */
	HEXGAMELIB_EXPORT Player(Color color);

	/**
	 * @brief destructor
	 */
	HEXGAMELIB_EXPORT virtual ~Player() = default;

	/**
	 * @brief Get the Color object
	 * @return the player's color
	 */
	HEXGAMELIB_EXPORT Color getColor() const;

	/**
	 * @brief choose the move to make
	 * @return Move move made 
	 */
	HEXGAMELIB_EXPORT virtual Move makeMove() = 0;
	
};
