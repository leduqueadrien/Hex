
#pragma once


#include "HexGameLib_export.hpp"

#include <vector>
#include <hexgame/gameUtils.hpp>
#include "AI.hpp"


class MonteCarlo : public AI {
private:
	Board * m_explore_board;

public :
	HEXGAMELIB_EXPORT MonteCarlo(Color color, Game* game);

	HEXGAMELIB_EXPORT MonteCarlo(Color color);

	HEXGAMELIB_EXPORT ~MonteCarlo();

	HEXGAMELIB_EXPORT Move makeMove();

	HEXGAMELIB_EXPORT Color playUntilEnd();

	HEXGAMELIB_EXPORT void simulateMove(Color color);

	HEXGAMELIB_EXPORT void MajBoard();

	HEXGAMELIB_EXPORT void initPlayer() override;

};

/*
Amelioration :
	
*/
