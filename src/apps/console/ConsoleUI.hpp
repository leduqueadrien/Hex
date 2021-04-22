
#include "hexGame/GameUI.hpp"
#include "hexGame/Board.hpp"

class ConsoleUI : public GameUI
{

private:
	/* data */

public:
	ConsoleUI(/* args */);
	~ConsoleUI();

	void displayBoard(Board* board);
	void getMove();

};
