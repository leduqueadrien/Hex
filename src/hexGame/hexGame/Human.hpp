
#pragma onces

#include "HexGameLib_export.hpp"

#include "Player.hpp"
#include "GameUI.hpp"

class Human final : public Player
{

private:
    GameUI* m_gameUI;

public:
	HEXGAMELIB_EXPORT Human(Color color, GameUI* gameUI);
	HEXGAMELIB_EXPORT ~Human();

	HEXGAMELIB_EXPORT Move makeMove();

};
