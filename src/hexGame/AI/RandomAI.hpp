
#include "HexGameLib_export.hpp"

#include "AI.hpp"
#include <hexGame/Board.hpp>

/**
 * @brief random AI player class
 *
 */
class RandomAI : public AI {

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
     * @brief Initialise the player
     *
     * @param board the board on which the player will play
     * @return HEXGAMELIB_EXPORT
     */
    HEXGAMELIB_EXPORT void initPlayer(Board *board) override;

    /**
     * @brief choose the move to make
     * @param current_board current state of the board
     * @return Move move made
     */
    HEXGAMELIB_EXPORT Move makeMove(Board *current_board) override;
};
