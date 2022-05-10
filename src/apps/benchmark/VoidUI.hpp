
#include <hexGame/GameUI.hpp>
#include <hexGame/Game.hpp>
#include <hexGame/Board.hpp>
#include <hexGame/Tile.hpp>

class VoidU final : public GameUI
{

private:

public:
	VoidU() {}
	~VoidU() {}

	std::string displayTile(Tile * tile) {}
	void displayBoard(Board* board) {}
	void displayTurnInfo(int, Color) {}
	void displayMove(Move) {}
	void getPlayerMove(Move& move) {}

};
