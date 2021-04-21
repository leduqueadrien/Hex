
#include <iostream>
#include <string>
#include <hexGame/Game.hpp>
#include "ConsoleUI.hpp"


int main(int, char const **)
{
	std::cout << "Starting Game" << std::endl;

	GameUI* gameUI = new ConsoleUI();

	Game* game = new Game(gameUI, 11);
	game->displayBoard();

	return 0;
}
