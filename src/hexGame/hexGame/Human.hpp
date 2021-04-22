
#include "HexGameLib_export.hpp"

#include "Player.hpp"
#include "GameUI.hpp"

class Human : public Player
{

private:
    GameUI* gameUI;

public:
	HEXGAMELIB_EXPORT Human(Color, GameUI*);
	HEXGAMELIB_EXPORT ~Human();

	HEXGAMELIB_EXPORT Move makeMove();

};
