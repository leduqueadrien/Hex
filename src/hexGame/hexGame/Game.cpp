
#include <iostream>
#include <string>
#include "Game.hpp"

Game::Game(GameUI* gameUI, Player* player1, Player* player2, int boardSize):
	gameUI(gameUI),
	player1(player1),
	player2(player2),
	boardSize(boardSize)
{

}

Game::~Game()
{
}


void Game::initGame()
{
}


void Game::launchGame()
{
	while(!isGameFinished()) {
		displayBoard();

	}
}


bool Game::isGameFinished() const
{
	return false;
}


void Game::displayBoard() const
{
	gameUI->displayBoard(board);
}
