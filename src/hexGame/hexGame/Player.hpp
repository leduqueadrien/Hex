
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

	/**
	 * @brief is the player a human
	 */
	bool m_isHuman;

public:

	/**
	 * @brief constructor
	 * @param color player's color
	 */
	HEXGAMELIB_EXPORT Player(Color color);

	/**
	 * @brief constructor
	 * @param color player's color
	 * @param isHuman is the player a human
	 */
	HEXGAMELIB_EXPORT Player(Color color, bool isHuman);


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
	 * @brief Get is the player is human
	 * @return is the player a human 
	 */
	HEXGAMELIB_EXPORT bool Player::getIsHuman() const;

	/**
	 * @brief choose the move to make
	 * @return Move move made 
	 */
	HEXGAMELIB_EXPORT virtual Move makeMove() = 0;
	
};
