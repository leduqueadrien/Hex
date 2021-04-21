
#include <iostream>
#include <string>
#include <hexGame/Game.hpp>


int main(int, char const **)
{
	std::cout << "Starting Game" << std::endl;
	Game* game = new Game(11);
	game->printBoard();
	return 0;
}
