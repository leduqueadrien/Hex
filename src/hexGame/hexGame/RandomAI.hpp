
#include "HexGameLib_export.hpp"

#include "AI.hpp"
#include "GameUI.hpp"

class RandomAI : public AI
{

public:
	HEXGAMELIB_EXPORT RandomAI(Color, Game*);
	HEXGAMELIB_EXPORT ~RandomAI();

	HEXGAMELIB_EXPORT Move makeMove();

};
