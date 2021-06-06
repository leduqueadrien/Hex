
#include <iostream>
#include <string>
#include <hexGame/Game.hpp>
#include <hexGame/Human.hpp>
#include "ConsoleUI.hpp"


int main(int, char const **)
{
	std::cout << "Starting Game" << std::endl;

	GameUI* gameUI = new ConsoleUI();
	Human* player1 = new Human(Color::White, gameUI);
	Human* player2 = new Human(Color::Black, gameUI);
	Game* game = new Game(gameUI, player1, player2, 3);

	(*game).initGame();
	(*game).launchGame();

	std::cout << "End Game" << std::endl;

	return 0;
}
