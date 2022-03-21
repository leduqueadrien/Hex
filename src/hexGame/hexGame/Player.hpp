
#pragma once

#include "HexGameLib_export.hpp"

#include "gameUtils.hpp"
#include "Board.hpp"


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


	HEXGAMELIB_EXPORT virtual void initPlayer();

	/**
	 * @brief Get the Color object
	 * @return the player's color
	 */
	HEXGAMELIB_EXPORT Color getColor() const;

	/**
	 * @brief Get is the player is human
	 * @return is the player a human 
	 */
	HEXGAMELIB_EXPORT bool getIsHuman() const;

	/**
	 * @brief choose the move to make
	 * @param current_board current state of the board
	 * @return Move move made
	 */
	HEXGAMELIB_EXPORT virtual Move makeMove(Board* current_board) = 0;
	
};
