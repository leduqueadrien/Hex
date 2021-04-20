
#include "GameUI.hpp"

class ConsoleUI : public GameUI
{

private:
	/* data */

public:
	ConsoleUI(/* args */);
	~ConsoleUI();

	void displayBoard();
	void getMove();

};
