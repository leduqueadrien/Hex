
#include "HexGameLib_export.hpp"

#include "AI.hpp"
#include <hexgame/GameUI.hpp>


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
	 * @param game game
	 */
	HEXGAMELIB_EXPORT RandomAI(Color color , Game* game);

	/**
	 * @brief destructor
	 */
	HEXGAMELIB_EXPORT ~RandomAI();

	/**
	 * @brief choose the move to make
	 * @return Move move made 
	 */
	HEXGAMELIB_EXPORT Move makeMove();

};
