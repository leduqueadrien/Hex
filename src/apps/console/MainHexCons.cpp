
#include <iostream>
#include <string>
#include <hexGame/Game.hpp>
#include <hexGame/Human.hpp>
#include <AI/RandomAI.hpp>
#include <AI/MonteCarlo.hpp>
#include "ConsoleUI.hpp"


int main(int, char const **)
{
	std::cout << "Starting Game" << std::endl;

	GameUI* gameUI = new ConsoleUI();
	Player* player1 = new MonteCarlo(Color::White);
	Player* player2 = new Human(Color::Black, gameUI);


	Game* game = new Game(gameUI, player1, player2, 3);

	(*game).initGame();
	(*game).launchGame();

	std::cout << "End Game" << std::endl;

	delete game;
	delete gameUI;

	return 0;
}
