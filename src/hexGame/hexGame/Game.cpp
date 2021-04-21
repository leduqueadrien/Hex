
#include <iostream>
#include <string>
#include "Game.hpp"

Game::Game(int boardSize):
	boardSize(boardSize)
{

}

Game::~Game()
{
}


void Game::printBoard()
{
	std::string space = "";

	std::cout << std::endl;
	for (int i=0; i<=boardSize; i++) {

		space.append(" ");
		std::cout << space;
		for (int j=0; j<=boardSize; j++) {
			std::cout << "[]";
		}

		std::cout << std::endl;
	}
	std::cout << std::endl;
}
