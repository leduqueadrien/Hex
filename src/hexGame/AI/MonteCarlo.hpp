
#pragma onces


// #ifndef MONTECARLO_HPP
// #define MONTECARLO_HPP




#include "HexGameLib_export.hpp"

#include <vector>
#include <hexgame/gameUtils.hpp>
#include "AI.hpp"

typedef struct Point
{
	int i;
	int j;
}Point;


class MonteCarlo : public AI {
private:
	int m_size;
	std::vector<std::vector<int>> m_proba;
	std::vector<std::vector<int>> m_isChecked;
	std::vector<std::vector<int>> m_board;
	std::vector<std::vector<int>> m_exploreBoard;



public :
	HEXGAMELIB_EXPORT MonteCarlo(Color color, Game* game);
	HEXGAMELIB_EXPORT ~MonteCarlo();

	HEXGAMELIB_EXPORT Move makeMove();

	HEXGAMELIB_EXPORT int playUntilEnd();

	HEXGAMELIB_EXPORT Move chooseMove() const;

	HEXGAMELIB_EXPORT void restartSimulationGame();

	HEXGAMELIB_EXPORT void simulateMove(int color);

	HEXGAMELIB_EXPORT void updateProba(int winnerColor);

	HEXGAMELIB_EXPORT void restVectorOfVectorOfInt(std::vector<std::vector<int>>& vector);

	HEXGAMELIB_EXPORT bool isMoveValid(int i, int j) const;

	HEXGAMELIB_EXPORT bool isPlayerWin(int color);

	HEXGAMELIB_EXPORT Point& getNextNeighbour(int tile_i, int tile_j, int num_neighbour);

	HEXGAMELIB_EXPORT Point& constructPoint(int i, int j);

	HEXGAMELIB_EXPORT void MajBoard();

};

/*
Amelioration :
	
*/

// erreur de compilation pas claire
// Visual C++ n'a pas l'aire de connaitre pragma once
//			https://docs.microsoft.com/fr-fr/cpp/preprocessor/once?view=msvc-160
// Le fait qu'aucun message d'erreur est afficher doit venir d'une option de compilation (pb pour le graphique avec ninja)


// #endif
