
#pragma once

#include "HexGameLib_export.hpp"

#include "AI.hpp"
#include "AdjacentList.hpp"
#include <hexGame/Board.hpp>

class MonteCarlo : public AI {
  private:
    Board *m_explore_board;

  public:
    HEXGAMELIB_EXPORT MonteCarlo(Color color, Board *board);

    HEXGAMELIB_EXPORT MonteCarlo(Color color);

    HEXGAMELIB_EXPORT ~MonteCarlo();

    HEXGAMELIB_EXPORT Move makeMove(Board *current_board);

    HEXGAMELIB_EXPORT Color playUntilEnd(AdjacentList &adjlist);

    HEXGAMELIB_EXPORT void simulateMove(Color color, AdjacentList &adjList);

    HEXGAMELIB_EXPORT void ResetExploreBoard(Board *current_board);

    HEXGAMELIB_EXPORT void initPlayer(Board *board) override;
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
