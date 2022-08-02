
#pragma once

#include "HexGameLib_export.hpp"

#include <hexGame/Board.hpp>

#include "AI.hpp"
#include "AdjacentList.hpp"

#include <vector>

/**
 * @brief AI based on Monte Carlo principal
 */
class MonteCarloCrossGame : public AI {

private:
    /**
     * @brief board used to explore games
     */
    Board *m_explore_board;

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
     * @brief from the current state of the board, simulate a game until
     * the end
     * @param adjlist AdjacentList that contain the tile that can
     * be played by the players
     * @return color of the winner
     */
    HEXGAMELIB_EXPORT Color playUntilEnd(AdjacentList<Tile> &adjlist);

    /**
     * @brief Make a move on the exploration game
     * @param color color of the player that had to play
     * @param adjList AdjacentList of all the playable
     * @return void
     */
    HEXGAMELIB_EXPORT void simulateMove(Color color,
                                        AdjacentList<Tile> &adjList);

    /**
     * @brief reset the exploration board in order to be like the current
     * state of the board
     * @param current_board current board
     * @return void
     */
    HEXGAMELIB_EXPORT void ResetExploreBoard(Board *current_board);

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

        - Ne pas faire un check de fin de partie a chaque coup.
                Le faire tous les 2, 3, ... coup
                A la fin de la partie, quand toutes les pieces ont ete posse
        








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
