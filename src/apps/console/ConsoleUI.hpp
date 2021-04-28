
#include <hexGame/GameUI.hpp>
#include <hexGame/Board.hpp>
#include <hexGame/Tile.hpp>

class ConsoleUI final : public GameUI
{

private:

public:
	ConsoleUI();
	~ConsoleUI();

	std::string displayTile(Tile * tile);
	void displayBoard(Board* board);
	void getPlayerMove(Move& move);

};
