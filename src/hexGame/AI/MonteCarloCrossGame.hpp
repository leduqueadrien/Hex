
#pragma once

#include "HexGameLib_export.hpp"

#include "MonteCarlo.hpp"

#include <vector>

/**
 * @brief AI based on Monte Carlo principal
 */
class MonteCarloCrossGame : public MonteCarlo {

private:

    std::vector<int> m_boardCounter;

public:
    /**
     * @brief constructor
     * @param color player's color
     * @param board current board
     */
    HEXGAMELIB_EXPORT MonteCarloCrossGame(Color color, Board *board);

    /**
     * @brief constructor
     * @param color player's color
     */
    HEXGAMELIB_EXPORT MonteCarloCrossGame(Color color);

    /**
     * @brief destructor
     */
    HEXGAMELIB_EXPORT ~MonteCarloCrossGame();

    /**
     * @brief choose the move to make
     * @param current_board current state of the board
     * @return move made
     */
    HEXGAMELIB_EXPORT Move makeMove(Board *current_board);

    /**
     * @brief Initialise the player
     * @param board current state of the board
     * @return void
     */
    HEXGAMELIB_EXPORT void initPlayer(Board *board) override;

    HEXGAMELIB_EXPORT void initGameCounter();

    HEXGAMELIB_EXPORT void resetCountBoard();

    HEXGAMELIB_EXPORT void updateBoardCounter();

    HEXGAMELIB_EXPORT Move chooseMove(Board *current_board);
};

/*
Amelioration :
        - Utilisation de mutex et qu'un seul tableau compteur ou plusieur
tableau compteur et pas de mutex A decider avec du benchmark

        - Trouver un algo opti de recherche de chemin dans un graph

        - Utiliser namespace pour la librairie

        -Utiliser Smart Pointer

        - Regarder goulot d'etranglement pour savoir ou optimiser
                Savoir si la partie a ete gagne en est un, c'est sur
                Un trouver d'autre

        - Utiliser patron de conception pour :
                Creation des Tiles : fabrique
                Utilisation AI : Strategie
                Utilisation de lalgo de MT : Strategie
                Pour IHM : fabrique
*/
