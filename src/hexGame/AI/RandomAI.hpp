
#include "HexGameLib_export.hpp"

#include "AI.hpp"
#include <hexgame/Board.hpp>

/**
 * @brief random AI player class
 * 
 */
class RandomAI : public AI
{

public:

	/**
	 * @brief constructor
	 * @param color player's color
	 */
	HEXGAMELIB_EXPORT RandomAI(Color color);

	/**
	 * @brief destructor
	 */
	HEXGAMELIB_EXPORT ~RandomAI();

	/**
	 * @brief choose the move to make
	 * @param current_board current state of the board
	 * @return Move move made
	 */
	HEXGAMELIB_EXPORT Move makeMove(Board* current_board);

};
