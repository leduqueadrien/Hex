
#include <hexGame/GameUI.hpp>
#include <hexGame/Board.hpp>

class ConsoleUI : public GameUI
{

private:

public:
	ConsoleUI();
	~ConsoleUI();

	void displayBoard(Board* board);
	void getMove();

};
