
#include <hexGame/GameUI.hpp>
#include <hexGame/Board.hpp>

class ConsoleUI final : public GameUI
{

private:

public:
	ConsoleUI();
	~ConsoleUI();

	void displayBoard(Board* board);
	void getPlayerMove(Move& move);

};
